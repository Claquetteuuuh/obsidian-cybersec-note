## 1. Introduction to Cleartext Protocols
### Security Challenges

- Lack of encryption
- Vulnerable to multiple attack vectors
- Easily intercepted communication
### Primary Risks

- Man-in-the-Middle (MITM) attacks
- Credential exposure
- Unauthorized access
- Potential malware transmission
- Data exfiltration opportunities
## 2. FTP Protocol Analysis
### FTP Fundamentals

- File Transfer Protocol
- Designed for simplicity over security
- Transmits data and credentials in plain text
### Wireshark FTP Filtering Techniques
#### Global FTP Search

```
# Basic FTP packet filtering
ftp
```
### 2.1 Response Code Categories
#### x1x Series (Information Responses)

```
# System status
ftp.response.code == 211

# Typical codes
211: System status
212: Directory status
213: File status
```
#### x2x Series (Connection Messages)

```
# Connection and mode-related codes
ftp.response.code == 227

# Key connection codes
220: Service ready
227: Entering passive mode
228: Long passive mode
229: Extended passive mode
```
#### x3x Series (Authentication Messages)

```
# Authentication-related codes
ftp.response.code == 230

# Authentication status codes
230: User login successful
231: User logout
331: Valid username
430: Invalid username
530: Login failed
```

You can see the entire dialog:
- Right click on the packet
- Press Follow
- -> TCP Stream
![[Pasted image 20250308105629.png]]
## 3. Advanced FTP Investigation Techniques
### Command Tracking

```
# Track specific FTP commands
ftp.request.command == "USER"
ftp.request.command == "PASS"
ftp.request.arg == "password"
```
### Suspicious Activity Detection
#### Brute Force Indicators

```
# Failed login attempts
ftp.response.code == 530

# Specific username targeting
(ftp.response.code == 530) and (ftp.response.arg contains "username")

# Password spray detection
(ftp.request.command == "PASS") and (ftp.request.arg == "password")
```
## 4. Comprehensive Investigation Workflow
### Analysis Steps

1. Capture full network traffic
2. Apply FTP-specific filters
3. Analyze authentication attempts
4. Track file transfer activities
5. Identify potential security breaches
### Red Flags

- Multiple failed login attempts
- Unusual file transfer patterns
- Suspicious usernames
- Repeated connection attempts
- Unexpected passive mode entries
## 5. Mitigation Strategies
### Recommended Actions

1. Use FTPS or SFTP instead of standard FTP
2. Implement strong authentication
3. Enable encrypted file transfers
4. Use multi-factor authentication
5. Monitor and log FTP activities
### Security Best Practices

- Disable plain-text FTP
- Use VPN for remote file transfers
- Implement network segmentation
- Regular security audits
- Update and patch systems
## 6. Advanced Detection Techniques
### Forensic Analysis Approach

- Correlate FTP activities with other network logs
- Analyze time-based connection patterns
- Track source and destination IP relationships
- Investigate file transfer metadata
## 7. Tools and Resources
### Recommended Tools

- Wireshark
- Network monitoring solutions
- SIEM systems
- Intrusion detection systems
## 8. Challenges in FTP Analysis
### Detection Complexity

- Encrypted traffic identification
- Distinguishing legitimate from malicious transfers
- Performance overhead of deep packet inspection
- Evolving attack techniques
