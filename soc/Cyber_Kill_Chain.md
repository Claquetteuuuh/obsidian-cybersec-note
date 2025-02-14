# Kill Chain
![[Pasted image 20250210170347.png]]

A **Kill chain is the structure of an attack**, it include:
- Identification
- Decision
- Order to attack the target
- Target destruction

This concept was created for cybersecurity in 2011 by Lockheed Martin.

It help to understand and protect against ransomwares, security breaches as well as APT's (Advanced Persistent Threats)
## Reconnaissance
The reconnaissance is **discovering and collecting information** on the target.
OSINT also falls under reconnaissance.
For exemple you can use Email harvesting to get emails from public, paid or free services. You can use tools like:
- [The harvester](https://github.com/laramies/theHarvester)
- [Hunter.io](https://hunter.io/)
## Weaponisation
In the weaponisation phase contains:
- The creation of the **payload**
- The creation of the **way to infect** the target
- The **backdoor** implant
## Delivery
The delivery phase is when the attacker decides to choose the **method for transmitting**. It can be:
- **Phishing campain**
- Distributing **Infected USB** drive in public places.
- **Watering hole attack**, designed to aim at a specific group of people by compromising the website.
## Exploitation
It can be user to do lateral movement (move deeper into a network to obtain sensitive data). 
Exploitation can be:
- The victim triggers the exploit by opening the email attachment or clicking on a malicious link.
- Using a zero-day exploit
- Exploit software, Hardware, or event human vulnerabilities
- Exploit a server-based vulnerability
## Installation
An attacker can be removed from the system if there is a later patch or if he lose the connection for exemple. 
To stay in the system he have to install a [persistent backdoor](https://www.offsec.com/metasploit-unleashed/persistent-backdoors/) .
The persistance can be:
- Installing a webshell on the webserver.
- Installing a backdoor on the victim's machine
- Creating or modifying Windows services
- Adding the entry to the ["run keys"](https://attack.mitre.org/techniques/T1547/001/) for the malicious payload in the Registry or the Startup Folder
## Command & Control
After being installed, the attackers have to get a permanent control on the machine.
The most common C2 channels used by adversaries nowadays:
- The protocols HTTP on port 80 and HTTPS on port 443 - this type of beaconing blends the malicious traffic with the legitimate traffic and can help the attacker evade firewalls.    
- DNS (Domain Name Server). The infected machine makes constant DNS requests to the DNS server that belongs to an attacker, this type of C2 communication is also known as DNS Tunneling.
## Actions on objectives (Exfiltration)
The final goal of an kill chain is to:
- Collect the credentials from users
- Perform privilege escalation
- Internal reconnaissance
- Lateral movement through the company's environment
- Collect and exfiltrate sensitive data
- Deleting the backups and shadow copies (Microsoft technology that can create backup copies)
- Overwrite or corrupt data
	