
## __SYN Scan__

Pour analyser l'état des ports d'une machine dans un réseaux via un SYN Scan.

```powershell
<PORT_1>, <PORT_2> | % { Test-NetConnection 192.168.1.100 -Port $_ -InformationLevel Detailed -Verbose }
```

