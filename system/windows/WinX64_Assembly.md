
# Fonction

A l'**appelle d'une fonction** le registre **RBP** va prendre en valeur le **RSP** (haut de la pile) au moment de l'appelle afin de délimiter où la fonction commence.

## Paramètre

Le **premier paramètre** est transmit par **RCX**
Le **seconde** est transmit par **RDX**
Le **troisième** est transmit par **R8**
Le **quatrième** est transmit par **R9**

Et les **autres** sont transmis dans le **sens inverses** avec l'instruction **PUSH**.
On peut ensuite les **récupérer** dans des registres **R0 à 13**

```c
function(1,2,3,4,5,6,7,8)
```

```nasm
MOV RCX 0x1 ; Going left to right.
MOV RDX 0x2
MOV R8 0x3
MOV R9 0x4
PUSH 0x8 ; Now going right to left.
PUSH 0x7
PUSH 0x6
PUSH 0x5
CALL function
```

```asm
POP R10 ; = 5
POP R11 ; = 6
POP R12 ; = 6
POP R13 ; = 7
```

On peut maintenant les **récupérer de gauches à droite** dans cette ordre: RCX, RDX, R8, R9, R10, R11, R12, R13.

## Retour

On **retourne une valeur** avec l'instruction **`ret`** et cette valeur est **stocké** dans le registre **RAX**.