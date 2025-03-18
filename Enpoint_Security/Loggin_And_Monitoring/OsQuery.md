Osquery is an open-source tool created by Facebook. It offer to Security Analysts, Incident Responders, and Threat Hunters can query an endpoint (or multiple endpoints) using SQL syntax.

To start the interactive mode.
```powershell
C:\Users\Administrator\> osqueryi
Using a virtual database. Need help, type 'help' 
osquery>
```

```powershell
osquery> select pid,name,path from processes where name='lsass.exe';
+-----+-----------+-------------------------------+
| pid | name      | path                          |
+-----+-----------+-------------------------------+
| 748 | lsass.exe | C:\Windows\System32\lsass.exe |
+-----+-----------+-------------------------------+

osquery>
```
## List the table
```powershell
osquery> .table
  => appcompat_shims
  => arp_cache
  => atom_packages
  => authenticode
  => autoexec
  => azure_instance_metadata
  (...)
  => chrome_extension_content_scripts
```
Filter in table
```powershell
osquery> .table user
  => user_groups
  => user_ssh_keys
  => userassist
  => users
```
### Exemple of tables
| name           | content                                                                                 |
| -------------- | --------------------------------------------------------------------------------------- |
| **userassist** | Store process execution evidence in Windows OS                                          |
| **autoexec**   | contains the list of executables that are automatically executed on the target machine. |
## Understand the schema of a table
https://osquery.io/schema/5.5.1/

```powershell
osquery> .schema users
CREATE TABLE users(`uid` BIGINT, `gid` BIGINT, `uid_signed` BIGINT, `gid_signed` BIGINT, `username` TEXT, `description` TEXT, `directory` TEXT, `shell` TEXT, `uuid` TEXT, `type` TEXT, `is_hidden` INTEGER HIDDEN, `pid_with_namespace` INTEGER HIDDEN, PRIMARY KEY (`uid`, `username`, `uuid`, `pid_with_namespace`)) WITHOUT ROWID;

```
## CheatSheet
### Principes de base
- Osquery utilise un sous-ensemble de SQL basé sur SQLite
- Principalement des requêtes en lecture seule (SELECT)
- Les requêtes se terminent par un point-virgule (;)
- Commandes de base: `.schema`, `.tables`, `.help`
### Structure des requêtes

```sql
SELECT colonne1, colonne2, ... FROM table 
[WHERE condition] 
[GROUP BY colonne] 
[ORDER BY colonne [ASC|DESC]] 
[LIMIT nombre];
```
### Fonctions utiles

- `count(*)` - Compter le nombre de lignes
- `distinct` - Éliminer les doublons
- `LIKE` - Recherche avec motifs
- `JOIN` - Joindre des tables
### Opérateurs de comparaison

| Opérateur | Description           |
| --------- | --------------------- |
| =         | Égal à                |
| <>        | Différent de          |
| >         | Supérieur à           |
| >=        | Supérieur ou égal à   |
| <         | Inférieur à           |
| <=        | Inférieur ou égal à   |
| BETWEEN   | Entre deux valeurs    |
| LIKE      | Correspond à un motif |
### Caractères spéciaux (wildcards)

| Caractère | Description                               |
| --------- | ----------------------------------------- |
| %         | Remplace zéro, un ou plusieurs caractères |
| _         | Remplace exactement un caractère          |
### Correspondance de chemins

| Modèle | Description                                           |
| ------ | ----------------------------------------------------- |
| %      | Correspond à tous les fichiers/dossiers sur un niveau |
| %%     | Correspond à tous les fichiers/dossiers récursivement |
| %abc   | Correspond à tout ce qui se termine par "abc"         |
| abc%   | Correspond à tout ce qui commence par "abc"           |
### Exemples de requêtes

```sql
-- Afficher les programmes installés
SELECT name, version, install_location FROM programs LIMIT 10;

-- Compter les programmes installés
SELECT count(*) FROM programs;

-- Filtrer les utilisateurs
SELECT * FROM users WHERE username='James';

-- Joindre des tables
SELECT p.pid, p.name, p.path, u.username FROM processes p 
JOIN users u ON u.uid=p.uid LIMIT 10;

-- Recherche avec motifs
SELECT * FROM programs WHERE name LIKE '%Chrome%';
```
### Tables courantes

- `processes` - Processus en cours d'exécution
- `users` - Utilisateurs du système
- `programs` - Programmes installés
- `listening_ports` - Ports en écoute
- `services` - Services système
- `file` - Informations sur les fichiers (requiert WHERE)
- `registry` - Clés de registre (Windows)
