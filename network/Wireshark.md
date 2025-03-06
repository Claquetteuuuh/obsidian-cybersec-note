Wireshark supports over 3000 protocols, allowing detailed packet-level investigation through sophisticated filtering techniques. This guide explores the key protocol filter types across different OSI model layers.

## 1. IP Filters (Network Layer)
### Core IP Filtering Techniques
#### Basic IP Packet Filtering

```
# Show all IP packets
ip

# Filter specific IP address
ip.addr == 10.10.10.111

# Filter subnet
ip.addr == 10.10.10.0/24
```
#### Directional IP Filtering

```
# Packets originating from specific IP
ip.src == 10.10.10.111

# Packets sent to specific IP
ip.dst == 10.10.10.111
```
#### Key Differences

- `ip.addr`: Filters traffic without considering packet direction
- `ip.src/ip.dst`: Filters based on specific packet direction
## 2. TCP and UDP Filters (Transport Layer)
### TCP Filtering Examples

```
# All TCP packets on port 80
tcp.port == 80

# TCP packets from specific source port
tcp.srcport == 1234

# TCP packets to specific destination port
tcp.dstport == 80
```
### UDP Filtering Examples

```
# All UDP packets on port 53
udp.port == 53

# UDP packets from specific source port
udp.srcport == 1234

# UDP packets to specific destination port
udp.dstport == 5353
```
## 3. Application Layer Protocol Filters
### HTTP Filtering

```
# Show all HTTP packets
http

# HTTP responses with status code 200
http.response.code == 200

# Specific HTTP methods
http.request.method == "GET"
http.request.method == "POST"
```
### DNS Filtering

```
# Show all DNS packets
dns

# DNS requests
dns.flags.response == 0

# DNS responses
dns.flags.response == 1

# Specific DNS record types
dns.qry.type == 1  # A records
```
## 4. Display Filter Expressions: Pro Tips
### Accessing Filter Expressions

- Menu Path: `Analyze --> Display Filter Expression`
### Why Use Display Filter Expressions?

- Helps when you can't recall specific filter syntax
- Provides protocol field details
- Shows accepted value types
- Displays predefined values
### Best Practices

1. Use the Display Filter Expression menu for complex filters
2. Practice and familiarize yourself with protocol structures
3. Understand value types (integer vs. string)
4. Experiment with different filter combinations
## 5. Advanced Filtering Techniques
### Combining Filters

```
# Complex filter example
ip.addr == 192.168.1.0/24 and tcp.port == 80
```
### Color Coding Filters

- Use `View --> Coloring Rules` to highlight filter results
- Helps visually distinguish different packet types/conditions
## Pro Tips for Effective Filtering

- Start with broad filters, then narrow down
- Use logical operators (and, or, not)
- Leverage subnet and range filtering
- Practice regularly to build filtering expertise
## Common Challenges

- Protocols have unique, complex structures
- Memorizing all filter variations is challenging
- Continuous learning and practice are key
## Recommended Learning Path

1. Master basic IP, TCP, UDP filters
2. Explore application-layer protocol filters
3. Use Display Filter Expressions frequently
4. Experiment with complex, multi-condition filters
# Advanced Wireshark Filtering Techniques
## 1. Contains Filter

#### Key Characteristics
- Case-sensitive
- Searches within specific fields
- Similar to "Find" functionality

#### Examples

```
# Find Apache servers
http.server contains "Apache"

# Find packets containing specific keywords
http.request.uri contains "login"
```
## 2. Matches Filter
#### Key Characteristics
- Case-insensitive
- Supports complex pattern matching
- Allows regex-based filtering
#### Examples

```
# Find .php and .html pages
http.host matches "\.(php|html)"

# Match multiple file extensions
http.request.uri matches "\.(jpg|png|gif)$"
```
## 3. In Filter
#### Key Characteristics

- Check membership in a predefined set
- Works with multiple value types
- Simplifies complex filtering conditions
#### Examples

```
# Filter specific ports
tcp.port in {80 443 8080}

# Match multiple IP ranges
ip.addr in {192.168.1.0/24 10.0.0.0/16}
```
## 4. String Manipulation Filters
### Uppercase Filter

```
# Find servers in uppercase
upper(http.server) contains "APACHE"
```
### Lowercase Filter

```
# Find servers in lowercase
lower(http.server) contains "apache"
```
### String Conversion Filter

```
# Find frames with odd numbers
string(frame.number) matches "[13579]$"
```
## 5. Advanced Filtering Strategies
### Combining Multiple Filters

```
# Complex filter example
(http.request.method == "GET") and (http.host contains "example") and (tcp.port in {80 443})
```
## 6. Workflow Optimization
### Bookmarks

- Save complex filters for quick reuse
- Access via filter toolbar
- Simplifies repetitive investigations
### Filter Buttons

- Create one-click filter shortcuts
- Customize for specific investigation scenarios
## 7. Wireshark Profiles
#### Key Features

- Save multiple configuration profiles
- Quickly switch between investigation setups
- Preserve custom settings
#### Access Methods

- `Edit --> Configuration Profiles`
- Lower right status bar --> Profile section
### Profile Management Best Practices

1. Create distinct profiles for different investigation types
2. Save unique color rules
3. Preserve filter configurations
4. Easily switch between investigation contexts
## 8. Pro Tips for Advanced Filtering
### Filtering Best Practices

- Start with broad filters, then narrow down
- Use regex carefully (performance implications)
- Leverage function filters for complex matching
- Test and validate complex filters incrementally
### Common Use Cases

- Malware detection
- Network anomaly identification
- Security investigation
- Performance analysis
## 9. Potential Challenges

- Performance overhead with complex regex
- Case sensitivity considerations
- Regular expression complexity
- Matching nuanced packet characteristics
