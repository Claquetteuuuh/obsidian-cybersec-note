![[Pasted image 20250316122624.png]]
## Control Unit
It get the instruction from the main memory. The address to the next instruction is stored in a register called **Instruction Pointer or IP**. 
In 32-bit systems it is called: EIP
In 64-bit systems it is called: RIP
## Arithmetic Logic Unit
It executes the instruction fetched from the Memory. The results of the executed instruction are then stored in either the Registers or the Memory.
## Registers
They are the CPU's storage.
They are generally much smaller than the main memory. It help save time in executing instructions by placing important data in direct access to the CPU.
## Memory
The Memory, also called Main Memory or Random Access Memory (RAM), contains all the code and data for a program to run.
## I/O devices
I/O devices or Input/Output devices are all other devices that interact with a computer. These devices include Keyboards, Mice, Displays, Printers, Mass storage devices like Hard Disks and USBs, etc.
# Registers
Registers are the CPU's storage medium. The CPU can access data from the registers quicker than any other storage medium.
The registers are divided into the following different types:
- Instruction Pointer
- General Purpose Registers
- Status Flag Registers
- Segment Registers
## The Instruction Pointer:
This is a register that contains the address of the next instruction to be executed by the CPU. It is also called the Program Counter.
16-bits: IP
32-bits: EIP
64-bits: RIP
## General purpose register

|Registre|Nom complet|Description brève|
|---|---|---|
|EAX/RAX|Accumulator Register|Stocke les résultats des opérations arithmétiques|
|EBX/RBX|Base Register|Stocke l'adresse de base pour référencer un décalage|
|ECX/RCX|Counter Register|Utilisé pour le comptage (boucles)|
|EDX/RDX|Data Register|Utilisé pour multiplication/division|
|ESP/RSP|Stack Pointer|Pointe vers le sommet de la pile|
|EBP/RBP|Base Pointer|Accède aux paramètres passés par la pile|
|ESI/RSI|Source Index|Utilisé pour les opérations sur les chaînes (source)|
|EDI/RDI|Destination Index|Utilisé pour les opérations sur les chaînes (destination)|
|R8-R15|General Purpose Registers|Registres supplémentaires en 64-bit|
## Tailles des registres

- Registres 64-bit : RAX, RBX, RCX, RDX, RSP, RBP, RSI, RDI, R8-R15
- Registres 32-bit : EAX, EBX, ECX, EDX, ESP, EBP, ESI, EDI, R8D-R15D
- Registres 16-bit : AX, BX, CX, DX, R8W-R15W
- Registres 8-bit : AL/AH, BL/BH, CL/CH, DL/DH, R8B-R15B

