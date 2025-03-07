# Nmap Scan Detection
## Overview of Nmap Scan Types

Nmap is a critical network scanning tool used by security professionals and potential attackers. Understanding its scan patterns is essential for network security analysis.
## 1. TCP Flags Primer
### Common TCP Flag Filters

| Flag Combination | Wireshark Filter                                                       | Explanation                |
| ---------------- | ---------------------------------------------------------------------- | -------------------------- |
| SYN Only         | `tcp.flags == 2` or `tcp.flags.syn == 1`                               | Initial connection request |
| ACK Only         | `tcp.flags == 16` or `tcp.flags.ack == 1`                              | Acknowledgment packet      |
| SYN-ACK          | `tcp.flags == 18` or `(tcp.flags.syn == 1) and (tcp.flags.ack == 1)`   | Connection acknowledgment  |
| RST Only         | `tcp.flags == 4` or `tcp.flags.reset == 1`                             | Connection reset           |
| RST-ACK          | `tcp.flags == 20` or `(tcp.flags.reset == 1) and (tcp.flags.ack == 1)` | Reset with acknowledgment  |
| FIN Only         | `tcp.flags == 1` or `tcp.flags.fin == 1`                               | Finish connection          |
## 2. TCP Connect Scan Detection
### Characteristics

- Uses full three-way handshake
- Nmap command: `nmap -sT`
- Typically used by non-privileged users
- Window size > 1024 bytes
### Wireshark Filter

```
tcp.flags.syn==1 and tcp.flags.ack==0 and tcp.window_size > 1024
```
### Scan Pattern

1. Open Port Sequence:
    - SYN -->
    - <-- SYN, ACK
    - ACK -->
2. Closed Port Sequence:
    - SYN -->
    - <-- RST, ACK
## 3. SYN Scan Detection
### Characteristics

- Incomplete three-way handshake
- Nmap command: `nmap -sS`
- Privileged users only
- Window size ≤ 1024 bytes
### Wireshark Filter

```
tcp.flags.syn==1 and tcp.flags.ack==0 and tcp.window_size <= 1024
```
### Scan Pattern
1. Open Port Sequence:
    
    - SYN -->
    - <-- SYN, ACK
    - RST -->
2. Closed Port Sequence:
    
    - SYN -->
    - <-- RST, ACK
## 4. UDP Scan Detection
### Characteristics

- No handshake process
- Nmap command: `nmap -sU`
- No direct open port indication
- ICMP error messages for closed ports
### Wireshark Filter

```
icmp.type==3 and icmp.code==3
```
### Scan Pattern

1. Open Port:
    - UDP packet sent
    - No immediate response
2. Closed Port:
    - UDP packet sent
    - ICMP Type 3, Code 3 (Destination Unreachable)
## 5. Advanced Detection Strategies
### Identifying Scan Characteristics

1. Analyze packet flags and window sizes
2. Look for repetitive connection attempts
3. Check for ICMP error messages
4. Examine packet sequences and timing
### Common Red Flags

- Rapid sequential port probes
- Unusual packet flag combinations
- Consistent window size patterns
- Repeated ICMP unreachable messages
## 6. Mitigation and Response
### Detection Techniques

- Use comprehensive Wireshark filters
- Create custom coloring rules
- Set up Wireshark profiles for scan detection
- Correlate with other network logs
### Recommended Actions

1. Log and document scan attempts
2. Block source IP if malicious intent is suspected
3. Review network security configurations
4. Investigate potential network vulnerabilities

