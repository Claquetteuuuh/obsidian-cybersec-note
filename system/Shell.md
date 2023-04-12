
Un shell est une interface homme machine en ligne de commande.

## __Outils__

Pour mettre en place des reverses shells, on a une mutltitude d'outils disponible.

### Netcat

**Netcat** peut être utilisé pour effectuer beaucoup de choses comme du **banner grabbing** pendant des énumérations. Mais l'usage principale qu'on va en faire est de **pouvoir recevoir une connection** depuis un port.

### Socat

**Socat** peut faire **tous ce que Netcat peut faire** mais aussi **beaucoup d'autres choses**. Les shells socat sont **plus stable** que les shells Netcat.

Les 2 problèmes de socat comparé à Netcat sont :
- La syntaxe est **plus difficile**
- Netcat est installé sur pratiquement toutes les distributions Linux par défaut. Socat est **très rarement installé** par défaut.

### Metasploit multi/handler

C'est le module **`exploit/multi/handler`** de metasploit, il a les **mêmes fonctionnalités** que Netcat ou Socat mais c'est le seul moyen d'intéragir avec un **shell meterpreter** et de gérer des **payloads metasploit**.

### Msfvenom

**Msfvenom** fait aussi partie de msf - metasploit framework, mais c'est un **outil indépendant**. Il est utilisé pour créer des payloads et **aussi des reverses shell**.

### Autres

On peut **[créer des reverses shell pour des langages de programation en particulier ou pour un os particulier](Reverse_shell##__Scripts__)**.


## __Types de shell__

### Reverse shell

Un **reverse shell** est ce qui se produit quand une cible **éxécute un code qui se connecte à notre machine**. L'avantage d'un reverse shell est qu'on contourne les règles des firewalls, cependant le problème est qu'on est obligé de notre coté de configurer notre réseau pour accepter ce shell.
