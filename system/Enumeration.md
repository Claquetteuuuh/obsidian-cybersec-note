
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

La commande **`sudo -l`** liste les commandes que l'**utilisateur peut effectuer en sudoer**.


## __ls -la__

La commande **`ls -la`** **lister tous les fichiers** présent dans le répertoire, même les **fichiers caché**, ainsi que leurs **droits**.

```shell
$ ls -la
total 104
drwxr-xr-x  23 root root  4096 Jun 18  2021 .
drwxr-xr-x  23 root root  4096 Jun 18  2021 ..
drwxr-xr-x   2 root root  4096 Jun 18  2021 bin
drwxr-xr-x   3 root root  4096 Jun 18  2021 boot
drwxrwxr-x   2 root root  4096 Jun 18  2021 cdrom
drwxr-xr-x  13 root root  3920 Apr 17 15:05 dev
drwxr-xr-x 129 root root 12288 Apr 17 15:06 etc
drwxr-xr-x   3 root root  4096 Jun 18  2021 home
lrwxrwxrwx   1 root root    33 Jun 18  2021 initrd.img -> boot/initrd.img-3.13.0-24-generic
drwxr-xr-x  23 root root  4096 Jun 18  2021 lib
drwxr-xr-x   2 root root  4096 Apr 16  2014 lib64
drwx------   2 root root 16384 Jun 18  2021 lost+found
drwxr-xr-x   2 root root  4096 Apr 16  2014 media
drwxr-xr-x   2 root root  4096 Apr 10  2014 mnt
drwxr-xr-x   2 root root  4096 Apr 16  2014 opt
dr-xr-xr-x 150 root root     0 Apr 17 15:05 proc
drwx------   2 root root  4096 Jun 18  2021 root
drwxr-xr-x  22 root root   780 Apr 17 15:23 run
drwxr-xr-x   2 root root 12288 Jun 18  2021 sbin
drwxr-xr-x   2 root root  4096 Apr 16  2014 srv
dr-xr-xr-x  13 root root     0 Apr 17 15:05 sys
drwxrwxrwt   4 root root  4096 Apr 17 15:23 tmp
drwxr-xr-x  10 root root  4096 Apr 16  2014 usr
drwxr-xr-x  13 root root  4096 Apr 16  2014 var
lrwxrwxrwx   1 root root    30 Jun 18  2021 vmlinuz -> boot/vmlinuz-3.13.0-24-generic
```


## __id__

La commande **`id`** nous donne les **informations sur les droits** de l'utilisateur.

```shell
$ id
uid=1001(karen) gid=1001(karen) groups=1001(karen)
```


## __/etc/passwd__

Le fichier **`/etc/passwd`** nous donne la possibilité de voir simplements les **utilisateurs du systemes**.

```shell
$ cat /etc/passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
libuuid:x:100:101::/var/lib/libuuid:
syslog:x:101:104::/home/syslog:/bin/false
messagebus:x:102:106::/var/run/dbus:/bin/false
usbmux:x:103:46:usbmux daemon,,,:/home/usbmux:/bin/false
dnsmasq:x:104:65534:dnsmasq,,,:/var/lib/misc:/bin/false
avahi-autoipd:x:105:113:Avahi autoip daemon,,,:/var/lib/avahi-autoipd:/bin/false
kernoops:x:106:65534:Kernel Oops Tracking Daemon,,,:/:/bin/false
rtkit:x:107:114:RealtimeKit,,,:/proc:/bin/false
saned:x:108:115::/home/saned:/bin/false
whoopsie:x:109:116::/nonexistent:/bin/false
speech-dispatcher:x:110:29:Speech Dispatcher,,,:/var/run/speech-dispatcher:/bin/sh
avahi:x:111:117:Avahi mDNS daemon,,,:/var/run/avahi-daemon:/bin/false
lightdm:x:112:118:Light Display Manager:/var/lib/lightdm:/bin/false
colord:x:113:121:colord colour management daemon,,,:/var/lib/colord:/bin/false
hplip:x:114:7:HPLIP system user,,,:/var/run/hplip:/bin/false
pulse:x:115:122:PulseAudio daemon,,,:/var/run/pulse:/bin/false
matt:x:1000:1000:matt,,,:/home/matt:/bin/bash
karen:x:1001:1001::/home/karen:
sshd:x:116:65534::/var/run/sshd:/usr/sbin/nologin
```

