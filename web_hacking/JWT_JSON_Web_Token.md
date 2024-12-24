A JWT is composed of three component:
- **Header**: It indicate the type of token and what signing algorithm is used.
- **Payload**: It is the body of the token, where the information that we want to store are stored.
- **Signature**: The signature is the part of the token that confirm that the token is authentic.

![[Pasted image 20241221181606.png]]
## Signing algorithm
- **None**: The none algorithm mean that there is no algorithm used for signature.
- **Symmetric Signing**: Such as HS265, append a secret value in the header and the body of the token before encrypt it.
- **Asymmetric Signing**: Such as RS256, encrypt the payload with a private key, and every system that have the public key associate with the private key can perform the verification of the signature.
# Issue with JWT
## Sensitive information disclosure
```python
payload = {
	"username" : username,
	"password" : password,
	"admin" : 0,
	"flag" : "[redacted]" 
}

access_token = jwt.encode(payload, self.secret, algorithm="HS256")
```

Here the `flag` property contain a sensitive information.
We can easily decode the token in the https://jwt.io/ website for exemple:
![[Pasted image 20241222173639.png]]
## Signature validation mistake
```python
payload = jwt.decode(token, options={'verify_signature': False})
```
The fix:
```python
payload = jwt.decode(token, self.secret, algorithms="HS256")
```
Here you can edit easily the content of the payload and don't care about the signature validation.
## Weak symmetric secrets
If the symmetric **secret is easy to guess**, you can find it with **hashcat** for exemple:
```bash
$ hashcat -m 16500 -a 0 jwt.txt jwt.secrets.list.txt --show
eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VybmFtZSI6InVzZXIiLCJhZG1pbiI6MH0.yN1f3Rq8b26KEUYHCZbEwEk6LVzRYtbGzJMFIF8i5HY:secret
```
Here you can see that the key found is  `secret`.
Now you can use this key too create a signed JWT.
