# ARP scan
Nmap can be used too to discover live host with mulitple request `-sn`.
```bash
$> nmap -sn 172.25.227.0/20
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 09:43 CEST
Nmap scan report for LAPTOP-DIIMKCVU.mshome.net (172.25.224.1)
Host is up (0.00036s latency).
MAC Address: 00:15:5D:69:16:D2 (Microsoft)
Nmap scan report for 172.25.227.5
Host is up.
Nmap done: 4096 IP addresses (2 hosts up) scanned in 9.67 seconds
```
# Syn packet
You can choose the type of packet that nmap will use by specified the `-PS` option for **SYN** packets
```bash
$> nmap -sn -PS 172.25.227.0/20
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 10:05 CEST
Nmap scan report for LAPTOP-DKUMKCVU.mshome.net (172.25.224.1)
Host is up (0.00042s latency).
MAC Address: 00:15:5D:69:16:D2 (Microsoft)
Nmap scan report for 172.25.227.5
Host is up.
Nmap done: 4096 IP addresses (2 hosts up) scanned in 9.56 seconds
```
You can specified the port following the `-PS<PORT>`
exemple:
- `-PS1-8080`
- `-PS3389` (rdp)
- `-PS80,8080,3000` (better in a large network scan)
## Port scan
You can use this technique to do a port scan:
```bash
$ nmap -PS1-8080 172.25.227.5
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 10:11 CEST
Nmap scan report for 172.25.227.5
Host is up (0.000014s latency).
Not shown: 996 closed tcp ports (reset)
PORT     STATE    SERVICE
3000/tcp filtered ppp
3001/tcp filtered nessus
5432/tcp filtered postgresql
8888/tcp filtered sun-answerbook

Nmap done: 1 IP address (1 host up) scanned in 1.41 seconds
```
# Specified our target
You can do the nmap discover on a range of ips
```bash
$> nmap -sn 172.25.220-230.0-10
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 09:43 CEST
Nmap scan report for LAPTOP-DIIMKCVU.mshome.net (172.25.224.1)
Host is up (0.00036s latency).
MAC Address: 00:15:5D:69:16:D2 (Microsoft)
Nmap scan report for 172.25.227.5
Host is up.
Nmap done: 4096 IP addresses (2 hosts up) scanned in 9.67 seconds
```
On a list of ips:
Create a new file:
```txt
172.25.227.5
172.25.224.1
```
Request with this file as option.
```bash
$> nmap -sn -iL target.txt 
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 09:43 CEST
Nmap scan report for LAPTOP-DIIMKCVU.mshome.net (172.25.224.1)
Host is up (0.00036s latency).
MAC Address: 00:15:5D:69:16:D2 (Microsoft)
Nmap scan report for 172.25.227.5
Host is up.
Nmap done: 4096 IP addresses (2 hosts up) scanned in 9.67 seconds
```

