  
| **Capability**             | **Description**                                                                                                                                                               |
| -------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Traffic sniffing           | It can intercept the traffic, sniff it, and collect and log packets that pass through the network.                                                                            |
| Parsing PCAP files         | It can parse pcap files and show the content of the packets in detail.                                                                                                        |
| Protocol analysis          | It can identify the used protocols from the parsed pcap file.                                                                                                                 |
| OS fingerprinting          | It can identify the used OS by reading the pcap file. This feature strongly relies on [Satori](https://github.com/xnih/satori/) and [p0f](https://lcamtuf.coredump.cx/p0f3/). |
| File Extraction            | It can extract images, HTML files and emails from the parsed pcap file.                                                                                                       |
| Credential grabbing        | It can extract credentials from the parsed pcap file.                                                                                                                         |
| Clear text keyword parsing | It can extract cleartext keywords and strings from the parsed pcap file.                                                                                                      |
There is 2 modes:
-  Sniffer mode
- Packet Parsing/Processing
# Differences Between Wireshark and NetworkMiner
  
| **Feature**                 | **NetworkMiner**                                     | **Wireshark**     |
| --------------------------- | ---------------------------------------------------- | ----------------- |
| Purpose                     | Quick overview, traffic mapping, and data extraction | In-Depth analysis |
| GUI                         | ✅                                                    | ✅                 |
| Sniffing                    | ✅                                                    | ✅                 |
| Handling PCAPS              | ✅                                                    | ✅                 |
| OS Fingerprinting           | ✅                                                    | ❌                 |
| Parameter/Keyword Discovery | ✅                                                    | Manual            |
| Credential Discovery        | ✅                                                    | ✅                 |
| File Extraction             | ✅                                                    | ✅                 |
| Filtering Options           | Limited                                              | ✅                 |
| Packet Decoding             | Limited                                              | ✅                 |
| Protocol Analysis           | ❌                                                    | ✅                 |
| Payload Analysis            | ❌                                                    | ✅                 |
| Statistical Analysis        | ❌                                                    | ✅                 |
| Cross-Platform Support      | ✅                                                    | ✅                 |
| Host Categorisation         | ✅                                                    | ❌                 |
| Ease of Management          | ✅                                                    | ✅                 |
# Difference between version

| Tool                            | 2.7 | 1.6 |
| ------------------------------- | --- | --- |
| Mac address Processing          | ✅   | :x: |
| Sent/Received Packet Processing | :x: | ✅   |
| Frame processing                | :x: | ✅   |
| Parameter Processing            | ✅   | :x: |
| Cleartext Processing            | :x: | ✅   |
