# Hash value - Trivial
- **MD5** (Message digest, Defined by RFC 1321), 128 bits. **Not considered cryptographically secure**.
- **SHA-1** (Secure Hash Algorithm 1, defined by RFC 3174), produce a 160 bits hash values, 40Hex number. **Vulnerable by bruteforce**
- **SHA-2** (Secure hash Algorith 2), a variant is SHA-256, it send a 256 bits values, 64Hex numbers.
A hash is not cryptographically secure if 2 files havent the same hash value or digest.
## Check hash
Many tools can be used to do hash lookups like [VirusTotal](https://www.virustotal.com/gui/home/upload) and [Metadefender cloud - OPSWAT](https://metadefender.opswat.com/)
It's easy to change the signature, for exemple you can append a character at the end of the file.
![[Pasted image 20250103153338.png]]
![[Pasted image 20250103153407.png]]
# IP address - Easy
You can see what ip address a program try to connect with and then block this address.
# Domain name - Simple
## Punycode
A punycode attack is when you uses unicode characters in the domain name to imitate a known domain.
Exemple:
`adidas.com`
Can be replaced by
`adıdas.com`
## Url shortener
The attackers use URL Shortener to hide their domain:
- Bit.ly
- Goo.gl
- Aïe.ly
- s.id
- smarturl.it
- minuscule.pl
- tinyurl.com
- x.co
You can see where these url point, just add a "+" after the url:
http://bit.ly/vHle3SI+
# Host artifacts - Annoying
Host artifacts are the traces or observables that attackers leave on the system, such as:
- registery values
- suspicious process execution
- attack patterns
- IOCs
- file dropped by malicious application
# Network artifacts - Annoying
They can be:
- user agent string
- C2 information
- URI patterns
Network artifacts can be detected **in Wireshark PCAPSs** (file that contains the packet data of a network) by using a **network protocol analyzer such as Tshark**.
The following command is to filter the User-Agent strings:
```bash
tshark --Y http.request -T fields -e http.host -e http.user_agent -r <analysis_file.pcap>
```
# Tools - Challenging
We can use Fuzzy hashes (context triggered piecewise hashes) to determine similarity between the files.
# TTP - Tough
Tactics, Techniques & Procedures. It include all the https://attack.mitre.org/ Matrice, it's all the step followed by an attacker to achieve his objective, from phishing to persistance and data exfiltration. 