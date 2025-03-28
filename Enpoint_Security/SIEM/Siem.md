A **Security Information and Event Management system** is a tool that collects data from various endpoints/network devices, stores them and perform correlation on them.
# Network visibility
![[Pasted image 20250328094435.png]]
Here is an exemple of a simple network that comprise multiple Linux/Windows based Endpoints. Each component communicates with the other or accesses the internet.
## Host-centric Log Sources
This is the log sources that are **captured from a particular host**. Some log source that capture this type of logs are:
- **Windows Event logs**
- **Sysmon**
- **OsQuery**
Some exemple of these logs are:
- A **user accessing a file**
- A **user attempting** to **authentificate**
- A **process Execution** Activity
- A **process** **adding/editing/deleting** a **registry key** or value
- **Powershell execution**
## Network-Centric Log Sources
These logs are **generated when a host communicate with another host** or **accessing the internet** to visit a website. Some protocols are **SSH, VPN, HTTP/s, FTP**...
Some exemple of these logs are:
- SSH connection
- A file being accessed via FTP
- Web traffic
- A user accessing company's resources through VPN.
- Network file sharing Activity
# Importance of a SIEM
All these devices generate hundreds of events per second, examining the logs of each device one by one in case of any incident can be a tendious task.
That is one of the advantages of having a SIEM solution in place. It **provide the ability of correlate between events**, **search through the logs**, **investigate incidents** and are respond promptly. 
They contains:
- Real-time log ingestion
- Alerting against abnormal activities
- 24/7 Monitoring and visibility
- Protection against the latest threats through early detection
- Data insights and visualization
- Ability to investigate past incidents.
# Sources
## Windows
All the logs can be found in the Event Viewer:
![[30beed26fc514cb7f52773b88a4510b9.gif]]
## Linux Workstation
Some common locations where Linux store logs are:
- **/var/log/httpd**: Contains HTTP Request / Response and error logs.
- **/var/log/cron**: Events related to cron jobs are stored in this location.
- **/var/log/auth.log and /var/log/secure**: Store authentication related logs.
- **/var/log/kern**: This file stores kernel related events.

Here is an exemple of cron logs:
```
May 28 13:04:20 ebr crond[2843]: /usr/sbin/crond 4.4 dillon's cron daemon, started with loglevel notice  
May 28 13:04:20 ebr crond[2843]: no timestamp found (user root job sys-hourly)  
May 28 13:04:20 ebr crond[2843]: no timestamp found (user root job sys-daily)  
May 28 13:04:20 ebr crond[2843]: no timestamp found (user root job sys-weekly)  
May 28 13:04:20 ebr crond[2843]: no timestamp found (user root job sys-monthly)  
Jun 13 07:46:22 ebr crond[3592]: unable to exec /usr/sbin/sendmail: cron output for user root job sys-daily to /dev/null
```
## Web server
For Apache, logs are stored in: **/var/log/apache** or **/var/log/httpd**
Here is an exemple:
```
192.168.21.200 - - [21/March/2022:10:17:10 -0300] "GET /cgi-bin/try/ HTTP/1.0" 200 3395
127.0.0.1 - - [21/March/2022:10:22:04 -0300] "GET / HTTP/1.0" 200 2216
```
## Log ingestion
All these logs provide a wealth of information and can help in identify security issues.
Each SIEM solution has its own way of ingesting the logs, it can be:
- **Agent / Forwarder**: It provide lightweight tool called an agent (forwarder by Splunk) that gets installed in the endpoint. It is configured to capture all the important logs and send them to the SIEM server.
- **Syslog**: Syslog is a widely used protocol to collect data from various systems like web servers, databases, etc., are sent real-time data to the centralized destination.
- **Manual Upload**: Some SIEM solutions, like Splunk, ELK, etc., allow users to ingest offline data for quick analysis. Once the data is ingested, it is normalized and made available for analysis.
- **Port-Forwarding**: SIEM solutions can also be configured to listen on a certain port, and then the endpoints forward the data to the SIEM instance on the listening port.
# Analysing logs and alerts
## Dashboard
These are the most important components of any SIEM. Some of the information that can be found in a dashboard are:
- Alert Highlights
- System Notification
- Health Alert
- List of Failed Login Attempts
- Events Ingested Count
- Rules triggered
- Top Domains Visited

Here is an exemple of a default dashboard in QRadar SIEM:
![[Pasted image 20250328110825.png]]
## Correlation rules
It play an important role in the timely detection of threats allowing analysts to take action on time. Correlation rules are **logical expressions set to be triggered**.
Exemples:
- If a User gets 5 failed Login Attempts in 10 seconds - Raise an alert for `Multiple Failed Login Attempts`
- If login is successful after multiple failed login attempts - Raise an alert for `Successful Login After multiple Login Attempts`
- A rule is set to alert every time a user plugs in a USB (Useful if USB is restricted as per the company policy)
- If outbound traffic is > 25 MB - Raise an alert to potential Data exfiltration Attempt (Usually, it depends on the company policy)
### How it is created
#### Use case 1:
Adversaries tend to remove the logs during the post-exploitation phase to remove their tracks. A unique Event ID **104** is logged every time a user tries to remove or clear event logs. To create a rule based on this activity, we can set the condition as follows:
**Rule:** If the Log source is WinEventLog **AND** EventID is **104** - Trigger an alert `Event Log Cleared`
#### Use case 2:
Adversaries use commands like **whoami** after the exploitation/privilege escalation phase. The following Fields will be helpful to include in the rule.
- Log source: Identify the log source capturing the event logs  
- Event ID: which Event ID is associated with Process Execution activity? In this case, event id 4688 will be helpful.  
- NewProcessName: which process name will be helpful to include in the rule?
**Rule:** If Log Source is WinEventLog **AND** EventCode is **4688,** and NewProcessName contains **whoami,** then Trigger an ALERT `WHOAMI command Execution DETECTED`
## Alert Investigation
SIEM analysts spend most of their time on dashboards. Once an alert is triggered, the events/flows associated with the alert are examined, and the rule is checked to see which conditions are met.
Based on investigation the analyst determines if it's a True or False positive.
After the analysis:
- Alert is False Alarm. It may require tuning the rule to avoid similar False positives from occurring again.  
- Alert is True Positive. Perform further investigation.  
- Contact the asset owner to inquire about the activity.
- Suspicious activity is confirmed. Isolate the infected host.
- Block the suspicious IP.
