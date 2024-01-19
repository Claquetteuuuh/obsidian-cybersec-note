
Les instructions **CPU** sont en **HEXADECIMAL**, pour les traduire en langage humain on utilise des langages d’assemblage :
- **NASM**, Netwide Assembler
- **MASM**, Microsoft Macro Assembleur

![[machine_asm.png]]

# ISA

Chaque processeur a **sa propre architecture à jeu d'instructions** (Instruction Set Architecture), **ISA**.

L’ISA est ce qu’un **programmeur peut voir** (Mémoire, registre, instruction) c’est ce dont un développeur **a besoin pour écrire en langage machine**.
- L’ISA x86 communique avec les processeurs 32 bits*
- L’ISA x64 communique avec les processeurs 64 bits

\*Le nombre de bit fait référence au nombre de registres ( un registre est une variable temporaire utilisée par le CPU pour stocker des donnés )

# Les Registres

Il existe **2 types de registres**:
- Ceux qui ont des fonctions spécifiques
- Ceux qui sont utilisés pour du Data Storage
Il y a des conventions de nommage pour ces registres :
- Les registres **8 bits** sont composés soit de Low bytes « *L* » ou de High bytes « *H* » ( écrit à la fin du nom du registre )
- Les registres **16 bits** combinent les 2 cités précédemment et commencent par un « *X* »
- Les registres **32 bits** rajoutent un « *E* » au début du nom du registre
- Les **64 bits** remplacent le « E » par un « *R* »

![[register_name.png]]

En plus des 8 registres précédents, il y a aussi le registre **EIP** (Instruction Pointer) qui pointe vers la **prochaine instruction à effectuer**.

# Mémoire

La mémoire est organisée de cette manière :
Le CPU est **divisé en 4 régions** :
- **Texte**, contient les instructions (read only)
- **Donnée**, contient les **données initialisées** et non initialisées, les données initialisées correspondent au variable **globale** et **statique**. **Les données non initialisées** sont appelées **BSS**
- **Le Tas**, il sert à demander plus de mémoire avec les commandes **brk** et **sbrk** (utilisé par malloc, realloc et free), c’est **l’espace destiné à la mémoire dynamique**
- **La Pile**, c’est la partie la plus importante, elle fonctionne en **LIFO (Last In First Out)** elle est stockée là où il y a le plus de mémoire et fonctionne comme un Array. Le **registre ESP (Stack Pointer)** sert à identifier le haut de la pile et il change à chaque fois qu’une valeur est **ajoutée (Push)** ou qu’une valeur est **retirée (Pop)**

# La pile

Contrairement à ce qu’on peut penser, **les adresses** de la pile n’augmentent pas vers le haut mais **augmentent vers le bas**.

Si on veut ajouter une adresse mémoire on va descendre de 4 bits ou 8 bits selon l’architecture du processeur :
- **4 bits** pour du **x86**
- **8 bits** pour du **x64**
- 
Exécution d’une commande **PUSH**:
- Instruction donnée au processeur : **PUSH**, **soustrait 4 ou 8 bits du ESP** et écrit les données sans les adresses
- Procédé du PUSH : Le **PUSH** est exécuté et le **ESP change**, si le PUSH **ne soustrait pas** les données, l’opération va **écraser les donnés** présentes et elles **seront perdues**
- Le **ESP** devient le nouveau **haut du tas**

![[push.png]]

Pour la commande **POP** c’est l’exacte inverse, le **ESP** sera **incrémenté** de **4** ou **8 bits**

![[pop.png]]

Lorsqu’une donnée est retirée de la pile, elle n’est pas supprimée, et restera dans la pile jusqu’à ce qu’une donnée vient l’écraser.

# Les fonctions

Les **fonctions** et les **procédures altèrent** le fonctionnement normal de **la pile** et **rendent le contrôle** une fois celles-ci terminées. De cette situation en découlent 2 notions: 
- **Le prologue**, il permet de préparer la pile à être utilisée et peut être vue comme un marque page
- L’**épilogue**, il permet de remettre la pile au paramètre du prologue

Lorsqu’une fonction/procédure est lancée, une **trame de la pile** (stack frame) est créée et **assignée à l’endroit pointé par L’ESP** (le haut de la pile), cela permet à la **subroutine** de fonctionner **indépendamment** dans la pile.

Quand la subroutine est terminée il se passe 2 choses:
- Le programme reçois les paramètres de **sortie renvoyés**
- L’EIP (pointeur d’instruction) est **remis à l’endroit initial** avant l’appel de la subroutine

![[basic_c_prog.png]]

On peut résumer l’exécution de ce programme par ce schéma

![[prologue.png]]

# Le Buffer overflow

Lorsque la fonction **main()**, appelée par l’OS, sont appelés à leur tour le **CPU push**, le contenu de L’**EIP** dans la pile et ils **pointent sur le premier octet** après l’appel. *Cette étape est importante car on a besoin de récupérer **l’adresse de la prochaine** instruction une fois que la fonction est terminée*.

Le **Caller** (l’instruction appelante) **perds le contrôle** et le **Callee** (la fonction appelée) **prend le controle**. 

![[buffer_of.png]]

Une fois dans la **fonction main()**, un nouveau **Stack Frame est créé**, il est défini par le **EBP** (Base Pointer) et le **ESP** (Stack Pointer) car on ne veut **pas perdre les informations** de l’ancien Stack Framev : on doit donc **sauvegarder l’EBP actuel dans la pile**. Si on ne le fais pas, une fois la fonction terminée on ne saura pas quelles sont les information de l’ancienne Stack Frame. Une fois ces infos stockées, l’**EBP est actualisé** et pointe vers le **haut de la pile**.

# Comment les valeurs sont stockées ?

# Prologue

En fait **L’EBP** est mis à la **valeur de l’ESP** au début de la fonction et **garde la même valeur** là ou **l’ESP**, lui, **va changer** de valeur pendant la fonction. L’intérêt est de pouvoir retrouver là où étaient les données avant l’appel de la fonction.

```nasm
push ebp // sauvegarde l’ancien pointeur 
mov ebp, esp // copy la valeur d’ESP dans EBP 
sub esp, <number> // decremente l’ESP pour faire de la place
```

![[asm_prologue.png]]

Une fois le prologue terminé la pile ressemblera à ça :

Etant donné qu’on ne peut **pas push** les **variables** de la fonction car elles seraient en **haut de la pile**, on va **déplacer** les valeurs des variables dans une adresse **entre EBP** et **ESP**.

Exemple :
`MOV DWORD PTR SS : [ESP+], 0B`
Ici, la valeur 11 va être stockée à l’adresse ESP + qui est entre EBP et ESP.

![[ebp_esp_storage.png]]

Pour résumer, voici le processus d’un épilogue lors de l’appel de fonction:
- **Empiler** (PUSH) les paramètres de la fonction dans la pile
- **Appel** de la fonction
- **Exécution** du prologue
- **Allocation** des variables locales dans la pile
 
![[full_stack.png]]

# Comment les valeurs sont détruites ?

# Epilogue

Le but de l’Epilogue est :
- **Rendre** le contrôle au **Caller**
- **Remettre l’ESP** (stack pointer) sur la valeur **actuelle de l’EBP** (base pointer) pour restaurer sa valeur d’avant l’appel de la fonction, il **dépile** (POP) donc l’**EBP** pour **récupérer** sa valeur
- **Renvoyer** au Caller l’**EIP** (instruction pointer)

Exemple de code d’épilogue:

```nasm
mov esp, ebp // met la valeur d’EBP dans l’ESP
pop ebp // retire EBP de la pile
ret  // retire toutes les valeurs du haut de la pile jusqu’à l’ancien EIP et rends le contrôle au Caller, ret ne touche qu’à EIP et ESP
```

*/!\\ L’épilogue se lance même si la fonction ne comporte pas de return*

A la fin de l’épilogue, tout est restauré et le programme continue avec la prochaine instruction.

![[epilogue.png]]

# Représentation_des_bytes

Il y a 2 concepts à comprendre :
- Le **MSB**, c’est la plus grosse valeur, **l’octet le plus à gauche**. Pour 100₂ , le MSB est 1
- Le **LSB**, c’est la plus petite valeur, **l’octet le plus à droite**. pour 110₂ , le LSB est 0

Il y a 3 types de représentations (endianness) en voici 2 :
- **Big-endian**, dans cette représentation, le LSB est stocké à **la plus grande adresse mémoire** et le **MSB est à la plus basse**.![[big_endian.png]]
- **Little-endian**, ici le **LSB** est stocké à **la plus basse adresse mémoire** et le **MSB à la plus haute**![[little_endian.png]]

# BufferOverflow

Pour effectuer un **BufferOverflow**, on va s’aider des instructions **assembleur NOP**. Cette instruction ne fais rien donc le programme **passe à l’instruction suivante**. Cette instruction est représentée par la valeur **0x90**.

Le **NOP-sled** est donc une technique du BufferOverflow pour **descendre** jusqu’aux instructions qu’on veut **exécuter après le NOP-sled** car le BufferOverflow doit être à un **endroit spécifique** et avoir une **taille spécifique**.

## Méthode pour éviter le BufferOverflow

Il y a 3 méthodes pour éviter le BufferOverflow :
- **Adress Space Layout Randomization** (ASLR), consiste à **changer** systématiquement l’**adresse** où l’**exécutable sera stocké**. L’**ASLR** n’est **pas accessible à tous les modules**, cela crée des failles dans des programmes normalement sécurisés.
- **Data Execution Prevention** (DEP), est une sécurité qui **empêche les codes** qui ne sont **pas explicitement des exécutable d’être exécutés**.
- **Stack Cookies** (Canary), consiste à placer une valeur à côté de l’adresse de retour de la pile, le **prologue va charger une valeur** et **l’épilogue va vérifier** que cette valeur **reste intacte**. Si cette valeur n’est plus la même, il y a sûrement eu un **BufferOverflow** car celui-ci va **écraser les données**.

