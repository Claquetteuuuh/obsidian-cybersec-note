| **Parameter** | **Purpose**                                                                                                                                                                                                                                                                                                                                                                                                    |
| ------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| --color       | - Wireshark-like colourised output.<br>- `tshark --color`                                                                                                                                                                                                                                                                                                                                                      |
| -z            | - Statistics<br>- There are multiple options available under this parameter. You can view the available filters under this parameter with:<br><br>- `tshark -z help`<br><br>- Sample usage.<br><br>- `tshark -z filter`<br><br>- Each time you filter the statistics, packets are shown first, then the statistics provided. You can suppress packets and focus on the statistics by using the `-q` parameter. |
## Colors
```bash
tshark -r colour.pcap --color
```
![[Pasted image 20250309153607.png]]

## Statistics
### Protocol Hierarchy
```bash
$ tshark -r demo.pcapng -z io, phs -q

===================================================================
Protocol Hierarchy Statistics
Filter: 

eth                                      frames:43 bytes:25091
  ip                                     frames:43 bytes:25091
    tcp                                  frames:41 bytes:24814
      http                               frames:4 bytes:2000
        data-text-lines                  frames:1 bytes:214
          tcp.segments                   frames:1 bytes:214
        xml                              frames:1 bytes:478
          tcp.segments                   frames:1 bytes:478
    udp                                  frames:2 bytes:277
      dns                                frames:2 bytes:277
===================================================================

```

We can filter:
```bash
$ tshark -r demo.pcapng -z io,phs,udp -q

===================================================================
Protocol Hierarchy Statistics
Filter: udp

eth                                      frames:2 bytes:277
  ip                                     frames:2 bytes:277
    udp                                  frames:2 bytes:277
      dns                                frames:2 bytes:277
===================================================================

```
### Packet lengths tree
```bash
$ tshark -r demo.pcapng -z plen,tree -q


==================================================================================================================================
Packet Lengths:
Topic / Item       Count         Average       Min val       Max val       Rate (ms)     Percent       Burst rate    Burst start  
----------------------------------------------------------------------------------------------------------------------------------
Packet Lengths     43            583.51        54            1484          0.0014        100%          0.0400        2.554        
 0-19              0             -             -             -             0.0000        0.00%         -             -            
 20-39             0             -             -             -             0.0000        0.00%         -             -            
 40-79             22            54.73         54            62            0.0007        51.16%        0.0200        0.911        
 80-159            1             89.00         89            89            0.0000        2.33%         0.0100        2.554        
 160-319           2             201.00        188           214           0.0001        4.65%         0.0100        2.914        
 320-639           2             505.50        478           533           0.0001        4.65%         0.0100        0.911        
 640-1279          1             775.00        775           775           0.0000        2.33%         0.0100        2.984        
 1280-2559         15            1440.67       1434          1484          0.0005        34.88%        0.0200        2.554        
 2560-5119         0             -             -             -             0.0000        0.00%         -             -            
 5120 and greater  0             -             -             -             0.0000        0.00%         -             -            

----------------------------------------------------------------------------------------------------------------------------------
```
### Endpoints
| **Filter** | **Purpose**                                       |
| ---------- | ------------------------------------------------- |
| eth        | - Ethernet addresses                              |
| ip         | - IPv4 addresses                                  |
| ipv6       | - IPv6 addresses                                  |
| tcp        | - TCP addresses<br>- Valid for both IPv4 and IPv6 |
| udp        | - UDP addresses<br>- Valid for both IPv4 and IPv6 |
| wlan       | - IEEE 802.11 addresses                           |
```bash
$ tshark -r demo.pcapng -z endpoints,ip -q

================================================================================
IPv4 Endpoints
Filter:<No Filter>
                       |  Packets  | |  Bytes  | | Tx Packets | | Tx Bytes | | Rx Packets | | Rx Bytes |
145.254.160.237               43         25091         20            2323          23           22768   
65.208.228.223                34         20695         18           19344          16            1351   
216.239.59.99                  7          4119          4            3236           3             883   
145.253.2.203                  2           277          1             188           1              89   
================================================================================
```
### Conversations
```bash
$ tshark -r demo.pcapng -z conv,ip -q  

================================================================================
IPv4 Conversations
Filter:<No Filter>
                                               |       <-      | |       ->      | |     Total     |    Relative    |   Duration   |
                                               | Frames  Bytes | | Frames  Bytes | | Frames  Bytes |      Start     |              |
65.208.228.223       <-> 145.254.160.237           16      1351      18     19344      34     20695     0.000000000        30.3937
145.254.160.237      <-> 216.239.59.99              4      3236       3       883       7      4119     2.984291000         1.7926
145.253.2.203        <-> 145.254.160.237            1        89       1       188       2       277     2.553672000         0.3605
================================================================================
```
### Expert Info
```bash
$ tshark -r demo.pcapng -z expert -q


Notes (3)
=============
   Frequency      Group           Protocol  Summary
           1   Sequence                TCP  This frame is a (suspected) spurious retransmission
           1   Sequence                TCP  This frame is a (suspected) retransmission
           1   Sequence                TCP  Duplicate ACK (#1)

Chats (8)
=============
   Frequency      Group           Protocol  Summary
           1   Sequence                TCP  Connection establish request (SYN): server port 80
           1   Sequence                TCP  Connection establish acknowledge (SYN+ACK): server port 80
           1   Sequence               HTTP  GET /download.html HTTP/1.1\r\n
           1   Sequence               HTTP  GET /pagead/ads?client=ca-pub-2309191948673629&random=1084443430285&lmt=1082467020&format=468x60_as&output=html&url=http%3A%2F%2Fwww.ethereal.com%2Fdownload.html&color_bg=FFFFFF&color_text=333333&color_link=000000&color_url=666633&color_bo
           2   Sequence               HTTP  HTTP/1.1 200 OK\r\n
           2   Sequence                TCP  Connection finish (FIN)
```
### IPv4 and IPv6
You can filter all IP addresses using the parameters given below.
- **IPv4:** `-z ip_hosts,tree -q`
- **IPv6:** `-z ipv6_hosts,tree -q`
```bash
$ tshark -r demo.pcapng -z ip_hosts,tree -q


=================================================================================================================================
IPv4 Statistics/All Addresses:
Topic / Item      Count         Average       Min val       Max val       Rate (ms)     Percent       Burst rate    Burst start  
---------------------------------------------------------------------------------------------------------------------------------
All Addresses     43                                                      0.0014        100%          0.0400        2.554        
 145.254.160.237  43                                                      0.0014        100.00%       0.0400        2.554        
 65.208.228.223   34                                                      0.0011        79.07%        0.0300        0.911        
 216.239.59.99    7                                                       0.0002        16.28%        0.0300        3.916        
 145.253.2.203    2                                                       0.0001        4.65%         0.0100        2.554        

---------------------------------------------------------------------------------------------------------------------------------
```

 You can filter **all source and destination addresses** using the parameters given below.
- IPv4: `-z ip_srcdst,tree -q`
- IPv6: `-z ipv6_srcdst,tree -q`
```bash
$ tshark -r demo.pcapng -z ip_srcdst,tree -q

================================================================================================================================================
IPv4 Statistics/Source and Destination Addresses:
Topic / Item                     Count         Average       Min val       Max val       Rate (ms)     Percent       Burst rate    Burst start  
------------------------------------------------------------------------------------------------------------------------------------------------
Source IPv4 Addresses            43                                                      0.0014        100%          0.0400        2.554        
 145.254.160.237                 20                                                      0.0007        46.51%        0.0200        0.911        
 65.208.228.223                  18                                                      0.0006        41.86%        0.0200        2.554        
 216.239.59.99                   4                                                       0.0001        9.30%         0.0200        3.916        
 145.253.2.203                   1                                                       0.0000        2.33%         0.0100        2.914        
Destination IPv4 Addresses       43                                                      0.0014        100%          0.0400        2.554        
 145.254.160.237                 23                                                      0.0008        53.49%        0.0200        2.554        
 65.208.228.223                  16                                                      0.0005        37.21%        0.0200        0.911        
 216.239.59.99                   3                                                       0.0001        6.98%         0.0100        2.984        
 145.253.2.203                   1                                                       0.0000        2.33%         0.0100        2.554        

------------------------------------------------------------------------------------------------------------------------------------------------
```

You can filter all outgoing traffic by using the parameters given below.
- IPv4: `-z dests,tree -q`
- IPv6: `-z ipv6_dests,tree -q`
```bash
$ tshark -r demo.pcapng -z dests,tree -q

=======================================================================================================================================
IPv4 Statistics/Destinations and Ports:
Topic / Item            Count         Average       Min val       Max val       Rate (ms)     Percent       Burst rate    Burst start  
---------------------------------------------------------------------------------------------------------------------------------------
Destinations and Ports  43                                                      0.0014        100%          0.0400        2.554        
 145.254.160.237        23                                                      0.0008        53.49%        0.0200        2.554        
  TCP                   22                                                      0.0007        95.65%        0.0200        2.554        
   3372                 18                                                      0.0006        81.82%        0.0200        2.554        
   3371                 4                                                       0.0001        18.18%        0.0200        3.916        
  UDP                   1                                                       0.0000        4.35%         0.0100        2.914        
   3009                 1                                                       0.0000        100.00%       0.0100        2.914        
 65.208.228.223         16                                                      0.0005        37.21%        0.0200        0.911        
  TCP                   16                                                      0.0005        100.00%       0.0200        0.911        
   80                   16                                                      0.0005        100.00%       0.0200        0.911        
 216.239.59.99          3                                                       0.0001        6.98%         0.0100        2.984        
  TCP                   3                                                       0.0001        100.00%       0.0100        2.984        
   80                   3                                                       0.0001        100.00%       0.0100        2.984        
 145.253.2.203          1                                                       0.0000        2.33%         0.0100        2.554        
  UDP                   1                                                       0.0000        100.00%       0.0100        2.554        
   53                   1                                                       0.0000        100.00%       0.0100        2.554        

---------------------------------------------------------------------------------------------------------------------------------------
```
### DNS
```bash
$ tshark -r demo.pcapng -z dns,tree -q

==============================================================================================================================================
DNS:
Topic / Item                   Count         Average       Min val       Max val       Rate (ms)     Percent       Burst rate    Burst start  
----------------------------------------------------------------------------------------------------------------------------------------------
Total Packets                  2                                                       0.0055        100%          0.0100        2.554        
 rcode                         2                                                       0.0055        100.00%       0.0100        2.554        
  No error                     2                                                       0.0055        100.00%       0.0100        2.554        
 opcodes                       2                                                       0.0055        100.00%       0.0100        2.554        
  Standard query               2                                                       0.0055        100.00%       0.0100        2.554        
 Query/Response                2                                                       0.0055        100.00%       0.0100        2.554        
  Response                     1                                                       0.0028        50.00%        0.0100        2.914        
  Query                        1                                                       0.0028        50.00%        0.0100        2.554        
 Query Type                    2                                                       0.0055        100.00%       0.0100        2.554        
  A (Host Address)             2                                                       0.0055        100.00%       0.0100        2.554        
 Class                         2                                                       0.0055        100.00%       0.0100        2.554        
  IN                           2                                                       0.0055        100.00%       0.0100        2.554        
Payload size                   2             96.50         47            146           0.0055        100%          0.0100        2.554        
Query Stats                    0                                                       0.0000        100%          -             -            
 Qname Len                     1             29.00         29            29            0.0028                      0.0100        2.554        
 Label Stats                   0                                                       0.0000                      -             -            
  3rd Level                    1                                                       0.0028                      0.0100        2.554        
  4th Level or more            0                                                       0.0000                      -             -            
  2nd Level                    0                                                       0.0000                      -             -            
  1st Level                    0                                                       0.0000                      -             -            
Response Stats                 0                                                       0.0000        100%          -             -            
 no. of questions              2             1.00          1             1             0.0055                      0.0200        2.914        
 no. of authorities            2             0.00          0             0             0.0055                      0.0200        2.914        
 no. of answers                2             4.00          4             4             0.0055                      0.0200        2.914        
 no. of additionals            2             0.00          0             0             0.0055                      0.0200        2.914        
Service Stats                  0                                                       0.0000        100%          -             -            
 request-response time (secs)  1             0.36          0.360518      0.360518      0.0028                      0.0100        2.914        
 no. of unsolicited responses  0                                                       0.0000                      -             -            
 no. of retransmissions        0                                                       0.0000                      -             -            

----------------------------------------------------------------------------------------------------------------------------------------------
```
### HTTP
You can filter the packets and view the details using the parameters given below.  
- **Packet and status counter for HTTP:** `-z http,tree -q`
- **Packet and status counter for HTTP2:** `-z http2,tree -q`
- **Load distribution:** `-z http_srv,tree -q`
- **Requests:** `-z http_req,tree -q`
- **Requests and responses:** `-z http_seq,tree -q`
```bash
$ tshark -r demo.pcapng -z http,tree -q
=======================================================================================================================================
HTTP/Packet Counter:
Topic / Item            Count         Average       Min val       Max val       Rate (ms)     Percent       Burst rate    Burst start  
---------------------------------------------------------------------------------------------------------------------------------------
Total HTTP Packets      4                                                       0.0010        100%          0.0100        0.911        
 HTTP Response Packets  2                                                       0.0005        50.00%        0.0100        3.956        
  2xx: Success          2                                                       0.0005        100.00%       0.0100        3.956        
   200 OK               2                                                       0.0005        100.00%       0.0100        3.956        
  ???: broken           0                                                       0.0000        0.00%         -             -            
  5xx: Server Error     0                                                       0.0000        0.00%         -             -            
  4xx: Client Error     0                                                       0.0000        0.00%         -             -            
  3xx: Redirection      0                                                       0.0000        0.00%         -             -            
  1xx: Informational    0                                                       0.0000        0.00%         -             -            
 HTTP Request Packets   2                                                       0.0005        50.00%        0.0100        0.911        
  GET                   2                                                       0.0005        100.00%       0.0100        0.911        
 Other HTTP Packets     0                                                       0.0000        0.00%         -             -            

---------------------------------------------------------------------------------------------------------------------------------------
```
