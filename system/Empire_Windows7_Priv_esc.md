
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

Certains objets COM ont la capacité d'élever leurs p
