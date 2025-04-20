![[Pasted image 20250417183346.png]]
# Kernel callback telemetry
## 1. Process Creation Kernel callbacks
- **Process Creation Kernel Callbacks** routines are used to **notify drivers** whenever a process is **created or terminated** on the system
- Commonly used by **EDR**'s to collect initial telemetries on **malicious process creation** like its full file image path and to be aware of its creation
- They are **stored in** a kernel array called **nt!PspCreateProcessNotifyRoutine**.
- Those Callback routines are triggered initially from user-mode by system call such as **NtCreateUserProcess, NtCreateProcessEx**, ...
- Drivers can register those callback routines using the following kernel APIs **PsSetCreateProcessNotifyRoutine**, **PsSetCreateProcessNotifyRoutineEx**, **PsSetCreateProcessNotifyRoutineEx2**
	![[Pasted image 20250417184926.png]]
![[Pasted image 20250417185100.png]]
- The **Telemetries Collected by the Process Creation Kernel Callbacks** routines are:
	- The **EPROCESS** of the created process
	- The **PID** of the created process
	- The **PPS_CREATE_NOTIFY_INFO** structure pointer which contains informations like **ParentProcessId**, **ImageFileName**, **CommandLine** and **CreatingThreadId**
	![[Pasted image 20250417185537.png]]
## 2. Thread Creation Kernel Callbacks
- **Thread Creation Kernel Callbacks routines** are used to notify drivers whenever a Thread is created or terminated on the system
- Commonly used by **EDRs** to collect initial telemetries on malicious **thread creation**
- They are stored in a kernel array called **nt!PspCreateThreadNotifyRoutine.**
- Those Callback routines are triggered initially from user-mode by system calls such as **NtCreateThreadEx**, **NtTerminateThread**, ...
- Driver can register those callback routines using the following kernel APIs **PsSetCreateThreadNotifyRoutine**, **PsSetCreateThreadNotifyRoutineEx**.
	![[Pasted image 20250417190107.png]]
![[Pasted image 20250417190456.png]]
## 3. Image load Kernel Callbacks
- Image Loading Kernel Callbacks routines are used to notify drivers whenever a PE Image (such as **.sys** driver, **.dll**, or **.exe**) is loaded into memory by the system
- Commonly used by **EDRs** to collect initial telemetries on **malicious Image Loading**
- They are stored in a kernel array called **nt!PspLoadImageNotifyRoutine.**
- Those Callback routines are triggered initially from user-mode by system calls such as **NtMapViewOfSection, LdrLoadDll, ...**
- Drivers can register those callback routines using the following kernel APIs **PsSetLoadImageNotifyRoutine, PsSetLoadImageNotifyRoutineEx.**
	![[Pasted image 20250420102113.png]]	
![[Pasted image 20250420102246.png]]

- The **Telemetries Collected** by the Image Loading Kernel Callbacks routines are:
	- The **Full Image Name** of the loaded image
	- The **PID** of the process into which the image is loaded
	- The **Base Address** of the Loaded Image and its **Size**
## 4. Registry Operation Kernel Callbacks
- **Registry Pre/Post operations kernel callbacks routines** are low level routines used to notify drivers when operations (such as read, write, delete, or query) are performed on the Windows registry
- Commonly used by **EDRs** to collect initial telemetries on **malicious Registry Operation** used for persistence or privilege escalation
- They are stored in a doubly linked list headed by **nt!CallbackListHead**
- Those Callback routines are triggered initially from user-mode by system calls such as **NtOpenKeyEx, NtSetValueKey, ...**
- Drivers can register those callback routines using the following kernel APIs **CmRegisterCallback, CmRegisterCallbackEx**
	![[Pasted image 20250420103352.png]]
	![[Pasted image 20250420103753.png]]
- The telemetries Collected by the Registry Operation Kernel Callbacks routines are:
	- The **Full Name of the registry key** that is being opened
	- The **PID** of the process that is performing the registry operation
	- The **TID** of the thread within the process that is performing the operation
	- ...
	![[Pasted image 20250420104011.png]]
	