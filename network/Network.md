## __Passive_reconnaissance__

La reconnaissance passive permet d'obtenir des informations sans que la cible n'en soit informé.

### Whois

La commande **whois <\domain\>** permet d’avoir des informations sur le détenteur du domaine et les serveurs, on peut y trouver :
- Le **registrar** : c’est l’entreprise chez qui le domaine est enregistré
- Les **infos de contact** du registrar
- **Date de création** du domaine, **mise à jour** et **expiration**
- **Nom du serveur** sur lequel tourne le domaine

```shell
user@ip$ whois tryhackme.com 
[Querying whois.verisign-grs.com]
[Redirected to whois.namecheap.com]
[Querying whois.namecheap.com]
[whois.namecheap.com]
Domain name: tryhackme.com
Registry Domain ID: 2282723194_DOMAIN_COM-VRSN
Registrar WHOIS Server: whois.namecheap.com 
Registrar URL: http://www.namecheap.com 
Updated Date: 2021-05-01T19:43:23.31Z 
Creation Date: 2018-07-05T19:46:15.00Z 
Registrar Registration Expiration Date: 2027-07-05T19:46:15.00Z 
Registrar: NAMECHEAP INC 
Registrar IANA ID: 1068 
Registrar Abuse Contact Email: abuse@namecheap.com 
Registrar Abuse Contact Phone: +1.6613102107 
Reseller: NAMECHEAP INC 
Domain Status: clientTransferProhibited https://icann.org/epp#clientTransferProhibited 
Registry Registrant ID: 
Registrant Name: Withheld for Privacy Purposes 
Registrant Organization: Privacy service provided by Withheld for Privacy ehf 
[...]
URL of the ICANN WHOIS Data Problem Reporting System: http://wdprs.internic.net/ 
>>> Last update of WHOIS database: 2021-08-25T14:58:29.57Z <<<
For more information on Whois status codes, please visit https://icann.org/epp
```


### Nslookup & Dig

La commande **nslookup \<domain\>** permet de récupérer les informations sur les registres d'un domaine. On peut spécifier un type de record à cibler avec l’option **-type=\<record\>**. On peut effectuer les mêmes recherche avec l’outil Dig et la commande **dig \<domain\> \<record\>**.


Commande Nslookup

```shell
user@ip$ nslookup -type=MX 
tryhackme.com Server: 127.0.0.53 
Address: 127.0.0.53#53 

Non-authoritative answer:
tryhackme.com   mail exchanger = 5 alt1.aspmx.l.google.com.
tryhackme.com   mail exchanger = 1 aspmx.l.google.com.
tryhackme.com   mail exchanger = 10 alt4.aspmx.l.google.com.
tryhackme.com   mail exchanger = 10 alt3.aspmx.l.google.com.
tryhackme.com   mail exchanger = 5 alt2.aspmx.l.google.com.
```

Commande Dig

```shell
user@ip$ dig tryhackme.com MX 
; <<>> DiG 9.16.19-RH <<>> tryhackme.com MX 
;; global options: +cmd 
;; Got answer: 
;; ->>HEADER<
```


### Hackertarget

Pour **trouver tous les sous domaines** d’un nom de domaine, on peut utiliser le module **hackertarget** de la tool **[recon-ng](https://hackertarget.com/recon-ng-tutorial/)**.

```shell
[recon-ng][default][hackertarget] > options set SOURCE tryhackme.com
SOURCE => tryhackme.com
[recon-ng][default][hackertarget] > run

-------------
TRYHACKME.COM
-------------
[*] Country: None
[*] Host: www.tryhackme.com
[*] Ip_Address: 172.67.27.10
[*] Latitude: None
[*] Longitude: None
[*] Notes: None
[*] Region: None
[*] --------------------------------------------------
[*] Country: None
[*] Host: blog.tryhackme.com
[*] Ip_Address: 172.67.27.10
[*] Latitude: None
[*] Longitude: None
[*] Notes: None
[*] Region: None
[*] --------------------------------------------------
[*] Country: None
[*] Host: remote.tryhackme.com
[*] Ip_Address: 172.67.27.10
[*] Latitude: None
[*] Longitude: None
[*] Notes: None
[*] Region: None
[*] --------------------------------------------------
[*] Country: None
[*] Host: admin.tryhackme.com
[*] Ip_Address: 104.22.55.228
[*] Latitude: None
[*] Longitude: None
[*] Notes: None
[*] Region: None
[*] --------------------------------------------------
[*] Country: None
[*] Host: help.tryhackme.com
[*] Ip_Address: 172.67.27.10
[*] Latitude: None
[*] Longitude: None
[*] Notes: None
[*] Region: None
[*] --------------------------------------------------

-------
SUMMARY
-------
[*] 5 total (0 new) hosts found.
```


### Shodan.io

[Shodan.io](https://www.shodan.io/) permet de récupérer beaucoup d’information du au **logs** des nom de domaines :
- **IP address**
- **hosting company**
- **geographic location**
- **server type and version**

Ou des statistiques comme le taux d’utilisation des technologies des serveurs, les ports utilisé…

![[shodan.io.png]]


| **Purpose**                             | **Commandline Example**                       |
| ----------------------------------- | ----------------------------------------- |
| Lookup WHOIS record                 | `whois tryhackme.com`                     |
| Lookup DNS A records                | `nslookup -type=A tryhackme.com`          |
| Lookup DNS MX records at DNS server | `nslookup -type=MX tryhackme.com 1.1.1.1` |
| Lookup DNS TXT records              | `nslookup -type=TXT tryhackme.com`        |
| Lookup DNS A records                | `dig tryhackme.com A`                     |
| Lookup DNS MX records at DNS server | `dig @1.1.1.1 tryhackme.com MX`           |
| Lookup DNS TXT records              | `dig tryhackme.com TXT`                   |


## __Active reconnaissance__

La reconnaissance active permet de recupérer certaines informations sur une cible mais il faut faire attention lorsqu'on la pratique car la cible peut être mis au courant.

- **Ping** : Envoyer un **paquet à une ip**
- **Traceroute** : Récupérer **tous les routeurs** vers lesquels on passe
- **telnet**: Faire une **requête** sur le port d’une IP
- **netcat client** : être à **l’écoute d’une requête d’un port**
- **netcat serveur** : faire **tourner un serveur** pour être à l’écoute d’un port

| **Command**          | **Example**                                   |
| ---------------- | ----------------------------------------- |
| ping             | `ping -c 10 MACHINE_IP` on Linux or macOS |
| ping             | `ping -n 10 MACHINE_IP` on MS Windows     |
| traceroute       | `traceroute MACHINE_IP` on Linux or macOS |
| tracert          | `tracert MACHINE_IP` on MS Windows        |
| telnet           | `telnet MACHINE_IP PORT_NUMBER`           |
| netcat as client | `nc MACHINE_IP PORT_NUMBER`               |
| netcat as server | `nc -lvnp PORT_NUMBER`                    |

On peut aussi utiliser [nmap](NMAP-Host_active_directory) pour analyser l'**état des ports** de la cible.