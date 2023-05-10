
## __SYN Scan__

Pour analyser l'état des ports d'une machine dans un réseaux via un SYN Scan.

```powershell
3000,  | % { Test-NetConnection 192.168.1.100 -Port $_ -InformationLevel Detailed -Verbose }
```