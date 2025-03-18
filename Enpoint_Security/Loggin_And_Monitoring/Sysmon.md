Sysmon, a tool used to **monitor and log events** on Windows, is commonly used by enterprises as part of their monitoring and logging solutions.
It **gathers detailed** and **high-quality logs** as well as event tracing that assists in **identifying anomalies** in your environment.
It is commonly used with a **security information and event management (SIEM)** system or other log parsing solutions.

# Starting Sysmon
```shell
Sysmon.exe -accepteula -i ..\Configuration\swift.xml
```

If it is installed correctly you will se this logs:
![[Pasted image 20250311105426.png]]

