# Process
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
	