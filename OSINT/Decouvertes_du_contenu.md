
La découverte du contenu peut se faire de 3 manières : Manuellement, Automatiquement ou avec de l’OSINT.

## __Manually Discovery__

Il y a plusieurs manière pour trouver manuellement les **routes d’un site** :

- **Robots.txt**, ce fichier est un document qui **dit au moteur de recherche** ce qu’il faut **afficher** ou **ne pas afficher** dans les résultats de recherches. C’est une pratique courante et il peut y avoir beaucoup de page comme les portails admin.
- **Favicon**, souvent, quand les sites sont codé avec des **frameworks**, il reste une favicon, elle peut donner une **information sur le framework** utilisé.
- **Sitemap.xml**, A l’inverse du fichier Robots.txt, ce fichier liste toutes les routes qui **doivent être listé par le moteur de recherche**.
- **http headers**, en effectuant une requête **`$ curl <ip> -v`** on peut récupérer la **version du serveur web** ainsi que du **langage de programmation** du site.
- **OSINT-Google dork**, Google, comme de nombreux moteur de recherche, met à notre disposition des [dorks](https://en.wikipedia.org/wiki/Google_hacking) qui permettent de trouver des **informations sur des sites**. Exemple site:tryhackme.com listera tous les sites du domaine tryhackme.com.
- **OSINT**, L’extension [Wappalyzer](https://www.wappalyzer.com/) permet de connaitre les **technologies utilisé sur le site**.
- **OSINT-Wayback**, [Wayback-Machine](https://archive.org/web/) est une archive qui répertorie depuis 1990 toutes les pages qui **ont été hébergé sur un domaine**, on pourra grâce à ça trouver les anciennes pages du site.
- **OSINT-Github**, github est un **outil de versioning** qui suit les modifications apporté à un fichier.
- **OSINT-S3Bucket**, le S3 bucket est un **service de stockage fournis par AWS** qui permet aux utilisateurs de sauvegarder des fichiers. Parfois les autorisations sont mal configuré le format des s3 buckets est : http(s)://{name}. s3.amazonaws.com


## __Automatised Discovery__

Grace à des **[listes de mots](https://github.com/danielmiessler/SecLists)**, on peut **fuzzer** (tester toutes les routes accessible d’un site)
Pour fuzzer, on peut utiliser l’outil **fuff** disponible sur les distributions linux comme ubuntu, debian, kali etc

```shell
user@machine$ ffuf -w /usr/share/wordlists/SecLists/Discovery/Web-Content/common.txt -u http://MACHINE_IP/FUZZ
```

L'option **`-w`** sert à préciser le **chemin vers la wordlist**, **`-u`** pour préciser l'URL que l'on doit fuzzer, le mot **`FUZZ`** est la variable où les mots **vont être inséré**.


Voici un code similaire avec **gobuster** :

```shell
gobuster dir -u http://MACHINE_IP/ -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt
```
