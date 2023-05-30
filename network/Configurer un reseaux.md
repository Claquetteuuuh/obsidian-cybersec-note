
## __Creation de notre ip reseaux__

Faire les branchement sur les switchs

### Reseau A

Sur machine  A:

```shell
$ sudo ifconfig ens33 172.16.1.1 netmask 255.255.0.0
$ ifconfig
```

Sur machine B:

```shell
$ sudo ifconfig ens33 172.16.1.2 netmask 255.255.0.0
$ ifconfig
```

Sur machine B:

```shell
$ sudo wireshark
```

Sur machine A :

```shell
$ ping 172.16.1.2
# le ping doit fonctionner
```

### Reseau B

Sur machine C:

```shell
$ sudo ifconfig ens33 172.17.1.1 netmask 255.255.0.0
$ ifconfig
```

Sur machine D:

```shell
$ sudo ifconfig ens33 172.17.1.2 netmask 255.255.0.0
$ ifconfig
```

Sur machine C:

```shell
$ sudo wireshark
```

Sur machine D:

```shell
$ ping 172.17.1.1
# Le ping doit marcher
```


## __Router__

Brancher, allumer le router et faire le branchement cable blanc sur FE 0/1 (reseau 2) ou FE 0/0 (reseau 1).

Brancher le cable bleu sur un port console et à un USB du pc

### Config du router

Lancer Tera Term sur le windows

Choisir SERIE : Port (choisir le port USB)

Effectuer les commandes suivante :

- enable (entrée dans le routeur)
- (écrire le mot de passe)
- configure terminal (entrée dans le config)
- ip routing
- interface fastethernet 0/0 (entrée dans le premier config-if ajout du 1er réseau)
- ip address 172.1.1.1 255.255.255.0