Le but du cracking est simplement de détourner un code de sa logique initial pour arriver à nos fins.
# Reconnaissance

Avant de commencer quoi que ce soit on va récupérer des informations sur le fichiers pour savoir comment s'y prendre.

## File

```shell
$ file crackme
crackme: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=b799eb348f3df15f6b08b3c37f8feb269a60aba7, not stripped
```

Ici les mots clés correspondent à:
- **ELF 32-bit**, veut dire que c'est un **executable linux** compilé sur **32 bits**
- **LSB**, veut dire que les données sont en **[Little-Endian](Architecture_Representation.md#Représentation_des_bytes)**
- **not stripped**, signifie que le **nom des fonctions** à été gardé tel qu'elle (ça nous est très utile pour le deboggage)

## Strings

```shell
$ strings crackme
/lib/ld-linux.so.2
libc.so.6
_IO_stdin_used
puts
printf
memset
strcmp
__libc_start_main
/usr/local/lib:$ORIGIN
__gmon_start__
GLIBC_2.0
PTRh
j3jA
[^_]
UWVS
t$,U
[^_]
Usage: %s password
super_secret_password
Access denied.
Access granted.
```

La commande **`strings`** affiche tous les strings contenu dans le code. Ici on peut par exemple lire que ce code semble checker un mot de passe.
