
Le Digital Forensic est complémentaire à l'[OSINT](Osint-Utils.md) lorsqu'on doit rechercher des informations.

## __Document Metadata__

Les metadatas sont **des informations relative au fichier** qui se crée automatiquement lors de la création du fichier, on peut y trouver de multiples informations sur le fichier.

### Pdfinfo

Pdfinfo est une tool qui permet d'obtenir des **informations sur des pdfs**, pour l'installer il faut effectuer la commande **`sudo apt install poppler-utils`**.

```shell
user@ip:~$ pdfinfo ransom-letter.pdf
Title:           Pay NOW
Subject:         We Have Gato
Author:          Ann Gree Shepherd
Creator:         Microsoft® Word 2016
Producer:        Microsoft® Word 2016
CreationDate:    Wed Feb 23 10:10:36 2022 CET
ModDate:         Wed Feb 23 10:10:36 2022 CET
Custom Metadata: no
Metadata Stream: yes
Tagged:          yes
UserProperties:  no
Suspects:        no
Form:            none
JavaScript:      no
Pages:           1
Encrypted:       no
Page size:       595.44 x 842.04 pts (A4)
Page rot:        0
File size:       71371 bytes
Optimized:       no
PDF version:     1.7
```


### Exiftool

Exiftool est une tool qui permet d'obtenir des **informations sur des images**, pour l'installer il faut effectuer la commande **`sudo apt install exiftool`**.

```shell
user@ip:~$ exiftool letter-image.jpg
ExifTool Version Number         : 12.40
File Name                       : letter-image.jpg
Directory                       : .
File Size                       : 124 KiB
File Modification Date/Time     : 2022:02:23 09:53:33+01:00
...
Light Value                     : 7.9
Lens ID                         : Canon EF 50mm f/1.8 STM
```

Etant donné qu'il y a souvent une **grosse quantité de donnée**, on peut les **filtrer** avec la commande **`grep`**.

```shell
user@ip:~$ exiftool letter-image.jpg | grep [mM]odel
Camera Model Name               : Canon EOS R6
Lens Model                      : EF50mm f/1.8 STM
Device Model                    :
Device Model Desc               : sRGB
```


### Analyse de système

voir [[Windows Register]]