
## __Scan ARP__

Pour effectuer un scan ARP on doit être dans le même sous-réseaux que la cible. Pour ce faire on utilise la commande **`nmap -sn <cible>`**. Cette commande va nous renvoyer toutes les adresses MAC du sous réseaux mais aussi l’états des ports. Si l’on souhaite uniquement le scan ARP on doit rajouter l’option **`-PR`**, l’option **`-sn`** permet de ne pas faire de scan des ports.

```shell
pentester@ip$ sudo nmap -PR -sn 10.10.210.6/24

Starting Nmap 7.60 ( https://nmap.org ) at 2021-09-02 07:12 BST
Nmap scan report for ip-10-10-210-75.eu-west-1.compute.internal (10.10.210.75)
Host is up (0.00013s latency).
MAC Address: 02:83:75:3A:F2:89 (Unknown)
Nmap scan report for ip-10-10-210-100.eu-west-1.compute.internal (10.10.210.100)
Host is up (-0.100s latency).
MAC Address: 02:63:D0:1B:2D:CD (Unknown)
Nmap scan report for ip-10-10-210-165.eu-west-1.compute.internal (10.10.210.165) 
Host is up (0.00025s latency).
MAC Address: 02:59:79:4F:17:B7 (Unknown)
Nmap scan report for ip-10-10-210-6.eu-west-1.compute.internal (10.10.210.6) 
Host is up. 
Nmap done: 256 IP addresses (4 hosts up) scanned in 3.12 seconds
```

![[nmap3.1.png]]

![[nmap3.2.png]]

## __Scan ICMP__

Il faut savoir que beaucoup de **firewall bloque les écho ICMP** comme par exemple celui de MS-WINDOWS qui bloque toutes les requêtes ICMP par default. Rappel : une requête ARP précèdera toujours une requête ICMP si la cible se trouve sur le même sous réseau. La commande à effectuer est **`nmap -PE -sn <cible>/24`**.

```shell
pentester@ip$ sudo nmap -PP -sn 10.10.68.220/24 

Starting Nmap 7.92 ( https://nmap.org ) at 2021-09-02 12:06 EEST 
Nmap scan report for 10.10.68.50
Host is up (0.13s latency).
Nmap scan report for 10.10.68.52
Host is up (0.25s latency).
Nmap scan report for 10.10.68.77
Host is up (0.14s latency).
Nmap scan report for 10.10.68.110
Host is up (0.14s latency).
Nmap scan report for 10.10.68.140
Host is up (0.15s latency).
Nmap scan report for 10.10.68.209 
Host is up (0.14s latency).
Nmap scan report for 10.10.68.220 
Host is up (0.14s latency). 
Nmap scan report for 10.10.68.222 
Host is up (0.14s latency). 
Nmap done: 256 IP addresses (8 hosts up) scanned in 10.93 seconds
```

![[nmap3.3.png]]

![[nmap3.4.png]]


## __Scan TCP__

On peut envoyer un **flag SYN** a un port d’une machine, un port ouvert répondra par un flag SYN/ACK un port fermé lui entrainera un RST. La commande à effectuer est **`nmap -PS -sn <cible>/24`**. [En savoir plus sur le scan TCP](NMAP-TCP_UDP_Port_Scan).

```shell
pentester@ip$ sudo nmap -PS -sn 10.10.68.220/24 
Starting Nmap 7.92 ( https://nmap.org ) at 2021-09-02 13:45 EEST 
Nmap scan report for 10.10.68.52
Host is up (0.10s latency).
Nmap scan report for 10.10.68.121 
Host is up (0.16s latency).
Nmap scan report for 10.10.68.125 
Host is up (0.089s latency).
Nmap scan report for 10.10.68.134 
Host is up (0.13s latency). 
Nmap scan report for 10.10.68.220
Host is up (0.11s latency).
Nmap done: 256 IP addresses (5 hosts up) scanned in 17.38 seconds
```

![[nmap4.1.png]]

![[nmap4.2.png]]

On peut également effectuer une requête similaire avec un **flag ACK**, l’option **`-PA<port>`** sera utilisé.

## __Scan UDP__

Enfin, on peut analyser les Hosts actifs en effectuant une requête **UDP**, contrairement au requête précédente, elle n’envoie pas de packet si l’hote est ouvert. La commande est **`nmap -PU -sn <cible>/24`**.

![[nmap5.1.png]]

```shell
pentester@ip$ sudo nmap -PU -sn 10.10.68.220/24
Starting Nmap 7.92 ( https://nmap.org ) at 2021-09-02 13:45 EEST
Nmap scan report for 10.10.68.52
Host is up (0.10s latency). 
Nmap scan report for 10.10.68.121 
Host is up (0.10s latency). 
Nmap scan report for 10.10.68.125 
Host is up (0.14s latency). 
Nmap scan report for 10.10.68.134 
Host is up (0.096s latency). 
Nmap scan report for 10.10.68.220
Host is up (0.11s latency).
Nmap done: 256 IP addresses (5 hosts up) scanned in 9.20 seconds
```

![[nmap5.2.png]]

| **Scan Type**          | **Exemple Command**                         |
| ---------------------- | ------------------------------------------- |
| ARP Scan               | `sudo nmap -PR -sn MACHINE_IP/24`           |
| ICMP Echo Scan         | `sudo nmap -PE -sn MACHINE_IP/24`           |
| ICMP Timestamp Scan    | `sudo nmap -PP -sn MACHINE_IP/24`           |
| ICMP Address Mask Scan | `sudo nmap -PM -sn MACHINE_IP/24`           |
| TCP SYN Ping Scan      | `sudo nmap -PS22,80,443 -sn MACHINE_IP/30`  |
| TCP ACK Ping Scan      | `sudo nmap -PA22,80,443 -sn MACHINE_IP/30`  |
| UDP Ping Scan          | `sudo nmap -PU53,161,162 -sn MACHINE_IP/30` |

| **Option** | **Purpose**                      |
| ---------- | -------------------------------- |
| `-n`         | no DNS lookup                    |
| `-R`       | reverse-DNS lookup for all hosts |
| `-sn`      | host discovery only                                 |
