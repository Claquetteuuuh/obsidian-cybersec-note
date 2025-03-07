## 1. Understanding ARP Protocol
### Key Characteristics

- Local network communication protocol
- Translates IP addresses to MAC addresses
- Lacks built-in security mechanisms
- Not routable
- No authentication
## 2. ARP Packet Types
### Normal ARP Communication

- Request (Broadcast): Asking for MAC address of an IP
- Response: Providing MAC address for a specific IP
- Announcement: Declaring IP-MAC binding
- Gratuitous ARP: Unsolicited address announcement
## 3. Wireshark ARP Filters
### Basic ARP Filters

```
# Show all ARP packets
arp

# ARP Requests
arp.opcode == 1

# ARP Responses
arp.opcode == 2

# Detect Potential ARP Scanning
arp.dst.hw_mac == 00:00:00:00:00:00

# Duplicate Address Detection
arp.duplicate-address-detected or arp.duplicate-address-frame

# Detect packet from Mac address
eth.src == 00:00:00:00:00:00
```
## 4. Red Flags for ARP Poisoning
### Suspicious Patterns

1. Multiple MAC addresses claiming same IP
2. Unexpected ARP responses
3. Rapid ARP request/response cycles
4. MAC addresses with unusual behavior
5. Gratuitous ARP announcements without clear reason
### Detection Strategies

- Track IP-MAC address bindings
- Monitor ARP packet frequency
- Identify conflicting MAC-IP mappings
- Analyze expert information warnings
## 5. Man-in-the-Middle (MITM) Detection Indicators
### Network Behavior Anomalies

- Unexpected traffic redirection
- MAC address manipulations
- Suspicious ARP request patterns
- Multiple claims on gateway IP
### Investigation Workflow

1. Identify conflicting ARP entries
2. Analyze MAC address behaviors
3. Correlate ARP activities with network traffic
4. Examine traffic flow patterns
## 6. Advanced Detection Techniques
### Wireshark Analysis Approach

```
# Complex ARP poisoning detection filter
((arp) && (arp.opcode == 1)) && (arp.src.hw_mac == target-mac-address)
```
### Key Investigation Steps

1. Add MAC address columns in packet list
2. Trace IP-MAC address mappings
3. Look for unusual traffic patterns
4. Correlate ARP activities across time frames
## 7. Potential Attack Scenarios
### Common ARP Poisoning Techniques

- Gateway IP address spoofing
- Multiple IP claim attempts
- Traffic interception
- Network communication manipulation
## 8. Mitigation Strategies
### Prevention Techniques

1. Use static ARP entries
2. Implement ARP spoofing detection tools
3. Configure network switches with port security
4. Use encrypted communication protocols
5. Implement network segmentation
### Detection Tools

- Wireshark
- Arpwatch
- Network monitoring solutions
- Intrusion detection systems (IDS)
## 9. Analyst Mindset and Approach
### Investigation Principles

- Maintain detailed documentation
- Correlate multiple evidence sources
- Look beyond individual packet anomalies
- Understand network topology
- Recognize contextual network behaviors
### Documentation Template

```
Detection Notes:
- IP-MAC Matches
- Suspicious MAC Addresses
- Traffic Redirection Patterns
- Potential Attack Vectors
```
## 10. Conclusion

ARP poisoning detection requires:

- Deep protocol understanding
- Analytical skills
- Technical toolset
- Contextual network knowledge
### Key Takeaways

- ARP protocol is inherently insecure
- Constant vigilance is crucial
- Multiple detection methods enhance security
- Technical skills and analytical thinking are paramount
