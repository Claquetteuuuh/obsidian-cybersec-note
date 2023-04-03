
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

Répertoire 