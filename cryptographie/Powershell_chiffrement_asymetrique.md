
Depuis Powershell V3, on peut utiliser une cmdlet du module PKI pour chiffrer un fichier en utilisant une bi-clé.

## __Generate__

### Certificat

Pour generer un certificat on peut utiliser la commande : 

```powershell
New-SelfSignedCertificate -Subject PowershellCypher -DnsName psalpes.fr -CertStoreLocation "Cert:\CurrentUser\My" -Type DocumentEncryptionCert
```

### Verify

Pour 