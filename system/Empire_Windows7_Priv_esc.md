
A partir de **Windows Vista**, le concept d'**UAC** (User Account Control) à été introduit ce qui permet au process d'avoir **3 niveaux differents de permission** :

- **HIGH**: Droit **administrateur**
- **MEDIUM**: Droit d'**utilisateur** standard
- **LOW**: **Restreint** à certaines autorisations

## __High_integrity__

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

Il est donc possible sur notre client windows 7 de passer administrateur avec la commande `bypassuac`