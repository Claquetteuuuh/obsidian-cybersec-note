Wazuh is an open-source, freely available, and extensive EDR solution, which Security Engineers can deploy in all scales of environments.

As mentioned, Wazuh is an EDR. 
**Endpoint detection and response (EDR)** are tools and applications that **monitor devices** for an activity that could indicate a **threat or security breach**. These tools and applications have features that include:  
- **Auditing** a device for common vulnerabilities
- **Proactively monitoring** a device for suspicious activity such as unauthorized logins, brute-force attacks, or privilege escalations.
- **Visualizing complex data and events** into neat and trendy graphs
- **Recording** a device's normal operating behaviour to help with detecting anomalies

![[6c2d68f59482de413940f2d11913fae1.gif]]
# Agents
The devices that record the events and processes of a system are called agents. It monitor the event that take place on the device, such as authentification and user management.
Agents need to be installed into devices to log such events.
Wazuh can guide you through the deployment, some pre-requisites are:
- Operating system
- The address of the Wazuh server that the agent should send logs to (this can be a DNS entry or an IP address)
- What group the agent will be under - you can sort agents into groups within Wazuh if you wish

This wizard can be launched by clicking in: **Wazuh -> Agents -> Deploy New Agent**
![[Pasted image 20250324145432.png]]
Then in stage 4, you are given a command to copy and paste which will install & configure the agent on the device that you wish to collect logs from.
![[Pasted image 20250324145529.png]]
# Vulnerability assessment & security events
This is a powerful tool that can be used to periodically scan an agent's operating system for installed applications and their version number.
![[3a195f897882eee1b3151a3b5b167054.gif]]
# Policy Auditing
Wazuh is capable of auditing and monitoring an agent's configuration. When the Wazuh agent is installed, an audit is performed where a metric is given using multiple frameworks and legislations such as NIST, MITRE and GDPR.

![[Pasted image 20250324150129.png]]

![[Pasted image 20250324150102.png]]
# Generate report
![[Pasted image 20250324151158.png]]
![[Pasted image 20250324151205.png]]
![[Pasted image 20250324151210.png]]
![[Pasted image 20250324151220.png]]