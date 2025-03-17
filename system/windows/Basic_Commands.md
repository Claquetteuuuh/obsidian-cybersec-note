# System Information
Version:
```shell
user@WINSRV2022-CORE C:\Users\user>ver

Microsoft Windows [Version 10.0.20348.2655]
```

System information:
```shell
user@WINSRV2022-CORE C:\Users\user>systeminfo

Host Name:                 WINSRV2022-CORE
OS Name:                   Microsoft Windows Server 2022 Datacenter
OS Version:                10.0.20348 N/A Build 20348
OS Manufacturer:           Microsoft Corporation
OS Configuration:          Standalone Server
OS Build Type:             Multiprocessor Free
Registered Owner:          Windows User
(...)
Network Card(s):           1 NIC(s) Installed.
                           [01]: Amazon Elastic Network Adapter
                                 Connection Name: Ethernet
                                 DHCP Enabled:    Yes
                                 DHCP Server:     10.10.0.1
                                 IP address(es)
                                 [01]: 10.10.6.102
                                 [02]: fe80::16c2:8e64:b11:43b4
Hyper-V Requirements:      A hypervisor has been detected. Features required for Hyper-V will not be displayed.
```
# Network
## Ip config
Get all the information about ip address and mac address:
```shell
ipconfig /all
```
## netstat
Get all the information about the port listened:
```shell
netstat -abon
```
# Processus
## tasklist
Get all the process
```shell

user@WINSRV2022-CORE C:\Treasure\Hunt>tasklist

Image Name                     PID Session Name        Session#    Mem Usage
========================= ======== ================ =========== ============
System Idle Process              0 Services                   0          8 K
System                           4 Services                   0        136 K
Registry                        96 Services                   0     15,012 K
smss.exe                       320 Services                   0        868 K
(...)
conhost.exe                   4028 Services                   0     12,744 K
WmiPrvSE.exe                  2604 Services                   0      9,512 K
mscorsvw.exe                  3396 Services                   0     14,260 K
tasklist.exe                   676 Services                   0      8,804 K
```

And you can filter with `/FI`:
```bash
user@WINSRV2022-CORE C:\Treasure\Hunt>tasklist /FI "imagename eq sshd.exe"

Image Name                     PID Session Name        Session#    Mem Usage
========================= ======== ================ =========== ============
sshd.exe                      1416 Services                   0      2,864 K
sshd.exe                      2696 Services                   0      8,300 K
sshd.exe                      1820 Services                   0      8,272 K

```
## Taskkill
You can use `taskkill` to kill a process
```shell
taskkill /PID 1516
```
