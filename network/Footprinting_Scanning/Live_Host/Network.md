# IPV4
### Header
- Version (4bits)
- Header length (4bits)
- Type of Service (8bits)
- Total length (16bits)
	- Max 65,535 bytes
- Identification (16bits) (Used for reasembling packets)
- Flags (3bits)
	- 0: reserved always set to 0
	- 1: DF, if set to 1 dont fragment
	- 2: MD, If set to 1, indicates that more fragment follow in a fragmented packet
- Time-To-Live (8bits)
	- Maximum numbers of hops (router) the packet can traverse before discarded (decremented by one at each hops)
- Protocol (8 bits)
	- 6=TCP
	- 17=UDP
	- 1=UCMP
- Source IP address (32bits)
- Destination IP address (32 bits)
![[Pasted image 20241002111549.png]]

### Reserved IPv4
- 0.0.0.0 - 0.255.255.255 representing "this" network
- 127.0.0.0 - 127.255.255.255 representing this local host
- 192.168.0.0 - 192.168.255.255 reserved for private network
Details in RFC5735

# TCP
Transmission control protocol: **Connection oriented** protocol
- ACK between client & server before sending message
- Reliable: Resend packet if is not acknoledged
- Ordered data transfert, data sended in correct order
## 3-Way Handshake
![[Pasted image 20241002172603.png]]
## Control flags
### Etablish connection (request)
- SYN (Set): Initiates a connection request
- ACK (Clear): No acknowledgment yet
- FIN (Clear): No Termination request
### Etablish a connection (response)
- SYN (Set): Acknowledges the connection request
- ACK (Set): Acknowledges the received data
- FIN (Clear): No termination request
### Exemple
- HTTP
- FTP
- Telnet
- SMTP
- HTTPS
### See yours connections

```bash
$> netstat -anp
```
# UDP
User datagram protocol: **Connectionless** protocol
- Simple
- Minimalistic
- Efficient
- Real time application
- Stateless
- Each packet is independant
### Exemple
- DNS
- DHCP
- SNMP
- VolP
# Wireshark
Used to inspect the packets that transit in the network.
```bash
$> sudo wireshark -i eth0 
```
The `-i` option is used to specified a network interface. 