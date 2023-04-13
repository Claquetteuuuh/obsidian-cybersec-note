
## __Reverse shell__

Pour setup un reverse shell avec socat c'est légèrement plus compliqué qu'avec netcat.

#### 1- Listener

Sur notre machine il faut effectuer la commande :

```shell
user@ip:~$ socat TCP-L:1345 -
```

Cette commande est équivalente à faire **`nc -vnlp 1234`**.

