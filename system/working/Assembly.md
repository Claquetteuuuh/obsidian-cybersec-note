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


### __LSL__

#### Description

LSL decale la valeur de n bit vers la gauche en binaire, soit elle multiplie par une puissance de 2.

#### Usage

**LSL RX, RX, \#n**

```
LSL R0,R0,#2 ; Stock dans R0 le resultat de R0 * 4
```


### __CMP__

#### Description

CMP effectue une comparaison entre 2 nombres en faisant une soustraction. Il est suivis d'une [instruction](Assembly##__Condition__) (BEQ, BNE ...)

#### Usage

**CMP RX, n**
**Bxx suite** 
	**code du cas ou c'est pas Bxx**
**BAL must**
	**etiquette else**
**suite :**
	**si c'est Bxx**

## __Condition__

**Z** signifie que le **resultat** de l'opération **= 0**
**N** signifie que le **resultat** est **negatif**
**V** signifie qu'il y a un **depassement**

| Condition    | Resultat               | Z      | N      | V   | Instruction |
| ------------ | ---------------------- | ------ | ------ | --- | ----------- |
| (R1) = (R0)  | (R1) - (R0) = 0        | 1      | 0      | 0   | BEQ         |
| (R1) != (R0) | (R1) - (R0) != 0       | 0      | x      | 0   | BNE         |
| (R1) < (R0)  | (R1) - (R0) < 0        | 0      | 1      | 0   | BLT         |
| (R1) > (R0)  | (R1) - (R0) > 0        | 0      | 0      | 0   | BGT         |
| (R1) <= (R0) | (R1) - (R0) < 0 ou = 0 | 0 ou 1 | 1 ou 0 | 0   | BLE         |
| (R1) >= (R0) | (R1) - (R0) > 0 ou = 0 | 0 ou 1 | 0      | 0   | BGE            |

## __Exercices__

<u>Partie 1</u>

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

<u>Partie 2 - Tableau</u> 

1)

```
MOV R0, #5
STR R0, [SP, #12]
MOV R0, #9
STR R0, [SP]
LDR R0, [SP, #16]
STR R0, [SP, #4]
```

2)

```
LDR R0, [SP, #28]
LDR R1, [SP, #4]
LDR R2, [SP]
ADD R0, R0, R1
STR R0, [SP, #8]
LDR R0, [SP, #20]
LDR R1, [SP, #24]
ADD R2, R0, R1
STR R2, [SP]
```

3)

```c
int tab[100];
int x = 33;

tab[x] = tab[x + 8];
```

```
MOV R0, #33
STR R0, [SP]
LSL R1, R0, #2
ADD R2, R0, #8
LSL R2, R2, #2
MOV R3, [SP, R2]
STR R3, [R1]
```

ou

```
MOV R0,#33
LDR R0,[SP]
LSL R1,R0,#2
ADD R2,R0,#8
LSL R2,R2,#2
ADD R3,SP,#4
LDR R3,[R3,R2]
STR R4,[R3,R1]
```

<u>Partie 3 - if tous ca</u>

2)

```c
int x,y;

if(x < 28){
	y=54;
}
x = 73;
```

```
LDR R0,[SP,#4]
CMP R0,#28
BGE suite
    MOV R0,#54
    STR R0,[SP]
suite:
    MOV R0,#73
    STR R0,[SP,#4]

```

3)

```c
int x,y;
if(x != y){
	y = 54;
}else{
	y = 28;
}
x = 73;
```

```
LDR R0, [SP, #4]
LDR R1, [SP]

CMP R0, R1
BNE else
	MOV R1, #54
	STR R1, [SP]
BAL suite
	else: 
		MOV R1, #28
		STR R1, [SP]
suite :
	MOV R0, #73
	STR R1, [SP, #4]
```

4)

```c
int x,y,z;
x = 0;
while(x < 100){
	y+=z;
	x+=3;
}
z = y+9;
```

```
MOV R0, #0
STR R0, [SP, #8]
LDR R0, [SP, #8]
LDR R1, [SP, #4]
LDR R2, [SP]

boucle:	
	CMP R0, #100
	BGE suite
		ADD R1, R1, R2
		STR R1, [SP, #4]
		ADD R0, R0, #3
		STR R0, [SP, #8]
		BAL boucle
suite:
ADD R2, R1, #9
STR R2, [SP]
```

5)

```c
int x = 7, i;
for(i = 0; i<1000;i++){
	x+=i;
}
int z = x + 3;
```

```
MOV R0, #7
STR R0, [SP, #8]
MOV R1, #0
STR R1, [SP, #4]

boucle:
	CMP R1, #1000
	BGE suite
		ADD R0, R0, R1
		STR R0, [SP, #8]
		ADD R1, R1, #1
		STR R1, [SP, #4]
		BAL boucle
suite:
ADD R2, R0, #3
STR R2, [SP]
```

6)

```
MOV R0, #36
STR R0, [SP, #4]
MOV R1, #0
STR R
```