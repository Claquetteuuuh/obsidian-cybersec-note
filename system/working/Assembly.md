## __Registres__

Les registres sont des endroits dans le processeur où l'on peut stocker des valeurs.

On dispose de **16 registres** en ARM.

| Registres         | Usages                                               |
| ----------------- | ---------------------------------------------------- |
| **R0 -> R6**      | nous servent à stocker des valeurs                   |
| **R7**            | stock des nombres SYSCALL                            |
| **R8 -> R10**     | utilisé pour FIQ                                     |
| **R11** ou **BP** | Base pointer                                         |
| **R12**           | Scratch registre                                     |
| **R13** ou **SP** | Stack pointer (haut de la pile)                      |
| **R14** ou **LR** | Link register (pointe vers la prochaine instruction) |
| **R15**           | Program counter                                                     |


## __Instruction__

### __MOV__

#### Description

MOV sert à stocker des valeurs dans un registre. Cela peut être un nombre, une adresse mémoire.

#### Usage

**MOV RX , \<VAL>**
 
```asm
MOV R0, #45    ; Stock 45 dans R0
MOV R1, #0x01  ; Stock l'adresse 0x01 dans R1
MOV R2, [R1]   ; Stock la valeur de l'adresse stocké dans R1 dans R2
```


### __LDR__

#### Description

LDR sert à charger une valeur stocké à une adresse mémoire dans un registre.

#### Usage

**LDR RX, \<ADR>**

```asm
MOV R0, #0x01
LDR R0, [R0]      ; Charge dans R0 la valeur à l'adresse 0x01
LDR R1, [10, #5]  ; Charge dans R1 la valeur à l'adresse 0x10 + 5
```


### __ADD__

#### Description

ADD sert à stocker le resultat d'une addition dans un registre.

#### Usage

**ADD RX, \<n1>, \<n2>**

```asm
ADD R0, #4, #2 ; Met le resultat de 4 + 2 dans R0
```


### __STR__

#### Description

STR sert à stocker un registre dans une adresse mémoire.

#### Usage

**STR RX, \<ADR>**

```asm
ADD R0, #4, #2
STR R0, 36208   ; Stock R0 à l'adresse 0x36208
```


### 


## __Exercices__

<u>

1)

```
MOV R0, #36
MOV R1, #24
ADD R2, R0, R1
```

2)

```
LDR R0, 36200
LDR R1, 36204
ADD R1, R1, R0
STR R1, 36208
```

3)
.1)

```
LDR R0, 60504
ADD R0, R0, #2
STR R0, 60504
```

.2)

```
MOV R1, #60504
LDR R0, [R1]
ADD R0, R0, #2
STR R0, [R1]
```

4)

```
MOV R0, #33
STR R0, [SP]
```

5)
```
`MOV R0, #9
STR R0, [SP, #8]
MOV R1, #7
STR R1, [SP, #4]
ADD R1, R1, R0
STR R1, [SP]
```

6)

```
MOV R0, #11
STR R0, [SP, #12]
SUB R1, R0, #22
STR R1, [SP, #8]
MOV R2, #33
STR R2, [SP, #4]
ADD R3, R1, #44
SUB R3, R3, R2
ADD R3, R3, R0
STR R3, [SP]
```

7)

```
MOV R0, #19
STR R0, [SP, #4]
MOV R1, [SP, #4]
STR R1, [SP]
MOV R0, #34
STR R0, [R1]
```

