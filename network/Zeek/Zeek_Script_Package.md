The Zeek Package Manager helps users install third-party scripts and plugins to extend Zeek functionality. This guide explains how to use the `zkg` tool to manage packages and demonstrates practical examples.
## Basic zkg Commands

| Command                    | Description                              | Example                                          |
| -------------------------- | ---------------------------------------- | ------------------------------------------------ |
| `zkg install package_path` | Install a package using path             | `zkg install zeek/j-gras/zeek-af_packet-plugin`  |
| `zkg install git_url`      | Install package using git URL            | `zkg install https://github.com/corelight/ztest` |
| `zkg list`                 | List all installed packages              | `zkg list`                                       |
| `zkg remove`               | Remove an installed package              | `zkg remove zeek-sniffpass`                      |
| `zkg refresh`              | Check for updates for installed packages | `zkg refresh`                                    |
| `zkg upgrade`              | Update all installed packages            | `zkg upgrade`                                    |

**Note**: You need root privileges to use the `zkg` tool.
## Three Ways to Use Packages

1. **Using as frameworks**: Call specific package path/directory per usage
2. **Using in scripts**: Load packages in scripts with the `@load` method
3. **Using package names**: Call packages directly by name (only works for packages installed with `zkg`)
## Example 1: Cleartext Password Detection

Let's install and use the `zeek-sniffpass` package, which alerts on cleartext passwords in HTTP POST requests.
### Installing the Package

```bash
$ zkg install zeek/cybera/zeek-sniffpass
The following packages will be INSTALLED:
  zeek/cybera/zeek-sniffpass (master)
Proceed? [Y/n] Y
Installing "zeek/cybera/zeek-sniffpass"
Installed "zeek/cybera/zeek-sniffpass" (master)
Loaded "zeek/cybera/zeek-sniffpass"
```
### Checking Installed Packages

```bash
$ zkg list
zeek/cybera/zeek-sniffpass (installed: master) - Sniffpass will alert on cleartext passwords discovered in HTTP POST requests
```
### Using the Package (Three Methods)
#### Method 1: Using in a Script

Create a script file (`sniff-demo.zeek`):

```zeek
@load /opt/zeek/share/zeek/site/zeek-sniffpass
```

Then run:

```bash
$ zeek -Cr http.pcap sniff-demo.zeek
```
#### Method 2: Using by Path

```bash
$ zeek -Cr http.pcap /opt/zeek/share/zeek/site/zeek-sniffpass
```
#### Method 3: Using by Package Name

```bash
$ zeek -Cr http.pcap zeek-sniffpass
```
### Viewing Results

Check the `notice.log` file for detected passwords:

```bash
$ cat notice.log | zeek-cut id.orig_h id.resp_h proto note msg
10.10.57.178  44.228.249.3  tcp  SNIFFPASS::HTTP_POST_Password_Seen  Password found for user BroZeek
10.10.57.178  44.228.249.3  tcp  SNIFFPASS::HTTP_POST_Password_Seen  Password found for user ZeekBro
```
## Example 2: Geolocation Data

The `geoip-conn` package provides geolocation information for IP addresses in the `conn.log` file. It uses the `GeoLite2-City.mmdb` database created by MaxMind.
### Using the Package

```bash
$ zeek -Cr case1.pcap geoip-conn
```
### Viewing Results

```bash
$ cat conn.log | zeek-cut uid id.orig_h id.resp_h geo.orig.country_code geo.orig.region geo.orig.city geo.orig.latitude geo.orig.longitude geo.resp.country_code geo.resp.region geo.resp.city
Cbk46G2zXi2i73FOU6  10.6.27.102  23.63.254.163  -  -  -  -  -  US  CA  Los Angeles
```
## Summary

Zeek Package Manager (`zkg`) greatly extends Zeek's functionality by allowing you to install and use third-party scripts and plugins. This guide demonstrated two practical examples:

1. Detecting cleartext passwords in HTTP traffic with `zeek-sniffpass`
2. Adding geolocation data to connection logs with `geoip-conn`

You can find more packages in the [Zeek Package Repository](https://packages.zeek.org/).