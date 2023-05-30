
## __Creation de notre ip reseaux__

Faire les **branchement** sur les **switchs**

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

**Brancher**, **allumer** le **router** et faire le branchement **cable blanc sur FE 0/1** (reseau 2) ou **FE 0/0** (reseau 1).

Brancher le **cable bleu sur un port console** et à un **USB du pc**

### Config du router

Lancer **Tera Term sur le windows**

Choisir **SERIE : Port (choisir le port USB)**

Faire un ctrl C pour sortir de la configuration par defaut

Effectuer les commandes suivante :

- **`enable`** (entrée dans le routeur)
- (écrire le mot de passe)
- **`configure terminal`** (entrée dans le config)
- **`ip routing`**
- **`interface fastethernet 0/0`** (entrée dans le premier config-if ajout du 1er réseau)
- **`ip address 172.16.255.254 255.255.0.0`** (setup l'ip du router)
- **`no shutdown`**
- **`exit`** (sortie du config-if)
- **`interface fastethernet 0/1`** (entrée dans le deuxième config-if ajout du 2e réseau)
- **`ip address 172.17.255.254 255.255.0.0`**
- **`no shutdown`**
- **`exit`** (sortie du config-if)
- **`exit`** (sortie du config)
- **`disable`** (sortie du routeur)
- **`show ip interface brief`**
- **`ping 172.16.1.1`** (verification de la connection)
- **`ping 172.17.1.1`**

### Table de routage

Sur la machine A du reseau 1:

```shell
$ ip route del default
$ ip route add default via 172.16.255.254
```

Sur machine C du reseau 2:

```shell
$ ip route del default
$ ip route add default via 172.17.255.254
```

Verifier avec IP route

```shell
$ ip route
172.17.0.0/16 dev ens33 proto kernel scope link src 172.17.1.1
```

### Verification

Sur machine A :

```shell
$ ping 172.17.1.1
# doit marcher
```

Sur machine C:

```shell
$ ping 172.16.1.1
# doit marcher
```

On peut maintenant acceder au site web.

NOTE : SI ON A 3 ROUTER BIEN VERIFIER QUE LES IP DES ROUTERS SOIENT DIFFERENTE