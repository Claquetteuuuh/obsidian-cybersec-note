
Depuis Powershell V3, on peut utiliser une cmdlet du module PKI pour chiffrer un fichier en utilisant une bi-clé.

## __Generate_Certificat___

### Certificat

Pour generer un certificat on peut utiliser la commande : 

```powershell
New-SelfSignedCertificate -Subject PowershellCypher -DnsName psalpes.fr -CertStoreLocation "Cert:\CurrentUser\My" -Type DocumentEncryptionCert
```

L'option **`-DnsName`** précise le nom alternatif de l'objet.

### Verify

Pour controller la présence du certificat on peut utiliser la commande :

```powershell
Get-Childitem -Path Cert:\CurrentUser\My -DocumentEncryptionCert
```


## __Encrypt_Content__

## Encrypt

Pour chiffrer du contenu directement avec les cmdlet `Protect-CmsMessage` :

```powershell
"Ceci est un message secret" | Protect-CmsMessage -To cn=PowershellCypher -OutFile .\secret.txt
```

## Verify

Pour controller le bon déroulement du chiffrement :

```powershell
Get-Content .\secret.txt
```

## Decrypt

Pour déchiffrer le fichier :