
## Registers
Les **registres windows** sont une base de données de **donnés de configuration système** à propos de **matériel**, **logiciel**, **utilisateurs**.

Pour récuperer les registres ils faut lancer **regedit.exe**.

| **Dossier/clé prédéfinie** | Description                                                                                                               |
| -------------------------- | ------------------------------------------------------------------------------------------------------------------------- |
| **HKEY_CURRENT_USER**      | Les **informations** à propos de l'**utilisateur actuellement connecté**: dossiers, screen colors, control pannel. *HKCU* |
| **HKEY_USERS**             | Tout les utilisateurs chargé sur la machine. *HKU*                                                                        |
| **HKEY_LOCAL_MACHINE**     | **Information de configuration** de la machine. *HKLM*                                                                    |
| **HKEY_CLASSES_ROOT**      | Fusionne la vue des registres `HKEY_LOCAL_MACHINE\Software\Classes` et `HKEY_CURRENT_USER\Software\Classes`. **`HKCR`**   |
| **HKEY_CURRENT_CONFIG**    | Information sur le **hardware profile** utilisé par la machine.                                                           |
## Hives
Les hives sont des fichiers contenant ce qui s'est passé sur la machine.

La plupart de ces hives sont dans `C:\Windows\System32\Config` :
- **DEFAULT** (mounted on `HKEY_USERS\DEFAULT`)
- **SAM** (mounted on `HKEY_LOCAL_MACHINE\SAM`)
- **SECURITY** (mounted on `HKEY_LOCAL_MACHINE\Security`)
- **SOFTWARE** (mounted on `HKEY_LOCAL_MACHINE\Software`)
- **SYSTEM** (mounted on `HKEY_LOCAL_MACHINE\System`)

D'autres hives sert à avoir les **informations sur un utilisateur** :
- **NTUSER.DAT** (mounted on HKEY_CURRENT_USER when a user logs in), il est sauvegardé dans le dossier `C:\Users\<username>\`.
- **USRCLASS.DAT** (mounted on `HKEY_CURRENT_USER\Software\CLASSES`), il est sauvegardé dans le disque dans `C:\Users\<username>\AppData\Local\Microsoft\Windows`.

Un hive important est le *AmCache*, il consigne des **metadonnées** sur l'**execution** et l'**installation** de programmes sur un systeme. `C:\Windows\AppCompat\Programs\Amcache.hve`.


## Autopsy

Pour faire une **analyse forensic** il est conseiller de faire une **copie du disque** que nous allons analyser, malheuresement on ne peut pas directement copier les hives du dossier `%WINDIR%\System32\Config` car il est **restreint**.

Pour répondre à ce problème, on va utiliser **[Autopsy](https://www.autopsy.com/)**.
Il permet d'acquerir des données à partir d'une image disque à partir d'un dossier selectionné. 

![[autopsy.png]]
## Get informations
### OS Version
Pour trouver la **version** on peut utiliser la clé de registre *`SOFTWARE\Microsoft\Windows NT\CurrentVersion`*
![[Pasted image 20250401110513.png]]

### Current control set
That is the configuration data used for controlling system startup, there is two control set:
- **ControlSet001**
- **ControlSet002**
In most case ControlSet001 will point to the Control Set that the machine booted with and ControlSet002 will be the `last known good`  configuration.

Locate in:
`SYSTEM\ControlSet001`
`SYSTEM\ControlSet002`

Windows create a volatile control set called **CurrentControlSet** (`HKLM\SYSTEM\CurrentControlSet`)
We can find wich control set is used: `SYSTEM\Select\Current`
Same for the last know good: `SYSTEM\Select\LastKnownGood`
![[Pasted image 20250401110620.png]]
### Computer name
It is essential to be sure that we work on the good computer.
`SYSTEM\CurrentControlSet\Control\ComputerName\ComputerName`
![[Pasted image 20250401111024.png]]
### Time zone
This help to understand the chronology of the events:
`SYSTEM\CurrentControlSet\Control\TimeZoneInformation`
![[Pasted image 20250401111124.png]]
### Network interfaces and past networks
This list the network interfaces on the machine.
`SYSTEM\CurrentControlSet\Services\Tcpip\Parameters\Interfaces`
![[Pasted image 20250401111330.png]]

The past network:
`SOFTWARE\Microsoft\Windows NT\CurrentVersion\NetworkList\Signatures\Unmanaged`
`SOFTWARE\Microsoft\Windows NT\CurrentVersion\NetworkList\Signatures\Managed`
![[Pasted image 20250401111529.png]]
### Autoruns
The programs that un once the user is logged.
`NTUSER.DAT\Software\Microsoft\Windows\CurrentVersion\Run`
`NTUSER.DAT\Software\Microsoft\Windows\CurrentVersion\RunOnce`
`SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce`
`SOFTWARE\Microsoft\Windows\CurrentVersion\policies\Explorer\Run`
`SOFTWARE\Microsoft\Windows\CurrentVersion\Run`
![[Pasted image 20250401111612.png]]

The key that contains information about services.
`SYSTEM\CurrentControlSet\Services`
![[Pasted image 20250401111640.png]]
In this registry key, if the `start`   key is set to 0x02, this means that this service will start at boot.
### SAM hive and user information
It contains user account information, login information and group information.
`SAM\Domains\Account\Users`
![[Pasted image 20250401111738.png]]
# Files / Folders
## Recent files
Windows store a list of recently open files.
`NTUSER.DAT\Software\Microsoft\Windows\CurrentVersion\Explorer\RecentDocs`
![[Pasted image 20250401112027.png]]
## Office recent files
Microsoft Office also maintains a list of recently opened documents.
`NTUSER.DAT\Software\Microsoft\Office\VERSION`

The version number for each Microsoft Office release is different, for exemple:
`NTUSER.DAT\Software\Microsoft\Office\15.0\Word`
## ShellBags
The informations about the layout are stored as "shell" and are stored and can identify the Most Recently Used files and folders.

`USRCLASS.DAT\Local Settings\Software\Microsoft\Windows\Shell\Bags`
`USRCLASS.DAT\Local Settings\Software\Microsoft\Windows\Shell\BagMRU`
`NTUSER.DAT\Software\Microsoft\Windows\Shell\BagMRU`
`NTUSER.DAT\Software\Microsoft\Windows\Shell\Bags`

![[Pasted image 20250401155143.png]]
## Open/save and LastVisited Dialog MRUs
When we open or save a file, a dialog box appears asking us where to save or open that file from.
Windows remember that location.
`NTUSER.DAT\Software\Microsoft\Windows\CurrentVersion\Explorer\ComDlg32\OpenSavePIDlMRU`
`NTUSER.DAT\Software\Microsoft\Windows\CurrentVersion\Explorer\ComDlg32\LastVisitedPidlMRU`
![[Pasted image 20250401155359.png]]
## Windows Explorer Address/Search Bars
We can look the paths typed in the Windows Explorer address bar:
`NTUSER.DAT\Software\Microsoft\Windows\CurrentVersion\Explorer\TypedPaths`
`NTUSER.DAT\Software\Microsoft\Windows\CurrentVersion\Explorer\WordWheelQuery`
![[Pasted image 20250401155553.png]]
# Execution
## UserAssist
Windows keep trace of the application launched.
`NTUSER.DAT\Software\Microsoft\Windows\Currentversion\Explorer\UserAssist\{GUID}\Count`
![[Pasted image 20250401155816.png]]
## ShimCache
This is a mechanism used to keep track of application compatibility with the OS.
`SYSTEM\CurrentControlSet\Control\Session Manager\AppCompatCache`

ShimCache stores file name, file size, and last modified time of the executables.
![[Pasted image 20250401160053.png]]
We can use the following command to run the AppCompatCache (shimcache) Parser Utility:

`AppCompatCacheParser.exe --csv <path to save output> -f <path to SYSTEM hive for data parsing> -c <control set to parse>`
## AmCache
This is the same thing that ShimCache and store additional data related to program executions. 
It includes execution path, installation, execution and deletion times, and SHA1 hashes of the executed programs
`C:\Windows\appcompat\Programs\Amcache.hve`

The informations can be found in this location:
`Amcache.hve\Root\File\{Volume GUID}\`
![[Pasted image 20250401160412.png]]
## BAM / DAM
Background Activity Monitor keeps a tab on the activity of background applications.
Desktop Activity Moderator is a part of Microsoft Windows that optimizes the power consumption of the device.

`SYSTEM\CurrentControlSet\Services\bam\UserSettings\{SID}`
`SYSTEM\CurrentControlSet\Services\dam\UserSettings\{SID}`

![[Pasted image 20250401160642.png]]
# External devices
## Identification
The following locations keep track of USB keys plugged.
It store the vendor id and version.
`SYSTEM\CurrentControlSet\Enum\USBSTOR`
`SYSTEM\CurrentControlSet\Enum\USB`

![[Pasted image 20250401161038.png]]
## First/Last times
`SYSTEM\CurrentControlSet\Enum\USBSTOR\Ven_Prod_Version\USBSerial#\Properties\{83da6326-97a6-4088-9453-a19231573b29}\####`
This key tracks the first time the device was connected, the last time it was connected and the last time is was removed from the system.

In this key, the #### sign can be replaced by the following digits to get the required information:

| Value | Information           |
| ----- | --------------------- |
| 0064  | First Connection time |
| 0066  | Last Connection time  |
| 0067  | Last removal time     |
## USB Device Volume name
The device name of the connected drive can be found here:
`SOFTWARE\Microsoft\Windows Portable Devices\Devices`
![[Pasted image 20250401161509.png]]
