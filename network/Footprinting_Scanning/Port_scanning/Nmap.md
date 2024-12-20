# Skip_Host_discovery
It can be important sometimes to skip host discovery check, because host can bloc request on certain port that we use for that and not for others.
To skip this host discovery we can use the `-Pn` option:
```bash
$> nmap -Pn 172.25.227.5
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 10:47 CEST
Nmap scan report for 172.25.227.5
Host is up (0.0000080s latency).
Not shown: 996 closed tcp ports (reset)
PORT     STATE    SERVICE
3000/tcp filtered ppp
3001/tcp filtered nessus
5432/tcp filtered postgresql
8888/tcp filtered sun-answerbook

Nmap done: 1 IP address (1 host up) scanned in 1.43 seconds
```

Notice that **if you use sudo privilege, Nmap will do a Syn scan, else it will do a TCP scan.**
The difference is that as root the Three-Way handshake will not finish.
# UDP_Scan
```bash
$ nmap -Pn -T5 -sU -p53,137,138,139 172.25.227.5
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 11:17 CEST
Nmap scan report for 172.25.227.5
Host is up (0.00041s latency).

PORT    STATE  SERVICE
53/udp  closed domain
137/udp closed netbios-ns
138/udp closed netbios-dgm
139/udp closed netbios-ssn

Nmap done: 1 IP address (1 host up) scanned in 0.30 seconds
```
# Choose_Ports
## 100_most_common
By default in a nmap scan, it scan the 1000 most popular port.
If you want to decrease it to 100 you can use the `-F` option.
```bash
$> sudo nmap -Pn -F 172.25.227.5
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 10:56 CEST
Nmap scan report for 172.25.227.5
Host is up (0.000017s latency).
Not shown: 97 closed tcp ports (reset)
PORT     STATE    SERVICE
3000/tcp filtered ppp
5432/tcp filtered postgresql
8888/tcp filtered sun-answerbook

Nmap done: 1 IP address (1 host up) scanned in 1.35 seconds
```
## Select_port
You can select the port that you want to scan by use the `-p` option
```bash
$> sudo nmap -Pn -p 80 172.25.227.5
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 10:59 CEST
Nmap scan report for 172.25.227.5
Host is up (0.00016s latency).

PORT   STATE  SERVICE
80/tcp closed http

Nmap done: 1 IP address (1 host up) scanned in 0.18 seconds
```
You can use those format:
- `-p1-8080`
- `-p3389` (rdp)
- `-p80,8080,3000` (better in a large network scan)
- `-p-` (Scan the entire TCP port)

# Detect_Service_Version

```shell
$ sudo nmap -Pn -sV 127.0.0.1 

Starting Nmap 7.60 ( https://nmap.org ) at 2021-09-10 05:03 BST
Nmap scan report for MACHINE_IP Host is up (0.0040s latency). 
Not shown: 995 closed ports 
PORT    STATE SERVICE VERSION 
22/tcp  open  ssh OpenSSH 6.7p1 Debian 5+deb8u8 (protocol 2.0) 
25/tcp  open  smtp Postfix smtpd 
80/tcp  open  http nginx 1.6.2 
110/tcp open  pop3 Dovecot pop3d 
111/tcp open  rpcbind 2-4 (RPC #100000) 
MAC Address: 02:A0:E7:B5:B6:C5 (Unknown) 
Service Info: Host: debra2.thm.local; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ . 
Nmap done: 1 IP address (1 host up) scanned in 8.40 seconds
```
You can use `--version-intensity <0-8>` to make an agressive service version detection.
# Detect_OS
Use the -O to ask nmap to guess the OS.
```bash
$> nmap -sS -sV -O -p- -T5 192.17.166.3
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 15:02 IST                                                    
Nmap scan report for demo.ine.local (192.17.166.3)   
Host is up (0.000074s latency).                   
Not shown: 65532 closed tcp ports (reset)                                      
PORT      STATE SERVICE VERSION                            
6421/tcp  open  mongodb MongoDB 2.6.10                                      
41288/tcp open  achat   AChat chat system                               
55413/tcp open  ftp     vsftpd 3.0.3                            
MAC Address: 02:42:C0:11:A6:03 (Unknown)                                 
Aggressive OS guesses: Linux 2.6.32 (96%), Linux 3.2 - 4.9 (96%), Linux 4.15 - 5.8 (96%), Linux 2.6.32 - 3.10 (96%), Linux 5.0 - 5.5 (96%), Linux 3.4 - 3.10 (95%), Linux 3.1 (95%), Linux 3.2 (95%), AXIS 210A or 211 Network Camera (Linux 2.6.17) (95%), Linux 2.6.32 - 2.6.35 (94%)                                                                                                      
No exact OS matches for host (test conditions non-ideal).                                   
Network Distance: 1 hop            
Service Info: OS: Unix                                                                                          
OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .                                                      
Nmap done: 1 IP address (1 host up) scanned in 16.56 seconds  
```
You can use `--osscan-guess` to make an agressive os detection.
# Script_Engine
## List all script
```bash
$> ls -al /usr/share/nmap/scripts/
```

Find particular script:
```bash
$> ls -al /usr/share/nmap/scripts/ | grep -e "http"
...
-rw-r--r-- 1 root root 20667 Jun 20 23:57 http-enum.nse
...
```
## Get info of a script
```bash
$> nmap --script-help=<SCRIPT_NAME>
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 11:53 CEST

mongodb-databases
Categories: default discovery safe
https://nmap.org/nsedoc/scripts/mongodb-databases.html
  Attempts to get a list of tables from a MongoDB database.

```
## Use script
### Default
```bash
$> nmap -sS -sV -sC -O -p- -T5 192.17.166.3
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 15:18 IST
Nmap scan report for demo.ine.local (192.17.166.3)
Host is up (0.000076s latency).
Not shown: 65532 closed tcp ports (reset)
PORT      STATE SERVICE VERSION
6421/tcp  open  mongodb MongoDB 2.6.10 2.6.10
| mongodb-info: 
|   MongoDB Build info
|     versionArray
|       0 = 2
|       1 = 6
|       2 = 10
|       3 = 0
|     loaderFlags = -fPIC -pthread -Wl,-z,now -rdynamic
|     sysInfo = Linux lgw01-12 3.19.0-25-generic #26~14.04.1-Ubuntu SMP Fri Jul 24 21:16:20 UTC 2015 x86_64 BOOST_LIB_VERSION=1_58
|     compilerFlags = -Wnon-virtual-dtor -Woverloaded-virtual -fPIC -fno-strict-aliasing -ggdb -pthread -Wall -Wsign-compare -Wno-unused-function -Wno-unused-variable -Wno-maybe-uninitialized -Wno-unknown-pragmas -Winvalid-pch -pipe -Werror -O3 -Wno-unused-local-typedefs -Wno-unused-function -Wno-deprecated-declarations -fno-builtin-memcmp
|     OpenSSLVersion = OpenSSL 1.0.2g  1 Mar 2016
...
| mongodb-databases: 
|   totalSize = 83886080.0
|   ok = 1.0
|   databases
|     0
|       empty = false
|       sizeOnDisk = 83886080.0
|       name = local
|     1
|       empty = true
|       sizeOnDisk = 1.0
|_      name = admin
41288/tcp open  achat   AChat chat system
55413/tcp open  ftp     vsftpd 3.0.3
MAC Address: 02:42:C0:11:A6:03 (Unknown)
Aggressive OS guesses: Linux 2.6.32 (96%), Linux 3.2 - 4.9 (96%), Linux 4.15 - 5.8 (96%), Linux 2.6.32 - 3.10 (96%), Linux 5.0 - 5.5 (96%), Linux 3.4 - 3.10 (95%), Synology DiskStation Manager 5.2-5644 (95%), Linux 3.1 (95%), Linux 3.2 (95%), AXIS 210A or 211 Network Camera (Linux 2.6.17) (95%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 1 hop
Service Info: OS: Unix

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 20.02 seconds
```
This scan reveal that the target is running on Ubuntu.
### Select script
If you want to run a particular script, use the `--script=<SCRIPT_NAME>` option.
```bash
$> sudo nmap -sS -sV --script=http-git -O -p- -T5 172.25.227.5
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-07 11:56 CEST
Nmap scan report for 172.25.227.5
Host is up (0.000071s latency).
Not shown: 65530 closed tcp ports (reset)
PORT     STATE    SERVICE        VERSION
3000/tcp filtered ppp
3001/tcp filtered nessus
3002/tcp filtered exlm-agent
5432/tcp filtered postgresql
8888/tcp filtered sun-answerbook
Too many fingerprints match this host to give specific OS details
Network Distance: 0 hops

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 4.34 seconds

```
### Select mulitple script
`--script=ftp-*`, will run all script start with "ftp-"
`--script=http-enum,mongodb-databases`, will run the 2 scripts
# Fragmentation
The `-f` option allow fragmentation of packet, 
after you can specify the minimum size of packet with the `-mtu`
And you can specify the max size of packet with the `--data-length` option
```bash
$> nmap -sA -Pn -sV -p445,135,3389 -f -mtu 8 10.2.21.87                                                                                                 
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-14 14:30 IST
Nmap scan report for demo.ine.local (10.2.21.87)
Host is up (0.0028s latency).

PORT     STATE      SERVICE       VERSION
135/tcp  unfiltered msrpc
445/tcp  unfiltered microsoft-ds
3389/tcp unfiltered ms-wbt-server

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 0.26 seconds
```
# Spoofing
Use the `-D` option to specified the decoy IP (ip that you want to usurp).
```bash
$> nmap -sA -Pn -sV -p445,135,3389 -D <USURPED_IP> <DEST>
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-14 14:37 IST
Nmap scan report for demo.ine.local (10.2.21.87)
Host is up (0.0031s latency).

PORT     STATE      SERVICE       VERSION
135/tcp  unfiltered msrpc
445/tcp  unfiltered microsoft-ds
3389/tcp unfiltered ms-wbt-server

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 0.28 seconds
```

You can use the `-g` option to specified the port where the packet are from.
# Optimize
You can use the `--host-timeout` option to specified the time to wait before switch to another host.
```bash
$> nmap -sA -Pn -sV -p445,135,3389 --host-timeout 5s;2m;2h 10.2.21.0/24                                                            
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-14 14:50 IST
Nmap scan report for demo.ine.local (10.2.21.87)
Host is up (0.0027s latency).

PORT     STATE      SERVICE       VERSION
135/tcp  unfiltered msrpc
445/tcp  unfiltered microsoft-ds
3389/tcp unfiltered ms-wbt-server

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 0.26 seconds
```
# Output
Nmap can be used to export the result to analyse it.
## Normal
```bash
$> nmap -Pn -sS -F 8 10.2.21.87 -oN nmap_normal.txt                                                                                                 
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-14 14:30 IST
Nmap scan report for demo.ine.local (10.2.21.87)
Host is up (0.0028s latency).

PORT     STATE      SERVICE       VERSION
135/tcp  unfiltered msrpc
445/tcp  unfiltered microsoft-ds
3389/tcp unfiltered ms-wbt-server

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 0.26 seconds
```
## XML
```bash
$> nmap -Pn -sS -F 8 10.2.21.87 -oX nmap_xml.xml                                                                                                 
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-10-14 14:30 IST
Nmap scan report for demo.ine.local (10.2.21.87)
Host is up (0.0028s latency).

PORT     STATE      SERVICE       VERSION
135/tcp  unfiltered msrpc
445/tcp  unfiltered microsoft-ds
3389/tcp unfiltered ms-wbt-server

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 0.26 seconds
```
