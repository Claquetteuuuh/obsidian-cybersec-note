# Elastic Stack
This is a collection of different open source components linked together to help users take the data from any source and IP in any format and perform a search, analyze and visualize the data in real-time.
![[Pasted image 20250328112842.png]]
![[Pasted image 20250328113743.png]]
## Elastic Search
It is a **full-text search** and **analytics engine** used to store **JSON**-formated documents.
This is an important component used to **store, analyse, perform correlation** on the data.
## Logstash
This is a data processing engine used to **take the data from different source**, apply the **filter** on it or **normalize** it.

The **input** is where the user defines the **source** from which the data is being ingested.
[https://www.elastic.co/guide/en/logstash/8.1/input-plugins.html](https://www.elastic.co/guide/en/logstash/8.1/input-plugins.html)

The **filter** is where the user specifies the **filter** options to normalize the log ingested.
[https://www.elastic.co/guide/en/logstash/8.1/filter-plugins.html](https://www.elastic.co/guide/en/logstash/8.1/filter-plugins.html)

The **output** is where the user wants the **filtered data to send**. It can be a listening port, Kibana interface, elasticsearch database, file, etc...
[https://www.elastic.co/guide/en/logstash/8.1/output-plugins.html](https://www.elastic.co/guide/en/logstash/8.1/output-plugins.html)
## Beats
It is a host-based agent known as Data-shippers that is used to ship/transfer data from the endpoints to elasticsearch.
![[Pasted image 20250328113614.png]]
## Kibana
This is a web-based data visualization that works with elasticsearch to analyze, investigate and visualize the data stream in real-time. It allow user to create multiple visualizations and dashboards for better visibility.
![[Pasted image 20250328122427.png]]
1. **Logs (document):** Each log here is also known as a single document containing information about the event. It shows the fields and values found in that document.
2. **Fields pane**: Left panel of the interface shows the list of the fields parsed from the logs. We can click on any field to add the field to the filter or remove it from the search.
3. **Index Pattern:** Let the user select the index pattern from the available list.
4. **Search bar:** A place where the user adds search queries / applies filters to narrow down the results.
5. **Time Filter:** We can narrow down results based on the time duration. This tab has many options to select from to filter/limit the logs.
6. **Time Interval:** This chart shows the event counts over time.
7. **TOP Bar:** This bar contains various options to save the search, open the saved searches, share or save the search, etc.
