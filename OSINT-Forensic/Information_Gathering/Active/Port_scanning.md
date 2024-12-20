# All_in_one

```js
$ sudo nmap -Pn -A 127.0.0.1
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-09-29 15:59 CEST
Nmap scan report for localhost (127.0.0.1)
Host is up (0.000057s latency).
Not shown: 999 closed tcp ports (reset)
PORT     STATE SERVICE VERSION
8000/tcp open  http    SimpleHTTPServer 0.6 (Python 3.12.6)
|_http-server-header: SimpleHTTP/0.6 Python/3.12.6
|_http-title: Directory listing for /
Device type: general purpose
Running: Linux 2.6.X
OS CPE: cpe:/o:linux:linux_kernel:2.6.32
OS details: Linux 2.6.32
Network Distance: 0 hops

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 8.21 seconds

```
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

# OS
```shell
$ sudo nmap -sS -O 127.0.0.1 

Starting Nmap 7.60 ( https://nmap.org ) at 2021-09-10 05:04 BST 
Nmap scan report for MACHINE_IP Host is up (0.00099s latency). 
Not shown: 994 closed ports
PORT    STATE SERVICE 
22/tcp  open  ssh
25/tcp  open  smtp 
80/tcp  open  http 
110/tcp open  pop3 
111/tcp open  rpcbind 
143/tcp open  imap
MAC Address: 02:A0:E7:B5:B6:C5 (Unknown)
Device type: general purpose 
Running: Linux 3.X 
OS CPE: cpe:/o:linux:linux_kernel:3.13 
OS details: Linux 3.13 
Network Distance: 1 hop 

OS detection performed. Please report any incorrect results at https://nmap.org/submit/ . 
Nmap done: 1 IP address (1 host up) scanned in 3.91 seconds
```

# Default_script

```shell
$ nmap -sV -sC 127.0.0.1
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-09-29 15:57 CEST
Nmap scan report for localhost (127.0.0.1)
Host is up (0.000012s latency).
Not shown: 999 closed tcp ports (reset)
PORT     STATE SERVICE VERSION
8000/tcp open  http    SimpleHTTPServer 0.6 (Python 3.12.6)
|_http-title: Directory listing for /
|_http-server-header: SimpleHTTP/0.6 Python/3.12.6

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 6.88 seconds

```

# Time/Speed_Of_Scan
```js
$ nmap -Pn -T4 # 1=>5
```
# Export_In_File
Normal export: `-oN <file>`
Xml export: `-oX <file>`
