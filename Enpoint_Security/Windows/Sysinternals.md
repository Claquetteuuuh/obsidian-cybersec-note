The Sysinternals tools are a compilation of over 70+ Windows-based tools. Each of the tools falls into one of the following categories:

- File and Disk Utilities
- Networking Utilities
- Process Utilities
- Security Utilities
- System Information
- Miscellaneous
## Process Explorer
The Process Explorer display consists of two sub-windows.
Top: show a list of the currently active processes.
Bottom: Depends on the mode that Process Explorer is in:
- **Handle mode**: the handles that the process selected in the top window has opened
- **DLL mode**: DLLs and memory-mapped files that the process has loaded
![[Pasted image 20250311103936.png]]

# Download
[https://docs.microsoft.com/en-us/sysinternals/downloads](https://docs.microsoft.com/en-us/sysinternals/downloads/)

Alternatively you can download the tool that you want.
For exemple:
https://learn.microsoft.com/en-us/sysinternals/downloads/process-utilities

And if you want to download the sysinternals suite:
https://learn.microsoft.com/en-us/sysinternals/downloads/sysinternals-suite

Alternatively, a PowerShell module can download and install all of the Sysinternals tools. 
- PowerShell command: `Download-SysInternalsTools C:\Tools\Sysint`
# Sysinternals Live
This enable you to execute sysinternal tool directly in the web without hunting for manually downloading them.
Just write **`live.sysinternals.com/<toolname>`** in the command prompt / explorer.

If it fail, the webdav client must be installed and started.
![[Pasted image 20250311171350.png]]

We have to enable **Network Discovery** too:
```powershell
control.exe /name Microsoft.NetworkAndSharingCenter
```

Click on `Change advanced sharing settings` and select `Turn on network discovery` for your current network profile.

Or simply with Powershell:
```powershell
Install-WindowsFeature WebDAV-Redirector –Restart
```
And check the installation:
```powershell
Get-WindowsFeature WebDAV-Redirector | Format-Table –Autosize
```
# File and Disk Utilities
## Sigcheck
**Sigcheck** is a command-line utility that shows file version number, timestamp information, and digital signature details, including certificate chains. It also includes an option to check a file’s status on VirusTotal and an option to upload a file for scanning.

```powershell
C:\Users\Administrator>sigcheck --accepteula

Sigcheck v2.90 - File version and signature viewer
Copyright (C) 2004-2022 Mark Russinovich
Sysinternals - www.sysinternals.com

usage: sigcheck [-a][-h][-i][-e][-l][-n][[-s]|[-c|-ct]|[-m]][-q][-p <policy GUID>][-r][-u][-vt][-v[r][s]][-f catalog file] [-w file] <file or directory>
usage: sigcheck -d [-c|-ct] [-w file] <file or directory>
usage: sigcheck -o [-vt][-v[r]] [-w file] <sigcheck csv file>
usage: sigcheck -t[u][v] [-i] [-c|-ct] [-w file] <certificate store name|*>
```

Use Case: Check for unsigned files in C:\Windows\System32.
Command: `sigcheck -u -e C:\Windows\System32`
Parameter usage:
- `-u` "If VirusTotal check is enabled, show files that are unknown by VirusTotal or have non-zero detection, otherwise show only unsigned files."
- `-e` "Scan executable images only (regardless of their extension)"
## Streams
The NTFS file system provides applications the ability to create alternate data streams of information. By default, all data is stored in a file's main unnamed data stream, but by using the syntax `'file:stream'`, you are able to read and write to alternates.

**Alternate Data Streams (ADS)** is a file attribute specific to Windows NTFS (New Technology File System). Every file has at least one data stream ($DATA) and ADS allows files to contain more than one stream of data.

Malware writers have used ADS to hide data in an endpoint, but not all its uses are malicious.

```powershell
C:\Users\Administrator>streams --accepteula

streams v1.60 - Reveal NTFS alternate streams.
Copyright (C) 2005-2016 Mark Russinovich
Sysinternals - www.sysinternals.com

usage: streams [-s] [-d] <file or directory>
-s     Recurse subdirectories
-d     Delete streams
-nobanner
       Do not display the startup banner and copyright message.
```

```powershell
C:\Users\Administrator>streams Desktop\SysinternalsSuite.zip

streams v1.60 - Reveal NTFS alternate streams.
Copyright (C) 2005-2016 Mark Russinovich
Sysinternals - www.sysinternals.com

C:\Users\Administrator\Desktop\SysinternalsSuite.zip:
   :Zone.Identifier:$DATA       139
```

You can read the content of these ADS like that:

![[Pasted image 20250311172845.png]]
# Networking Utilities

## TCPView
TCPView is a Windows program that will show you **detailed listings of all TCP and UDP endpoints** on your system, including the **local and remote addresses** and state of TCP connections.

![[Pasted image 20250311103439.png]]

This is a good time to mention that Windows has a built-in utility that provides the same functionality. This tool is called **Resource Monitor**. There are many ways to open this tool. From the command line use `resmon`.
![[Pasted image 20250311173846.png]]

Here is the default tcpview interface:
![[Pasted image 20250311174019.png]]

When you click on the green flag:
![[Pasted image 20250311174134.png]]