
# Fonctionnement

Windows fonctionne avec 2 modes, **user** et **kernel**.

Le mode **User** a des **permissions limitées**, il peut par exemple **lire les fichiers** ou gérer des **paramètres réseaux**, mais pour des **actions plus poussé** par exemple communiquer directement avec les composants, il doit **passer par une API**.

Le mode **kernel** peut lui **tout faire**, que ce soit **communiquer directement avec les composant** ou utiliser des **fonctions critique**.


## Architecture

Ceci est une image résumé du fonctionnement de l'architecture Windows.

![[Pasted image 20231214142013.png]]

