# Process
![[Pasted image 20250417115850.png]]
## User mode
### General
- Container that seperate applications from each other
- It manages Threads, Handles, Token, Memory
- IT doesn't run anything, the Thread that runs code
- Uniquely identified by its process ID (PID), not by its the executable file.
- If it get destroyed, another process will reuse its PID
- Each process have its own address space, its own threads, its own handle table, its own token, its own unique PID
- If the parent died, the process continue to run
- Integrity level: Low, medium, high, system. It define the level of action the process can perform on a system.
You can use **Process hacker** to see those informations.
### Integrity levels
#### Low Integrity
- The **least trust** level. Can only interact with other Low-integrity processes
- Can only write to specify low integrity locations like: **%USERPROFILE%\AppData\LocalLow** and limited access to **HKEY_CURRENT_USER**
#### Medium Integrity
- The **default level** for most user processes. Can interact with Medium and Low-Integrity processes.
- Can only write to user-owned folders **Document, Downloads, Desktop, AppData\Roaming** and only **HKEY_CURRENT_USER** registry
#### High Integrity
- This level is typically for applications running with administrative privileges. Can interact with High, medium, Low processes
- Can write to system directories C:\Windows, Program Files and full access to registry keys
#### System Integrity
- The highest Integrity level, reserved for the OS and it's core components, can interact with all integrity levels
- Full access to entire file system and registry
### Process protection levels
These levels are defined by two components:
- **Signer**: Who signed the process
- **Protection type**: Strength of protection
#### PS_PROTECTED_SYSTEM (0x72)
- **Signer**: WinSystem (7)
- **Protection Type**: Protected (2)
- **Purpose**: Highest protection for hypervisor-related processes
#### PS_PROTECTED_LSA_LIGHT (0x41)
- **Signer**: LSA (4)
- **Protection Type**: Protected Light (1)
- **Purpose**: Shields the Local Security Authority (LSASS) & Prevents credential theft
#### PS_PROTECTED_ANTIMALWARE_LIGHT (0x31)
- **Signer**: Antimalware (3)
- **Protection Type**: Protected Light (1)
- **Purpose**: Secures antivirus/antimalware software from tampering
### Mitigation Policies
- Process Mitigation Policies are security mechanisms implemented to **reduce the attack surface** and **protect against exploitation techniques**
- **Data Execution Prevention (DEP)**: Prevent code execution from non-executable memory regions
- **Address Space Layout Randomization (ASLR)**: Randomizes memory addresses of executables, DLLs and heaps to mitigate Return-Oriented Programming (ROP) and code reuse attacks
- **Control Flow Guard (CFG)**: Prevent memory corruption exploits
- **Signatures Restricted (Microsoft Only)**: Allows only Microsoft-Signed code to execute
- **Images Restricted**: Blocks loading executables/DLLs from network shares (SMB, WebDAV)
## Threads
- They **execute** code allowing current execution task
- Type:
	- **Main thread**: Execute the main function
	- **Threads Created by Code** (createThread): Executes specific functions or tasks defined by the programmer, running concurrently with main thread and other threads
	- **Worker threads**: perform cleanups, resource management...
- State:
	- **Waiting**: The thread is paused, awaiting an event or condition before it can continue execution
	- **Ready**: The thread is prepared to execute but is waiting for processor availability
	- **Running**: The thread is actively execution code on a processor
### Modes
- **Access Mode**:
	- **User mode**: The thread operates with **limited privileges**, interacting with user-space memory and executing user code. It uses the **user mode stack** during this mode
	- **Kernel mode**: The thread operates with **elevated privileges**, allowing direct interaction with hardware and system resources. When a thread switch to this mode it begins using the **kernel mode stack**
- **Thread stacks**:
	- **User mode stack**:
		- Resides in the **process's user space**.
		- Used for **local variables**, **function parameters** and **return address** during user mode execution
		- Start with small commited space, it **grow dynamically** as needed
	- **Kernel mode stack**:
		- **Reside in kernel space**
		- **Smaller** and fixed compared to the user mode stack (12KB on 32bit sys, 24KB on 64bit sys)
	- **Thread call stack**: list of function calls that shows the path the program took to reach the current point of execution
## User mode
### Table of handles
- Kernel exposes different type of objects for use by user mode process accessed indirectly through Handles.
- **Every process** has a **private handle** table to kernel objects.
- Each handle has a **unique Value**, a **Type**, a **Name**, and the **Access Mask**
![[Pasted image 20250416181037.png]]
### Token
- The Access Token **stores the default security context** of the process, including:
	- **User account and Groups** the process belongs to, defining **what resources it can access** based on its memberships and restrictions
	- **Privileges granted** to the process, indicating **what actions the process can perform**.
![[Pasted image 20250416181416.png]]
### Virtual Memory
- Virtual Memory address in **x64** user process is **128 TB** relative to each process, starting from:
	- **0x00000000 00000000 to 0x0007FFFF FFFFFFFF**
- Virtual Memory Pages by order:
	- USER_SHARED_DATA
	- PEB (Process Environment Block)
	- Stacks
	- Heaps
	- NLS & MUI files
	- Allocated Pages
	- Executable File Image
	- Module
![[Pasted image 20250416181814.png]]

- Virtual Memory Pages by **State**:
	- **Free**: Page not allocated
	- **Commited**: Allocated pages
	- **Reserved**: Pages with reserved address space for future use, not allocated yet
- Virtual Memory Pages by **Type**:
	- **Mapped**: Pages associated with files on disk
	- **Private**: Pages exclusive to a process
	- **Image**: Pages from executable files (.exe, .dll)
- Virtual Memory Pages by **Protection**:
	- R, RW, X, RWX, No access Guard
## Kernel mode
### General
- The kernel is a core component of the system. His goal is to:
	- **Manage** the actuel processes that are running
	- Make sure they have **separated memory space** 
	- Manage the **privileges** between those processes
- **Enforce security barriers** between processes
- **128 absolute TB** for System Address Space, **0xFFFF8000 00000000** to **0xFFFFFFFF FFFFFFFF**
- It track the state of the process during execution using **\_EPROCESS** structure
- **\_EPROCESS** is a kernel memory structure that describe a process
	- Image name, token, protection level, threads, memory
	- **Change accross** the windows **versions**, you can use **Vergilius project** to compare them
### EPROCESS Overview
To get the **address**: `!process 0 0 explorer.exe`
To get the **fields**: `dt nt!_eprocess <EPROCESS_addr>`

Interesting fields:
- UniqueProcessID (PID)
- ImageFileName => **Process comparaison**
- Token => **Privilege Escalation**
- Protection => **Bypass PPL**
- ActiveProcessLinks => **Enumerate processes**
- InheritedFromUniqueProcessId (PPID) => **Identify the parent**
- Peb
- ObjectTable => **Stores handles to kernel objects**
- SectionBaseAddress
- ThreadListHead => **Iterate the Threads**
### ActiveProcessLinks & Process Hiding
- **Double-linked list** that links all the processes in the OS together
	![[Pasted image 20250416084519.png]]
- Each process has its own **ActiveProcessLinks** that contains **Flink** and **Blink**, the Flink is pointing on the **ActiveProcessLinks** of the **next process** and Blink is pointing on the **ActiveProcessLinks** of the **previous process** 
	![[Pasted image 20250416084843.png]]
- To **hide cmd** process, we have to **unlink its ActiveProcessLinks** from that chain by making its **previous process ActiveProcessLinks's Flink** pointing to the **cmd next process ActiveProcessLinks**. And the **cmd next process ActiveProcessLinks's Blink** pointing to the cmd **previous process's ActiveProcessLink**
![[Pasted image 20250416183503.png]]
### Token
- Describes process's security context, of type \_EX_FAST_REF
- The Value field holds the tokens value
![[Pasted image 20250416183713.png]]
### Token & Privilege Escalation
![[Pasted image 20250416183753.png]]
### Token & EDR Downgrade
![[Pasted image 20250416184412.png]]
![[Pasted image 20250416184443.png]]
### Protection & LSASS dump
- The Process Protection level **resides in the Kernel as 1 byte value**, it's part of the **EPROCESS** structure under the protection field
- It's a combination of 8 bits (Type, Audit, Signer)
![[Pasted image 20250416184636.png]]
![[Pasted image 20250416184657.png]]

![[Pasted image 20250416184736.png]]
![[Pasted image 20250416185057.png]]
## Hide the process from proc explorer
### Get Offsets
#### ActiveProcessLinks
```
kd> dt nt!_eprocess ActiveProcessLinks
+0x448 ActiveProcessLinks: _LIST_ENTRY
```
#### Get the structure
```
kd> dt nt!_LIST_ENTRY
+0x000 Flink : Ptr64 _LIST_ENTRY
+0x008 Blink : Ptr64 _LIST_ENTRY
```
### Get process informations
```
kd> !process 0 0 cmd.exe
```
![[Pasted image 20250417094004.png]]
#### Get ActiveProcessLinks
![[Pasted image 20250417094415.png]]
### Overide the information
#### Previous activeProcessLinks Flink with next ActiveProcessLinks
![[Pasted image 20250417094646.png]]
#### Next activeProcessLinks Blink with previous ActiveProcessLinks
![[Pasted image 20250417094800.png]]
#### Current ActiveProcessLinks Flink with null same for Blink
![[Pasted image 20250417094902.png]]
## Privilege escalation with tokens
### Get Eprocess of cmd and system
![[Pasted image 20250417095241.png]]
### Get offset of the token
![[Pasted image 20250417095633.png]]
### Get token of system
![[Pasted image 20250417095655.png]]
### Change token value of CMD with System Token value
![[Pasted image 20250417095718.png]]
### Check if it worked
![[Pasted image 20250417095927.png]]
## Remove Lsass Protection
### Get Lsass informations
![[Pasted image 20250417100413.png]]
### Change the Level
![[Pasted image 20250417100440.png]]
## Vergilius project
https://www.vergiliusproject.com/kernels/x64
https://www.vergiliusproject.com/kernels/x64/windows-11/24h2/_EPROCESS
Is a tool where you can see the difference between all the kernel address in the windows version.

# PE Format
![[Pasted image 20250417115413.png]]
## DOS Header
- 1st 64 bytes of the file
- 1st **2 bytes** called **e_magic** it's value is **4D 5A** which is **"MZ"** in ASCII, represents the **DOS Header Signature**, it's used to check the validity of the PE
- Its last **4 bytes** called **e_lfanew**, tells where the **PE/NT Header** is located
## DOS stub
- Piece of code that runs **"This program cannot be run in DOS mode"** when the program is only compatible with DOS mode
## NT/PE Header
- Starts with **50 45 00 00** which is **"PE\0\0"** in ASCII representing the **PE signature**
- The **File Header** is the **next 20 bytes** of the PE file
	- contains some PE's properties like: architecture type of the computer, number of sections, some PE Characteristics, size of Optional Header.
- The **Optional Header** start just after the File Header, it contains some valuable informations like:
	- **Magic** field tells wheather an executable image is **32-bit or 64-bit**
	- **AddressOfEntryPoint** holds the RVA of the Entry Point
	- **SizeOfImage** indicates **size of the PE file** when it is loaded into the memory
	- **Subsystem** indicates the type of subsystem the file will use once loaded such as 0x3 = console, 0x2 = GUI

- The last member of the **Optional Header** is the **Data Directory** which is an array of **IMAGE_DATA_DIRECTORY** structures each of them represents something:
	- **Export Directory** at **index 0** representing the **functions and variables** that are **exported** from the executable
	- **Import Directory** at **index** 1 representing the addresses of functions **imported** from **other executable** files
## Section Headers
- Array of **IMAGE_SECTION_HEADER** structures and contains information related to the various sections available in the image of an executable file.
	- **SizeOfRawData** indicates size of a section in the file
	- **VirtualSize** indicates size of a section in memory
	- **VirtualAddress** indicates the RVA of the section in memory
	- **Characteristics** indicates the memory access rights for that section in memory (R, RW, RX, RWX)
## Sections
- Contains the Code and Data used to create the executable
- They have unique name
	- **.text**: 1st section, that contains the executable code, it's marked as **RX**
	- **.rdata**: contains read-only initilized data **(R)**
	- **.data**: contains initialized global and static variables that the program might modify during execution **(RW)**
	- **.reloc**: contains information about the address of relocation table **(R)**
	- **.rsrc**: resource section contains things like images
