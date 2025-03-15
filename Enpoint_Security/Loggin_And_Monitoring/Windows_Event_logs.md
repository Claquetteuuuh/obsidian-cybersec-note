The windows logs are **not txt file**, they can be convert in XML with the windows API.
They are **stored in binary** format with `.evt` or `.evtx` extension.
You can find these logs in: `C:\Windows\System32\winevt\Logs`.

There are three main ways of **accessing these event logs** within a Windows system:
1. **Event Viewer** (GUI-based application)
2. **Wevtutil.exe** (command-line tool)
3. **Get-WinEvent** (PowerShell cmdlet)
![[Pasted image 20250311104842.png]]
# Event Viewer
The event Viewer MMC (**Microsoft Management Console**) can be run by simply right clicking the Windows icon in the taskbar and selecting EventViewer:
1. The pane on the left provides a hierarchical tree listing of the event log providers.
2. The pane in the middle will display a general overview and summary of the events specific to a selected provider.
3. The pane on the right is the actions pane.
![[e2ceaa065e80a6763b7a861dbd4142fb.gif]]

For exemple let's go in `Applications and Services Logs >Microsoft > Windows > PowerShell > Operational`
![[Pasted image 20250315173912.png]]
You can see:
- **Level:** Highlights the log recorded type based on the identified event types specified earlier. In this case, the log is labe led as **Information**.
- **Date and Time:** Highlights the time at which the event was logged.
- **Source:** The name of the software that logs the event is identified. From the above image, the source is PowerShell.
- **Event ID:** This is a predefined numerical value that maps to a specific operation or event based on the log source. This makes Event IDs not unique, so `Event ID 4103` in the above image is related to Executing Pipeline but will have an entirely different meaning in another event log.
- **Task Category:** Highlights the Event Category. This entry will help you organize events so the Event Viewer can filter them. The event source defines this column.

You can create a new View to filter log on one log:
![[a06823a8acefe78317235bf66d02152d.gif]]
# Wevtutil.exe
This tool permit to create script to retrieve information about event logs and publishers.
To know how to use this tool you can use the `/?` option.
```shell
wevtutil.exe /?
Windows Events Command Line Utility.

Enables you to retrieve information about event logs and publishers, install
and uninstall event manifests, run queries, and export, archive, and clear logs.

Usage:

You can use either the short (for example, ep /uni) or long (for example,
enum-publishers /unicode) version of the command and option names. Commands,
options and option values are not case-sensitive.

Variables are noted in all upper-case.

wevtutil COMMAND [ARGUMENT [ARGUMENT] ...] [/OPTION:VALUE [/OPTION:VALUE] ...]

Commands:

el | enum-logs          List log names.
gl | get-log            Get log configuration information.
sl | set-log            Modify configuration of a log.
ep | enum-publishers    List event publishers.
gp | get-publisher      Get publisher configuration information.
im | install-manifest   Install event publishers and logs from manifest.
um | uninstall-manifest Uninstall event publishers and logs from manifest.
qe | query-events       Query events from a log or log file.
gli | get-log-info      Get log status information.
epl | export-log        Export a log.
al | archive-log        Archive an exported log.
cl | clear-log          Clear a log.

Common options:

/{r | remote}:VALUE
(...)
```
# Get-WinEvent
This is a powershell cmdlet, it gets events from event logs and event tracing log files on local and remote computers.
## Exemple 1: Get all logs from a computer
```bash
PS C:\Users\Administrator> Get-WinEvent -ListLog *

LogMode   MaximumSizeInBytes RecordCount LogName
-------   ------------------ ----------- -------
Circular            20971520        1295 Application
Circular            20971520           0 HardwareEvents
Circular             1052672           0 Internet Explorer
Circular            20971520           0 Key Management Service
Circular            20971520       28293 Security
(...)
```
## Exemple 2: Get event log providers and log names
```bash
PS C:\Users\Administrator> Get-WinEvent -ListProvider *


Name     : .NET Runtime
LogLinks : {Application}
Opcodes  : {}
Tasks    : {}

Name     : .NET Runtime Optimization Service
LogLinks : {Application}
Opcodes  : {}
Tasks    : {}

Name     : Application
LogLinks : {Application}
Opcodes  : {}
Tasks    : {Devices
           , Disk
           , Printers
           , Services
           ...}

Name     : Application Error
LogLinks : {Application}
Opcodes  : {}
Tasks    : {}

Name     : Application Hang
LogLinks : {Application}
Opcodes  : {}
Tasks    : {}
```
The argument is a regex so :
```bash
```bash
PS C:\Users\Administrator> Get-WinEvent -ListProvider *Powershell*
```
Works fine.
## Example 3: Log filtering
```bash
PS C:\Users\Administrator> Get-WinEvent -LogName Application | Where-Object { $_.ProviderName -Match 'WLMS' }


   ProviderName: WLMS

TimeCreated                     Id LevelDisplayName Message
-----------                     -- ---------------- -------
12/21/2020 4:23:47 AM          100
12/18/2020 3:18:57 PM          100
12/15/2020 8:50:22 AM          100
12/15/2020 8:48:34 AM          101
12/15/2020 8:18:34 AM          100
12/15/2020 7:48:34 AM          100
12/14/2020 7:12:18 PM          101
12/14/2020 6:42:18 PM          100
12/14/2020 6:12:18 PM          100
12/14/2020 6:09:09 PM          101
12/14/2020 5:39:08 PM          100
12/14/2020 5:09:08 PM          100
```
OR
```bash
(Get-WinEvent -ListProvider Microsoft-Windows-PowerShell).Events | Format-Table Id, Description | Measure-Object
```
OR
```powershell
Get-WinEvent -FilterHashtable @{ LogName='Application';ProviderName='WLMS' }
```
Syntaxes:
```powershell
@{ <name> = <value>; [<name> = <value> ] ...}
```

![[Pasted image 20250315181537.png]]

See:
https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.diagnostics/get-winevent?view=powershell-7.5&viewFallbackFrom=powershell-7.1
