[https://github.com/volatilityfoundation/volatility3](https://github.com/volatilityfoundation/volatility3)
It is used to analyse the memory
The extensions are:
- VMWare - .vmem
- Hyper-V - .bin
- Parallels - .mem
- VirtualBox - .sav file \*_this is only a partial memory file_
# Get information
You can use the plugin based on the OS:
- windows.info
- linux.info
- mac.info
# List processes and connections
```cmd
python3 vol.py -f <file> windows.pslist
```

Some malware use rootkits, they can unlink themselve from the list you will no longer see their when using `pslist`
To bypass it:
```cmd
python3 vol.py -f <file> windows.psscan
```

You can use pstree to list it based on the PPID
```cmd
python3 vol.py -f <file> windows.pstree
```

To get the network connections:
```cmd
python3 vol.py -f <file> windows.netstat
```

You can see all DLLs associate with a process.
```cmd
python3 vol.py -f <file> windows.dlllist
```
# Detection capabilities
You can use the plugin `malfind` that use the heap and identifying processes that have the executable bit set to `RWE or RX` and no memory-mapped file on disk (file-less malware)
```cmd
python3 vol.py -f <file> windows.malfind
```

You can use the plugin `yarascan` to use yara rules you can use a YARA file as an argument or list rules.
```cmd
python3 vol.py -f <file> windows.yarascan
```
# Advanced Memory Forensic
The goal is to detect hidden or advanced malware (like rootkits) by analyzing memory and identifying signs of system manipulation (e.g., hooks or rogue drivers).
- SSDT = System Service Descriptor Table
    - Used by the Windows kernel to map system calls.
    - Malware can modify this table to redirect calls to malicious code (this is called "hooking").
```bash
python3 vol.py -f <memory_file> windows.ssdt
```
Not all hooks are malicious. Some legitimate software also use hooks—your job is to spot the suspicious ones.

You can investigate the drivers:
```bash
python3 vol.py -f <memory_file> windows.modules
```
or
```bash
python3 vol.py -f <memory_file> windows.driverscan
```

| Plugin      | Purpose                                            |
| ----------- | -------------------------------------------------- |
| `modscan`   | Scans memory for hidden kernel modules             |
| `driverirp` | Views IRP handlers to analyze driver communication |
| `callbacks` | Shows kernel callbacks (potential persistence)     |
| `idt`       | Dumps the Interrupt Descriptor Table               |
| `apihooks`  | Detects API function hooks                         |
| `moddump`   | Extracts modules for offline inspection            |
| `handles`   | Lists system handles (files, processes, registry)  |
# Other
## User agent
```bash
vol.py -f <dump> -o /dir/to/store_dump/ windows.memmap.Memmap --pid <suspicious PID> --dump 
```
Once the dump is stored use:
```bash
strings *.dmp | grep -i "user-agent"
```
