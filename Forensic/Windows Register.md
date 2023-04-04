
## __Registers__

Les **registres windows** sont une base de données de **donnés de configuration système** à propos de **matériel**, **logiciel**, **utilisateurs**.

Pour récuperer les registres ils faut lancer **regedit.exe**.

| **Dossier/clé prédéfinie** | Description                                                                                                               |
| -------------------------- | ------------------------------------------------------------------------------------------------------------------------- |
| **HKEY_CURRENT_USER**      | Les **informations** à propos de l'**utilisateur actuellement connecté**: dossiers, screen colors, control pannel. *HKCU* |
| **HKEY_USERS**             | Tout les utilisateurs chargé sur la machine. *HKU*                                                                        |
| **HKEY_LOCAL_MACHINE**     | **Information de configuration** de la machine. *HKLM*                                                                                      |
| **HKEY_CLASSES_ROOT**      | Fusionne la vue des registres `HKEY_LOCAL_MACHINE\Software\Classes` et `HKEY_CURRENT_USER\Software\Classes`. **`HKCR`**   |
| **HKEY_CURRENT_CONFIG**    | Information sur le **hardware profile** utilisé par la machine.                                                                                                                           |


## __Hives__

Les hives sont des fichiers contenant ce qui s'est passé sur la machine.

La plupart de ces hives sont dans `C:\Windows\System32\Config` :

- **DEFAULT** (mounted on `HKEY_USERS\DEFAULT`)

- **SAM** (mounted on `HKEY_LOCAL_MACHINE\SAM`)

- **SECURITY** (mounted on `HKEY_LOCAL_MACHINE\Security`)

- **SOFTWARE** (mounted on `HKEY_LOCAL_MACHINE\Software`)

- **SYSTEM** (mounted on `HKEY_LOCAL_MACHINE\System`)


D'autres hives sert à avoir les **informations sur un utilisateur** :

- **NTUSER.DAT** (mounted on HKEY_CURRENT_USER when a user logs in), il est sauvegardé dans le dossier `C:\Users\<username>\`.

- **USRCLASS.DAT** (mounted on `HKEY_CURRENT_USER\Software\CLASSES`), il est sauvegardé dans le disque dans `C:\Users\<username>\AppData\Local\Microsoft\Windows`.

Un hive important est le *AmCache*, il consigne des **metadonnées** sur l'**execution** et l'**installation** de programmes sur un systeme. `C:\Windows\AppCompat\Programs\Amcache.hve`.


