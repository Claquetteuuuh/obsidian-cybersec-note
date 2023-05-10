
Depuis Powershell V3, on peut utiliser une cmdlet du module PKI pour chiffrer un fichier en utilisant une bi-clé.

# __Chiffrement_Asymetrique___

## __Generate_Certificat___

### Certificat

Pour generer un certificat on peut utiliser la commande : 

```powershell
New-SelfSignedCertificate -Subject PowershellCypher -DnsName psalpes.fr -CertStoreLocation "Cert:\CurrentUser\My" -Type DocumentEncryptionCert
```

L'option **`-Subject`** précise le nom de notre certificat.
L'option **`-DnsName`** précise le nom alternatif de l'objet.

### Verify

Pour controller la présence du certificat on peut utiliser la commande :

```powershell
Get-Childitem -Path Cert:\CurrentUser\My -DocumentEncryptionCert
```

### Delete

Pour supprimer un certificat, il faut lancer powershell en administrateur et executer la commande :

```powershell
certutil -delstore my "<Thumbprint>"
```


## __Encrypt_Content__

On peut chiffrer directement avec des cmdlet depuis Powershell v5.

## Encrypt

Pour chiffrer du contenu directement avec les cmdlet `Protect-CmsMessage` :

```powershell
"Ceci est un message secret" | Protect-CmsMessage -To cn=PowershellCypher -OutFile .\secret.txt
```

Alernative avant Powershell v5 :

```powershell
> $Cert = Get-ChildItem Cert:\LocalMachine\My | Where-Object {$_.Subject -like "PowershellCypher"}
> $Message = 'Ceci est un message secret'
> $Bytes = [System.text.encoding]::UTF8.GetBytes($Message)
> $EncryptedBytes = $Cert.PublicKey.Key.Encrypt($Bytes, $true)
> EncryptedMsg = [System.Convert]::ToBase64String($EncryptedBytes)
```

## Verify

Pour controller le bon déroulement du chiffrement :

```powershell
Get-Content .\secret.txt
```

## Decrypt

Pour déchiffrer le fichier :

```powershell
Unprotect-CmsMessage -Path .\secret.txt
```

Alernative avant Powershell v5 :

```powershell
> $EncryptedMsg
> $EncryptedBytes = [System.Convert]::FromBase64String($EncryptedMsg)
> $DecryptedBytes = $Cert.PrivateKey.Decrypt($EncryptedBytes, $true)
> $Message = [System.text.encoding]::UTF8.GetString($DecryptedBytes)
```


# __Chiffrement_Symetrique_SHA256___

## __Cle__

Pour generer notre clé de chiffrement symetrique, notre message :

```powershell
> $cle = "mot2passe"
> $sha256 = New-Object System.Security.Cryptography.SHA256Managed
> $cleBytes = [System.Text.Encoding]::UTF8.GetByptes($cle)
> $cleAES = $sha256.ComputeHash($cleBytes)

> $Message = "Ceci est un message secret"
> $MessageBytes = [Text.Encoding]::UTF8.GetBytes($Message)

> $AES = [Security.Cryptography.SymmetricAlgotithm]::Create('AesManaged')
> $initVectore = $AES.IV
```


## __Encrypt__

Pour chiffrer un message avec AES :

```powershell
> $Encryptor = $AES.CreateEncryptor($cleAES, $initVector)

> $stream_mem = New-Object -TypeName IO.MemoryStream
> $stream_crypt = New-Object -TypeName Security.Cryptography.CryptoStream -ArgumentList @($stream_mem, $Encryptor, 'Write')

> $stream_crypt.Write($MessageBytes, 0, $MessageBytes.Length)
> $stream_crypt.FlushFinalBlock()

> $encryptedBytes = $stream_mem.ToArray()
> $encryptedb64 = [Convert]::ToBase64String($encryptedBytes)
```

