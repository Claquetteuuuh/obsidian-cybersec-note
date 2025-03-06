This is the world's leading platform for network security monitoring, flexible, open-source, and powered by defenders.
It is an open source network traffic analyser, it can be used as a **network security monitor (NSM)** to support suspicious or malicious activity investigations.
# Zeek vs Snort

| **Tool**            | **Zeek**                                                                                                                                                                                                           | **Snort**                                                                                                                                               |
| ------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Capabilities**    | NSM and IDS framework. It is heavily focused on network analysis. It is more focused on specific threats to trigger alerts. The detection mechanism is focused on events.                                          | An IDS/IPS system. It is heavily focused on signatures to detect vulnerabilities. The detection mechanism is focused on signature patterns and packets. |
| **Cons**            | Hard to use.<br><br>The analysis is done out of the Zeek, manually or by automation.                                                                                                                               | Hard to detect complex threats.                                                                                                                         |
| **Pros**            | It provides in-depth traffic visibility.<br><br>Useful for threat hunting.<br><br>Ability to detect complex threats.<br><br>It has a scripting language and supports event correlation. <br><br>Easy to read logs. | Easy to write rules.<br><br>Cisco supported rules.<br><br>Community support.                                                                            |
| **Common Use Case** | Network monitoring.  <br>In-depth traffic investigation.  <br>Intrusion detecting in chained events.                                                                                                               | Intrusion detection and prevention.  <br>Stop known attacks/threats.                                                                                    |
## Architecture
![[Pasted image 20250305104739.png]]
## Available Frameworks
You can read more about it: https://docs.zeek.org/en/master/frameworks/index.html

| Logging   | Notice               | Input      | Configuration   | Intelligence   |
| --------- | -------------------- | ---------- | --------------- | -------------- |
| Cluster   | Broker Communication | Supervisor | GeoLocation     | File Analysis  |
| Signature | Summary              | NetControl | Packet Analysis | TLS Decryption |
# Commands
## Start
Pour démarrer zeek:
```bash
$ zeekctl
Warning: new zeek version detected (run the zeekctl "deploy" command)

Welcome to ZeekControl 2.4.0

Type "help" for help.

[ZeekControl] > 
```
## Status
```bash
[ZeekControl] > status
Name         Type       Host          Status    Pid    Started
zeek         standalone localhost     stopped
```
## Start
```bash
[ZeekControl] > start
starting zeek ...
```
## Stop
```bash
[ZeekControl] > stop
stopping zeek ...
```
## Logs
### Introduction to Zeek Logs
- Zeek captures and generates logs for every network connection and application-level protocol.
- It identifies over **50 types of logs**, categorized into **7 main groups**.
- Logs are **structured, tab-separated ASCII files**, making them easy to read but requiring effort to analyze.
### Log Structure
- Each log contains multiple **fields**, each holding specific traffic data.
- The key element for **correlating logs** is the **UID** (Unique Identifier for each session).
### Log Categories

| **Category**             | **Description**                                                             |
| ------------------------ | --------------------------------------------------------------------------- |
| **Network**              | Network protocol logs (conn.log, dns.log, http.log, etc.).                  |
| **Files**                | File analysis logs (files.log, pe.log, etc.).                               |
| **NetControl**           | Network control and flow logs (netcontrol.log, openflow.log, etc.).         |
| **Detection**            | Detection and anomaly logs (intel.log, notice.log, etc.).                   |
| **Network Observations** | Logs related to network observations (known_hosts.log, software.log, etc.). |
| **Miscellaneous**        | Various additional logs (weird.log, dpd.log, etc.).                         |
| **Zeek Diagnostic**      | Zeek system and diagnostic logs (stats.log, reporter.log, etc.).            |

### Log Update Frequency
- **Daily Updated Logs**: Contain information about discovered hosts, services, and SSL certificates.
- **Per-Session Logs**: Include alerts, threat indicators, and detected signatures.
### Log Investigation Approach

| **Phase**          | **Objective**                                                  |
| ------------------ | -------------------------------------------------------------- |
| **Overall Info**   | General review of connections, shared files, and indicators.   |
| **Protocol-Based** | In-depth analysis of suspicious protocols.                     |
| **Detection**      | Reviewing alerts and Zeek signature detections.                |
| **Observation**    | Checking hosts, services, software, and unexpected activities. |

### Tools for Log Analysis
- **Linux Commands**: `cat`, `cut`, `grep`, `sort`, `uniq`.
- **Zeek-Cut Tool**: Simplifies extracting specific columns from logs.
### Example of Using `zeek-cut`
- Extracting specific columns from `conn.log`:
```
cat conn.log | zeek-cut uid proto id.orig_h id.orig_p id.resp_h id.resp_p
```
- Output:
```bash
CTMFXm1AcIsSnq2Ric	udp	192.168.121.2	51153	192.168.120.22	53 CLsSsA3HLB2N6uJwW	udp	192.168.121.10	50080	192.168.120.10	514`
```
- **Benefit**: Allows quick analysis without manually scanning the entire file.

**Other exemple**
```bash
cat notice.log | zeek-cut uid | sort | uniq | wc -l
```
# Parameters

| **Parameter** | **Description**                           |
| ------------- | ----------------------------------------- |
| **-r**        | Reading option, read/process a pcap file. |
| **-C**        | Ignoring checksum errors.                 |
| **-v**        | Version information.                      |
| **zeekctl**   | ZeekControl module.                       |



Go to packet number 39765
Look at the "packet details pane". Right-click on the JPEG section and "Export packet bytes". This is an alternative way of extracting data from a capture file. What is the MD5 hash value of extracted image?
