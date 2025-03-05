## Loading Frameworks
Zeek has 15+ frameworks to help discover events of interest. Frameworks are loaded using:

```zeek
@load /path/to/framework/script
```
## File Framework

The File Framework allows for file analysis and extraction from network traffic.
### File Hashing
You can enable MD5, SHA1, and SHA256 hashing for all files:

```zeek
# Method 1: Direct load
@load /opt/zeek/share/zeek/policy/frameworks/files/hash-all-files.zeek

# Method 2: In a script file
# Contents of hash-demo.zeek
@load /opt/zeek/share/zeek/policy/frameworks/files/hash-all-files.zeek
```

The script that powers the hash functionality:

```zeek
# Enable MD5, SHA1 and SHA256 hashing for all files.
@load base/files/hash
event file_new(f: fa_file)
{
    Files::add_analyzer(f, Files::ANALYZER_MD5);
    Files::add_analyzer(f, Files::ANALYZER_SHA1);
    Files::add_analyzer(f, Files::ANALYZER_SHA256);
}
```

Execution and output:

```
$ zeek -C -r case1.pcap hash-demo.zeek
$ cat files.log | zeek-cut md5 sha1 sha256
cd5a4d3fdd5bffc16bf959ef75cf37bc 33bf88d5b82df3723d5863c7d23445e345828904 6137f8db2192e638e13610f75e73b9247c05f4706f0afd1fdb132d86de6b4012
b5243ec1df7d1d5304189e7db2744128 a66bd2557016377dfb95a87c21180e52b23d2e4e f808229aa516ba134889f81cd699b8d246d46d796b55e13bee87435889a054fb
cc28e40b46237ab6d5282199ef78c464 0d5c820002cf93384016bd4a2628dcc5101211f4 749e161661290e8a2d190b1a66469744127bc25bf46e5d0c6f2e835f4b92db18
```
### File Extraction
Extract all files from the network traffic:

```zeek
$ zeek -C -r case1.pcap /opt/zeek/share/zeek/policy/frameworks/files/extract-all-files.zeek
```

This creates an `extract_files` directory containing all extracted files:

```
$ ls extract_files | nl
     1 extract-1561667874.743959-HTTP-Fpgan59p6uvNzLFja
     2 extract-1561667889.703239-HTTP-FB5o2Hcauv7vpQ8y3
     3 extract-1561667899.060086-HTTP-FOghls3WpIjKpvXaEl

$ file extract_files/* | nl
     1 extract-1561667874.743959-HTTP-Fpgan59p6uvNzLFja:  ASCII text, with no line terminators
     2 extract-1561667889.703239-HTTP-FB5o2Hcauv7vpQ8y3:  Composite Document File V2 Document, Little Endian...
     3 extract-1561667899.060086-HTTP-FOghls3WpIjKpvXaEl: PE32 executable (GUI) Intel 80386, for MS Windows
```
### File Naming Convention
Zeek renames extracted files using this format:

- `extract-[timestamp]-[protocol]-[connection_id]`
### Correlating File Information
You can correlate file information across logs:

```
$ cat files.log | zeek-cut fuid conn_uids tx_hosts rx_hosts mime_type extracted | nl
     1 Fpgan59p6uvNzLFja CaeNgL1QzYGxxZPwpk 23.63.254.163 10.6.27.102 text/plain extract-1561667874.743959-HTTP-Fpgan59p6uvNzLFja
     2 FB5o2Hcauv7vpQ8y3 CCwdoX1SU0fF3BGBCe 107.180.50.162 10.6.27.102 application/msword extract-1561667889.703239-HTTP-FB5o2Hcauv7vpQ8y3
     3 FOghls3WpIjKpvXaEl CZruIO2cqspVhLuAO9 107.180.50.162 10.6.27.102 application/x-dosexec extract-1561667899.060086-HTTP-FOghls3WpIjKpvXaEl
```

Cross-reference with other logs:

```
$ grep -rin CZruIO2cqspVhLuAO9 * | column -t | nl
     1 conn.log:43:1561667898.852600   CZruIO2cqspVhLuAO9  10.6.27.102     49162        107.180.50.162      80    tcp  http        
     2 files.log:11:1561667899.060086  FOghls3WpIjKpvXaEl  107.180.50.162  10.6.27.102  CZruIO2cqspVhLuAO9  HTTP  0    EXTRACT,PE  
     3 http.log:11:1561667898.911759   CZruIO2cqspVhLuAO9  10.6.27.102     49162        107.180.50.162      80    1    GET
```
## Notice Framework - Intelligence
The Intelligence Framework processes and correlates events using threat intelligence feeds.
### Creating an Intelligence File
Intelligence files must be tab-delimited:

```
#fields indicator indicator_type meta.source meta.desc
smart-fax.com Intel::DOMAIN zeek-intel-test Zeek-Intelligence-Framework-Test
```
### Intelligence Script
Create a script to load the intelligence framework and specify the intel file:

```zeek
# intelligence-demo.zeek
@load policy/frameworks/intel/seen
@load policy/frameworks/intel/do_notice
redef Intel::read_files += { "/opt/zeek/intel/zeek_intel.txt" }; 
```
### Execution and Results
```
$ zeek -C -r case1.pcap intelligence-demo.zeek 

$ cat intel.log | zeek-cut uid id.orig_h id.resp_h seen.indicator matched
CZ1jLe2nHENdGQX377 10.6.27.102 10.6.27.1 smart-fax.com Intel::DOMAIN        
C044Ot1OxBt8qCk7f2 10.6.27.102 107.180.50.162 smart-fax.com Intel::DOMAIN 
```
### Important Notes on Intelligence Files
1. Files must be tab-delimited
2. You can add lines to the intel file without redeploying Zeek
3. If you delete a line, you must redeploy the Zeek instance
