
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

Sur mach

### Reseau B

Sur machine C:

```shell
$ sudo ifconfig ens33 172.17.1.1 netmask 255.255.0.0
$ ifconfig
```