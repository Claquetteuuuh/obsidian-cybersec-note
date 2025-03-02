Snort is an open-source, rule-based Network **Intrusion Detection and Prevention System (NIDS/NIPS)**, see [[IDS-IPS]]. We can call it an "full-blown" NIPS.

**Capabilities of Snort**:
- Live traffic analysis
- Attack and probe detection
- Packet logging
- Protocol analysis
- Real-time alerting
- Modules & plugins
- Pre-processors
- Cross-platform support! (Linux & Windows)

**Snort has three main use models**:
- **Sniffer Mode** - Read IP packets and prompt them in the console application.
- **Packet Logger Mode** - Log all IP packets (inbound and outbound) that visit the network.
- **NIDS (Network Intrusion Detection System)  and NIPS (Network Intrusion Prevention System) Modes** - Log/drop the packets that are deemed as malicious according to the user-defined rules.
# Snort
## Version
To see if it is installed, let's look at the version:
```bash
$ snort -v
Running in packet dump mode

        --== Initializing Snort ==--
Initializing Output Plugins!
pcap DAQ configured to passive.
Acquiring network traffic from "eth0".
ERROR: Can't start DAQ (-1) - socket: Operation not permitted!
Fatal Error, Quitting..

```
## Configuration
To see if the configuration file is valid:
```bash
$ sudo snort -c /etc/snort/snort.conf -T 
--== Initializing Snort ==-- 
(...)
Snort successfully validated the configuration!
Snort exiting
```
## Logging
```bash
$ sudo snort -dev -K ASCII -l .
```
This create one folder by IP.
It is in a readable format.
## Reading logs
```bash
$ sudo snort -r snort.log.1638459842
```
### Full header
```bash
$ sudo snort -r snort.log.1638459842 -X
```
### Limit the showed lines
```bash
$ sudo snort -r snort.log.1638459842 -n 10
```
### Filter with BPF
https://biot.com/capstats/bpf.html
```bash
$ sudo snort -r snort.log.1638459842 'tcp port 80'
```
## IDS/IPS mode
To start snort in IPS mode, we have to run it in background:
```bash
sudo snort -c /etc/snort/snort.conf -D

Spawning daemon child...
My daemon child 2513 lives...
Daemon parent exiting (0)

```
## IDS mode with -A
```bash
sudo snort -c /etc/snort/snort.conf -A console
Running in IDS mode
...
```
## IDS mode with "-A fast"
This mode has no console output, it provide alert messages, timestamps, and source and destination IP addresses.
```bash
sudo snort -c /etc/snort/snort.conf -A fast
```
## IDS mode with "-A full"
Full alert mode provides all possible information about the alert.
```bash
sudo snort -c /etc/snort/snort.conf -A full
```
## IPS mode and dropping packets
```bash
sudo snort -c /etc/snort/snort.conf -q -Q --daq afpacket -i eth0:eth1 -A console
```
## PCAP
You can read pcap files:
```bash
sudo snort -c /etc/snort/snort.conf -A full -l . -r mx-2.pcap
```
# Cheatsheet
## Information

| **Parameter**      | **Description**                                                                                        |
| ------------------ | ------------------------------------------------------------------------------------------------------ |
| **-V / --version** | This parameter provides information about your instance version.                                       |
| **-c**             | Identifying the configuration file                                                                     |
| **-T**             | Snort's self-test parameter, you can test your setup with this parameter.                              |
| -**q**             | Quiet mode prevents snort from displaying the default banner and initial information about your setup. |
## Sniffer mode
| **Parameter** | **Description**                                                                                                                                               |
| ------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **-v**        | Verbose. Display the TCP/IP output in the console.                                                                                                            |
| **-d**        | Display the packet data (payload).                                                                                                                            |
| **-e**        | Display the link-layer (TCP/IP/UDP/ICMP) headers.                                                                                                             |
| -**X**        | Display the full packet details in HEX.                                                                                                                       |
| -**i**        | This parameter helps to define a specific network interface to listen/sniff. Once you have multiple interfaces, you can choose a specific interface to sniff. |
## Logger mode
| **Parameter** | **Description**                                                                                                                                                                  |
| ------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **-l**        | Logger mode, target **log and alert** output directory. Default output folder is **/var/log/snort**<br><br>The default action is to dump as tcpdump format in **/var/log/snort** |
| **-K ASCII**  | Log packets in ASCII format.                                                                                                                                                     |
| **-r**        | Reading option, read the dumped logs in Snort.                                                                                                                                   |
| **-n**        | Specify the number of packets that will process/read. Snort will stop after reading the specified number of packets.                                                             |
## IDS/IPS mode
| **Parameter** | **Description**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| ------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **-c**        | Defining the configuration file.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| **-T**        | Testing the configuration file.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| **-N**        | Disable logging.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| **-D**        | Background mode.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| **-A**        | Alert modes;  <br><br>**full:** Full alert mode, providing all possible information about the alert. This one also is the default mode; once you use -A and don't specify any mode, snort uses this mode.<br><br>**fast:**  Fast mode shows the alert message, timestamp, source and destination IP, along with port numbers.<br><br>console: Provides fast style alerts on the console screen.<br><br>**cmg:** CMG style, basic header details with payload in hex and text format.<br><br>**none:** Disabling alerting. |
## PCAP

| **Parameter**           | **Description**                                   |
| ----------------------- | ------------------------------------------------- |
| **-r / --pcap-single=** | Read a single pcap                                |
| **--pcap-list=""**      | Read pcaps provided in command (space separated). |
| **--pcap-show**         | Show pcap name on console during processing.      |
