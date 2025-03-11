The windows logs are **not txt file**, they can be convert in XML with the windows API.
They are **stored in binary** format with `.evt` or `.evtx` extension.
You can find these logs in: `C:\Windows\System32\winevt\Logs`.

There are three main ways of **accessing these event logs** within a Windows system:
1. **Event Viewer** (GUI-based application)
2. **Wevtutil.exe** (command-line tool)
3. **Get-WinEvent** (PowerShell cmdlet)
![[Pasted image 20250311104842.png]]

