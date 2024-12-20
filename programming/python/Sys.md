La librairie sys, qui est installé par défaut dans votre interpreteur python, nous permet d'effectuer plusieurs interactions directement avec le systeme.

# Informations
Nous pouvons **récupérer des informations sur l'OS**

```python
sys.version # Retourne la version de notre interpreteur
sys.executable # Retourne le chemin de notre interpreteur
sys.platform # Retourne l'OS
```

# Std
Nous pouvons **interagir avec les entrées et sorties système**, ce script permet de demander au client d'entrer quelque chose et de l'afficher ou de quitter cette boucle s'il entre "exit"

```python
for line in sys.stdin:
	if line.strip() == "exit":
		break
	sys.stdout.write(f">> {line}")
```

# Args
Nous pouvons récuperer les arguments passé lors de l'execution du script:

```python
print(sys.argv) # va afficher une liste d'arguments passé
```

```shell
$ python3 script.py blabla bla
>> ['script.py', 'blabla', 'bla']
```

# Path
Nous pouvons récuperer les chemins

```python
print(sys.path)
```

```shell
$ python3 script.py
>> [<CURRENT_DIRECTORY>, <PYTHON_LIB_DIRECTORY>, <EXECUTABLE>, <...LIBS>]
```

# Modules
Nous pouvons récuperer les modules auxquels ont a accès

```python
print(sys.modules)
```
