## 1. HTTP Protocol Overview
### Fundamental Characteristics
- Cleartext-based protocol
- Request-response communication model
- Client-server architecture
- Default web communication standard
### Potential Security Risks
- Phishing detection
- Web attack identification
- Data exfiltration
- Command and Control (C2) traffic
- Unauthorized access attempts
## 2. Wireshark HTTP Filtering Techniques
### Basic HTTP Protocol Filters

```
# Global HTTP search
http
http2
```
### 2.1 HTTP Request Methods

```
# GET requests
http.request.method == "GET"

# POST requests
http.request.method == "POST"

# List all HTTP requests
http.request
```
### 2.2 HTTP Response Status Codes

```
# Successful requests
http.response.code == 200

# Authentication failures
http.response.code == 401  # Unauthorized
http.response.code == 403  # Forbidden

# Not found resources
http.response.code == 404

# Server errors
http.response.code == 500  # Internal Server Error
http.response.code == 503  # Service Unavailable
```
## 3. Advanced HTTP Parameter Analysis
### Key Parameters to Investigate

```
# User Agent Identification
http.user_agent contains "nmap"

# URI Analysis
http.request.uri contains "admin"
http.request.full_uri contains "admin"

# Server Identification
http.server contains "apache"

# Host Analysis
http.host contains "keyword"
http.host == "keyword"

# Connection Status
http.connection == "Keep-Alive"
```
## 4. User Agent Analysis
### Anomaly Detection Techniques

```
# Audit Tool Detection
(http.user_agent contains "sqlmap") or 
(http.user_agent contains "Nmap") or 
(http.user_agent contains "Wfuzz") or 
(http.user_agent contains "Nikto")
```
![[Pasted image 20250308110121.png]]
### Red Flags in User Agent Analysis

- Rapid user agent changes
- Non-standard user agent strings
- Subtle spelling variations
- Presence of audit tool signatures
- Unexpected payload in user agent field
## 5. Specific Vulnerability Detection
### Log4j Vulnerability Analysis

```
# Log4j Specific Filters
# POST request detection
http.request.method == "POST"

# Known exploit patterns
(ip contains "jndi:ldap") or 
(ip contains "Exploit.class")

# Suspicious user agent patterns
(http.user_agent contains "$") or 
(http.user_agent contains "==")
```
![[Pasted image 20250308110251.png]]
## 6. Investigation Workflow
### Systematic Analysis Approach

1. Capture full network traffic
2. Apply HTTP-specific filters
3. Analyze request methods
4. Examine response codes
5. Investigate user agent patterns
6. Look for potential exploit indicators
## 7. Advanced Detection Strategies
### Comprehensive Analysis Techniques

- Correlate HTTP activities with other network logs
- Track IP address reputation
- Analyze time-based request patterns
- Investigate unusual URI structures
- Check for potential data exfiltration
## 8. Mitigation Strategies
### Recommended Actions

1. Implement HTTPS
2. Use web application firewalls
3. Regular security patch management
4. Monitor and log HTTP traffic
5. Implement strict input validation
## 9. Challenges in HTTP Analysis
### Detection Complexity

- Encryption techniques
- Sophisticated obfuscation
- High-volume traffic
- Evolving attack methodologies
