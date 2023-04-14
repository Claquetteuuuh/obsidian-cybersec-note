
Pour **trouver** les noms de domaines, on a plusieurs méthodes : **[Brute force](Decouvertes_du_contenu##__Automatised_Discovery__), [OSINT](Osint-Utils), Virtual Host**.

## __OSINT__

- Il existe des **logs** des **certificats SSL** qui ont été généré pour des domaines. Des [sites](https://crt.sh/) **répertorie les certificats** qui ont été généré. Cela nous permet par exemple de trouver des sous domaines ayant un certificat SSL.
- Les **Googles dorks**, permettent de trouver les sous domaines trouvé par le moteur de recherche de google grâce la recherche **`-site:www.<website>.com site:*.<website>.com`**

## __Sublist3r__

Pour **automatiser la recherche**, des outils comme [Sublist3r](https://github.com/aboul3la/Sublist3r) ont été créé.
La commande à effectuer est **`$ ./sublist3r.py -d <domain>`**

```shell
user@thm:~$ ./sublist3r.py -d acmeitsupport.thm  
  
          ____        _     _ _     _   _____  
         / ___| _   _| |__ | (_)___| |_|___ / _ __  
         \___ \| | | | '_ \| | / __| __| |_ \| '__|  
          ___) | |_| | |_) | | \__ \ |_ ___) | |  
         |____/ \__,_|_.__/|_|_|___/\__|____/|_|  
  
         # Coded By Ahmed Aboul-Ela - @aboul3la  
  
[-] Enumerating subdomains now for acmeitsupport.thm  
[-] Searching now in Baidu..  
[-] Searching now in Yahoo..  
[-] Searching now in Google..  
[-] Searching now in Bing..  
[-] Searching now in Ask..  
[-] Searching now in Netcraft..  
[-] Searching now in Virustotal..  
[-] Searching now in ThreatCrowd..  
[-] Searching now in SSL Certificates..  
[-] Searching now in PassiveDNS..  
[-] Searching now in Virustotal..  
[-] Total Unique Subdomains Found: 2  
web55.acmeitsupport.thm  
www.acmeitsupport.thm
```


## __Virtual Host__

Parfois, les **sous-domaines ne sont pas toujours hébergé** dans des résultats DNS accessible au public, à la place ils sont peut être conservé sur un serveur DNS privé ou enregistré sur les machines du développeur dans son fichier /etc/hosts qui mappe les noms de domaines sur l’adresse IP.

Pour trouver ces domaines on peut utiliser des wordlists pour fuzzer le site afin de trouver un domaine.
On peut utiliser l’outil fuff pour effectuer la commande si dessous. 

```shell
user@machine$ ffuf -w /usr/share/wordlists/SecLists/Discovery/DNS/namelist.txt -H "Host: FUZZ.acmeitsupport.thm" -u http://MACHINE_IP
```

L’option **`-w`** sert à préciser la wordlist, l’option **`-H`** modifie un entête ici Host, le mot **FUZZ** est notre variable qui changera pour prendre la valeur de chaque mot.
Etant donné que cette requête renverra forcement un résultat valide, on doit filtrer la sortie en rajoutant l’option **`-fs`** suivis de la taille qui à été la plus fréquente pour dire à fuff d’ignorer ceux précisé. 

```shell
user@machine$ ffuf -w /usr/share/wordlists/SecLists/Discovery/DNS/namelist.txt -H "Host: FUZZ.acmeitsupport.thm" -u http://MACHINE_IP -fs {size}
```


## __HackerTarget__

Hackertarget est un modules de [recon-ng](https://hackertarget.com/recon-ng-tutorial/).
