
## __Creation de notre ip reseaux__

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

```