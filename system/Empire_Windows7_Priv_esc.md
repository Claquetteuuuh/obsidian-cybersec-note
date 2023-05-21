
A partir de **Windows Vista**, le concept d'**UAC** (User Account Control) à été introduit ce qui permet au process d'avoir **3 niveaux differents de permission** :

- **HIGH**: Droit **administrateur**
- **MEDIUM**: Droit d'**utilisateur** standard
- **LOW**: **Restreint** à certaines autorisations

## __High_integrity__

Pour avoir l'information sur les permissions que nous avons sur notre backdoor Empire, on execute la commande **[`info`](Powershell_empire#####Info)**. La ligne **high_integrity**, par defaut False, indique notre niveau de permission.

```shell
(Empire: GYRE59LF) > info

┌Agent Options─────┬───────────────────────────────────────────────┐
│ session_id       │ GYRE59LF                                      │
├──────────────────┼───────────────────────────────────────────────┤
│ name             │ GYRE59LF                                      │
├──────────────────┼───────────────────────────────────────────────┤
│ listener         │ http                                          │
├──────────────────┼───────────────────────────────────────────────┤
│ host_id          │ 3001                                          │
├──────────────────┼───────────────────────────────────────────────┤
│ hostname         │ LAPTOP-A0JERQ2D                               │
├──────────────────┼───────────────────────────────────────────────┤
│ language         │ powershell                                    │
├──────────────────┼───────────────────────────────────────────────┤
│ language_version │ 5                                             │
├──────────────────┼───────────────────────────────────────────────┤
│ delay            │ 5                                             │
├──────────────────┼───────────────────────────────────────────────┤
│ jitter           │ 0.0                                           │
├──────────────────┼───────────────────────────────────────────────┤
│ external_ip      │ 192.168.106.1                                 │
├──────────────────┼───────────────────────────────────────────────┤
│ internal_ip      │ 192.168.23.1                                  │
├──────────────────┼───────────────────────────────────────────────┤
│ username         │ LAPTOP\User                        │
├──────────────────┼───────────────────────────────────────────────┤
│ high_integrity   │ False                                         │
├──────────────────┼───────────────────────────────────────────────┤
│ process_id       │ 12828                                         │
├──────────────────┼───────────────────────────────────────────────┤
(...)
```