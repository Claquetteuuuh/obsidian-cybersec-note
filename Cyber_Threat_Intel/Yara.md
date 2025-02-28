Yara can identify information based on both **binary** and **textual patterns**, such as hexadecimal and **strings contained within a file**.
For exemple we can detect the "Hello world" string in a software
# Why malware use strings  
| **Type**   | **Data**                                                                                                        | **Description**                                        |
| ---------- | --------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------ |
| Ransomware | [12t9YDPgwueZ9NyMgw519p7AA8isjr6SMw](https://www.blockchain.com/btc/address/12t9YDPgwueZ9NyMgw519p7AA8isjr6SMw) | Bitcoin Wallet for ransom payments                     |
| Botnet     | 12.34.56.7                                                                                                      | The IP address of the Command and Control (C&C) server |
# Rule
## Easy rule
### Create the rule
You have to create a file `.yar`:
```bash
touch myfirstrule.yar
```
In this file you can put:
```yaml
rule examplerule {
    condition: true
}
```
### Test the rule
If the file exists:
```bash
$ yara myfirstrule.yar somefile
examplerule somefile
```
If the file doesn't exists:
```bash
$ yara myfirstrule.yar sometextfile
error scanning sometextfile: could not open file
```
## Other rules
You can see all the rules in https://yara.readthedocs.io/en/stable/writingrules.html
![[Pasted image 20250227163801.png]]
### Meta
This is a section to talk about the **informations** of the rule, for exemple you can use `desc` to put a **description**.
### Strings
If we want to search in a directory all the files that contains "Hello world !":
```yaml
rule helloworld_checker{
	strings:
		$hello_world = "Hello World!"
}
```

After we have to put a condition to validate the rule:
```yaml
rule helloworld_checker{
	strings:
		$hello_world = "Hello World!"

	condition:
		$hello_world
}
```

We can put more strings in the condition:
```yaml
rule helloworld_checker{
	strings:
		$hello_world = "Hello World!"
		$hello_world_lowercase = "hello world"
		$hello_world_uppercase = "HELLO WORLD"

	condition:
		any of them
}
```
### Conditions
We can use others conditions like **!=** or **<=** or **>=**:
```yaml
rule helloworld_checker{
	strings:
		$hello_world = "Hello World!"

	condition:
        #hello_world <= 10
}
```
### Combining keywords
Moreover, you can use keywords such as:
- **and**
- **not**
- **or**
```yaml
rule helloworld_checker{
	strings:
		$hello_world = "Hello World!" 
        
        condition:
	        $hello_world and filesize < 10KB 
}
```
# Loki
Loki is an automated Yara tool.
```bash
user:~/suspicious-files/file1$ python ../../tools/Loki/loki.py -p .
                                                                               
      __   ____  __ ______                            
     / /  / __ \/ //_/  _/                            
    / /__/ /_/ / ,< _/ /                              
   /____/\____/_/|_/___/                              
      ________  _____  ____                           
     /  _/ __ \/ ___/ / __/______ ____  ___  ___ ____ 
    _/ // /_/ / /__  _\ \/ __/ _ `/ _ \/ _ \/ -_) __/ 
   /___/\____/\___/ /___/\__/\_,_/_//_/_//_/\__/_/    

   Copyright by Florian Roth, Released under the GNU General Public License
   Version 0.32.1
  
   DISCLAIMER - USE AT YOUR OWN RISK
   Please report false positives via https://github.com/Neo23x0/Loki/issues
  
                                                                               

[NOTICE] Starting Loki Scan VERSION: 0.32.1 SYSTEM: thm-yara TIME: 20250227T15:41:52Z
 PLATFORM:     PROC: x86_64 ARCH: 64bit 
[NOTICE] Registered plugin PluginWMI
[NOTICE] Loaded plugin /home/cmnatic/tools/Loki/plugins/loki-plugin-wmi.py
[NOTICE] PE-Sieve successfully initialized BINARY: /home/cmnatic/tools/Loki/tools/pe-
sieve64.exe SOURCE: https://github.com/hasherezade/pe-sieve
[INFO] File Name Characteristics initialized with 2841 regex patterns
[INFO] C2 server indicators initialized with 1541 elements
[INFO] Malicious MD5 Hashes initialized with 19034 hashes
[INFO] Malicious SHA1 Hashes initialized with 7159 hashes
[INFO] Malicious SHA256 Hashes initialized with 22841 hashes
[INFO] False Positive Hashes initialized with 30 hashes
[INFO] Processing YARA rules folder /home/cmnatic/tools/Loki/signature-base/yara
[INFO] Initializing all YARA rules at once (composed string of all rule files)
[INFO] Initialized 653 Yara rules
[INFO] Reading private rules from binary ...
[NOTICE] Program should be run as 'root' to ensure all access rights to process memory and file objects.
```
# YarGen
[YarGen](https://github.com/Neo23x0/yarGen) is a way to **create yara rules**.

For exemple, if you want to find a specific string in a file, you can look all the line but it can be hard if the number of line in the file is too big.
```shell
strings <file> | wc -l # Look the number of line in a file
```
## Update
Before running any command, you have to update the code of yaraGen:
```bash
python3 yarGen.py --update
```
## Generate a rule
To generate a rule for a specific directory:
```bash
python3 yarGen.py -m /home/cmnatic/<PATH> --excludegood -o /home/cmnatic/suspicious-files/file2.yar
```
**`-m`**: Specify the path
**`--excludegood`**: Remove the fake positive
**`-o`** The Path where you want to store the rule
# Valhalla
[Valhalla](https://www.nextron-systems.com/valhalla/) is a tool created by Florian Roth, the same guy who created all the tools before.
This tool has been created to **improve the detection capacity** with a thousands yara rules.

![[Pasted image 20250228111837.png]]
