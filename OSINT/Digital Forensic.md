
## __Document Metadata__

Les metadatas sont des informations qui se crée automatiquement lors de la création du fichier, on peut y trouver de multiples informations sur le fichier.

### Pdfinfo

Pdfinfo est une tool qui permet d'obtenir des informations sur des pdfs, pour l'installer il faut effectuer la commande **`sudo apt install poppler-utils`**.

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

