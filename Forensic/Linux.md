# Information gathering
## Host information
### OS release
To get OS release information:
```bash
$ cat /etc/os-release
NAME="Ubuntu"
VERSION="20.04.6 LTS (Focal Fossa)"
ID=ubuntu
ID_LIKE=debian
PRETTY_NAME="Ubuntu 20.04.6 LTS"
VERSION_ID="20.04"
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
VERSION_CODENAME=focal
UBUNTU_CODENAME=focal
```
### Hostname
```bash
$ cat /etc/hostname
Linux4n6
```
### Timezone
```bash
$ cat /etc/timezone
Asia/Karachi
```
### Network configuration
```bash
$ cat /etc/network/interfaces
# interfaces(5) file used by ifup(8) and ifdown(8)
# Include files from /etc/network/interfaces.d:
source-directory /etc/network/interfaces.d
```

```bash
$ ip address show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 9001 qdisc mq state UP group default qlen 1000
    link/ether 02:e0:ff:6b:9c:d5 brd ff:ff:ff:ff:ff:ff
    inet 10.10.95.126/16 metric 100 brd 10.10.255.255 scope global dynamic eth0
       valid_lft 2691sec preferred_lft 2691sec
    inet6 fe80::e0:ffff:fe6b:9cd5/64 scope link 
       valid_lft forever preferred_lft forever
```
### Active network connections
```bash
$ netstat -natp
(Not all processes could be identified, non-owned process info
 will not be shown, you would have to be root to see it all.)
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name    
tcp        0      0 127.0.0.1:5901          0.0.0.0:*               LISTEN      979/Xtigervnc       
tcp        0      0 0.0.0.0:22              0.0.0.0:*               LISTEN      -                   
tcp        0      0 0.0.0.0:80              0.0.0.0:*               LISTEN      -                   
tcp        0      0 127.0.0.1:631           0.0.0.0:*               LISTEN      -                   
tcp        0      0 127.0.0.53:53           0.0.0.0:*               LISTEN      -                   
tcp        0     40 127.0.0.1:35186         127.0.0.1:5901          ESTABLISHED -                   
tcp        0      0 10.10.95.126:57476      172.31.65.242:443       ESTABLISHED -                   
tcp        0      1 10.10.95.126:55558      185.125.188.59:443      SYN_SENT    -                   
tcp        0      0 10.10.95.126:80         10.100.2.28:33306       ESTABLISHED -                   
tcp        0      1 10.10.95.126:35968      185.125.188.54:443      SYN_SENT 
```
### Running processes
```bash
$ ps aux
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.5  0.3 104068 13072 ?        Ss   22:39   0:05 /sbin/init
root           2  0.0  0.0      0     0 ?        S    22:39   0:00 [kthreadd]
root           3  0.0  0.0      0     0 ?        I<   22:39   0:00 [rcu_gp]
root           4  0.0  0.0      0     0 ?        I<   22:39   0:00 [rcu_par_gp]
root           5  0.0  0.0      0     0 ?        I<   22:39   0:00 [slub_flushwq
root           6  0.0  0.0      0     0 ?        I<   22:39   0:00 [netns]
root           8  0.0  0.0      0     0 ?        I<   22:39   0:00 [kworker/0:0H
root           9  0.0  0.0      0     0 ?        I    22:39   0:00 [kworker/u30:
root          10  0.0  0.0      0     0 ?        I<   22:39   0:00 [mm_percpu_wq
root          11  0.0  0.0      0     0 ?        S    22:39   0:00 [rcu_tasks_ru
root          12  0.0  0.0      0     0 ?        S    22:39   0:00 [rcu_tasks_tr
root          13  0.0  0.0      0     0 ?        S    22:39   0:00 [ksoftirqd/0]
root          14  0.0  0.0      0     0 ?        I    22:39   0:00 [rcu_sched]
root          15  0.0  0.0      0     0 ?        S    22:39   0:00 [migration/0]
root          16  0.0  0.0      0     0 ?        S    22:39   0:00 [idle_inject/
root          18  0.0  0.0      0     0 ?        S    22:39   0:00 [cpuhp/0]
root          19  0.0  0.0      0     0 ?        S    22:39   0:00 [cpuhp/1]
root          20  0.0  0.0      0     0 ?        S    22:39   0:00 [idle_inject/
root          21  0.0  0.0      0     0 ?        S    22:39   0:00 [migration/1]
root          22  0.0  0.0      0     0 ?        S    22:39   0:00 [ksoftirqd/1]
root          23  0.0  0.0      0     0 ?        I    22:39   0:00 [kworker/1:0-
root          24  0.0  0.0      0     0 ?        I<   22:39   0:00 [kworker/1:0H
```
### DNS information
```bash
$ cat /etc/hosts
127.0.0.1 localhost

# The following lines are desirable for IPv6 capable hosts
::1 ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
ff02::3 ip6-allhosts
```

```bash
$ cat /etc/resolv.conf 
# This file is managed by man:systemd-resolved(8). Do not edit.
#
# This is a dynamic resolv.conf file for connecting local clients to the
# internal DNS stub resolver of systemd-resolved. This file lists all
# configured search domains.
#
# Run "resolvectl status" to see details about the uplink DNS servers
# currently in use.
#
# Third party programs must not access this file directly, but only through the
# symlink at /etc/resolv.conf. To manage man:resolv.conf(5) in a different way,
# replace this symlink by a static file or a different symlink.
#
# See man:systemd-resolved.service(8) for details about the supported modes of
# operation for /etc/resolv.conf.

nameserver 127.0.0.53
options edns0 trust-ad
search eu-west-1.compute.internal
```
## User informations
### User accounts
You can use the `/etc/passwd` file to get informations about the user accounts on the linux system.
```bash
$ cat /etc/passwd| column -t -s :
root                  x  0      0      root                                /root                    /bin/bash
daemon                x  1      1      daemon                              /usr/sbin                /usr/sbin/nologin
bin                   x  2      2      bin                                 /bin                     /usr/sbin/nologin
sys                   x  3      3      sys                                 /dev                     /usr/sbin/nologin
```
You can see that the password is: `x` that tell us that the password are stored in `/etc/shadow`
### Group information
To get the information about different user groups present on the host.
```bash
$ cat /etc/group
root:x:0:
daemon:x:1:
bin:x:2:
sys:x:3:
adm:x:4:syslog,ubuntu
tty:x:5:syslog
disk:x:6:
lp:x:7:
mail:x:8:
news:x:9:
uucp:x:10:
man:x:12:
proxy:x:13:
kmem:x:15:
```
### Sudoers list
To get the list of sudoers you can use the `/etc/sudoers`
```bash
$ sudo cat /etc/sudoers
#
# This file MUST be edited with the 'visudo' command as root.
#
# Please consider adding local content in /etc/sudoers.d/ instead of
# directly modifying this file.
#
# See the man page for details on how to write a sudoers file.
#
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

# Host alias specification

# User alias specification

# Cmnd alias specification

# User privilege specification
root	ALL=(ALL:ALL) ALL

# Members of the admin group may gain root privileges
%admin ALL=(ALL) ALL

# Allow members of group sudo to execute any command
%sudo	ALL=(ALL:ALL) ALL

# See sudoers(5) for more information on "#include" directives:

#includedir /etc/sudoers.d
```
### Login information
`/var/log/btmp` contains information about failed logins.
`var/log/wtmp` keeps historical data of logins.

```bash
$ sudo last -f /var/log/wtmp
reboot   system boot  5.15.0-1075-aws  Thu Apr 10 22:39   still running
ubuntu   pts/0        10.11.102.213    Sun Feb  9 19:36 - crash (60+03:02)
reboot   system boot  5.15.0-1075-aws  Sun Feb  9 19:36   still running
ubuntu   pts/0        10.11.102.213    Sun Feb  9 19:25 - 19:35  (00:09)
reboot   system boot  5.4.0-1029-aws   Sun Feb  9 19:23 - 19:35  (00:11)
reboot   system boot  5.4.0-1029-aws   Sun Apr 17 21:00 - 19:35 (1028+22:34)
reboot   system boot  5.4.0-1029-aws   Sun Apr 17 20:50 - 21:00  (00:10)
reboot   system boot  5.4.0-1029-aws   Sun Apr 17 09:40 - 09:43  (00:03)
reboot   system boot  5.4.0-1029-aws   Sun Apr 17 05:01 - 09:23  (04:22)
reboot   system boot  5.4.0-1029-aws   Sat Apr 16 22:51 - 23:10  (00:18)
reboot   system boot  5.4.0-1029-aws   Sat Apr 16 20:10 - 21:43  (01:32)

wtmp begins Sat Apr 16 20:10:29 2022
```
### Authentication logs
Every user that authenticates on Linux is logged in the `/var/log/auth.log` file
```bash
$ cat /var/log/auth.log |tail
Apr 10 22:39:55 Linux4n6 dbus-daemon[554]: [system] Failed to activate service 'org.bluez': timed out (service_start_timeout=25000ms)
Apr 10 22:45:55 Linux4n6 sudo:   ubuntu : TTY=pts/0 ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/cat /etc/sudoers
Apr 10 22:45:55 Linux4n6 sudo: pam_unix(sudo:session): session opened for user root by (uid=0)
Apr 10 22:45:55 Linux4n6 sudo: pam_unix(sudo:session): session closed for user root
Apr 10 22:48:19 Linux4n6 sudo:   ubuntu : TTY=pts/0 ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/last -f /var/log/wtmp
Apr 10 22:48:19 Linux4n6 sudo: pam_unix(sudo:session): session opened for user root by (uid=0)
Apr 10 22:48:19 Linux4n6 sudo: pam_unix(sudo:session): session closed for user root
Apr 10 22:48:31 Linux4n6 sudo:   ubuntu : TTY=pts/0 ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/last -f /var/log/wtmp
Apr 10 22:48:31 Linux4n6 sudo: pam_unix(sudo:session): session opened for user root by (uid=0)
Apr 10 22:48:31 Linux4n6 sudo: pam_unix(sudo:session): session closed for user root
```
## Persistance Mechanisms
### Cron jobs
This store commands that run periodically after a set amount of time.
```bash
$ cat /etc/crontab 
# /etc/crontab: system-wide crontab
# Unlike any other crontab you don't have to run the `crontab'
# command to install the new version when you edit this file
# and files in /etc/cron.d. These files also have username fields,
# that none of the other crontabs do.

SHELL=/bin/sh
PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin

# Example of job definition:
# .---------------- minute (0 - 59)
# |  .------------- hour (0 - 23)
# |  |  .---------- day of month (1 - 31)
# |  |  |  .------- month (1 - 12) OR jan,feb,mar,apr ...
# |  |  |  |  .---- day of week (0 - 6) (Sunday=0 or 7) OR sun,mon,tue,wed,thu,fri,sat
# |  |  |  |  |
# *  *  *  *  * user-name command to be executed
17 *	* * *	root    cd / && run-parts --report /etc/cron.hourly
25 6	* * *	root	test -x /usr/sbin/anacron || ( cd / && run-parts --report /etc/cron.daily )
47 6	* * 7	root	test -x /usr/sbin/anacron || ( cd / && run-parts --report /etc/cron.weekly )
52 6	1 * *	root	test -x /usr/sbin/anacron || ( cd / && run-parts --report /etc/cron.monthly )
#
```
### Service startup
Here is the services that run in background once the host is started.
```bash
$ ls /etc/init.d/
acpid             hddtemp            plymouth-log
alsa-utils        hibagent           pppd-dns
anacron           hwclock.sh         procps
apparmor          irqbalance         pulseaudio-enable-autospawn
apport            iscsid             rsync
atd               kerneloops         rsyslog
avahi-daemon      keyboard-setup.sh  saned
bluetooth         kmod               screen-cleanup
console-setup.sh  lightdm            speech-dispatcher
cron              lvm2               spice-vdagent
cryptdisks        lvm2-lvmpolld      ssh
cryptdisks-early  network-manager    udev
cups              networking         ufw
cups-browsed      open-iscsi         unattended-upgrades
dbus              open-vm-tools      uuidd
gdm3              openvpn            whoopsie
grub-common       plymouth           x11-common
```
### .Bashrc
When a bash shell is spawned it run the command stored in this file. 
This can be considered as a startup list of actions to be performed.
```bash
$ cat ~/.bashrc
# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac
```
## Evidence of execution
### Sudo execution history
```bash
$  cat /var/log/auth.log* |grep -i COMMAND|tail
Apr 10 22:39:29 Linux4n6 sudo:   ubuntu : TTY=unknown ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/sbin/runuser -l ubuntu -c vncserver :1 -depth 24 -geometry 1900x1200
Apr 10 22:39:29 Linux4n6 sudo:   ubuntu : TTY=unknown ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/python3 -m websockify 80 localhost:5901 -D
Apr 10 22:45:55 Linux4n6 sudo:   ubuntu : TTY=pts/0 ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/cat /etc/sudoers
Apr 10 22:48:19 Linux4n6 sudo:   ubuntu : TTY=pts/0 ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/last -f /var/log/wtmp
Apr 10 22:48:31 Linux4n6 sudo:   ubuntu : TTY=pts/0 ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/last -f /var/log/wtmp
Apr 10 22:51:37 Linux4n6 sudo:   ubuntu : TTY=pts/0 ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/last -f /var/log/wtmp
Binary file (standard input) matches
```
### Bash history
```bash
$ cat ~/.bash_history
ls -a
ls -al
unlink .bash_history
ls -a
rm -rf bash_logout
history -w
ls -a
ls -al
unlink .bash_history
ls -a
rm -rf bash_logout
history -w
ls -a
cat .bash_history 
sudo adduser tryhackme
cat /etc/passwd
last -f /var/log/btmp 
sudo last -f /var/log/btmp 
sudo last -f /var/log/wtmp 
vncpasswd
netstat -natp
cat /etc/passwd
sudo vim /etc/hostname
cat .bash_history
sudo apt-get install net-tools
netstat -natp
sudo last -f /var/log/wtmp
sudo dpkg-reconfigure tzdata 
sudo reboot
sudo su
cat /etc/passwd| column -t -s :
```
### Files accessed using vim
```bash
$ cat ~/.viminfo
# This viminfo file was generated by Vim 8.1.
# You may edit it if you're careful!

# Viminfo version
|1,4

# Value of 'encoding' when this file was written
*encoding=latin1


# hlsearch on (H) or off (h):
~h
# Last Search Pattern:
~Msle0~/\<startxfce4\>
(...)
|3,0,4,1,16,0,1645972192,"#!/bin/bash","","unset SESSION_MANAGER","unset DBUS_SESSION_BUS_ADDRESS","","xrdb $HOME/.Xresources","xsetroot -solid grey","","vncconfig -nowin&","","export SHELL=/bin/bash","","export XKL_XMODMAP_DISABLE=1","export XDG_RUNTIME_DIR=/home/$USER/.cache/xdg","export XDG_SESSION_TYPE=x11","#/etc/X11/Xsession"

# File marks:
'0  1  0  /var/log/syslog
|4,48,1,0,1650211844,"/var/log/syslog"
'1  133  0  /etc/cloud/cloud.cfg
|4,49,133,0,1645984005,"/etc/cloud/cloud.cfg"
'2  15  13  ~/.vnc/xstartup
|4,50,15,13,1645974934,"~/.vnc/xstartup"
'3  13  16  ~/.vnc/xstartup
```
## Log files
### Syslog
It contains message that are recorded by the host about system activity.
```bash
$  cat /var/log/syslog* | head
Apr 10 22:39:29 Linux4n6 rsyslogd: [origin software="rsyslogd" swVersion="8.2001.0" x-pid="576" x-info="https://www.rsyslog.com"] rsyslogd was HUPed
Apr 10 22:39:29 Linux4n6 dbus-daemon[554]: [system] Successfully activated service 'org.freedesktop.hostname1'
Apr 10 22:39:29 Linux4n6 systemd[1]: Started Hostname Service.
Apr 10 22:39:29 Linux4n6 NetworkManager[555]: <info>  [1744306769.2689] hostname: hostname: using hostnamed
Apr 10 22:39:29 Linux4n6 NetworkManager[555]: <info>  [1744306769.2692] hostname: hostname changed from (none) to "Linux4n6"
Apr 10 22:39:29 Linux4n6 NetworkManager[555]: <info>  [1744306769.2698] dns-mgr[0x55b9d75c3290]: init: dns=systemd-resolved rc-manager=symlink, plugin=systemd-resolved
Apr 10 22:39:29 Linux4n6 NetworkManager[555]: <info>  [1744306769.2709] manager[0x55b9d75e0020]: rfkill: Wi-Fi hardware radio set enabled
Apr 10 22:39:29 Linux4n6 NetworkManager[555]: <info>  [1744306769.2716] manager[0x55b9d75e0020]: rfkill: WWAN hardware radio set enabled
Apr 10 22:39:29 Linux4n6 NetworkManager[555]: <info>  [1744306769.3041] Loaded device plugin: NMWwanFactory (/usr/lib/x86_64-linux-gnu/NetworkManager/1.22.10/libnm-device-plugin-wwan.so)
Apr 10 22:39:29 Linux4n6 snapd[582]: overlord.go:274: Acquiring state lock file
```
### Auth logs
```bash
$ cat /var/log/auth.log* |head
Apr 10 22:39:29 Linux4n6 CRON[841]: pam_unix(cron:session): session opened for user ubuntu by (uid=0)
Apr 10 22:39:29 Linux4n6 CRON[842]: pam_unix(cron:session): session opened for user ubuntu by (uid=0)
Apr 10 22:39:29 Linux4n6 sudo:   ubuntu : TTY=unknown ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/sbin/runuser -l ubuntu -c vncserver :1 -depth 24 -geometry 1900x1200
Apr 10 22:39:29 Linux4n6 sudo:   ubuntu : TTY=unknown ; PWD=/home/ubuntu ; USER=root ; COMMAND=/usr/bin/python3 -m websockify 80 localhost:5901 -D
Apr 10 22:39:29 Linux4n6 sudo: pam_unix(sudo:session): session opened for user root by (uid=0)
Apr 10 22:39:29 Linux4n6 sudo: pam_unix(sudo:session): session opened for user root by (uid=0)
Apr 10 22:39:29 Linux4n6 systemd: pam_unix(systemd-user:session): session opened for user ubuntu by (uid=0)
Apr 10 22:39:30 Linux4n6 runuser: pam_unix(runuser-l:session): session opened for user ubuntu by (uid=0)
Apr 10 22:39:30 Linux4n6 sudo: pam_unix(sudo:session): session closed for user root
Apr 10 22:39:30 Linux4n6 CRON[841]: pam_unix(cron:session): session closed for user ubuntu
```
### Third-party logs
The third-party application such as webserver store logs too.
```bash
$  ls /var/log
Xorg.0.log             dmesg                   kern.log.3.gz
Xorg.0.log.old         dmesg.0                 landscape
alternatives.log       dmesg.1.gz              lastlog
alternatives.log.1     dmesg.2.gz              lightdm
alternatives.log.2.gz  dmesg.3.gz              openvpn
amazon                 dmesg.4.gz              prime-offload.log
apt                    dpkg.log                prime-supported.log
auth.log               dpkg.log.1              private
auth.log.1             dpkg.log.2.gz           samba
auth.log.2.gz          fontconfig.log          speech-dispatcher
auth.log.3.gz          gdm3                    syslog
btmp                   gpu-manager-switch.log  syslog.1
btmp.1                 gpu-manager.log         syslog.2.gz
cloud-init-output.log  hp                      syslog.3.gz
cloud-init.log         journal                 ubuntu-advantage.log
cloud-init.log.1       kern.log                unattended-upgrades
cups                   kern.log.1              wtmp
dist-upgrade           kern.log.2.gz
```