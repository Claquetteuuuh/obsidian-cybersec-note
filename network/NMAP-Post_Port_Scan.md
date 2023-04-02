
## __Version__

Pour détecter les versions des services qui tourne sur le port, on peut utiliser l’option **`-sV`**. La commande sera donc la suivante **`nmap -sV <cible>`**.

```shell
pentester@ip$ sudo nmap -sV MACHINE_IP 

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


## __OS__

Pour détecter le systeme d'exploitation de la machine ciblé, on utilise l’option **`-O`**. La commande sera donc la suivante **`nmap -sV -O <cible>`**.

```shell
pentester@ip$ sudo nmap -sS -O MACHINE_IP 

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


## __Traceroute__

Un traceroute permet de lister tout les routeurs par lequel est passé notre paquet entre notre machine et la machine cible. La commande est **`nmap -sS --traceroute <cible>`**.

```shell
pentester@ip$ sudo nmap -sS --traceroute MACHINE_IP 

Starting Nmap 7.60 ( https://nmap.org ) at 2021-09-10 05:05 BST
Nmap scan report for MACHINE_IP Host is up (0.0015s latency).
Not shown: 994 closed ports 
PORT    STATE SERVICE
22/tcp  open  ssh 
25/tcp  open  smtp 
80/tcp  open  http 
110/tcp open  pop3 
111/tcp open  rpcbind 
143/tcp open  imap 
MAC Address: 02:A0:E7:B5:B6:C5 (Unknown) 
TRACEROUTE HOP RTT ADDRESS 1 1.48 ms MACHINE_IP

Nmap done: 1 IP address (1 host up) scanned in 1.59 seconds
```


## __Scripts__

Nmap offre a disposition des scripts. On peut trouver la liste de ces scripts dans **/usr/share/nmap/scripts**.

```shell
pentester@ip /usr/share/nmap/scripts$ ls http* 
http-adobe-coldfusion-apsa1301.nse http-passwd.nse 
http-affiliate-id.nse              http-php-version.nse 
http-apache-negotiation.nse        http-phpmyadmin-dir-traversal.nse 
http-apache-server-status.nse      http-phpself-xss.nse 
http-aspnet-debug.nse              http-proxy-brute.nse 
http-auth-finder.nse               http-put.nse 
http-auth.nse                      http-qnap-nas-info.nse
http-avaya-ipoffice-users.nse      http-referer-checker.nse 
http-awstatstotals-exec.nse        http-rfi-spider.nse
http-axis2-dir-traversal.nse       http-robots.txt.nse
http-backup-finder.nse             http-robtex-reverse-ip.nse 
http-barracuda-dir-traversal.nse   http-robtex-shared-ns.nse 
http-brute.nse                     http-security-headers.nse 
http-cakephp-version.nse           http-server-header.nse http-chrono.nse 
http-shellshock.nse                http-cisco-anyconnect.nse 
http-sitemap-generator.nse         http-coldfusion-subzero.nse
http-slowloris-check.nse           http-comments-displayer.nse
http-slowloris.nse                 http-config-backup.nse
http-sql-injection.nse             http-cookie-flags.nse
http-stored-xss.nse                http-cors.nse 
http-svn-enum.nse                  http-cross-domain-policy.nse 
http-svn-info.nse                  http-csrf.nse 
http-title.nse                     http-date.nse 
http-tplink-dir-traversal.nse      http-default-accounts.nse
http-trace.nse                     http-devframework.nse 
http-traceroute.nse                http-dlink-backdoor.nse
http-unsafe-output-escaping.nse    http-dombased-xss.nse 
http-useragent-tester.nse          http-domino-enum-passwords.nse 
http-userdir-enum.nse              http-drupal-enum-users.nse 
http-vhosts.nse                    http-drupal-enum.nse 
http-virustotal.nse                http-enum.nse 
http-vlcstreamer-ls.nse            http-errors.nse 
```

| **Script Category** | **Description**                                                            |
| --------------- | ---------------------------------------------------------------------- |
| `auth`          | Authentication related scripts                                         |
| `broadcast`     | Discover hosts by sending broadcast messages                           |
| `brute`           | Performs brute-force password auditing against logins                  |
| `default`       | Default scripts, same as `-sC`                                         |
| `discovery`     | Retrieve accessible information, such as database tables and DNS names |
| `dos`             | Detects servers vulnerable to Denial of Service (DoS)                  |
| `exploit`       | Attempts to exploit various vulnerable services                        |
| `external`        | Checks using a third-party service, such as Geoplugin and Virustotal   |
| `fuzzer`          | Launch fuzzing attacks                                                 |
| `intrusive`       | Intrusive scripts such as brute-force attacks and exploitation         |
| `malware`         | Scans for backdoors                                                    |
| `safe`            | Safe scripts that won’t crash the target                               |
| `version`       | Retrieve service versions                                              |
| `vuln`            | Checks for vulnerabilities or exploit vulnerable services              |


| **Option**                      | **Meaning**                                         |
| --------------------------- | ----------------------------------------------- |
| `-sV`                       | determine service/version info on open ports    |
| `-sV --version-light`       | try the most likely probes (2)                  |
| `-sV --version-all`         | try all available probes (9)                    |
| `-O`                        | detect OS                                       |
| `--traceroute`              | run traceroute to target                        |
| `--script=SCRIPTS`          | Nmap scripts to run                             |
| `-sC` or `--script=default` | run default scripts                             |
| `-A`                        | equivalent to `-sV -O -sC --traceroute`         |
| `-oN`                       | save output in normal format                    |
| `-oG`                       | save output in grepable format                  |
| `-oX`                       | save output in XML format                       |
| `-oA`                       | save output in normal, XML and Grepable formats |

