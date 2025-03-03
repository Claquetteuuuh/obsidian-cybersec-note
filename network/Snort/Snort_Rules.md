![[Pasted image 20250302182206.png]]
There are 3 mains rules in sort:
- **General Rule Options** - Fundamental rule options for Snort. 
- **Payload Rule Options** - Rule options that help to investigate the payload data. These options are helpful to **detect specific payload patterns**.
- **Non-Payload Rule Options** - Rule options that focus on **non-payload data**. These options will help create specific patterns and identify network issues.
# IP and Port Filtering
- **Specific IP**: Triggers an alert for any ICMP packet from a specific IP.
```
 alert icmp 192.168.1.56 any <> any any (msg: "ICMP Packet From "; sid: 100001; rev:1;)
```   
- **IP Range**: Monitors an entire subnet.
```
alert icmp 192.168.1.0/24 any <> any any (msg: "ICMP Packet Found"; sid: 100001; rev:1;)
```   
- **Exclude IP**: Uses `!` to exclude a specific range.
```
alert icmp !192.168.1.0/24 any <> any any (msg: "ICMP Packet Found"; sid: 100001; rev:1;)
```
- **Specific Ports**: Triggers an alert for a particular port.  
```
alert tcp any any <> any 21 (msg: "FTP Activity Detected"; sid: 100001; rev:1;)
```   
- **Exclude a Port**: Monitors everything except a specific port.
```
alert tcp any any <> any !21 (msg: "Traffic Without FTP"; sid: 100001; rev:1;)
```   
- **Port Ranges**: Filters based on different methods (`1:1024`, `:1024`, `1025:`…).
```
alert tcp any any <> any 1:1024 (msg: "System Port Activity"; sid: 100001; rev:1;)
```   
# Packet Direction
- `<` : Unidirectional (source → destination).
- `>` : Reverse (destination → source).
- `<>` : Bidirectional (can go both ways).
# General Rule Options
- **`msg`**: Message displayed when the rule is triggered.
- **`sid`**: Unique identifier for the rule (>100,000,000 for custom rules).
- **`reference`**: Associates a rule with an external reference (e.g., CVE).
- **`rev`**: Revision number to track updates.
Example:
```
alert icmp any any <> any any (msg: "ICMP Packet Found"; sid: 100001; reference:cve,CVE-XXXX; rev:1;)
```
# Payload Detection
- **`content:"pattern"`**: Searches for a specific pattern (e.g., `GET` in HTTP).
```
alert tcp any any <> any 80 (msg: "GET Request Found"; content:"GET"; sid: 100001; rev:1;)
```
- **`nocase`**: Disables case sensitivity.
- **`fast_pattern`**: Optimizes search by prioritizing a key pattern.
```
alert tcp any any <> any 80 (msg: "GET Request Found"; content:"GET"; fast_pattern; content:"www"; sid:100001; rev:1;)
```
# Non-Payload Detection
- **`id`**: Filters based on the IP ID field.
```
alert ip any any <> any any (msg: "Specific IP ID Detected"; id:12345; sid: 100001; rev:1;)
```
- **`flags`**: Monitors TCP flags (`SYN`, `ACK`, etc.).
```
alert tcp any any <> any any (msg: "FLAG TEST"; flags:S; sid: 100001; rev:1;)
```
- **`dsize`**: Detects packets of specific sizes.
```
alert ip any any <> any any (msg: "SEQ TEST"; dsize:100<>300; sid:100001; rev:1;)
```
- **`sameip`**: Checks if the source and destination IP are the same.
6736