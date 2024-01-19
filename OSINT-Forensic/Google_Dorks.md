# Dorks

*Extension: https://addons.mozilla.org/fr/firefox/addon/google-dork-builder/?utm_source=addons.mozilla.org&utm_medium=referral&utm_content=search*

Les **Googles Dorks** sont des façons d'utiliser les **moteurs de recherches** pour faciliter et **cibler** notre recherche.

Par exemple cette recherche nous donne tous les fichiers PDF de sites en .info qui contiennent le texte "JO 2024" :

![[Pasted image 20231215133710.png]]

| Syntaxe                         | Fonction                                                                  |
| ------------------------------- | ------------------------------------------------------------------------- |
| `"expression"`                  | Va chercher tous les sites qui contiennent précisement cette "expression" |
| `OSINT filetype:pdf`            | Va chercher tous les pdf qui contiennent du contenu sur l'OSINT           |
| `salary site:*.gouv`            | Va chercher sur tous les sites en .gouv                                   |
| `pentest -site:exemple.com`     | Va exclure le site exemple.com de la recherche                            |
| `walkthrough intitle:Tryhackme` | Cherche exclusivement les pages avec le therme tryhackme dans le titre    |
| `challenge inurl:tryhackme`     | Cherche exclusivement les pages avec tryhackme dans l'url.                                                                          |
