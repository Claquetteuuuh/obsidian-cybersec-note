
Le site [Malfrat's OSINT Map](https://map.malfrats.industries/) ou [Osint framework](https://osintframework.com/) répertorie plein de site utile pour la collecte d'information par categories.

Pour s'entrainer, on peut utiliser les sites: [Ozint](https://ozint.eu/), ou [Tryhackme](https://tryhackme.com)

## __Plaque D'imatriculation__

- [Platesmania](https://platesmania.com/?&lang=fr), Pour **récuperer des informations** sur des voitures.
- [Evaluer-chauffeur](https://evaluer-chauffeur.fr/), Pour connaitre si le mec **à déjà effectué une infraction**.
- [Carvertical](https://www.carvertical.com/be/fr), avoir les **infos sur un vehicule**.
- [Mister-auto](https://www.mister-auto.com/), avoir toutes les informations sur les caractéristiques d'un véhicule.

```python
import requests from pprint 
import pprint

api_key = '' 
image_path = 'opel.jpg'

with open(image_path, 'rb') as image_file:
	response = requests.post('https://api.platerecognizer.com/v1/plate-reader/', 
							 files={'upload': image_file},
							 headers={'Authorization': 'Token ' + api_key}) 
if response.status_code == 200:
	data = response.json() 
	marque = data['results'][0]['vehicle']['make'][0]['name']
	modele = data['results'][0]['vehicle']['model'][0]['name'] 
	date_premiere_immatriculation = data['results'][0]['vehicle']['year'] 
	pays = data['results'][0]['country'] 

pprint(response.json())
```


## __Geoint__

- [Geohints](https://www.geohints.com/), répertorie **à quoi ressemble** les choses selon les pays.
- [Insecam](http://insecam.org/en/byrating/), montre en directe **les flux de certaines caméra connu**.
- [Adsbexchange](https://globe.adsbexchange.com/), **trace**, et donne les **informations** des **avions** en direct.
- L'utilisation de **`geocode:LAT,LONG,PERIM`**, `geocode:46.99814523000534,5.1563632071226015,.4km` sur twitter.
- [zoom-earth](https://zoom.earth/), affiche les informations météorologique dans le monde.
- [blitzortung](https://www.blitzortung.org/fr/live_lightning_maps.php?map=60), affiche les éclaires en direct.


## __Network__

- [Mxtoolbox](https://mxtoolbox.com/), sorte de **[[Network_reconnaissance#Nslookup & Dig]] avancé**.
- [Wigle](https://wigle.net/), donne les **informations** sur un **BSSID**.
- [Pulsedive](https://pulsedive.com), whois plus poussé.
- [Netlas](https://app.netlas.io), **info personnelle** du mec qui achete le domaine.
- [Talos intelligence](https://talosintelligence.com/reputation_center/lookup?search=52.154.170.73), IP information.

## __Image__

- [Fotoforensic](https://fotoforensics.com/), **information** sur l'image.
- [Pimeyes](https://pimeyes.com/en), trouver là ou l'image à été **publié**.


## __Moteur de recherche avancé__

- [Onyphe](https://www.onyphe.io/), moteur de recherche avancé, donne accès à **toutes les informations qu'un hacker peut avoir**.
- [CriminalIp](https://www.criminalip.io/en), shodan en mieux.
- [Masterseek](https://www.masterseek.com/), google dork recherche par compagnie, pays, etc.


## __Base de donnée__

- [Haveibeenpawned](https://haveibeenpwned.com/), recherche si une adresse **email** ou un numero de **telephone** a **leak**.
- [Intelligencex](https://intelx.io/), recherche des **leaks dans des milions de db**.
- [Whatsmyname](https://whatsmyname.app/), lie des **pseudos** à des **domaines**.
- [Leakcheck](https://leakcheck.io/), donne les **credentials** d'une adresse mail / telephone / pseudo. Voir [[Comptes]]
- [Cavalier](https://cavalier.hudsonrock.com/api/json/v2/preview/search-by-login/osint-tools?email=tiimalb21@gmail.com), BDD d'email backdoor (utiliser via l'api car pu de creation de compte)
- [Kaspr](https://www.kaspr.io/), nom prenom => info. Voir [[Comptes]]

 
## __Tools__

- [Ignorant](https://github.com/megadose/ignorant), cherche sur quel **site** est enregistré un **numero de telephone**.
- [Holehe](https://github.com/megadose/holehe), cherche sur quel **site** est enregistré un **email**.
- [Osintgram](https://github.com/Datalux/Osintgram), **analyse** des comptes **instagram**.
- [Spiderfoot](https://github.com/smicallef/spiderfoot), outil d'**OSINT automatisé**.
