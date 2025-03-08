The steganography is the fact to hide a text in an image:

![[dark_1578020060816.png]]
We can use tools like stegsolve to find the message in:
**Download**
```bash
wget http://www.caesum.com/handbook/Stegsolve.jar -O stegsolve.jar
chmod +x stegsolve.jar
mkdir bin
mv stegsolve.jar bin/
```
**Run it**
```bash
$ java -jar bin/stegsolve.jar
Picked up _JAVA_OPTIONS: -Dawt.useSystemAAFontSettings=on -Dswing.aatext=true
```
![[Pasted image 20250308120852.png]]
