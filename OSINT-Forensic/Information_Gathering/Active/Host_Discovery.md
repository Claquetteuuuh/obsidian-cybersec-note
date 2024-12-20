# Nmap
Used here to find the host up
```js
$ sudo nmap -sn 172.25.237.5/20 # network address
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-09-28 10:07 CEST
Nmap scan report for LAPTOP-DKUMKCVU.mshome.net (172.25.224.1)
Host is up (0.00059s latency).
MAC Address: 00:15:5D:B0:BF:FE (Microsoft)
Nmap scan report for 172.25.227.5
Host is up.
Nmap done: 4096 IP addresses (2 hosts up) scanned in 9.90 seconds
```

# Netdiscover - Tool
Same has nmap, discover active directory in a range (network)
```js
$ sudo netdiscover -i eth0 -r 172.25.237.5/16
 Currently scanning: Finished!   |   Screen View: Unique Hosts

 1 Captured ARP Req/Rep packets, from 1 hosts.   Total size: 42
 _____________________________________________________________________________
   IP            At MAC Address     Count     Len  MAC Vendor / Hostname
 -----------------------------------------------------------------------------
 172.25.224.1    00:15:5d:b0:bf:fe      1      42  Microsoft Corporation
```