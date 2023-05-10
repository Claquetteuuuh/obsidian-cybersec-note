
## __SYN Scan__

Pour analyser l'état des ports d'une machine dans un réseaux via un SYN Scan.

```powershell
<PORT_1>, <PORT_2> | % { Test-NetConnection 192.168.1.100 -Port $_ -InformationLevel Detailed -Verbose }
```

Ou la fonction

```powershell
Function New-TcpConnectScan{
    Param(
        [Parameter(Mandatory=$true)][IPAddress[]] $IPs,
        [Parameter(Mandatory=$true)][Int16[]] $Ports
    )  
    Process {
        foreach($ip in $IPs){
            foreach($port in $Ports){
                $Results = Test-NetConnection $ip -Port $port -InformationLevel Detailed -Verbose
                if($Results.TcpTestSucceeded){
                    Write-Host "Le port TCP $port est ouvert sur la machine $ip"
                }
            }
        }
    }
}

New-TcpConnectScan -IPs "<IP>" -Ports <PORT>
```

Pour une utilisation plus puissante voir https://github.com/BornToBeRoot/PowerShell_IPv4PortScanner.

