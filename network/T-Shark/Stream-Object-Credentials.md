# Follow Stream  
This option helps analysts to follow traffic streams similar to Wireshark. The query structure is explained in the table given below.

| **Main Parameter** | **Protocol**                        | **View Mode**    | **Stream Number**    | **Additional Parameter** |
| ------------------ | ----------------------------------- | ---------------- | -------------------- | ------------------------ |
| -z follow          | - TCP<br>- UDP<br>- HTTP<br>- HTTP2 | - HEX<br>- ASCII | 0 \| 1 \| 2 \| 3 ... | -q                       |
Streams start from "0". You can filter the packets and follow the streams by using the parameters given below.

- **TCP Streams:** `-z follow,tcp,ascii,0 -q`
- **UDP Streams:** `-z follow,udp,ascii,0 -q`
- **HTTP Streams:** `-z follow,http,ascii,0 -q`
```bash
 $ tshark -r demo.pcapng -z follow,tcp,ascii,1 -q

===================================================================
Follow: tcp,ascii
Filter: tcp.stream eq 1
Node 0: 145.254.160.237:3371
Node 1: 216.239.59.99:80
721
GET /pagead/ads?client=ca-pub-2309191948673629&random=1084443430285&lmt=1082467020&format=468x60_as&output=html&url=http%3A%2F%2Fwww.ethereal.com%2Fdownload.html&color_bg=FFFFFF&color_text=333333&color_link=000000&color_url=666633&color_border=666633 HTTP/1.1
Host: pagead2.googlesyndication.com
User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.6) Gecko/20040113
Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,image/jpeg,image/gif;q=0.2,*/*;q=0.1
Accept-Language: en-us,en;q=0.5
Accept-Encoding: gzip,deflate
Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
Keep-Alive: 300
Connection: keep-alive
Referer: http://www.ethereal.com/download.html


	1430
HTTP/1.1 200 OK
P3P: policyref="http://www.googleadservices.com/pagead/p3p.xml", CP="NOI DEV PSA PSD IVA PVD OTP OUR OTR IND OTC"
Content-Type: text/html; charset=ISO-8859-1
Content-Encoding: gzip
Server: CAFE/1.0
Cache-control: private, x-gzip-ok=""
Content-length: 1272
Date: Thu, 13 May 2004 10:17:14 GMT

...........W.s.8..~...mI....y..1y..Mz..7.O7.%.....d.M.....p d.....a...v...{...~/...{JO9..~n4~...6....(.,.Tv.e.Sr.mL.8K..-
..m..Y<hF.3.4%....S...C...A..X.....x*.u.k,...1.y...ZK....t.+U.....mv....3.......2.*.,...Fy..i...d..:.......4..B..t%..L..9..-$B.]...mmU.x..o.1...X.l.(.AL.f.....dX..KAh....Q......p$u.=1..;D...'.!%...Bw..{.Y/T...<...GY9J....?;.ww...Ywf..... >6..Ye.X..H_@.X.YM.$......#:.....D..~O..STrt..,4....H9W..!E.....&.X.=..P9..a...<...-.O.l.-m....h..p7.(O?.a..:..-knhie...
.q.ZU....#....ps..g...p.u.T...`.bp.d.B.r....H...@........L..T.#!Cj.b.l.l....a..........,drp.4..........:aj.....p.H...=......7z...M.........}...w...y`....In.p...........'.0hnp'..T*.@/.w..@5<..(..{5@_ ../.......}r.........=K....J...qcbX..}.Q.... .>.R....<.......b...sH.u.R...T.>.x.J.+.tb).L...U.(...>.........bOO.....m..OP.o.F'L..
....m..(:m.0.h..A].eBj.......
	160
)...$.P.+-...J.yQ\.v.r..m..j..h...+.%@..yP....o..%
..g.A.x..;.M..6./...{..9....H.W.a.qz...O.....B..
===================================================================

```
# Export Objects
| **Main Parameter** | **Protocol**                                  | **Target Folder**                | **Additional Parameter** |
| ------------------ | --------------------------------------------- | -------------------------------- | ------------------------ |
| --export-objects   | - DICOM<br>- HTTP<br>- IMF<br>- SMB<br>- TFTP | Target folder to save the files. | -q                       |
```bash
$ tshark -r demo.pcapng --export-objects http,/home/ubuntu/Desktop/extracted-by-tshark -q

ubuntu@ip-10-10-114-142:~/Desktop/exercise-files$  ls -l /home/ubuntu/Desktop/extracted-by-tshark/
total 24
-rw-r--r-- 1 ubuntu ubuntu  3608 Mar  9 15:13 'ads%3fclient=ca-pub-2309191948673629&random=1084443430285&lmt=1082467020&format=468x60_as&output=html&url=http%3A%2F%2Fwww.ethereal.com%2Fdownload.html&color_bg=FFFFFF&color_text=333333&color_link=000000&color_url=666633&color_border=666633'
-rw-r--r-- 1 ubuntu ubuntu 18070 Mar  9 15:13  download.html
```
# Credentials
```bash
$  tshark -r credentials.pcap -z credentials -q
===================================================================
Packet     Protocol         Username         Info            
------     --------         --------         --------
72         FTP              admin            Username in packet: 37
80         FTP              admin            Username in packet: 47
(...)
1076       FTP              administrator    Username in packet: 1044
1087       FTP              administrator    Username in packet: 1061
===================================================================
```
# Extract Information
## Hostnames
```bash
$ tshark -r hostnames.pcapng -T fields -e dhcp.option.hostname     
92-rkd
92-rkd
T3400
(...)
202-ac
202-ac
```

A skilled analyst should know how to use native Linux tools/utilities to manage and organise the command line output, as shown below.
```bash
$ tshark -r hostnames.pcapng -T fields -e dhcp.option.hostname | awk NF | sort -r | uniq -c | sort -r

    26 202-ac
    18 92-rkd
    (...)
    1 mailroom2
    1 90-tasd-new
```

| **Query**                                                      | **Purpose**                                                                         |
| -------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| `tshark -r hostnames.pcapng -T fields -e dhcp.option.hostname` | Main query.  <br>Extract the DHCP hostname value.                                   |
| `awk NF`                                                       | Remove empty lines.                                                                 |
| `sort -r`                                                      | Sort recursively before handling the values.                                        |
| `uniq -c`                                                      | Show unique values, but calculate and show the number of occurrences.               |
| `sort -r`                                                      | The final sort process.  <br>Show the output/results from high occurrences to less. |
## DNS Queries
```bash
$ tshark -r dns-queries.pcap -T fields -e dns.qry.name | awk NF | sort -r | uniq -c | sort -r

    472 db.rhodes.edu
     96 connectivity-check.ubuntu.com.rhodes.edu
     94 connectivity-check.ubuntu.com
      8 3.57.20.10.in-addr.arpa
      4 e.9.d.b.c.9.d.7.1.b.0.f.a.2.0.2.0.0.0.0.0.0.0.0.0.0.0.0.0.8.e.f.ip6.arpa
      4 6.7.f.8.5.4.e.f.f.f.0.d.4.d.8.8.0.0.0.0.0.0.0.0.0.0.0.0.0.8.e.f.ip6.arpa
      4 3.4.b.1.3.c.e.f.f.f.4.0.e.e.8.7.0.0.0.0.0.0.0.0.0.0.0.0.0.8.e.f.ip6.arpa
      4 1.1.a.2.6.2.e.f.f.f.1.9.9.f.8.6.0.0.0.0.0.0.0.0.0.0.0.0.0.8.e.f.ip6.arpa
      4 1.0.18.172.in-addr.arpa
      4 1.0.17.172.in-addr.arpa
      4 0.f.2.5.6.b.e.f.f.f.b.7.2.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.8.e.f.ip6.arpa
      2 _ipps._tcp.local,_ipp._tcp.local
      2 84.170.224.35.in-addr.arpa
      2 22.2.10.10.in-addr.arpa
      2 21.2.10.10.in-addr.arpa
```

For exemple, to see the total number of queries of the most common DNS query?
```bash
$ tshark -r dns-queries.pcap -T fields -e dns.qry.name | sort | uniq -c | sort -nr | head -1
472 db.rhodes.edu
```
## User Agents
```bash
$  tshark -r user-agents.pcap -T fields -e http.user_agent | awk NF | sort -r | uniq -c | sort -r
      9 Wfuzz/2.4
      6 Mozilla/5.0 (Windows; U; Windows NT 6.4; en-US) AppleWebKit/534.10 (KHTML, like Gecko) Chrome/8.0.552.237 Safari/534.10
      5 Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:100.0) Gecko/20100101 Firefox/100.0
      5 Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.32 Safari/537.36
      4 sqlmap/1.4#stable (http://sqlmap.org)
      3 Wfuzz/2.7
      3 Mozilla/5.0 (compatible; Nmap Scripting Engine; https://nmap.org/book/nse.html)
      2 Microsoft-WNS/10.0
      1 Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.82 Safari/537.36
```