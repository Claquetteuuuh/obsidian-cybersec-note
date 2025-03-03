# Get
To find a GET request we have to put the Magic Numbers (GET in hexadecimal).
```bash
alert tcp any any <> any 80 (msg: "GET Request Found";content:"|47 45 54|";sid:10002;rev:1;)
```
