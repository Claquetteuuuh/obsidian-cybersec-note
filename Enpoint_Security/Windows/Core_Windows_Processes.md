# Task Manager
The **Task manager** is a **built-in GUI-based** Windows utility that allows users to **see what is running** on the Windows system.
It provide information on resource usage, CPU and memory.

![[Pasted image 20250311102613.png]]

Note: **">"** symbol represents a parent-child relationship. `System (Parent) > smss.exe (Child)`
- System
- System > smss.exe
- csrss.exe
- wininit.exe
- wininit.exe > services.exe
- wininit.exe > services.exe > svchost.exe
- lsass.exe
- winlogon.exe
- explorer.exe

## Smss.exe
smss.exe (Session Manager subsystem) is responsible for creating new sessions. It is the first user-mode process started by the kernel.

SMSS is also responsible for creating environment variables, virtual memory paging files and starts winlogon.exe (the Windows Logon Manager).

It start crss.exe and wininit.exe in Session 0, an isolated Windows session for the operating system. And csrss.exe and winlogon.exe for Session 1, wich is the user session.

![[Pasted image 20250311113618.png]]
![[Pasted image 20250311113625.png]]

Any other subsystem listed in the `Required` value of `HKLM\System\CurrentControlSet\Control\Session Manager\Subsystems` is also launched.
![[Pasted image 20250311113720.png]]
### Unusual
-  A different parent process other than System (4)
- The image path is different from C:\Windows\System32
- More than one running process. (children self-terminate and exit after each new session)
- The running User is not the SYSTEM user
- Unexpected registry entries for Subsystem
## Csrss.exe
**csrss.exe** (**Client Server Runtime Process**) is the user-mode side of the Windows subsystem. 
This process is responsible for the Win32 console window and process thread creation and deletion.
### Unusual
- An actual parent process. (smss.exe calls this process and self-terminates)
- Image file path other than C:\Windows\System32
- Subtle misspellings to hide rogue processes masquerading as csrss.exe in plain sight
- The user is not the SYSTEM user.
## Wininit.exe
The **Windows Initialization Process**, **wininit.exe**, is responsible for launching services.exe (Service Control Manager), lsass.exe (Local Security Authority), and lsaiso.exe within Session 0.
### Unusual
- An actual parent process. (smss.exe calls this process and self-terminates)
- Image file path other than C:\Windows\System32
- Subtle misspellings to hide rogue processes in plain sight
- Multiple running instances
- Not running as SYSTEM
## Services.exe
**Service Control Manager** (SCM), it is primary responsibility is to handle system services: loading services, interacting with services and starting or ending services. It maintains a database that can be queried using a Windows built-in utility, `sc.exe`.

```powershell
C:\Users\Administrator> sc.exe
DESCRIPTION:
	SC is a command line program used for communicating with the
	Service Control Manager and services.
USAGE:
    sc <server> [command] [service name] <option1> <option2>...
```

Information about it are stored in `HKLM\System\CurrentControlSet\Services`
![[Pasted image 20250311161937.png]]

When a user logs into a machine successfully, this process is responsible for setting the value of the Last Known Good control set (Last Known Good Configuration), `HKLM\System\Select\LastKnownGood`, to that of the CurrentControlSet.
![[Pasted image 20250311162102.png]]
### Unusual
- A parent process other than wininit.exe
- Image file path other than C:\Windows\System32
- Subtle misspellings to hide rogue processes in plain sight
- Multiple running instances
- Not running as SYSTEM
## Svchost.exe
**Service Host** (Host Process for Windows Services), is responsible for hosting and managing Windows services.

The services running in this process are implemented as DLLs. The DLL to implement is stored in the registry for the service under the `Parameters` subkey in `ServiceDLL`. The full path is `HKLM\SYSTEM\CurrentControlSet\Services\SERVICE NAME\Parameters`.
### Unusual
- A parent process other than services.exe
- Image file path other than C:\Windows\System32
- Subtle misspellings to hide rogue processes in plain sight
- The absence of the -k parameter
## Explorer.exe
### Unusual
- An actual parent process. (userinit.exe calls this process and exits)
- Image file path other than C:\Windows
- Running as an unknown user
- Subtle misspellings to hide rogue processes in plain sight
- Outbound TCP/IP connections
