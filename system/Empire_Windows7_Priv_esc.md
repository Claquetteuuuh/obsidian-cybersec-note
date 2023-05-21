
A partir de **Windows Vista**, le concept d'**UAC** (User Account Control) à été introduit ce qui permet au process d'avoir **3 niveaux differents de permission** :

- **HIGH**: Droit **administrateur**
- **MEDIUM**: Droit d'**utilisateur** standard
- **LOW**: **Restreint** à certaines autorisations

## __High_integrity__

Pour avoir l'information sur les permissions que nous avons sur notre backdoor Empire, on execute la commande **[`info`](Powershell_empire#####Info)**. La ligne **high_integrity** (par defaut False), 