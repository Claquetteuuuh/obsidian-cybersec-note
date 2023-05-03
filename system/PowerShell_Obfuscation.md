Source : https://github.com/t3l3machus/PowerShell-Obfuscation-Bible/blob/main/README.md

L'**obfuscation** est le fait de **rendre** un payload **plus obscure** afin d'**évader** les protections **Antivirus**.

## __Entropie__

L'**entropie** est une notion mathématique qui vise à **mesurer** à quel point un **payload est aléatoire**, si une chaine est composé exclusivement d'un seul caractère son entropie sera 0, **plus il y a de caractère différent plus l'entropie va augmenter**, le calcul prend aussi en compte la **fréquence d'apparition** de ces caractères.

Pour la calculer on a implémenté la **formule** de **Claude E. Shannon** en python :

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

Avant d'effectuer une tentative d'obscusissement du code, il faut savoir ce qui déclanche l'alerte, pour se faire, on peut utiliser **[AMSITrigger](https://github.com/RythmStick/AMSITrigger)**.

