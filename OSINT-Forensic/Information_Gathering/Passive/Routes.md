# Robots.txt
This is a file where are written the routes than google can index.
## Exemple
https://hackersploit.org/robots.txt
```
User-agent: *
Disallow: /wp-content/uploads/wpo/wpo-plugins-tables-list.json

# START YOAST BLOCK
# ---------------------------
User-agent: *
Disallow:

Sitemap: https://hackersploit.org/sitemap_index.xml
# ---------------------------
# END YOAST BLOCK
```
We can see that we have a /wp-.../ mean that this website is using wordpress

# Sitemap.xml
This is a file that help the search engine to understand better the website. In this sitemap you can find the list of route that can be indexed by the search engine.
