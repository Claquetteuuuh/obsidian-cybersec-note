HTTP basic authentification is defined by https://datatracker.ietf.org/doc/html/rfc7617,
It's where username and password are transported in base64-encode string in the HTTP authorization header.
![[Pasted image 20241220110319.png]]
```html
Authorization: Basic <credentials>
```
# Bruteforce
We can bruteforce it using burp suite:
## Setup
### Decode the payload
![[Pasted image 20241220111328.png]]
### Set variable
Put the **§** char to create a variable.
![[Pasted image 20241220110649.png]]
### Create the payload
First load the payload, find a password file:
![[Pasted image 20241220110831.png]]
### Add payload processing
Create a payload processing:
![[Pasted image 20241220111008.png]]
#### Add a prefix for the username
![[Pasted image 20241220110936.png]]
#### Add a base64 encoding
![[Pasted image 20241220111051.png]]
## Found the good one
The length of the response should be different.
![[Pasted image 20241220110443.png]]![[Pasted image 20241220110455.png]]