# Usage
Zeek has an **event-driven scripting language** that allows for deep network traffic analysis and correlation of detected events. Zeek scripts are used to apply policies, extract data, and automate network monitoring.
## Zeek Script Locations
- **Base scripts (default, not to be modified):** `/opt/zeek/share/zeek/base`
- **User-generated scripts:** `/opt/zeek/share/zeek/site`
- **Policy scripts:** `/opt/zeek/share/zeek/policy`
- **Zeek configuration file (for auto-loading scripts in live mode):** `/opt/zeek/share/zeek/site/local.zeek`
## Running Zeek with Scripts
Scripts use the `.zeek` extension and can be loaded manually or automatically:
```bash
zeek -C -r sample.pcap script.zeek
```
To load scripts automatically, add `@load script-name` in `local.zeek`.
## Zeek vs. Other Tools (Wireshark, tcpdump, tshark)
- **GUI tools like Wireshark** provide insights but are not ideal for automation.
- **Command-line tools like tcpdump/tshark** allow data extraction but require complex commands.
- **Zeek scripts** provide **simpler automation** with structured event handling.
## Example: Extracting DHCP Hostnames
- **Using tcpdump/tshark (complex):**

```bash
tcpdump -ntr smallFlows.pcap port 67 or port 68 -e -vv | grep 'Hostname Option' | awk -F: '{print $2}' | sort -nr | uniq | nl
```

- Using Zeek (simpler 4-line script):

```bash
event dhcp_message (c: connection, is_orig: bool, msg: DHCP::Msg, options: DHCP::Options) {   
	print options$host_name;
}
```

**Run script:**
```bash
zeek -C -r smallFlows.pcap dhcp-hostname.zeek
```
## Built-In Functions (Bif) & Protocol Support
Zeek uses built-in functions and protocol analyzers to extract data. These are stored in:
- `/opt/zeek/share/zeek/base/bif`
- `/opt/zeek/share/zeek/base/protocols`

Zeek scripting is powerful for network monitoring, automation, and data correlation, making it a superior alternative for analyzing network events.
# Create one

## 1. Introduction to Zeek Scripts
Zeek scripts contain operators, types, attributes, declarations, statements, and directives. Here are the fundamental concepts:
### Basic Events: zeek_init and zeek_done
These events are triggered when the Zeek process starts and stops.

```zeek
event zeek_init()
{
    print("Started Zeek!");
}

event zeek_done()
{
    print("Stopped Zeek!");
}
```
Execution:
```
$ zeek -C -r sample.pcap 101.zeek
Started Zeek!
Stopped Zeek!
```
## 2. Connection Analysis
### Displaying All Connection Information
The `new_connection` event is automatically generated for each new connection.

```zeek
event new_connection(c: connection)
{
    print c;
}
```
The output provides detailed (but unfiltered) information for each connection.
### Filtering Relevant Information
To extract specific information:

```zeek
event new_connection(c: connection)
{
    print("###########################################################");
    print("");
    print("New Connection Found!");
    print("");
    print fmt("Source Host: %s # %s --->", c$id$orig_h, c$id$orig_p);
    print fmt("Destination Host: resp: %s # %s <---", c$id$resp_h, c$id$resp_p);
    print("");
}
```
Execution:

```
$ zeek -C -r sample.pcap 103.zeek
###########################################################

New Connection Found!

Source Host: 192.168.121.2 # 58304/udp --->
Destination Host: resp: 192.168.120.22 # 53/udp <---

###########################################################
```
## 3. Combining Scripts and Signatures
### Signature-Based Detection
Scripts can use signature results for more advanced analysis.
Signature:

```zeek
signature ftp-admin {
    ip-proto == tcp
    ftp /.*USER.*admin.*/
    event "FTP Username Input Found!"
}
```

Script to detect signature matches:

```zeek
event signature_match(state: signature_state, msg: string, data: string)
{
    if (state$sig_id == "ftp-admin")
    {
        print("Signature hit! --> #FTP-Admin");
    }
}
```

Execution:

```
$ zeek -C -r ftp.pcap -s ftp-admin.sig 201.zeek
Signature hit! --> #FTP-Admin
Signature hit! --> #FTP-Admin
Signature hit! --> #FTP-Admin
Signature hit! --> #FTP-Admin
```
## 4. Loading Scripts
### Loading All Local Scripts
Zeek allows loading all local scripts defined in "local.zeek":

```
$ zeek -C -r ftp.pcap local
```

This command loads approximately 465 scripts and generates several additional log files.
### Loading Specific Scripts
To target a particular script:

```
$ zeek -C -r ftp.pcap /opt/zeek/share/zeek/policy/protocols/ftp/detect-bruteforcing.zeek
```

Result (in notice.log):

```
1024380732.223481    FTP::Bruteforcing    10.234.125.254 had 20 failed logins on 1 FTP server in 0m1s
```

Pre-built scripts often offer more advanced functionality than simple manually created scripts.
