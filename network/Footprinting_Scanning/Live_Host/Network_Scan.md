# Objectives
- Discovery of live hosts
- Identification of Open Ports and Services. It help to understand the attack surface and potential vulnerabilities.
- Network Topology Mapping: Creating a map or diagram of the network topology, including routers, switches, firewalls, and other network infrastructure elements.
- Operating System Fingerprinting: Determining the operating systems running on discovered hosts.
- Service Version Detection: Identifying specific versions of services running on open ports. This information is crucial for pinpointing vulnerabilities associated with particular service versions.
- Identifying Filtering and Security Measures: Discovering firewalls, intrusion prevention systems, and other security measures in place.
# Ping_Sweeps
## Definition
Network scanning technique, used to discover live hosts by ICMP request.
```bash
$> ping -c 5 1.1.1.1
PING 1.1.1.1 (1.1.1.1) 56(84) bytes of data.
64 bytes from 1.1.1.1: icmp_seq=1 ttl=51 time=258 ms
64 bytes from 1.1.1.1: icmp_seq=2 ttl=51 time=24.5 ms
64 bytes from 1.1.1.1: icmp_seq=3 ttl=51 time=21.3 ms
64 bytes from 1.1.1.1: icmp_seq=4 ttl=51 time=19.7 ms
64 bytes from 1.1.1.1: icmp_seq=5 ttl=51 time=46.5 ms

--- 1.1.1.1 ping statistics ---
5 packets transmitted, 5 received, 0% packet loss, time 4005ms
rtt min/avg/max/mdev = 19.742/74.040/258.168/92.568 ms
```

Use `-c` on linux and `-n` on windows to limite the number of packets sended.
Type field:
- The purpose or function of the ICMP message
Code field:
- Provides additional information or context related to the message type
![[Pasted image 20241004171118.png]]
## Request
ICMP Echo request:
- Type: 8
- Code: 0
## Response
ICMP Echo reply:
- Type: 0
- Code: 0
If we have no response it can mean that the host is offline but it can also mean that:
- there is congestion
- the host is temporary unavailable
- there is firewall setting that block our request
## Broadcast
The `-b` option permit to send a ping request to all the machine of the network
```bash
$> ping -b -c 1 172.25.239.255
WARNING: pinging broadcast address
PING 172.25.239.255 (172.25.239.255) 56(84) bytes of data.

--- 172.25.239.255 ping statistics ---
1 packets transmitted, 0 received, 100% packet loss, time 0ms
```
## Fping - tool
Fping is a tool that is used to perform ping to network.
```bash
$> fping -a -g 172.25.227.5/20
...
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.85
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.85
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.92
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.91
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.90
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.89
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.89
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.89
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.89
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.95
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.94
ICMP Host Unreachable from 172.25.227.5 for ICMP Echo sent to 172.25.227.93
...
```

