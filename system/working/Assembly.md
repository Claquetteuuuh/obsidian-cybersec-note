
## __MOV__

### Description

MOV sert à stocker des valeurs dans un registre. Cela peut être un nombre, une adresse mémoire.

### Usage

**MOV RX , \<VAL>**
 
```asm
MOV R0, #45    ; Stock 45 dans R0
MOV R1, #0x01  ; Stock l'adresse 0x01 dans R1
MOV R2, [R1]   ; Stock la valeur de l'adresse stocké dans R1 dans R2
```


## __LDR__

### Description

LDR sert à charger une valeur stocké à une adresse mémoire dans un registre.

### Usage

**LDR RX, \<ADR>**

```asm
MOV R0, #0x01
LDR R0, [R0]      ; Charge dans R0 la valeur à l'adresse 0x01
LDR R1, [10, #5]  ; Charge dans R1 la valeur à l'adresse 0x10 + 5
```


## __ADD__

### Description

ADD sert à stocker le resultat d'une addition dans un registre.

### Usage

**ADD RX, \<n1>, \<n2>**

```asm
ADD R0, #4, #2 ; Met le resultat de 4 + 2 dans R0
```


## __STR__

### Description

STR sert à stocker un registre dans une adresse mémoire.

### Usage

**STR RX, \<ADR>**

```asm
ADD R0, #4, #2
STR R0, 36208   ; Stock R0 à l'adresse 0x36208
```


## 
