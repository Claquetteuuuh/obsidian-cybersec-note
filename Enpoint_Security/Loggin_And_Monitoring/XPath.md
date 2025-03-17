Xpath (**XML Path Language**) is a filtering log tool to provide a standard syntax and scemantics for addressing parts of an XML document and manipulate strings, numbers, booleans.

An XPath event query starts with '**\***' or '**Event**'.

https://learn.microsoft.com/en-us/previous-versions/dotnet/netframework-4.0/ms256115(v=vs.100)

Here is a query for exemple
```powershell
Get-WinEvent -LogName Security -FilterXPath '*/EventData/Data[@Name="TargetUserName"]="Sam" and */System/EventID=4720'
```

```powershell
PS C:\Users\Administrator> Get-WinEvent -LogName Application -FilterXPath '*/System/EventID=100'

   ProviderName: WLMS

TimeCreated                     Id LevelDisplayName Message
-----------                     -- ---------------- -------
12/21/2020 4:23:47 AM          100
12/18/2020 3:18:57 PM          100
12/15/2020 8:50:22 AM          100
12/15/2020 8:18:34 AM          100
12/15/2020 7:48:34 AM          100
12/14/2020 6:42:18 PM          100
12/14/2020 6:12:18 PM          100
12/14/2020 5:39:08 PM          100
12/14/2020 5:09:08 PM          100
```

This was done to retrieve just 1 event and for it not to contain any XML tags.
```powershell
PS C:\Users\Administrator> wevtutil.exe qe Application /q:*/System[EventID=100] /f:text /c:1
Event[0]:
  Log Name: Application
  Source: WLMS
  Date: 2020-12-14T17:09:08.940
  Event ID: 100
  Task: None
  Level: Information
  Opcode: Info
  Keyword: Classic
  User: N/A
  User Name: N/A
  Computer: WIN-1O0UJBNP9G7
  Description:
N/A
```

