Osquery is an open-source tool created by Facebook. It offer to Security Analysts, Incident Responders, and Threat Hunters can query an endpoint (or multiple endpoints) using SQL syntax.

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