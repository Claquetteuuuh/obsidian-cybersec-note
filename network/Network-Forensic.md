# Use case
- **Network discovery**: Discovering the network to overview **connected devices**, **rouge hosts** and **network load**.
- **Packets reassembling**: Reassembling the packets to **investigate the traffic flow**. It is **helpful in encrypted** traffic flow
- **Data leakage detection**: **Reviewing packet transfer** rates for **each host and destination** address helps detect possible **data leakage**.
- **Anomaly and malicious activity detection**: Reviewing **overall network** load by **focusing on used ports**, **source** and **destination addresses** and data helps detect possible malicious activities.
- **Policy/Regulation compliance control**: Reviewing overall network behaviour helps **detect policy/regulation compliance**.
# Advantage
- **Availability of network-based evidence in the wild**: Capturing network traffic is **collecting evidence**, so it is easier than other types of evidence collections such as logs and IOCs.
- **Ease of data/evidence collection without creating noise**: It is easier than investigating unfiltered events by EDRs, EPPs and log systems. Usually sniffing **doesn't create** much noise, **logs and alerts**.
- **It is hard to destroy the network evidence, as it is the transferred data**: It is impossible to do anything without creating network noise. Still, it is possible to **hide the artifacts** by **encrypting**, **tunneling** and **manipulating the packets**.
- **Availability of log sources**: Logs **provide valuable information** which helps to correlate the chain of events and support the investigation hypothesis. The majority of the EDRs, EPPs and network devices **create logs by default**.
- **It is possible to gather evidence for memory and non-residential malicious activities**: The malware/threat might reside in the memory to avoid detection. However, the series of commands and connections live in the network. So it is possible to **detect non-residential threats** with network forensics tools and tactics.
# Challenges of Network Forensics
- **Deciding what to do**: One of the main challenges in network forensics is defining the investigation’s **goal** (SOC, IH/IR, Threat Hunting) and **choosing the right action** (observe, trap, stop an anomaly).
- **Data/evidence collection**: While easy to implement, it is complex due to the variety of capture points and parameters to consider.
- **Short data capture**: Continuously capturing all network activity is impractical, making it difficult to retrieve data before, during, and after an event.
- **Unavailability of full-packet capture**: Storing and processing full-packet captures is costly. NetFlow is sometimes used as an alternative to extend capture duration, but it lacks detailed payload information.
- **Encrypted traffic**: While its contents are unreadable, metadata (IP addresses, services used) can still provide valuable insights.
- **GDPR and privacy concerns**: Recording network traffic must comply with regulations (GDPR, HIPAA, PCI DSS, FISMA) to avoid privacy violations.
- **Nonstandard port usage**: Attackers may use uncommon ports to evade detection, making investigations based on standard traffic patterns more challenging.
- **Time zone issues**: Large-scale event analysis is complicated when multiple time zones are involved, hindering event correlation.
- **Lack of logs**: Network logs are crucial for investigation, but attackers often erase them to obscure their activities.
# Sources of Network Forensics Evidence
-   TAPS
- InLine Devices
- SPAN Ports
- Hubs
- Switches
- Routers
- DHCP Servers
- Name Servers
- Authentication Servers
- Firewalls
- Web Proxies
- Central Log Servers
- Logs (IDS/IPS, Application, OS, Device)
# Primary Purposes of Network Forensics
- **Security Operations (SOC):** Daily security monitoring activities on system performance and health, user behaviour, and security issues.
- **Incident Handling/Response and Threat Hunting:** During/Post-incident investigation activities on understanding the reason for the incident, detecting malicious and suspicious activity, and investigating the data flow content.