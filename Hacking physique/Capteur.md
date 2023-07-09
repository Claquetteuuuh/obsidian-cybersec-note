
# __Velleman VMA 405__

- [Branchement](##**Branchement**)
- [Software](##**Software**)
- [Code](##**Code**)
- [Documentation](##**Documentation**)


## **Branchement**

Il faut bien respecter le branchement sinon on pourrai endomager le matériel.
| VMA 405 pin | Rasp Pin    |
| ----------- | ----------- |
| VCC         | 1 - 3V3     |
| RST         | 15 - GPIO22 |
| GND         | 39 - GROUND |
| MISO        | 21 - MISO   |
| MOSI        | 19 - MOSI   |
| SCK         | 23 - SCLK   |
| NSS         | 24 - GPIO8  |
| IRQ         | -            |

![[schema-RPi]]


## **Software**

On doit effectuer quelques parametrage et téléchargement avant d'écrire notre script.

```shell
pi@raspberrypi:~ $ sudo raspi-config
```

![[interface1.png]]

![[interface2.png]]

![[interface3.png]]

```shell
pi@raspberrypi:~ $ sudo reboot
```

```shell
pi@raspberrypi:~ $ lsmod | grep spi
spidev                 20480  0
spi_bcm2835            20480  0 # s'il y a cette ligne c'est bon
```

```shell
pi@raspberrypi:~ $ sudo apt update && sudo apt upgrade -y
```

```shell
pi@raspberrypi:~ $ sudo pip3 install spidev mfrc522
```


## **Code**

**Read.py**

```python
#!/usr/bin/env python

import RPi.GPIO as GPIO
from mfrc522 import SimpleMFRC522
import time

reader = SimpleMFRC522()

try:
    while True:
        id, text = reader.read()
        if id == "216736162652":
        print(f"id : {id}")
        print(text)
        time.sleep(2)

except KeyboardInterrupt:
    GPIO.cleanup()

finally:
    GPIO.cleanup()
```

**Write.py**

```python
#!/usr/bin/env python

import RPi.GPIO as GPIO 
from mfrc522 import SimpleMFRC522

reader = SimpleMFRC522() 

try: 
	text = input('New data:')
	print("Now place your tag to write")
	reader.write(text)
	print("Written")
	
finally:
	GPIO.cleanup()
```


## **Documentation**

- [Mode d'emploi](https://www.velleman.eu/downloads/29/vma405_a4v03.pdf)

- [Scripts](https://pimylifeup.com/raspberry-pi-rfid-rc522/)

- ![[mode-emploi.png]]

- ![[schema-pin.png]]
