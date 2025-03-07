## 1. Introduction to Host Identification
### Importance in Network Forensics

- Critical for investigating compromises
- Essential for tracking malicious activities
- Helps establish network context
### Challenges

- Enterprise naming conventions
    - Pros: Predictable patterns
    - Cons: Potential for adversary exploitation
## 2. Key Identification Protocols
### 2.1 Dynamic Host Configuration Protocol (DHCP)
#### DHCP Analysis Fundamentals

- Automatic IP address assignment
- Manages network communication parameters
#### Wireshark DHCP Filters

```
# Global DHCP search
dhcp or bootp

# Packet Type Filters
# Request Packet
dhcp.option.dhcp == 3

# Acknowledgment Packet
dhcp.option.dhcp == 5

# Negative Acknowledgment Packet
dhcp.option.dhcp == 6

# See requested ip
dhcp.option.requested_ip_address==<IP>
```
#### Key DHCP Options to Investigate

```
# Hostname Identification
Option 12: Hostname
dhcp.option.hostname contains "keyword"

# IP Address Tracking
Option 50: Requested IP address
Option 61: Client MAC address

# Lease Information
Option 51: IP lease time
```
### 2.2 NetBIOS (NBNS) Analysis
#### NetBIOS Purpose

- Enables inter-host application communication
#### Wireshark NetBIOS Filters

```
# Global NetBIOS search
nbns

# Name-based Queries
nbns.name contains "keyword"

# Registration requests
nbns.flags.opcode == 5
```
### 2.3 Kerberos Analysis
#### Kerberos Fundamentals

- Default authentication for Windows domains
- Secure identity verification
#### Wireshark Kerberos Filters

```
# Global Kerberos search
kerberos

# User Account Identification
# User names (excluding hostnames)
kerberos.CNameString contains "keyword" 
kerberos.CNameString and !(kerberos.CNameString contains "$")

# Advanced Kerberos Filters
# Protocol version
kerberos.pvno == 5

# Domain realm
kerberos.realm contains ".org"

# Service name
kerberos.SNameString == "krbtg"
```
## 3. Advanced Host Identification Strategies
### 3.1 Comprehensive Investigation Approach

1. Cross-reference multiple protocols
2. Analyze naming patterns
3. Track MAC-to-IP-to-Hostname relationships
4. Investigate authentication traces
### 3.2 Red Flags in Host Identification

- Inconsistent hostname patterns
- Unexpected authentication requests
- Unusual DHCP lease behaviors
- Suspicious NetBIOS queries
## 4. Practical Investigation Workflow
### Steps for Host Identification

1. Capture network traffic
2. Apply protocol-specific filters
3. Extract hostname and user information
4. Correlate across different protocol layers
5. Document findings systematically
## 5. Mitigation and Best Practices
### Prevention Strategies

- Implement strict naming conventions
- Use randomized hostname generation
- Monitor for unauthorized device registrations
- Implement network segmentation
### Detection Techniques

- Regular network inventory audits
- Automated host tracking
- Anomaly detection systems
- Continuous log analysis
## 6. Tools and Resources
### Recommended Tools

- Wireshark
- Network monitoring solutions
- SIEM (Security Information and Event Management)
- Endpoint detection systems
