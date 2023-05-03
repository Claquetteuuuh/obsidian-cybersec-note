
## __MOV__

### Description

MOV sert à stocker des valeurs dans un registre. Cela peut être un nombre, une adresse.

### Usage

**MOV RX , \<VAL>**
 
```asm
MOV R0, #45    ; Stock 45 dans R0
MOV R1, #0x01  ; Stock l'adresse 0x01 dans R1
MOV R2, [R1]   ; Stock la valeur de l'adresse stocké dans R1 dans R2
```


## __LDR__

### Description

LDR sert à charger une valeur stocké à une adresse dans un registre.

### Usage

**LDR RX, \<ADR>**

```asm
MOV R0, #0x01
LDR R0, [R0]
LDR R1, [10, ]
```

