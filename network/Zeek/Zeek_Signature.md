## Overview
Zeek signatures help identify noteworthy network activities using pattern matching. Unlike Snort, Zeek rules are not the primary detection method but can trigger scripts for event correlation.
## Structure of a Zeek Signature
1. **Signature ID:** Unique name for identification.
2. **Conditions:**
    - **Header:** Filters based on IP, port, or protocol.
    - **Content:** Filters payload data, HTTP headers, FTP commands, etc.
3. **Actions:**
    - Default: Logs matches in `signatures.log`.
    - Additional: Can trigger a Zeek script.
## Common Filters & Conditions
- **Header:** Filters source/destination IP, ports, and protocols.
- **Content:** Searches for keywords or regex in HTTP requests, FTP commands, etc.
- **Comparison Operators:** `==, !=, <, <=, >, >=`
## Running Zeek with Signatures
Command:
```bash
zeek -C -r sample.pcap -s sample.sig
```
- `-C`: Ignores checksum errors.
- `-r`: Reads a pcap file.
- `-s`: Uses the specified signature file.
## Examples of Zeek Signatures
### 1. Detecting Cleartext Passwords in HTTP
Signature to detect "password" in HTTP traffic:
```zeek
signature http-password {
	ip-proto == tcp
	dst-port == 80      
	payload /.*password.*/      
	event "Cleartext Password Found!" 
}
```
**Log Analysis:**
- Matches appear in `signatures.log` and `notice.log`, showing the detected request.
### 2. Detecting FTP Brute-force Attempts
Signature to detect FTP admin login attempts:
```zeek
signature ftp-admin {      
	ip-proto == tcp      
	ftp /.*USER.*dmin.*/      
	event "FTP Admin Login Attempt!" 
}
```
**Improved Detection:** Instead of only detecting "admin" logins, detect all failed attempts:
```zeek
signature ftp-brute {      
	ip-proto == tcp      
	payload /.*530.*Login.*incorrect.*/      
	event "FTP Brute-force Attempt!" 
}
```
### 3. Combining Multiple FTP Signatures
A single file can contain multiple signatures:
```zeek
signature ftp-username {    
	ip-proto == tcp     
	ftp /.*USER.*/     
	event "FTP Username Input Found!"
}
signature ftp-brute {     
	ip-proto == tcp     
	payload /.*530.*Login.*incorrect.*/     
	event "FTP Brute-force Attempt!" 
}
```
**Log Analysis:**
- Detects both username inputs and failed login attempts for correlation.
## Key Takeaways
- Zeek signatures are useful for identifying network anomalies but should be used efficiently to avoid excessive logs.
- They can be combined to track detailed attack patterns like brute-force attempts.
- Zeek no longer supports direct Snort rule conversion (`snort2bro` is deprecated).