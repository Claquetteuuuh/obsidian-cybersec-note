
Une étape importante dans l'escalation de privilège est l'énumération des informations d'une machine.


## __Hostname__

La commande **`hostname`** permet de récupérer le **nom de la machine**. Cela peut nous permettre d'avoir des informations sur **son role dans le systeme** (ex: SQL-PROD-01).

```shell
$ hostname
wade7363
```


## __Uname -a__

La commande **`uname -a`** donne les infos sur le **noyau** (kernel) utilisé par le systeme.

```shell
$ uname -a
Linux wade7363 3.13.0-24-generic #46-Ubuntu SMP Thu Apr 10 19:11:08 UTC 2014 x86_64 x86_64 x86_64 GNU/Linux
```


## __/proc/version__

Le fichier **`/proc/version`** nous donne des infos sur le systeme comme **l'OS** ou le type de **compilateur installé**.

```shell
$ cat /proc/version
Linux version 3.13.0-24-generic (buildd@panlong) (gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1) ) #46-Ubuntu SMP Thu Apr 10 19:11:08 UTC 2014

```

Le fichier `/etc/issue` peut aussi nous donner des informations similaire mais peut être plus facilement modifier.

```shell
$ cat /etc/issue
Ubuntu 14.04 LTS \n \l
```


## __ps__

La commande **`ps`** est utilisé pour avoir la **liste des processus** en cour d'éxécution sur la machine.

-   **PID** : L'**ID** du processus (unique au processus)
-   **TTY** : **Type de terminal** utilisé par l'utilisateur
-   **TIME** : quantité de **CPU time** utilisée par le processus
-   **CMD** : La **commande** ou l'**exécutable** en cours d'exécution

```shell
$ ps
  PID TTY          TIME CMD
 2064 pts/3    00:00:00 sh
 2177 pts/3    00:00:00 ps
```

| Option        | Description                                  |
| ------------- | -------------------------------------------- |
| **`ps -A`**   | Donne tous les processus en cour d'execution |
| **`ps axjf`** | Affiche une arborescense des processus       |
| **`ps aux`**  | Affiche les processus de tous les utilisateurs                                             |


## __env__

La commande **`env`** affiche toutes les **variables d'environnements** de la machine.

```shell
$ env
MAIL=/var/mail/karen
USER=karen
SSH_CLIENT=10.10.148.226 50742 22
HOME=/home/karen
SSH_TTY=/dev/pts/3
QT_QPA_PLATFORMTHEME=appmenu-qt5
LOGNAME=karen
TERM=xterm
XDG_SESSION_ID=2
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
XDG_RUNTIME_DIR=/run/user/1001
LANG=en_US.UTF-8
SHELL=/bin/sh
PWD=/
SSH_CONNECTION=10.10.148.226 50742 10.10.179.158 22
```


## __sudo -l__

La commande **`sudo -l`** liste les commandes que l'utilisateur peut effectuer en sudoer.

