
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


# __Chiffrement_Symetrique__

## __SHA256___

https://gist.github.com/dindoliboon/9c23391a93d57f17e31dedcb999f1738

### Cle

Pour generer notre clé de chiffrement symetrique, notre message :

```powershell
> $cle = "mot2passe"
> $sha256 = New-Object System.Security.Cryptography.SHA256Managed
> $cleBytes = [System.Text.Encoding]::UTF8.GetBytes($cle)
> $cleAES = $sha256.ComputeHash($cleBytes)

> $Message = "Ceci est un message secret"
> $MessageBytes = [Text.Encoding]::UTF8.GetBytes($Message)

> $AES = [Security.Cryptography.SymmetricAlgorithm]::Create('AesManaged')
> $initVectore = $AES.IV
```


## Encrypt

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

ou

```powershell
> $PlaintextPassword = "Mot2Passe"
> $Plaintext = "Mon super secret"

> $Aes = [System.Security.Cryptography.Aes]::Create()
> $Aes.Key = [System.Security.Cryptography.HashAlgorithm]::Create('SHA256').ComputeHash([System.Text.Encoding]::UTF8.GetBytes($PlaintextPassword))
> $Aes.GenerateIV()
> $Aes.Mode = [System.Security.Cryptography.CipherMode]::CBC

> $Encryptor = $Aes.CreateEncryptor($Aes.Key, $Aes.IV)

> $MemoryStream = [System.IO.MemoryStream]::new()
> $CryptoStream = [System.Security.Cryptography.CryptoStream]::new($MemoryStream, $Encryptor, [System.Security.Cryptography.CryptoStreamMode]::Write)
> $StreamWriter = [System.IO.StreamWriter]::new($CryptoStream)

> $StreamWriter.Write($Plaintext)
> $StreamWriter.Close()
> $CryptoStream.Close()

> $EncryptedBytes = $MemoryStream.ToArray()
> $MemoryStream.Close()

> $CipherTextWithIv = New-Object -TypeName Byte[] -ArgumentList ($Aes.IV.Length + $EncryptedBytes.Length)
> [Array]::Copy($Aes.IV, 0, $CipherTextWithIv, 0, $Aes.IV.Length)
> [Array]::Copy($EncryptedBytes, 0, $CipherTextWithIv, $Aes.IV.Length, $EncryptedBytes.Length)

> Write-Output -InputObject $CipherTextWithIv
```

### Decrypt

Pour dechiffrer :

```powershell
> $encryptedBytes = [Convert]::fromBase64String($encryptedb64)

> $Decryptor = $AES.CreateDecryptor($cleAES, $initVector)

> $mem_stream = New-Object -TypeName IO.MemoryStream -ArgumentList @(, $encryptedBytes)
> $stream_crypt = New-Object -TypeName Security.Cryptography.CryptoStream -ArgumentList @($mem_stream, $Decryptor, 'Read')

> $decryptedBytes = New-Object -TypeName Byte[] -ArgumentList $encryptedBytes.Length
> $decryptedByteCount = $stream_crypt.Read($decryptedBytes, 0, $decryptedBytes.Length)
> $Message = [Text.Encoding]::UTF8.GetString($decryptedBytes, 0, $decryptedByteCount)
```

ou

```powershell
> $PlaintextPassword = "Mot2Passe"
> $EncryptedBytesBase64 = "Rl8xzyaP/fpV9EWIqoav9ecNgMTGq2lONZ+c3ejC32dGElyQ4ZVpr4+CkPyH2LmJ"

> $Aes = [System.Security.Cryptography.Aes]::Create()
> $Aes.Key = [System.Security.Cryptography.HashAlgorithm]::Create('SHA256').ComputeHash([System.Text.Encoding]::UTF8.GetBytes($PlaintextPassword))
> $Aes.GenerateIV()
> $Aes.Mode = [System.Security.Cryptography.CipherMode]::CBC

> $Decryptor = $Aes.CreateDecryptor($Aes.Key, $Aes.IV)

> $EncryptedBytes = [Convert]::FromBase64String($EncryptedBytesBase64)
> $MemoryStream = [System.IO.MemoryStream]::new($EncryptedBytes)
> $CryptoStream = [System.Security.Cryptography.CryptoStream]::new($MemoryStream, $Decryptor, [System.Security.Cryptography.CryptoStreamMode]::Read)
> $StreamReader = [System.IO.StreamReader]::new($CryptoStream)

> $Plaintext = $StreamReader.ReadToEnd()

> $StreamReader.Close()
> $CryptoStream.Close()
> $MemoryStream.Close()

> Write-Output -InputObject $Plaintext
```