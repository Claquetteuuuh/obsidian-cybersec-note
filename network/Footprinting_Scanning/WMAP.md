Web application vulnerability scanner.
Use metasploit.
# Run

```bash
msf5 > load wmap

.-.-.-..-.-.-..---..---.
| | | || | | || | || |-'
`-----'`-'-'-'`-^-'`-`
[WMAP 1.5.1] ===  et [  ] metasploit.com 2012
[*] Successfully loaded plugin: wmap
msf5 > wmap_
wmap_modules  wmap_nodes    wmap_run      wmap_sites    wmap_targets  wmap_vulns 
```
# Sites
```bash
msf5 > wmap_sites -h
[*] Usage: wmap_sites [options]
        -h        Display this help text
        -a [url]  Add site (vhost,url)
        -d [ids]  Delete sites (separate ids with space)
        -l        List all available sites
        -s [id]   Display site structure (vhost,url|ids) (level) (unicode output true/false)
```
## Add
You can create a site to target:
```bash
msf5 > wmap_sites -a 192.175.147.3
[*] Site created.
```
## List
```bash
msf5 > wmap_sites -l
[*] Available sites
===============

     Id  Host           Vhost          Port  Proto  # Pages  # Forms
     --  ----           -----          ----  -----  -------  -------
     0   192.175.147.3  192.175.147.3  80    http   0        0
```
# Target
## Add
You can add a target with the `-t` flag
```bash
msf5 > wmap_targets -t http://192.175.147.3
```
## List
You can list with the `-l` flag
```bash
msf5 > wmap_targets -l
[*] Defined targets
===============

     Id  Vhost          Host           Port  SSL    Path
     --  -----          ----           ----  ---    ----
     0   192.175.147.3  192.175.147.3  80    false      /
```
# Run
## List modules
List all the modules that can be used:
```bash
msf5 > wmap_run -t
[*] Testing target:
[*]     Site: 192.175.147.3 (192.175.147.3)
[*]     Port: 80 SSL: false
============================================================
[*] Testing started. 2024-11-01 17:48:23 +0000
[*] Loading wmap modules...
[*] 39 wmap enabled modules loaded.
[*] 
=[ SSL testing ]=
============================================================
[*] Target is not SSL. SSL modules disabled.
[*] 
=[ Web Server testing ]=
============================================================
[*] Module auxiliary/scanner/http/http_version
[*] Module auxiliary/scanner/http/open_proxy
[*] Module auxiliary/admin/http/tomcat_administration
[*] Module auxiliary/admin/http/tomcat_utf8_traversal
[*] Module auxiliary/scanner/http/drupal_views_user_enum
[*] Module auxiliary/scanner/http/frontpage_login
[*] Module auxiliary/scanner/http/host_header_injection
[*] Module auxiliary/scanner/http/options
[*] Module auxiliary/scanner/http/robots_txt
[*] Module auxiliary/scanner/http/scraper
[*] Module auxiliary/scanner/http/svn_scanner
[*] Module auxiliary/scanner/http/trace
[*] Module auxiliary/scanner/http/vhost_scanner
[*] Module auxiliary/scanner/http/webdav_internal_ip
[*] Module auxiliary/scanner/http/webdav_scanner
[*] Module auxiliary/scanner/http/webdav_website_content
[*] 
=[ File/Dir testing ]=
============================================================
[*] Module auxiliary/scanner/http/backup_file
[*] Module auxiliary/scanner/http/brute_dirs
[*] Module auxiliary/scanner/http/copy_of_file
[*] Module auxiliary/scanner/http/dir_listing
[*] Module auxiliary/scanner/http/dir_scanner
[*] Module auxiliary/scanner/http/dir_webdav_unicode_bypass
[*] Module auxiliary/scanner/http/file_same_name_dir
[*] Module auxiliary/scanner/http/files_dir
[*] Module auxiliary/scanner/http/http_put
[*] Module auxiliary/scanner/http/ms09_020_webdav_unicode_bypass
[*] Module auxiliary/scanner/http/prev_dir_same_name_file
[*] Module auxiliary/scanner/http/replace_ext
[*] Module auxiliary/scanner/http/soap_xml
[*] Module auxiliary/scanner/http/trace_axd
[*] Module auxiliary/scanner/http/verb_auth_bypass
[*] 
=[ Unique Query testing ]=
============================================================
[*] Module auxiliary/scanner/http/blind_sql_query
[*] Module auxiliary/scanner/http/error_sql_injection
[*] Module auxiliary/scanner/http/http_traversal
[*] Module auxiliary/scanner/http/rails_mass_assignment
[*] Module exploit/multi/http/lcms_php_exec
[*] 
=[ Query testing ]=
============================================================
[*] 
=[ General testing ]=
============================================================
[*] Done.
```
## Run
```bash
msf5 > wmap_run -e
[*] Using ALL wmap enabled modules.
[-] NO WMAP NODES DEFINED. Executing local modules
[*] Testing target:
[*]     Site: 192.175.147.3 (192.175.147.3)
[*]     Port: 80 SSL: false
============================================================
[*] Testing started. 2024-11-01 17:51:36 +0000
[*] 
=[ SSL testing ]=
============================================================
[*] Target is not SSL. SSL modules disabled.
[*] 
=[ Web Server testing ]=
============================================================
[*] Module auxiliary/scanner/http/http_version

[+] 192.175.147.3:80 Apache/2.4.18 (Ubuntu)
[*] Module auxiliary/scanner/http/open_proxy
[*] Module auxiliary/admin/http/tomcat_administration
[*] Module auxiliary/admin/http/tomcat_utf8_traversal
[*] Attempting to connect to 192.175.147.3:80
[+] No File(s) found
[*] Module auxiliary/scanner/http/drupal_views_user_enum
[-] 192.175.147.3 does not appear to be vulnerable, will not continue
[*] Module auxiliary/scanner/http/frontpage_login
[*] 192.175.147.3:80      - http://192.175.147.3/ may not support FrontPage Server Extensions
[*] Module auxiliary/scanner/http/host_header_injection
[*] Module auxiliary/scanner/http/options
[+] 192.175.147.3 allows GET,HEAD,POST,OPTIONS methods
[*] Module auxiliary/scanner/http/robots_txt
[*] [192.175.147.3] /robots.txt found
[+] Contents of Robots.txt:
# robots.txt for attackdefense 
User-agent: test                     
# Directories
Allow: /webmail

User-agent: *
# Directories
Disallow: /data
Disallow: /secure

[*] Module auxiliary/scanner/http/scraper
[+] [192.175.147.3] / [Apache2 Ubuntu Default Page: It works]
[*] Module auxiliary/scanner/http/svn_scanner
[*] Using code '404' as not found.
[*] Module auxiliary/scanner/http/trace
[*] Module auxiliary/scanner/http/vhost_scanner
[*] [192.175.147.3] Sending request with random domain Hjurb. 
[*] [192.175.147.3] Sending request with random domain IwxXe. 
[*] Module auxiliary/scanner/http/webdav_internal_ip
[*] Module auxiliary/scanner/http/webdav_scanner
[*] 192.175.147.3 (Apache/2.4.18 (Ubuntu)) WebDAV disabled.
[*] Module auxiliary/scanner/http/webdav_website_content
[*] 
=[ File/Dir testing ]=
============================================================
[*] Module auxiliary/scanner/http/backup_file
[*] Module auxiliary/scanner/http/brute_dirs
[*] Path: /
[*] Using code '404' as not found.
[+] Found http://192.175.147.3:80/doc/ 200
[+] Found http://192.175.147.3:80/pro/ 200
[*] Module auxiliary/scanner/http/copy_of_file
[*] Module auxiliary/scanner/http/dir_listing
[*] Path: /
[*] Module auxiliary/scanner/http/dir_scanner
[*] Path: /
[*] Detecting error code
[*] Using code '404' as not found for 192.175.147.3
[+] Found http://192.175.147.3:80/cgi-bin/ 200 (192.175.147.3)
...
[+] Found http://192.175.147.3:80/~nobody/ 404 (192.175.147.3)
[*] Module auxiliary/scanner/http/dir_webdav_unicode_bypass
[*] Path: /
[*] Using code '404' as not found.
[*] Found protected folder http://192.175.147.3:80/secure/ 401 (192.175.147.3)
[*]     Testing for unicode bypass in IIS6 with WebDAV enabled using PROPFIND request.
[*] Found protected folder http://192.175.147.3:80/webdav/ 401 (192.175.147.3)
[*]     Testing for unicode bypass in IIS6 with WebDAV enabled using PROPFIND request.
[*] Module auxiliary/scanner/http/file_same_name_dir
[*] Path: /
[-] Blank or default PATH set.
[*] Module auxiliary/scanner/http/files_dir
[*] Path: /
[*] Using code '404' as not found for files with extension .null
...
[*] Using code '404' as not found for files with extension .tmp
```
