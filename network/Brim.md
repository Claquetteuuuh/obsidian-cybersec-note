This is an open-source desktop app that **processes pcap files and logs files**, with a focus on providing **search and analytics**.

It can handle two types of data as an input:
- **Packet Capture Files**: Pcap files created with tcpdump, tshark and Wireshark like applications.
- **Log Files**: Structured log files like Zeek logs.

Brim is built on open-source platforms:
- **Zeek:** Log generating engine.
- **Zed Language:** Log querying language that allows performing keywoırd searches with filters and pipelines.
- **ZNG Data Format:** Data storage format that supports saving data streams.
- **Electron and React:** Cross-platform UI.
# Brim vs Wireshark vs Zeek
|                          | Brim                                                 | Wireshark                                                           | Zeek                                                 |
| ------------------------ | ---------------------------------------------------- | ------------------------------------------------------------------- | ---------------------------------------------------- |
| Purpose                  | Pcap processing; event/stream and log investigation. | Traffic sniffing. Pcap processing; packet and stream investigation. | Pcap processing; event/stream and log investigation. |
| GUI                      | ✔                                                    | ✔                                                                   | ✖                                                    |
| Sniffing                 | ✖                                                    | ✔                                                                   | ✔                                                    |
| Pcap processing          | ✔                                                    | ✔                                                                   | ✔                                                    |
| Log processing           | ✔                                                    | ✖                                                                   | ✔                                                    |
| Packet decoding          | ✖                                                    | ✔                                                                   | ✔                                                    |
| Filtering                | ✔                                                    | ✔                                                                   | ✔                                                    |
| Scripting                | ✖                                                    | ✖                                                                   | ✔                                                    |
| Signature Support        | ✔                                                    | ✖                                                                   | ✔                                                    |
| Statistics               | ✔                                                    | ✔                                                                   | ✔                                                    |
| File Extraction          | ✖                                                    | ✔                                                                   | ✔                                                    |
| Handling  pcaps over 1GB | Medium performance                                   | Low performance                                                     | Good performance                                     |
| Ease of Management       | 4/5                                                  | 4/5                                                                 | 3/5                                                  |
# Queries
## Connection Analysis Queries
### Unique Network Connections
Displays source and destination IP addresses and ports:

```
_path=="conn" | put total_bytes := orig_bytes + resp_bytes | sort -r total_bytes | cut uid, id.orig_h, id.orig_p, id.resp_h, id.resp_p, orig_bytes, resp_bytes, total_bytes
```
This query:
- Filters for connection logs
- Calculates total bytes (sum of originating and responding bytes)
- Sorts by total bytes (descending)
- Displays connection identifiers, IPs, ports, and byte counts

**Sample Results:**

| id.orig_h                | id.orig_p | id.resp_h           | id.resp_p |
| ------------------------ | --------- | ------------------- | --------- |
| 192.168.121.2            | 14        | 192.168.120.1       | 22        |
| 2003:51:6012:110::b15:22 | 22        | 2003:51:6012:121::2 | 53        |
| 192.168.47.171           | 25        | 192.168.47.134      | 53        |
### Traffic Volume Analysis
This analysis shows:

| orig_bytes | resp_bytes | total_bytes |
| ---------- | ---------- | ----------- |
| 7,517      | 15,159     | 22,676      |
| 8,856      | 0          | 8,856       |
| 5,682      | 3,340      | 8,922       |
## DNS and HTTP Analysis
### DNS Query Counting
Count DNS queries by domain:

```
_path=="dns" | count() by query | sort -r
```

**Sample Results:**

| query              | count |
| ------------------ | ----- |
| blog.webernetz.net | 15    |
| ip.webernetz.net   | 1     |
### HTTP Methods Analysis
Extract HTTP requests with details:

```
_path=="http" | cut id.orig_h, id.resp_h, id.resp_p, method, host, uri | uniq -c
```

**Sample Results:**

| value.id.orig_h | value.id.resp_h | value.id.resp_p | value.method | value.host          | value.uri     |
| --------------- | --------------- | --------------- | ------------ | ------------------- | ------------- |
| 10.10.57.178    | 44.228.249.3    | 80              | GET          | testphp.vulnweb.com | /login.php    |
| 10.10.57.178    | 44.228.249.3    | 80              | POST         | testphp.vulnweb.com | /userinfo.php |
| 10.10.57.178    | 44.228.249.3    | 80              | GET          | testphp.vulnweb.com | /favicon.ico  |
## File Activity Analysis
Detect file transfers and potential data exfiltration:

```
filename!=null | cut _path, tx_hosts, rx_hosts, conn_uids, mime_type, filename, md5, sha1
```

This query extracts:

- File transfer paths
- Source and destination hosts
- Connection IDs
- MIME types
- Filenames
- MD5 and SHA1 hashes

**Sample Results:**

| _path | tx_hosts         | rx_hosts         | conn_uids            | mime_type             | filename                       | md5               | sha1                |
| ----- | ---------------- | ---------------- | -------------------- | --------------------- | ------------------------------ | ----------------- | ------------------- |
| files | [192.168.1.46]   | [192.168.1.195]  | [CB9FopzThrS3josSZg] | application/x-dosexec | System32\RemComSvc.exe         | dd1ee675ffa45f... | 1eb042aa5dcbc24f... |
| files | [192.168.1.195]  | [192.168.1.46]   | [CXQBxaZD98XMf6vif]  | text/ini              | picklesworth.local\Policies... | fc43c7b00e42d4... | 2bb3a5d51aef3e...   |
| files | [192.168.47.171] | [192.168.47.134] | [Clx16oLezaN2eKWgb]  | image/gif             | cat01_with_hidden_text.gif     | 10117e6475c7a...  | af5da3f828cdbada... |
| files | [192.168.47.171] | [192.168.47.134] | [Clx16oLezaN2eKWgb]  | image/jpeg            | ehealth.jpg                    | 1a3351ba62ff2f... | 9f6a4e797846a8...   |
## IP Subnet Statistics
Analyze network traffic by subnet:

```
_path=="conn" | put classnet := network_of(id.resp_h) | cut classnet | count() by classnet | sort -r
```

**Sample Results:**

| classnet         | count |
| ---------------- | ----- |
| 192.168.1.0/24   | 17    |
| 224.0.0.0/24     | 10    |
| 192.168.120.0/24 | 10    |
## Suricata Alerts
Zeek can integrate with Suricata, an open-source threat detection engine that acts as a rule-based Intrusion Detection and Prevention System.
### Alerts by Category
```
event_type=="alert" | count() by alert.severity,alert.category | sort count
```

**Sample Results:**

| alert.severity | alert.category                        | count |
| -------------- | ------------------------------------- | ----- |
| 1              | Attempted User Privilege Gain         | 1     |
| 3              | Generic Protocol Command Decode       | 1     |
| 1              | Potential Corporate Privacy Violation | 2     |
### Alerts by Source and Destination
```
event_type=="alert" | alerts := union(alert.category) by src_ip, dest_ip
```

**Sample Results:**

| src_ip         | dest_ip        | alerts                                  |
| -------------- | -------------- | --------------------------------------- |
| 192.168.1.46   | 192.168.1.195  | [Attempted User Privilege Gain]         |
| 192.168.47.134 | 192.168.47.171 | [Generic Protocol Command Decode]       |
| 10.10.57.178   | 44.228.249.3   | [Potential Corporate Privacy Violation] |
### Alerts by Subnet
```
event_type=="alert" | alerts := union(alert.category) by network_of(dest_ip)
```

**Sample Results:**

| network_of      | alerts                                  |
| --------------- | --------------------------------------- |
| 44.0.0.0/8      | [Potential Corporate Privacy Violation] |
| 192.168.1.0/24  | [Attempted User Privilege Gain]         |
| 192.168.47.0/24 | [Generic Protocol Command Decode]       |
## Use case
### Référence des Requêtes Brim

| But                       | Syntaxe                              | Exemple de Requête                                                   |
| ------------------------- | ------------------------------------ | -------------------------------------------------------------------- |
| Recherche de base         | Valeur numérique ou texte            | 10.0.0.1                                                             |
| Opérateurs logiques       | Or, And, Not                         | 192 and NTP                                                          |
| Filtrer valeurs           | "nom du champ" == "valeur"           | id.orig_h==192.168.121.40                                            |
| Lister contenu spécifique | \_path=="nom du log"                 | _path=="conn"                                                        |
| Compter valeurs           | count () by "champ"                  | count () by _path                                                    |
| Trier résultats           | sort                                 | count () by _path \| sort -r                                         |
| Extraire champ spécifique | \_path=="conn" \| cut "nom du champ" | _path=="conn" \| cut id.orig_h, id.resp_p, id.resp_h                 |
| Lister valeurs uniques    | uniq                                 | _path=="conn" \| cut id.orig_h, id.resp_p, id.resp_h \| sort \| uniq |

**Note:** Il est recommandé d'utiliser les noms de champs et options de filtrage plutôt que des recherches irrégulières.
### Cas d'Utilisation Courants
#### Hôtes en Communication
```
_path=="conn" | cut id.orig_h, id.resp_h | sort | uniq
```
#### Hôtes Communiquant Fréquemment
```
_path=="conn" | cut id.orig_h, id.resp_h | sort | uniq -c | sort -r
```
#### Ports les Plus Actifs
```
_path=="conn" | cut id.resp_p, service | sort | uniq -c | sort -r count
```

```
_path=="conn" | cut id.orig_h, id.resp_h, id.resp_p, service | sort id.resp_p | uniq -c | sort -r
```
#### Connexions Longues
```
_path=="conn" | cut id.orig_h, id.resp_p, id.resp_h, duration | sort -r duration
```
#### Données Transférées

```
_path=="conn" | put total_bytes := orig_bytes + resp_bytes | sort -r total_bytes | cut uid, id, orig_bytes, resp_bytes, total_bytes
```
#### Requêtes DNS et HTTP
```
_path=="dns" | count () by query | sort -r
```

```
_path=="http" | count () by uri | sort -r
```
#### Noms d'Hôtes Suspects
```
_path=="dhcp" | cut host_name, domain
```
#### Adresses IP Suspectes

```
_path=="conn" | put classnet := network_of(id.resp_h) | cut classnet | count() by classnet | sort -r
```
#### Détecter les Fichiers

```
filename!=null
```
#### Activité SMB

```
_path=="dce_rpc" OR _path=="smb_mapping" OR _path=="smb_files"
```
#### Modèles Connus (Alertes)

```
event_type=="alert" or _path=="notice" or _path=="signatures"
```