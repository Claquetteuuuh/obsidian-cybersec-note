# Detect Login Failed
Here is the rule to detect failted FTP attempt.
```bash
alert tcp any any <> any 21 (msg: "Login failed attempt";sid:100001;rev:1;content:"530";)
```
# Detect Login Successful
Here is the rule to detect successful FTP attempt.
```bash
alert tcp any any <> any 21 (msg: "Login successfull attempt";sid:100001;rev:1;content:"230";)
```
# Detect Valid username No password
Here is the rule to detect failed FTP attempt with valid username and invalid password.
```bash
alert tcp any any <> any 21 (msg: "Login successfull attempt";sid:100001;rev:1;content:"331 password";)
```
# Detect Administrator username No password
Here is the rule to detect failed FTP attempt with valid username: Administrator and invalid password.
```bash
alert tcp any any <> any 21 (msg: "Login successfull attempt";sid:100001;rev:1;content:"331 password";content:"Administrator";)
```
