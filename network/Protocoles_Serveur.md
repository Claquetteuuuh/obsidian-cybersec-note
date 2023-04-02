
## __Telnet__

**Telnet** est un protocole de la **couche application** utilisé pour **se connecter a une autre machine**. Un serveur telnet utilise part défaut le **port 23**. On peut aussi utiliser telnet pour effectuer des requêtes sur **d’autre port** de la machine afin d’utiliser d’autres service.

```shell
pentester@ip$ telnet MACHINE_IP 
Trying MACHINE_IP...
Connected to MACHINE_IP.
Escape character is '^]'.
Ubuntu 20.04.3 LTS 
bento login: frank 
Password: D2xc9CgD 
Welcome to Ubuntu 20.04.3 LTS (GNU/Linux 5.4.0-84-generic x86_64)

	* Documentation: https://help.ubuntu.com
	* Management: https://landscape.canonical.com
	* Support: https://ubuntu.com/advantage 
	
	System information as of Fri 01 Oct 2021 12:24:56 PM UTC
	
	System load:  0.05             Processes: 243 
	Usage of /:   45.7% of 6.53GB  Users logged in: 1
	Memory usage: 15%              IPv4 address for ens33: MACHINE_IP
	Swap usage:   0% 
	
	 * Super-optimized for small spaces - read how we shrank the memory footprint of MicroK8s to make it the smallest full K8s around.
	 
	 https://ubuntu.com/blog/microk8s-memory-optimisation 
	 
0 updates can be applied immediately. 


*** System restart required *** 
Last login: Fri Oct 1 12:17:25 UTC 2021 from meiyo on pts/3 
You have mail. 
frank@bento:~$
```


## __HTTP__

**HTTP** est le protocole de transfère de page web. Il envoi les données de façon claire, elles ne sont pas encrypté. Il tourne par défaut sur le **port 80**.

![[http1.png]]

On peut effectuer une requête http grâce à telnet. Pour ce faire on va :
- Se connecter au port 80, **`telnet <machine_ip> 80`**
- Ecrire notre requête, **`GET <route> HTTP/1.1`**
- Mettre une valeur comme host, **`Host : telnet`**

```shell
pentester@ip$ telnet MACHINE_IP 80 
Trying MACHINE_IP...
Connected to MACHINE_IP.
Escape character is '^]'.
GET /index.html HTTP/1.1 
host: telnet

HTTP/1.1 200 OK
Server: nginx/1.18.0 (Ubuntu)
Date: Wed, 15 Sep 2021 08:56:20 
GMT Content-Type: text/html 
Content-Length: 234 
Last-Modified: Wed, 15 Sep 2021 08:53:59 GMT
Connection: keep-alive
ETag: "6141b4a7-ea"
Accept-Ranges: bytes

<!DOCTYPE html>
<html lang="en">
	<head> 
		<title>Welcome to my Web Server</title>
		<meta charset="UTF-8" /> 
		<meta name="viewport" content="width=device-width,initial-scale=1" /> 
	</head> 
	<body>
		<h1>Coming Soon<h1> 
	</body>
</html>
```

Les serveurs web les plus populaires sont :

- **Apache**
- **Nginx**
- **IIS ( Internet Information Service)**

Les navigateurs les plus populaires sont :

- **Chrome** par Google 
- **Firefox** par Mozilla
- **Edge** par Microsoft
- **Safari** par Apple


## __FTP__

**FTP** pour File Transfer Protocol est un protocole qui permet le transfert de fichier entre 2 machines et tourne par default sur le **port 21**.

Pour se connecter en FTP on doit spécifier un utilisateur avec **USER <nom\>** et le mot de passe avec **PASS
<password\>**. On peut récupérer quelques information avec la commande **STAT**, le système de la machine avec **SYST**.

```shell
pentester@ip$ telnet MACHINE_IP 21 
Trying MACHINE_IP...
Connected to MACHINE_IP.
Escape character is '^]'.
220 (vsFTPd 3.0.3)
USER frank 
331 Please specify the password. 
PASS D2xc9CgD 
230 Login successful.
SYST
215 UNIX Type: L8
PASV
227 Entering Passive Mode (10,10,0,148,78,223).
TYPE A
200 Switching to ASCII mode.
STAT
211-FTP server status:
	Connected to ::ffff:10.10.0.1
	Logged in as frank 
	TYPE: ASCII 
	No session bandwidth limit
	Session timeout in seconds is 300
	Control connection is plain text 
	Data connections will be plain text 
	At session startup, client count was 1
	vsFTPd 3.0.3 - secure, fast, stable
211 End of status 
QUIT 
221 Goodbye.
Connection closed by foreign host.
```

![[ftp.png]]

On peut utiliser la commande **ls** pour voir les fichiers disponible et la commande **get <filename\>** pour
télécharger un fichier sur notre machine.

```shell
pentester@ip$ ftp MACHINE_IP 
Connected to MACHINE_IP.
220 (vsFTPd 3.0.3)
Name: frank 
331 Please specify the password.
Password: D2xc9CgD 
230 Login successful.
Remote system type is UNIX.
Using binary mode to transfer files.
ftp> ls 
227 Entering Passive Mode (10,20,30,148,201,180).
150 Here comes the directory listing.
-rw-rw-r-- 1    1001    1001       4006 Sep 15 10:27 README.txt
226 Directory send OK.
ftp> ascii 
200 Switching to ASCII mode.
ftp> get README.txt
local: README.txt remote: README.txt
227 Entering Passive Mode (10,10,0,148,125,55).
150 Opening BINARY mode data connection for README.txt (4006 bytes).
WARNING! 9 bare linefeeds received in ASCII mode
File may not have transferred correctly. 
226 Transfer complete. 
4006 bytes received in 0.000269 secs (14892.19 Kbytes/sec)
ftp> exit
221 Goodbye.
```


## __SMTP__

**SMTP** (Simple Mail Tranfert Protocol) sert à envoyer des mails et tourne par default sur le **port 25**.
Pour envoyer un mail on a besoin de plusieurs chose :
- Agent de **soumission** de mail **(MSA)**
- Agent de **transfert** de mail **(MTA)**
- Agent de **livraison** du mail **(MDA)**
- Agent d’**utilisateur de messagerie** **(MUA)**

![[SMTP.png]]

1)  Un **MUA** se **connecte a un MSA** pour envoyer son message.
2)  Le **MSA recoit le message**, recherche des eventuelles erreurs et **l’envois au MTA** généralement hébergé sur le meme serveur.
3)  Le **MTA** **envoit le message au MTA** du destinataire.
4)  Le **MTA** fonctionne egalement comme un MDA.
5)  Le **MUA** **recupere son message** auprès du MDA.

Le SMTP est utilisé pour communiquer avec un serveur MTA, étant donné que les informations ne sont pas encrypté, on peut utiliser telnet pour s’y connecter. Une fois connecté on effectue la commande **helo hostname**, puis on tappe notre mail.

```shell
pentester@ip$ telnet MACHINE_IP 25
Trying MACHINE_IP...
Connected to MACHINE_IP.
Escape character is '^]'. 
220 bento.localdomain ESMTP Postfix (Ubuntu)
helo telnet
250 bento.localdomain 
mail from:
250 2.1.0 Ok
rcpt to:
250 2.1.5 Ok
data
354 End data with .
subject: Sending email with Telnet
Hello Frank,
I am just writing to say hi! 
.
250 2.0.0 Ok: queued as C3E7F45F06
quit
221 2.0.0 Bye
Connection closed by foreign host.
```

Après ‘helo’ on précise **mail from :** et **rcpt to:**. Pour ecrire notre message on utilise **data** et on tappe le
contenu du message. On appuis ensuite sur **Entré** puis sur **.** puis à nouveau sur **Entré**.


## __POP3__

**POP3** pour Post Office Protocole version 3, est un protocole qui tourne par default sur le **port 110** qui sert à
telecharger des mails depuis un MDA.

![[pop3.png]]

On doit d’abord s’authentifier avec **USER <username\>** et **PASS <password\>**. En utilisant la commande :
- **STAT**, on obtient un resultat sous la forme **+OK <nombre de mail\> <taille\>**
- **LIST** , on obtient la liste des nouveaux messages sur le serveur
- **RETR 1** , on recupere le 1 er message de la liste

```shell
pentester@ip$ telnet MACHINE_IP 110 
Trying MACHINE_IP...
Connected to MACHINE_IP.
Escape character is '^]'.
+OK MACHINE_IP Mail Server POP3 Wed, 15 Sep 2021 11:05:34 +0300
USER frank
+OK frank
PASS D2xc9CgD 
+OK 1 messages (179) octets
STAT
+OK 1 179
LIST
+OK 1 messages (179) octets 
1 179
.
RETR 1
+OK
From: Mail Server
To: Frank 
subject: Sending email with Telnet
Hello Frank,
I am just writing to say hi!
.
QUIT
+OK MACHINE_IP closing connection
Connection closed by foreign host.
```


| **Protocol** | **TCP PORT** | **Application(s)** | **Data Security** |
| -------- | -------- | -------------- | ------------- |
| FTP      | 21       | File Transfer  | Cleartext     |
| HTTP     | 80       | Worldwide Web  | Cleartext     |
| IMAP     | 143      | Email (MDA)    | Cleartext     |
| POP3     | 110      | Email (MDA)    | Cleartext     |
| SMTP     | 25       | Email (MTA)    | Cleartext     |
| Telnet   | 23       | Remote Access  | Cleartext              |

