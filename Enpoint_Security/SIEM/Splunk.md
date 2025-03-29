# Splunk Component
![[Pasted image 20250329095704.png]]
## Splunk Forwarder
This is a lightweight agent installed on the endpoint intended to be monitored. 
His main task is to collect the data and send it to the Splunk instance.
Some of the key data sources are:
- Web server generating web traffic.
- Windows machine generating Windows Event Logs, PowerShell, and Sysmon data.
- Linux host generating host-centric logs.
- Database generating DB connection requests, responses, and errors.
![[Pasted image 20250329095818.png]]
## Splunk Indexer
It plays the main role in processing the data it receives from forwarders.
It take the data and normalizes it into field-value pairs.
## Search Head
This is the place within the Search & Reporting App where users can search the indexed logs.
When the user searches for a term or uses a Search language known as Splunk Search Processing Language, the request is sent to the indexer and the relevant events are returned
![[Pasted image 20250329100022.png]]
![[Pasted image 20250329100028.png]]
# Adding data
![[Pasted image 20250329100550.png]]
## VPN logs
![[Pasted image 20250329100602.png]]

We will use the Upload option.
It has a total of 5 steps to successfully upload the data:
1. **Select Source** -> Where we select the Log source.
2. **Select Source Type** -> Select what type of logs are being ingested.
3. **Input Settings** ->Select the index where these logs will be dumped and hostName to be associated with the logs.  
4. **Review** -> Review all the gif  
5. **Done** -> Final step, where the data is uploaded successfully and ready to be analyzed.
![[c36a6f1c70007602251f331aee914d5c.gif]]
