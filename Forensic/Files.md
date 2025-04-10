# Fat
## Data structures of FAT
### Cluster
This is a basic storage unit of FAT. Each file stored on a storage device can be consider as a group of clusters containing bits of information.
### Directory
This contains information about file identification:
- File name
- Starting cluster
- Filename length
### File allocation table
This is a linked list of all the clusters. It contains the status of the cluster and the pointer to the next cluster in the chain.
## FAT12, FAT16, and FAT32
The maximum file size is 4GB.

| **Attribute**                  | **FAT12**  | **FAT16**  | **FAT32**   |
| ------------------------------ | ---------- | ---------- | ----------- |
| **Addressable bits**           | 12         | 16         | 28          |
| **Max number of clusters**     | 4,096      | 65,536     | 268,435,456 |
| **Supported size of clusters** | 512B - 8KB | 2KB - 32KB | 4KB - 32KB  |
| **Maximum Volume size**        | 32MB       | 2GB        | 2TB         |
# NTFS
New Technology File System is a very basic file system. It offer little more in terme of security, reliability and recovery capabilities.
## Journaling
It **keep a log** of changes to the metadata in the volume.
It help the system recover from a crash or data movement.
This log is stored in **`$LOGFILE`** in the volume's root directory.
## Access controls
The FAT does not have access controls based on the user.
The NTFS file system has access controls that define the **owner** of a file/directory and **permissions** for each user.
## Volume Shadow Copy
It **keep track** of **changes** made to a file using Volume Shadow Copies.
A user can restore previous file versions for recovery of system restore.
In a **ransomware attacks**, the actors have to **delete the shadow copies** to prevent the file recovery.
## Alternate Data Streams
A file is a stream of data organized in a file system.
Alternate data streams (ADS) is a feature in NTFS that allows files to have multiple streams of data stored in a single file.
Internet Explorer use it to identify files downloaded from the internet.
Malware has also been observed to hide their code in ADS.

See [[Sysinternals#Streams]] to look at it.
# Master file table
This table is more extensive than the File Allocation Table. It is a structured database that tracks the objects stored in a volume.
## $MFT
This is fisrt record in the volume. 
The Volume Boot Record (VBR) points to the cluster where it is located
 $MFT stores information about the clusters where all other objects are located.
## $LOGFILE
It stores the transactional logging of the file system.
It helps maintain the integrity of the file system in the event of a crash.
## $UsnJrnl
Update Sequence Number (USN) Journal is present in $Extend record.
It contains information about all the files that were changed in the file system and the reason for the change. It is also called the **change journal**.
## MFT Explorer
```
$> MFTECmd.exe

MFTECmd version 0.5.0.1

Author: Eric Zimmerman (saericzimmerman@gmail.com)
https://github.com/EricZimmerman/MFTECmd

        f               File to process ($MFT | $J | $LogFile | $Boot | $SDS). Required
        m               $MFT file to use when -f points to a $J file (Use this to resolve parent path in $J CSV output).

        json            Directory to save JSON formatted results to. This or --csv required unless --de or --body is specified
        jsonf           File name to save JSON formatted results to. When present, overrides default name
        csv             Directory to save CSV formatted results to. This or --json required unless --de or --body is specified
        csvf            File name to save CSV formatted results to. When present, overrides default name

        body            Directory to save bodyfile formatted results to. --bdl is also required when using this option
        bodyf           File name to save body formatted results to. When present, overrides default name
        bdl             Drive letter (C, D, etc.) to use with bodyfile. Only the drive letter itself should be provided
        blf             When true, use LF vs CRLF for newlines. Default is FALSE

        dd              Directory to save exported FILE record. --do is also required when using this option
        do              Offset of the FILE record to dump as decimal or hex. Ex: 5120 or 0x1400 Use --de or --vl 1 to see offsets

        de              Dump full details for entry/sequence #. Format is 'Entry' or 'Entry-Seq' as decimal or hex. Example: 5, 624-5 or 0x270-0x5.
        fls             When true, displays contents of directory specified by --de. Ignored when --de points to a file.
        ds              Dump full details for Security Id as decimal or hex. Example: 624 or 0x270

        dt              The custom date/time format to use when displaying time stamps. Default is: yyyy-MM-dd HH:mm:ss.fffffff
        sn              Include DOS file name types. Default is FALSE
        fl              Generate condensed file listing. Requires --csv. Default is FALSE
        at              When true, include all timestamps from 0x30 attribute vs only when they differ from 0x10. Default is FALSE

        vss             Process all Volume Shadow Copies that exist on drive specified by -f . Default is FALSE
        dedupe          Deduplicate -f & VSCs based on SHA-1. First file found wins. Default is FALSE


Examples: MFTECmd.exe -f "C:\Temp\SomeMFT" --csv "c:\temp\out" --csvf MyOutputFile.csv
          MFTECmd.exe -f "C:\Temp\SomeMFT" --csv "c:\temp\out"
          MFTECmd.exe -f "C:\Temp\SomeMFT" --json "c:\temp\jsonout"
          MFTECmd.exe -f "C:\Temp\SomeMFT" --body "c:\temp\bout" --bdl c
          MFTECmd.exe -f "C:\Temp\SomeMFT" --de 5-5

          Short options (single letter) are prefixed with a single dash. Long commands are prefixed with two dashes

-f is required. Exiting
```

For parse the MFT file you can use:
 `MFTECmd.exe -f <path-to-$MFT-file> --csv <path-to-save-results-in-csv>`

And after you can read it with EZViewer.
# Recovering
As we seen before a file system store the location of the file on the disk in a table or a database.
When a file is deleted the file system only delete the entry that store the location.
For the file system the location is now writable or non allocated.
But these files stay on the disk as long as they are not overwritten by the file system. 
## Disk image
A disk image file is a file that contains a bit-by-bit copy of a disk drive. 
This copy saves all the data in one file, including metadata. 
In forensic this helps in two ways. 1) The original evidence is not contaminated while performing forensics, and 2) The disk image file can be copied to another disk and analyzed without using specialized hardware.
## Recovering file
See [[Autopsy]].
# Evidence of Execution
## Windows Prefetch files
When a program is run in windows, it store his information for future use.
It is used to load program quickly in case of frequent use.
This information is stored in the `C:\Windows\Prefetch` directory.

These files have a `.pf` extension. It contains:
- the last run times of the application
- the number of time the application was run
- any files and devices handles used by the file

You can use Prefetch Parser for parsing Prefetch files and extracting data.

You can use this command:
`PECmd.exe -f <path-to-Prefetch-files> --csv <path-to-save-csv>`
or for a directory:
`PECmd.exe -d <path-to-Prefetch-directory> --csv <path-to-save-csv>`
## Windows 10 Timeline
Windows 10 store the recent application in an SQLite database called Windows 10 Timeline.
You can have information about the time of execution.
You can find it in:
`C:\Users\<username>\AppData\Local\ConnectedDevicesPlatform\{randomfolder}\ActivitiesCache.db`

We can use WxTCmd.exe to analyse the timeline.
`WxTCmd.exe -f <path-to-timeline-file> --csv <path-to-save-csv>`
## Windows Jump Lists
The jump list is used to help the user to find the last used applications.
`C:\Users\<username>\AppData\Roaming\Microsoft\Windows\Recent\AutomaticDestinations`

We can use `JLECmd.exe` to parse jump lists.
`JLECmd.exe -f <path-to-Jumplist-file> --csv <path-to-save-csv>`
# Files/Folder Knowledge
## Shortcut files
Windows create a shortcut for all opened file, locally or remotly. This file contains information about the first and last opened times of file and the path.

It can be found:
`C:\Users\<username>\AppData\Roaming\Microsoft\Windows\Recent\`
`C:\Users\<username>\AppData\Roaming\Microsoft\Office\Recent\`

You can use `LECmd.exe`:
`LECmd.exe -f <path-to-shortcut-files> --csv <path-to-save-csv>`
## IE/Edge History
The IE/Edge browsing history includes files opened in the system as well whether those files were opened using the browser or not.
We can access the location:
`C:\Users\<username>\AppData\Local\Microsoft\Windows\WebCache\WebCacheV*.dat`

Those files would appear with a prefix:  `file:///*`
You can use autopsy to open it.
![[Pasted image 20250406165039.png]]
![[Pasted image 20250406165047.png]]
![[Pasted image 20250406165053.png]]
![[Pasted image 20250406165058.png]]
![[Pasted image 20250406165105.png]]
## Jump lists
Jump list too can give you information about this
# External device / usb device
When a new device is attached to a system, his setup information are stored in:
`C:\Windows\inf\setupapi.dev.log`
This logs contains the device serial number and the first/last times when the device was connected.
![[Pasted image 20250406172408.png]]
## Shortcut files
These shortcut files can sometimes provide us with information about connected usb devices.
`C:\Users\<username>\AppData\Roaming\Microsoft\Windows\Recent\`
`C:\Users\<username>\AppData\Roaming\Microsoft\Office\Recent\`
