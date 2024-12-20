# Whois - Tool
Whois permit to have all information about the domain. You can visit the website https://who.is

```bash
$ whois hackersploit.org
Domain Name: hackersploit.org
Registry Domain ID: 77f8fe62a425487cbefef4bf7e27d2ec-LROR
Registrar WHOIS Server: whois.namecheap.com
Registrar URL: http://www.namecheap.com
Updated Date: 2023-12-20T10:47:46Z
Creation Date: 2018-04-05T11:27:07Z
Registry Expiry Date: 2025-04-05T11:27:07Z
Registrar: NameCheap, Inc.
Registrar IANA ID: 1068
Registrar Abuse Contact Email: abuse@namecheap.com
Registrar Abuse Contact Phone: +1.6613102107
Domain Status: clientTransferProhibited https://icann.org/epp#clientTransferProhibited
Registry Registrant ID: REDACTED FOR PRIVACY
Registrant Name: REDACTED FOR PRIVACY
Registrant Organization: Privacy service provided by Withheld for Privacy ehf
Registrant Street: REDACTED FOR PRIVACY
Registrant City: REDACTED FOR PRIVACY
Registrant State/Province: Capital Region
Registrant Postal Code: REDACTED FOR PRIVACY
Registrant Country: IS
Registrant Phone: REDACTED FOR PRIVACY
Registrant Phone Ext: REDACTED FOR PRIVACY
Registrant Fax: REDACTED FOR PRIVACY
Registrant Fax Ext: REDACTED FOR PRIVACY
Registrant Email: Please query the RDDS service of the Registrar of Record identified in this output for information on how to contact the Registrant, Admin, or Tech contact of the queried domain name.
Registry Admin ID: REDACTED FOR PRIVACY
Admin Name: REDACTED FOR PRIVACY
Admin Organization: REDACTED FOR PRIVACY
Admin Street: REDACTED FOR PRIVACY
Admin City: REDACTED FOR PRIVACY
Admin State/Province: REDACTED FOR PRIVACY
Admin Postal Code: REDACTED FOR PRIVACY
Admin Country: REDACTED FOR PRIVACY
Admin Phone: REDACTED FOR PRIVACY
Admin Phone Ext: REDACTED FOR PRIVACY
Admin Fax: REDACTED FOR PRIVACY
Admin Fax Ext: REDACTED FOR PRIVACY
Admin Email: Please query the RDDS service of the Registrar of Record identified in this output for information on how to contact the Registrant, Admin, or Tech contact of the queried domain name.
Registry Tech ID: REDACTED FOR PRIVACY
Tech Name: REDACTED FOR PRIVACY
Tech Organization: REDACTED FOR PRIVACY
Tech Street: REDACTED FOR PRIVACY
Tech City: REDACTED FOR PRIVACY
Tech State/Province: REDACTED FOR PRIVACY
Tech Postal Code: REDACTED FOR PRIVACY
Tech Country: REDACTED FOR PRIVACY
Tech Phone: REDACTED FOR PRIVACY
Tech Phone Ext: REDACTED FOR PRIVACY
Tech Fax: REDACTED FOR PRIVACY
Tech Fax Ext: REDACTED FOR PRIVACY
Tech Email: Please query the RDDS service of the Registrar of Record identified in this output for information on how to contact the Registrant, Admin, or Tech contact of the queried domain name.
Name Server: dee.ns.cloudflare.com
Name Server: jim.ns.cloudflare.com
DNSSEC: unsigned
URL of the ICANN Whois Inaccuracy Complaint Form: https://www.icann.org/wicf/
>>> Last update of WHOIS database: 2024-09-26T16:40:48Z <<<

For more information on Whois status codes, please visit https://icann.org/epp

Terms of Use: Access to Public Interest Registry WHOIS information is provided to assist persons in determining the contents of a domain name registration record in the Public Interest Registry registry database. The data in this record is provided by Public Interest Registry for informational purposes only, and Public Interest Registry does not guarantee its accuracy. This service is intended only for query-based access. You agree that you will use this data only for lawful purposes and that, under no circumstances will you use this data to (a) allow, enable, or otherwise support the transmission by e-mail, telephone, or facsimile of mass unsolicited, commercial advertising or solicitations to entities other than the data recipient's own existing customers; or (b) enable high volume, automated, electronic processes that send queries or data to the systems of Registry Operator, a Registrar, or Identity Digital except as reasonably necessary to register domain names or modify existing registrations. All rights reserved. Public Interest Registry reserves the right to modify these terms at any time. By submitting this query, you agree to abide by this policy.  The Registrar of Record identified in this output may have an RDDS service that can be queried for additional information on how to contact the Registrant, Admin, or Tech contact of the queried domain name.
```

# Netcraft - Site
https://sitereport.netcraft.com/
Offer all public information about a domain

![[Pasted image 20240926184829.png]]

# DNS Recon - Tool
Permit to have information about the DNS record
```bash
$ dnsrecon -d picturide.com
[*] std: Performing General Enumeration against: picturide.com...
[-] DNSSEC is not configured for picturide.com
[*]      SOA ns10.digicertdns.com 208.94.148.159
[*]      SOA ns10.digicertdns.com 2600:1800::1:1f
[*]      NS ns13.digicertdns.net 208.80.125.159
[-]      Recursion enabled on NS Server 208.80.125.159
[*]      NS ns13.digicertdns.net 2600:1801:3::1:1f
[*]      NS ns11.digicertdns.com 208.80.124.159
[-]      Recursion enabled on NS Server 208.80.124.159
[*]      NS ns11.digicertdns.com 2600:1801:1::1:1f
[*]      NS ns12.digicertdns.com 208.80.126.159
[-]      Recursion enabled on NS Server 208.80.126.159
[*]      NS ns12.digicertdns.com 2600:1802:2::1:1f
[*]      NS ns14.digicertdns.net 208.80.127.159
[-]      Recursion enabled on NS Server 208.80.127.159
[*]      NS ns14.digicertdns.net 2600:1802:4::1:1f
[*]      NS ns15.digicertdns.net 208.94.149.159
[-]      Recursion enabled on NS Server 208.94.149.159
[*]      NS ns15.digicertdns.net 2600:1800:8::1:1f
[*]      NS ns10.digicertdns.com 208.94.148.159
[-]      Recursion enabled on NS Server 208.94.148.159
[*]      NS ns10.digicertdns.com 2600:1800::1:1f
[*]      MX mx1.mail.ovh.net 188.165.36.237
[*]      MX mx2.mail.ovh.net 87.98.160.167
[*]      MX mx3.mail.ovh.net 91.121.53.175
[*]      A picturide.com 52.212.52.84
[*]      A picturide.com 54.247.69.169
[*]      A picturide.com 63.32.161.232
[*]      TXT picturide.com 3|welcome
[*]      TXT picturide.com v=spf1 include:spf.mailjet.com include:mx.ovh.com -all
[*]      TXT picturide.com 1|www.picturide.com
[*] Enumerating SRV Records
[+]      SRV _imaps._tcp.picturide.com ssl0.ovh.net 193.70.18.144 993
[+]      SRV _submission._tcp.picturide.com ssl0.ovh.net 193.70.18.144 465
[+]      SRV _autodiscover._tcp.picturide.com mailconfig.ovh.net 213.186.33.5 443
[+] 3 Records Found
```
MX = Mail server
A = IPV4
AAAA = IPV6
TXT = additionnal information
SOA = Domain authority
NS = Domain nameserver
CNAME = ALIAS
# DnsDumpster - Site
https://dnsdumpster.com/
![[Pasted image 20240926185950.png]]
Very usefull because we have a graph and we can make reverse research
# Sublist3r - Tool
Sublist3r permit to find the subdomain through search engines & dorks.
https://github.com/aboul3la/Sublist3r

```js
$ python3 sublist3r.py -d ine.com
                 ____        _     _ _     _   _____
                / ___| _   _| |__ | (_)___| |_|___ / _ __
                \___ \| | | | '_ \| | / __| __| |_ \| '__|
                 ___) | |_| | |_) | | \__ \ |_ ___) | |
                |____/ \__,_|_.__/|_|_|___/\__|____/|_|

                # Coded By Ahmed Aboul-Ela - @aboul3la

[-] Enumerating subdomains now for ine.com
[-] Searching now in Baidu..
[-] Searching now in Yahoo..
[-] Searching now in Google..
[-] Searching now in Bing..
[-] Searching now in Ask..
[-] Searching now in Netcraft..
[-] Searching now in DNSdumpster..
[-] Searching now in Virustotal..
[-] Searching now in ThreatCrowd..
[-] Searching now in SSL Certificates..
[-] Searching now in PassiveDNS..
[!] Error: Virustotal probably now is blocking our requests
[-] Total Unique Subdomains Found: 78
www.ine.com
1pass-scim.ine.com
admin.ine.com
www.admin.ine.com
...
virl.ine.com
www2.ine.com
```
# TheHarvester - Tool
https://github.com/laramies/theHarvester

```js
$ theHarvester -d hackersploit.org -b yahoo,anubis
Read proxies.yaml from /home/claquetteuuuh/.theHarvester/proxies.yaml
*******************************************************************
*  _   _                                            _             *
* | |_| |__   ___    /\  /\__ _ _ ____   _____  ___| |_ ___ _ __  *
* | __|  _ \ / _ \  / /_/ / _` | '__\ \ / / _ \/ __| __/ _ \ '__| *
* | |_| | | |  __/ / __  / (_| | |   \ V /  __/\__ \ ||  __/ |    *
*  \__|_| |_|\___| \/ /_/ \__,_|_|    \_/ \___||___/\__\___|_|    *
*                                                                 *
* theHarvester 4.6.0                                              *
* Coded by Christian Martorella                                   *
* Edge-Security Research                                          *
* cmartorella@edge-security.com                                   *
*                                                                 *
*******************************************************************

[*] Target: hackersploit.org

[*] Searching Anubis.
[*] Searching Yahoo.

[*] No IPs found.

[*] No emails found.

[*] Hosts found: 11
---------------------
apps.community.hackersploit.org
cloud.hackersploit.org
community.hackersploit.org
...
videos.hackersploit.org
```

