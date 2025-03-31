# Lifecycle
![[Pasted image 20250329101254.png]]
## Preparation
This phase covers the **readiness** of an organization against an attack.
That means:
- **documenting** the requirements
- **defining** the policies
- **incorporating the security controls** to monitor like EDR / SIEM / IDS / IPS
- **hiring/training** the staff
## Detection and Analysis
This phase covers everything related to **detecting an incident** and the analysis process of the incident.
It cover:
- **getting alerts** from the security controls like SIEM/EDR
- **investigating the alert** to find the root cause
- **hunting for the unknown threat** within the organization
## Containment, Eradication and Recovery
This phase covers the **actions needed to prevent the incident from spreading** and securing the network.
It involves:
- **isolating** the infected host
- **clearing the network** from the infection traces
- **gaining control** back from the attack
## Post-Incident Activity / Lesson learnt
This phase includes identifying the loopholes in the organization's security posture, which led to an intrusion, and improving so that the attack does not happen next time.
It includes:
- identifying weaknesses that led to the attack
- adding detection rules so that similar breach does not happen again
- training the staff if required
# Using Splunk
The goal is to get information about a deface in the imreallynotbatman.com website.
## Reconnaissance
Lets see all request about the website:
`index=botsv1 imreallynotbatman.com`
**Search Query explanation:** We are going to look for the event logs in the index "botsv1" which contains the term `imreallynotbatman.com`
![[c320e7a1192dd94671fb5048e6a3cf3d.gif]]
We can see that we have 4 sources:
- Suricata
- stream:http
- fortigate_utm
- iis

### Find the suspicious IP
Let's begin looking at the log source **stream:http** and examining the src_ip.
`index=botsv1 imreallynotbatman.com sourcetype=stream:http`
![[Pasted image 20250329102817.png]]

Lets examining the ip: 40.80.148.42
![[6e4de3d85d3322f76b20c71ea020d0b4.gif]]

### Validate
Lets now validate the fact that the Ip is scanning.
**Search Query:** `index=botsv1 imreallynotbatman.com src=40.80.148.42 sourcetype=suricata`
**Search Query Explanation:** This query will show the logs from the suricata log source that are detected/generated from the source IP **40.80.248.42**
![[ff5428b053d955ddc89da6ff9dc0f81e.gif]]
## Exploitation
To begin our investigation, let's note the information we have so far:
- We found two IP addresses from the reconnaissance phase with sending requests to our server.
- One of the IPs `40.80.148.42` was seen attempting to scan the server with IP **192.168.250.70**.
- The attacker was using the web scanner Acunetix for the scanning attempt.
### Count
**Search Query**:`index=botsv1 imreallynotbatman.com sourcetype=stream* | stats count(src_ip) as Requests by src_ip | sort - Requests`
**Query Explanation:** This query uses the stats function to display the count of the IP addresses in the field src_ip.
![[Pasted image 20250329104318.png]]
### Requests
Let's focus on the requests sended to out webserver:
**Search Query:** `index=botsv1 sourcetype=stream:http dest_ip="192.168.250.70"`
**Query Explanation:** This query will look for all the inbound traffic towards IP **192.168.250.70.**
![[Pasted image 20250329104522.png]]

To see what kind of traffic is coming through the POST requests, we will narrow down on the field `http_method=POST` as shown below:

**Search Query:** `index=botsv1 sourcetype=stream:http dest_ip="192.168.250.70" http_method=POST   `
![[Pasted image 20250329104615.png]]
![[ff5428b053d955ddc89da6ff9dc0f81e 1.gif]]
## Checking admin pannel
**Search query:** `index=botsv1 imreallynotbatman.com sourcetype=stream:http dest_ip="192.168.250.70"  uri="/joomla/administrator/index.php"   `  

**Query Explanation:** We are going to add `uri="/joomla/administrator/index.php"` in the search query to show the traffic coming into this URI.
![[Pasted image 20250329105040.png]]
We will dig deep into the values contained within the form_data field, as shown below:

**Search Query:** `index=botsv1 sourcetype=stream:http dest_ip="192.168.250.70" http_method=POST uri="/joomla/administrator/index.php" | table _time uri src_ip dest_ip form_data`

**Query Explanation:** We will add this -> `| table _time uri src_ip dest_ip form_data` to create a table containing important fields as shown below:
![[Pasted image 20250329105228.png]]
### Regex
Now, let's use Regex.  **`rex field=form_data "passwd=(?<creds>\w+)"`** To extract the **passwd** values only. This will pick the **form_data** field and extract all the values found with the field. **`creds`**.  

**Search Query:**`index=botsv1 sourcetype=stream:http dest_ip="192.168.250.70" http_method=POST form_data=*username*passwd* | rex field=form_data "passwd=(?<creds>\w+)" |table _time src_ip uri http_user_agent creds`
![[594dedebeb2d2d5a7cc6cae8d1ebc226 1.gif]]
## Installation
To begin an investigation, we first would narrow down any http traffic coming into our server **192.168.250.70** containing the term ".exe." This query may not lead to the findings, but it's good to start from 1 extension and move ahead.

**Search Query**: `index=botsv1 sourcetype=stream:http dest_ip="192.168.250.70" *.exe`
![[594dedebeb2d2d5a7cc6cae8d1ebc226 1.gif]]

With the search query in place, we are looking for the fields that could have some values of our interest. As we could not find the file name field, we looked at the missing fields and saw a field. `part_filename{}`.

Observing the interesting fields and values, we can see the field `part_filename{}` contains the two file names. an executable file `3791.exe` and a PHP file `agent.php`
![[Pasted image 20250329110756.png]]
### Was this file executed on the server after being uploaded?
**Search Query:** `index=botsv1 "3791.exe"`
![[Pasted image 20250329110827.png]]

Following the Host-centric log, sources were found to have traces of the executable 3791. exe.
- Sysmon
- WinEventlog
- fortigate_utm
For the evidence of execution, we can leverage sysmon and look at the EventCode=1 for program execution.

**Search Query:** `index=botsv1 "3791.exe" sourcetype="XmlWinEventLog" EventCode=1`
**Query Explanation:** This query will look for the process Creation logs containing the term **"3791.exe"** in the logs.
![[Pasted image 20250329110939.png]]
## Action on Objective
As the website was defaced due to a successful attack by the adversary, it would be helpful to understand better what ended up on the website that caused defacement.

We will start our investigation by examining the **Suricata** log source and the IP addresses communicating with the webserver 192.168.250.70.
**Search Query**:`index=botsv1 dest=192.168.250.70 sourcetype=suricata`
![[Pasted image 20250329111501.png]]

The logs do not show any external IP communicating with the server. Let us change the flow direction to see if any communication originates from the server.

**Search Query:** `index=botsv1 src=192.168.250.70 sourcetype=suricata`
![[Pasted image 20250329111523.png]]

What is interesting about the output? Usually, the web servers do not originate the traffic. The browser or the client would be the source, and the server would be the destination. Here we see three external IPs towards which our web server initiates the outbound traffic. There is a large chunk of traffic going to these external IP addresses, which could be worth checking.

Pivot into the destination IPs one by one to see what kind of traffic/communication is being carried out.

**Search Query:** `index=botsv1 src=192.168.250.70 sourcetype=suricata dest_ip=23.22.63.114`
![[Pasted image 20250329111641.png]]

The URL field shows 2 PHP files and one jpeg file. This jpeg file looks interesting. Let us change the search query and see where this jpeg file came from.

**Search Query:** `index=botsv1 url="/poisonivy-is-coming-for-you-batman.jpeg" dest_ip="192.168.250.70" | table _time src dest_ip http.hostname url`
![[da31347a03f68b6e9998e66db946dccb.gif]]
## Command and Control
The attacker uploaded the file to the server before defacing it. While doing so, the attacker used a Dynamic DNS to resolve a malicious IP. Our objective would be to find the IP that the attacker decided the DNS.

To investigate the communication to and from the adversary's IP addresses, we will be examining the network-centric log sources mentioned above. We will first pick fortigate_utm to review the firewall logs and then move on to the other log sources.

**Search Query:** `index=botsv1 sourcetype=fortigate_utm"poisonivy-is-coming-for-you-batman.jpeg"   `
![[Pasted image 20250329112326.png]]

Let us verify the answer by looking at another log source.`stream:http`.

**Search Query:** `index=botsv1 sourcetype=stream:http dest_ip=23.22.63.114 "poisonivy-is-coming-for-you-batman.jpeg" src_ip=192.168.250.70`
![[Pasted image 20250329112428.png]]
## Weaponization
So far, we have found a domain `prankglassinebracket.jumpingcrab.com` associated with this attack. Our first task would be to find the IP address tied to the domains that may potentially be pre-staged to attack Wayne Enterprise.

### Robtex:  
[Robtex](https://www.robtex.com/) is a Threat Intel site that provides information about IP addresses, domain names, etc.  

Please search for the domain on the robtex site and see what we get. We will get the IP addresses associated with this domain.

![[Pasted image 20250329113039.png]]
Some domains/subdomains associated with this domain:
![[Pasted image 20250329113052.png]]
### Get more info
You can get more information in:
https://otx.alienvault.com/indicator/domain/po1s0n1vy.com
