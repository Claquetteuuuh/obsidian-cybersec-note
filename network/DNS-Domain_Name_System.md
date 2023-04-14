Un domaine est une **suite de caractères** qui ont pour but de **pointer vers une IP**, on peut imaginer une
adresse (le domaine) pointant vers une maison (l’IP).

## __Hiérarchie des domaines__

- **TLD** (top-level domains), c’est la partie la **plus à droite** du nom de domaine, il y a 2 types de TLD :
	- **gTLD** (generic top level), servait à la base à dire **l’objectif** du domaine (.com pour du commercial).
	- **ccTLD** (country code top level), servait lui à des fins **géographiques** (.fr pour France).

- **SLD** (second-level domains), c’est la partie *‘principale’* du nom de domaine (pour domaine.com, ce sera domaine). La taille maximum de cette partie est **63 caractères de a-z 0-9 et avec des –** (ni au début ni à la fin).

- **Sous domaine**, c’est la partie **la plus à gauche** du nom de domaine (host.domaine.com, ce sera host). Elle est, tout comme le SLD, limitée à **63 caractères de a-z 0-9 et avec des –**. On peut séparer le nom de domaine avec des . pour le rendre plus long mais il ne pourra **pas dépasser 253 caractères**. On peut lister ces sous domaines grâce 

![[dns1.excalidraw]]

## __Les types de RECORDS__

Les DNS ne sont pas uniquement pour les sites web il existe plusieurs types de records :
- **A**, il pointe vers une adresse **IPv4** (104.26.10.229)
- **AAAA**, il pointe vers une adresse **IPv6** (2606:4700:20::681a:be5)
- **CNAME**, il pointe vers un **autres domaines** (store.domaine.com => shop.shopify.com)
- **MX**, il pointe vers le **serveur mail** (domaine.com =>  alt1.aspmx.l.google.com)
- **TXT**, il pointe vers n’importe quel **texte libre**, ils sont le plus souvent utilisé pour répertorier les serveurs pouvant envoyer un e-mail au nom de domaine pour éviter les spams.

## __Requête DNS__

1) Lorsqu’on fait une demande vers un nom de domaine, l’ordinateur vérifie d’abord le **cache local** pour voir si on a pas **déjà recherché le domaine**, sinon une demande à notre **serveur DNS récursif** sera faite.
2) Le **serveur DNS récursif**, peut être soit fournis par notre **FAI** soit défini par nous-même, ce serveur va d’abord **regarder dans son cache** si le domaine n’a pas été déjà recherché, si c’est le cas il vous le renvoie, sinon un parcours commence pour **trouver l’IP en commençant par les serveurs DNS racine d’internet**.
3) Le **serveur DNS racine** va rediriger vers le bon **TLD**, (domaine.com va chercher sur les serveur TLD qui traite les adresses .com)
4) Le **serveur TLD** a les indications vers le serveur faisant autorité aussi connu sous le nom de **serveur de nom de domaines**. (LWS, Cloudflare…)
5) Le **serveur de nom de domaines** est responsable du **stockage** des enregistrements DNS pour un nom de domaine. Selon le type de records, il sera **renvoyé au serveur DNS récursif** où une copie local sera mise en cache pour les futures demandes. La réponse sera ensuite envoyée à nous avec une valeur **TTL** (Time To Live) qui est le temps où le domaine doit être stocké localement.

![[dns2.png]]