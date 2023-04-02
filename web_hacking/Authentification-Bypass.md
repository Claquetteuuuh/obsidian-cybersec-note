## __Enumération des usernames__

Pour trouver les noms d’utilisateur déjà utilisé sur le site, on peut utiliser les **erreurs renvoyé par le site**.

Par exemple, si l’on essaye de créer un compte avec le nom *‘admin’* dans un site où ce nom est **déjà pris**, le site
pourrai nous renvoyer le message **‘username already exists’**, par conséquent, on peut connaitre savoir que le nom
que nous essayons d’entrer **existe déjà dans la base de donné du site**.

Pour automatiser ce processus, on peut utiliser un outil comme [[fuff]] et effectuer la commande suivante :
```shell
user@ip$ ffuf -w /usr/share/wordlists/SecLists/Usernames/Names/names.txt -X POST -d "username=FUZZ&email=x&password=x&cpassword=x" -H "Content-Type: application/x-www-form-urlencoded" -u http://MACHINE_IP/customers/signup -mr "username already exists"
```

Dans le code précédent, l’option *-w* sert à préciser la [**wordlist**](https://github.com/danielmiessler/SecLists/blob/master/Usernames/Names/names.txt), l’option *-x* sert à préciser la **méthode** de la
requête (ici POST), l’option *-d* sert à spécifier les **data** qu’on veut envoyer, l’option *-H* pour préciser les
**headers**, *-u* permet de spécifier l’**url** vers lequel nous effectuons la requête, et enfin l’option *-mr* a pour but
de regarder **si le texte est présent sur la page**.


## __Bruteforce__

Une fois que nous avons trouvé les noms d’utilisateurs valide, on doit maintenant **trouver le mot de passe** associé à
ce compte. 

On va donc faire une requête similaire à celle que nous avons effectué précédemment :
```shell
user@ip$ ffuf -w ./valid_usernames.txt:W1,/usr/share/wordlists/SecLists/Passwords/Common-Credentials/10-million-password-list-top-100.txt:W2 -X POST -d "username=W1&password=W2" -H "Content-Type: application/x-www-form-urlencoded" -u http://MACHINE_IP/customers/login -fc 200
```

Une différence est qu’ici à la place de l’option *-mr* nous allons utiliser l’option ***-fc***  qui sert à préciser le wordlist [**code de réponse**](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status) que nous attendons. De plus au lieu d’utiliser la variable FUZZ, nous avons **créé la variable W1 et [W2](https://github.com/danielmiessler/SecLists/blob/master/Passwords/Common-Credentials/10-million-password-list-top-100.txt)**
pour chaque wordlist.


## __Cookie tampering__

Les cookies servent principalement à **garder l’identité** de l’utilisateur pendant sa navigation sur le site. Par
conséquent, on peut les modifier pour potentiellement **changer notre niveau de privilège**. Par exemple on voit que le site nous fournis un cookie avec un attribut *admin=false*, nous pouvons essayer de changer cette attribut pour s’attribuer des permissions sur le site.

Pour modifier ce cookie, on peut effectuer une requête en changeant nos entêtes, par exemple :
```shell
user@ip$ curl -H "Cookie: logged_in=true; admin=true" http://MACHINE_IP/cookie-test
```

Souvent, les informations visible ne sont pas lisible car elles sont passé dans des algorithmes de [[Hash]] ou d'[[Encryption_Chiffrement]].
