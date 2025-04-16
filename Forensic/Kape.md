# Introduction
Kroll Artifact Parser and Extractor (KAPE) parses and extracts Windows Forensic artifacts.
It can significantly reduce the time needed to respond to an incident.
## How it work
It is highly configurable. The KAPE binary collects files and processes them as per the provided configuration.

The collection of files (targets) is in 2 time:
- The **first step** **copy all the file available**, it work for the **non locked** file. The other files are transfered to a secondary waitlist.
- This **second step** waitlist is processed using different technique like **raw read of the disk**, they will be copied and stored with the original **timestamp and metadata** and stored in a similar directory structure.

Once the data is collected KAPE can process it using modules.
![[Pasted image 20250416090744.png]]
# Target options
`Targets` are the artifacts that need to be collected from a system or image and copied to the provided destination.
For exemple with the Prefetch that store the evidence of execution so we can create a target for it.
Similary we can create a target for the registry hive.

Target folder:
![[Pasted image 20250416091300.png]]
The last four files are guide and template to create Targets and Compound Targets.

In the windows Directory:
![[Pasted image 20250416091454.png]]
We can see a lot of .tkape file. This is how a `Target` is defined.

This TKAPE file tells KAPE to collect files with the file mask `*.pf` from the path `C:\Windows\prefetch` and `C:\Windows.old\prefetch`.
![[Pasted image 20250416091552.png]]
## Compound Targets
These are `Targets` that are compounds of multiple other targets.
`Compound Targets` help us collect multiple targets by giving a single command.
Examples of `Compound Targets` include `!BasicCollection`, `!SANS_triage` and `KAPEtriage`.

This `Compound Target` will collect evidence of execution from Prefetch, RecentFileCache, AmCache, and Syscache `Targets`
![[Pasted image 20250416091924.png]]
## !Disabled
This directory contains `Targets` that you want to keep in the KAPE instance, but you don't want them to appear in the active Targets list.
## !Local
If you have create some `Targets` that you don't want to sync with the KAPE Github repository, you can place them here.
# Module
`Modules` run specific tools against the provided set of files.
Their goal is not to copy files from one place to another but rather run some command and store the output. 
![[Pasted image 20250416092911.png]]
## Windows
You can see the **Windows** directory
![[Pasted image 20250416092953.png]]
The files have a .mkape extension.
![[Pasted image 20250416093014.png]]
## Bin directory

![[Pasted image 20250416093047.png]]
It contains executables that we want to run on the system but are not natively present on most system.
# KAPE GUI
To collect targets:
![[Pasted image 20250416094633.png]]
![[Pasted image 20250416094638.png]]
![[Pasted image 20250416140112.png]]
![[Pasted image 20250416140117.png]]
![[Pasted image 20250416140121.png]]
![[Pasted image 20250416140125.png]]
![[Pasted image 20250416140131.png]]
![[Pasted image 20250416140135.png]]

# CLI
```cmd
>kape.exe

KAPE version 1.1.0.1 Author: Eric Zimmerman (kape@kroll.com)

        tsource         Target source drive to copy files from (C, D:, or F:\ for example)
        target          Target configuration to use
        tdest           Destination directory to copy files to. If --vhdx, --vhd or --zip is set, files will end up in VHD(X) container or zip file
        tlist           List available Targets. Use . for Targets directory or name of subdirectory under Targets.
        tdetail         Dump Target file details
        tflush          Delete all files in 'tdest' prior to collection
        tvars           Provide a list of key:value pairs to be used for variable replacement in Targets. Ex: --tvars user:eric would allow for using %user% in a Target which is replaced with eric at runtime. Multiple pairs should be separated by ^
        tdd             Deduplicate files from --tsource (and VSCs, if enabled) based on SHA-1. First file found wins. Default is TRUE

        msource         Directory containing files to process. If using Targets and this is left blank, it will be set to --tdest automatically
        module          Module configuration to use
        mdest           Destination directory to save output to
        mlist           List available Modules. Use . for Modules directory or name of subdirectory under Modules.
        mdetail         Dump Module processors details
        mflush          Delete all files in 'mdest' prior to running Modules
        mvars           Provide a list of key:value pairs to be used for variable replacement in Modules. Ex: --mvars foo:bar would allow for using %foo% in a module which is replaced with bar at runtime. Multiple pairs should be separated by ^
        mef             Export format (csv, html, json, etc.). Overrides what is in Module config

        sim             Do not actually copy files to --tdest. Default is FALSE
(...)
```