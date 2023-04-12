Les ports sont utilisé pour savoir si un **[service](Protocoles_Serveur) écoute** ce port ou non.

Il y a 6 états pour les ports :

- **Open**, le port est ouvert et un **service l’écoute**
- **Closed**, le port est fermé et **aucun service** ne tourne dessus
- **Filtered**, nmap ne peut **pas déterminer** si le port est ouvert ou non, cela peut être due à un **firewall**
- **Unfiltered**, nmap ne peut **pas déterminer** si le port est ouvert ou non même s’il **est accessible**
- **Open | filtered**, nmap ne peut pas déterminer s’il est **ouvert ou filtré**
- **Closed | filtered**, nmap ne peut pas déterminer s’il est **fermé ou filtré**

## __TCP / UDP__

Il y a diffèrent type d’analyse de port via TCP, elles dépendent des flags qu’il y a dans l’header de la requête.

- **URG** : indique que les données entrante sont urgente, ces donné sont **traité immédiatement sans regarder** si les segments précédent ont été envoyé.
- **ACK** : c’est un **accusé de réception**
- **PSH** : PUSH, il demande a TCP de **transmettre rapidement les données à l’application**
- **RST** : il sert à **réinitialiser** une connexion
- **SYN** : il sert à **synchroniser les numéros de séquence** avec l’autre hôte et il **initie un handshake à 3 voies**
- **FIN** : il n’y a **plus de donné** à envoyé


### TCP

Pour faire un scan TCP on effectue la commande **`nmap -sT <cible>`** , on peut utiliser l’option **`-F`** pour activer le mode **rapide** qui va passer le nombre de **port scanné à 100**.

```shell
pentester@ip$ nmap -sT MACHINE_IP

Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 09:53 BST
Nmap scan report for MACHINE_IP 
Host is up (0.0024s latency).
Not shown: 995 closed ports
PORT   STATE SERVICE 
22/tcp open  ssh
25/tcp open  smtp 
80/tcp open  http 
111/tcp open rpcbind 
143/tcp open imap
MAC Address: 02:45:BF:8A:2D:6B (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 0.40 seconds
```

![[nmap1.1.png]]

![[nmap1.2.png]]

Pour effectuer un scan avec le **flag SYN**, on va mettre l’option `-sS`, à ce moment-là on a **besoin des perms sudo**.

```shell
pentester@ip$ sudo nmap -sS MACHINE_IP

Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 09:53 BST
Nmap scan report for MACHINE_IP Host is up (0.0073s latency). 
Not shown: 994 closed ports 
PORT    STATE SERVICE 
22/tcp  open  ssh
25/tcp  open  smtp 
80/tcp  open  http 
110/tcp open  pop3 
111/tcp open  rpcbind 
143/tcp open  imap
MAC Address: 02:45:BF:8A:2D:6B (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 1.60 seconds
```


### UDP
UDP ne nécessite pas de connexion donc aucune prise de contact pour l’établissement d’une connexion. On ne peut donc **pas garantir qu’un service écoutant sur un port UDP répondra à nos packets**, cependant si un port **est fermé** on reçoit une **erreur ICMP de type 3**. La commande est **`sudo nmap -sU <cible>`**

```shell
pentester@ip$ sudo nmap -sU MACHINE_IP 

Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 09:54 BST
Nmap scan report for MACHINE_IP Host is up (0.00061s latency). 
Not shown: 998 closed ports
PORT    STATE         SERVICE 
68/udp  open|filtered dhcpc 
111/udp open          rpcbind 
MAC Address: 02:45:BF:8A:2D:6B (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 1085.05 seconds
```

![[nmap2.1.png]]

![[nmap2.2.png]]

![[nmap2.3.png]]

On peut utiliser l’option **`-p<min>-<max>`** pour préciser une **plage de ports**.

| **Port Scan Type**   | **Exemple Command**            |
| ---------------- | -------------------------- |
| TCP Connect Scan | `nmap -sT MACHINE_IP`      |
| TCP SYN Scan     | `sudo nmap -sS MACHINE_IP` |
| UDP Scan         | `sudo nmap -sU MACHINE_IP` |

| **option**                  | **Purpose**                                  |
| ----------------------- | ---------------------------------------- |
| `-p-`                   | all ports                                |
| `-p1-1023`              | scan ports 1 to 1023                     |
| `-F`                    | 100 most common ports                    |
| `-r`                    | scan ports in consecutive order          |
| `-T<0-5>`               | -T0 being the slowest and T5 the fastest |
| `--max-rate 50`         | rate <= 50 packets/sec                   |
| `--min-rate 15`         | rate >= 15 packets/sec                   |
| `--min-parallelism 100` | at least 100 probes in parallel          |


Pour en savoir plus rdv sur la note [[NMAP-Advanced_Port_Scan]]
