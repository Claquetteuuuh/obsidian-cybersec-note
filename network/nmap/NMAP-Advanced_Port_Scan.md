
Comme vu dans la notes [[NMAP-TCP_UDP_Port_Scan]], on peut appliquer des flags à nos requêtes TCP. On va ici découvrir d’autres scan avec d’autres flag que le flag SYN ce qui permet de contourner certains firewall qui se base sur ce flag pour bloquer les connections.

## __Null Scan__

Ce type de scan signifie qu’aucun flag va être appliqué, un scan de ce type ne renverra aucune réponse de la part de la cible si le port est ouvert, donc une absence de réponse sera traduite par **open | filtered**. La commande est **`nmap -sN <cible>`**.

![[nmap6.1.png]]

```shell
pentester@ip$ sudo nmap -sN MACHINE_IP

Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 10:30 BST
Nmap scan report for MACHINE_IP 
Host is up (0.00066s latency). 
Not shown: 994 closed ports 
PORT    STATE         SERVICE 
22/tcp  open|filtered ssh 
25/tcp  open|filtered smtp
80/tcp  open|filtered http 
110/tcp open|filtered pop3 
111/tcp open|filtered rpcbind 
143/tcp open|filtered imap 
MAC Address: 02:45:BF:8A:2D:6B (Unknown) 

Nmap done: 1 IP address (1 host up) scanned in 96.50 seconds
```

![[nmap6.2.png]]

## __FIN Scan__

Ce type de scan va appliquer un **flag FIN**, il fonctionne comme le NULL scan.
La commande est **`nmap -sF  <cible>`**.

![[nmap6.3.png]]

![[nmap6.4.png]]

```shell
pentester@ip$ sudo nmap -sF MACHINE_IP

Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 10:32 BST
Nmap scan report for MACHINE_IP Host is up (0.0018s latency). 
Not shown: 994 closed ports
PORT    STATE         SERVICE 
22/tcp  open|filtered ssh 
25/tcp  open|filtered smtp
80/tcp  open|filtered http
110/tcp open|filtered pop3 
111/tcp open|filtered rpcbind
143/tcp open|filtered imap 
MAC Address: 02:45:BF:8A:2D:6B (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 96.52 seconds
```


## __XMAS Scan__

Ce type de scan met simultanément les **flags FIN**, **PSH**, et **URG**, tout comme les 2 scans précédent la cible ne renverra aucune réponse si le port est ouvert ou filtré. La commande est **`nmap -sX  <cible>`**.

![[nmap6.5.png]]

```shell
pentester@TryHackMe$ sudo nmap -sX MACHINE_IP

Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 10:34 BST 
Nmap scan report for MACHINE_IP Host is up (0.00087s latency).
Not shown: 994 closed ports
PORT    STATE         SERVICE 
22/tcp  open|filtered ssh 
25/tcp  open|filtered smtp 
80/tcp  open|filtered http 
110/tcp open|filtered pop3 
111/tcp open|filtered rpcbind 
143/tcp open|filtered imap
MAC Address: 02:45:BF:8A:2D:6B (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 84.85 seconds
```

![[nmap6.6.png]]


*On peut utiliser d’autres flag dans le but d’exposer les règles du firewall et non des services. Pour cela on peut utiliser les flags ACK, WINDOW, ou d’autres flags CUSTOM.*

## __ACK Scan__

Ce type de scan enverra un **flag ACK** dans son packet, la cible renverra dans tout les cas un **flag RST**, ceci est du au fait qu’un flag ACK est envoyé en guise de réponse à une précédente requête et donc ne nous permettra pas de récupérer l’état du port. La commande est **`nmap -sA <cible>`**.

```shell
pentester@ip$ sudo nmap -sA MACHINE_IP 

Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 10:37 BST
Nmap scan report for MACHINE_IP 
Host is up (0.0013s latency).
All 1000 scanned ports on MACHINE_IP are unfiltered 
MAC Address: 02:45:BF:8A:2D:6B (Unknown) 

Nmap done: 1 IP address (1 host up) scanned in 1.68 seconds
```
*ici aucun port n'est bloqué*

```shell
pentester@ip$ sudo nmap -sA MACHINE_IP 

Starting Nmap 7.60 ( https://nmap.org ) at 2021-09-07 11:34 BST 
Nmap scan report for MACHINE_IP Host is up (0.00046s latency). 
Not shown: 997 filtered ports 
PORT   STATE      SERVICE 
22/tcp unfiltered ssh 
25/tcp unfiltered smtp
80/tcp unfiltered http 
MAC Address: 02:78:C0:D0:4E:E9 (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 15.45 seconds
```
*tous les ports sont bloqué sauf 3*

![[nmap6.7.png]]


## __WINDOW Scan__

Ce type de scan envois un paquet avec le **flag ACK** mais il examine le champ TCP window des paquets renvoyé pour **connaitre l’état du firewall**. Dans certains systèmes cela peut aussi révéler l’état du port. 
La commande est **`nmap -sW <cible>`**.

```shell
pentester@ip$ sudo nmap -sW MACHINE_IP 

Starting Nmap 7.60 ( https://nmap.org ) at 2021-09-07 11:39 BST 
Nmap scan report for MACHINE_IP 
Host is up (0.00040s latency). 
Not shown: 997 filtered ports 
PORT STATE SERVICE 
22/tcp closed ssh 
25/tcp closed smtp 
80/tcp closed http 
MAC Address: 02:78:C0:D0:4E:E9 (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 14.84 seconds
```
*ici on voit que 3 ports ne sont pas filtré mais aussi que contrairement a l’analyse ACK, on peut aussi avoir l’état réel du port et non fermé | filtré*

![[nmap6.8.png]]

## __Custom Scan__

On peut effectuer un scan **personnalisé** avec l’option **`nmap –scanflags <flag ex: RSTSYNFIN> <cible>`**.

![[nmap6.9.png]]


## __SPOOFING & DECOYS__

Dans certaines configuration on pourra analyser un système via une adresse IP ou MAC usurpé. Ce type d’analyse est utile que si l’on arrive a capturer la réponse. Pour usurper une IP, la commande est : 
**`nmap -S <spoof> <cible>`**.

![[nmap6.10.png]]

Il y a 3 étapes dans le **spoofing** :
⦁	L’attaquant **envoie un paquet avec l’adresse usurpé**
⦁	La machine cible **réponds à l’IP usurpé**
⦁	L’attaquant **capture les réponses** pour découvrir les ports ouverts


Si on est dans le **même réseaux** on peut aussi usurpé une **adresse MAC**, pour ce faire on doit spécifier l’adresse MAC source avec l’option **`--spoof-mac <spoof_mac>`**.

Le spoofing fonctionne dans très peu de cas, on peut donc **utiliser des leurres** pour que ce soit **plus difficile de nous identifier**. Pour ce faire, on utilise la commande **`nmap -D <ip1>,<ip2>,RND,RND,ME <cible>`**. ME dit à nmap que notre IP apparaitra à la dernière place.

![[nmap6.11.png]]

## __FRAGMENTED PACKETS__

Les **firewalls** fonctionnent grâce à des règles qui consiste à **bloquer tous les ports sauf certains** ou au contraire à **autoriser tous les ports sauf certains**. Il existe des firewalls plus sophistiqué qui vont **analyser l’entête** des donnés de la couche transport.

Un **IDS** (Système de Détection d’Intrusion) **analyse les paquets réseau** pour voir s’il ne **reconnais** pas un **comportement malveillant**, dans ce cas il **déclenchera une alerte**. En plus d’analyser l’entête, il analyse également le **contenu des données** de la couche transport.

Nmap offre la possibilité de **fragmenter** nos paquets avec l’option **`-f `** elle va diviser nos donnés IP en **8 octets** ou moins. On peut utiliser **`-ff`** pour les diviser en **16 octets**.


## __GETTING MORE DETAILS__

Pour obtenir plus de détail sur l’analyse on peut utiliser plusieurs options :
 - **`--reason`**, nous donnera des informations sur le **raisonnement** d’nmap et ses conclusions. Ici nmap a conclu que le port 22 était ouvert car il a **recu un packet syn-ack**.
 
 ```shell
 pentester@ip$ sudo nmap -sS --reason 10.10.252.27
 
Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 10:40 BST
Nmap scan report for ip-10-10-252-27.eu-west-1.compute.internal (10.10.252.27)
Host is up, received arp-response (0.0020s latency).
Not shown: 994 closed ports
Reason: 994 resets
PORT    STATE SERVICE REASON 
22/tcp  open  ssh     syn-ack ttl 64
25/tcp  open  smtp    syn-ack ttl 64 
80/tcp  open  http    syn-ack ttl 64 
110/tcp open  pop3    syn-ack ttl 64 
111/tcp open  rpcbind syn-ack ttl 64 
143/tcp open  imap    syn-ack ttl 64 
MAC Address: 02:45:BF:8A:2D:6B (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 1.59 seconds
```

- **`-vv`**, nous donnera encore plus de détail sur la verbosité

```shell
pentester@ip$ sudo nmap -sS -vv 10.10.252.27

Starting Nmap 7.60 ( https://nmap.org ) at 2021-08-30 10:41BST 
Initiating ARP Ping Scan at 10:41
Scanning 10.10.252.27 [1 port] 
Completed ARP Ping Scan at 10:41, 0.22s elapsed (1 total hosts) 
Initiating Parallel DNS resolution of 1 host. at 10:41 
Completed Parallel DNS resolution of 1 host. at 10:41, 0.00s elapsed 
Initiating SYN Stealth Scan at 10:41 
Scanning ip-10-10-252-27.eu-west-1.compute.internal (10.10.252.27) [1000 ports]
Discovered open port 22/tcp on 10.10.252.27 
Discovered open port 25/tcp on 10.10.252.27
Discovered open port 80/tcp on 10.10.252.27
Discovered open port 110/tcp on 10.10.252.27
Discovered open port 111/tcp on 10.10.252.27
Discovered open port 143/tcp on 10.10.252.27 
Completed SYN Stealth Scan at 10:41, 1.25s elapsed (1000 total ports)
Nmap scan report for ip-10-10-252-27.eu-west-1.compute.internal (10.10.252.27) 
Host is up, received arp-response (0.0019s latency). 
Scanned at 2021-08-30 10:41:02 BST for 1s 
Not shown: 994 closed ports 
Reason: 994 resets 
PORT    STATE SERVICE REASON 
22/tcp  open  ssh     syn-ack ttl 64 
25/tcp  open  smtp    syn-ack ttl 64 
80/tcp  open  http    syn-ack ttl 64 
110/tcp open  pop3    syn-ack ttl 64 
111/tcp open  rpcbind syn-ack ttl 64 
143/tcp open  imap    syn-ack ttl 64 
MAC Address: 02:45:BF:8A:2D:6B (Unknown)

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 1.59 seconds
	Raw packets sent: 1002 (44.072KB) | Rcvd: 1002 (40.092KB)
```


| **Port Scan Type**             | **Example Command**                                   |
| ------------------------------ | ----------------------------------------------------- |
| TCP Null Scan                  | `sudo nmap -sN MACHINE_IP`                            |
| TCP FIN Scan                   | `sudo nmap -sF MACHINE_IP`                            |
| TCP Xmas Scan                  | `sudo nmap -sX MACHINE_IP`                            |
| TCP Maimon Scan                | `sudo nmap -sM MACHINE_IP`                            |
| TCP ACK Scan                   | `sudo nmap -sA MACHINE_IP`                            |
| TCP Window Scan                | `sudo nmap -sW MACHINE_IP`                            |
| Custom TCP Scan                | `sudo nmap --scanflags URGACKPSHRSTSYNFIN MACHINE_IP` |
| Spoofed Source IP              | `sudo nmap -S SPOOFED_IP MACHINE_IP`                  |
| Spoofed MAC Address            | `--spoof-mac SPOOFED_MAC`                             |
| Decoy Scan                     | `nmap -D DECOY_IP,ME MACHINE_IP`                      |
| Idle (Zombie) Scan             | `sudo nmap -sI ZOMBIE_IP MACHINE_IP`                  |
| Fragment IP data into 8 bytes  | `-f`                                                  |
| Fragment IP data into 16 bytes | `-ff`                                                 |

| **Option**               | **Purpose**                              |
| ------------------------ | ---------------------------------------- |
| `--reason`               | explains how Nmap made its conclusion    |
| `-v`                     | verbose                                  |
| `-vv`                    | very verbose                             |
| `-d`                     | debugging                                |
| `-dd`                    | more details for debugging               |
| `--source-port PORT_NUM` | specify source port number               |
| `--data-length NUM`      | append random data to reach given length |
