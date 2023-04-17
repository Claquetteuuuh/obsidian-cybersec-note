
Une étape importante dans l'escalation de privilège est l'énumération des informations d'une machine.


## __Hostname__

La commande **`hostname`** permet de récupérer le **nom de la machine**. Cela peut nous permettre d'avoir des informations sur **son role dans le systeme** (ex: SQL-PROD-01).

```shell
$ hostname
wade7363
```


## __Uname -a__

La commande **`uname -a`** donne les infos sur le noyaux utilisé par le systeme.

```shell
$ uname -a
Linux wade7363 3.13.0-24-generic #46-Ubuntu SMP Thu Apr 10 19:11:08 UTC 2014 x86_64 x86_64 x86_64 GNU/Linux
```

