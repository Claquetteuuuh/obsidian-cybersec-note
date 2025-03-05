# Processing Zeek Logs
## Basic Commands

| **Action**                          | **Command** |
| ----------------------------------- | ----------- |
| View command history                | `history`   |
| Execute the 10th command in history | `!10`       |
| Repeat the last command             | `!!`        |
## Reading Files

| **Action**              | **Command**       |
| ----------------------- | ----------------- |
| Read a file             | `cat sample.txt`  |
| Read the first 10 lines | `head sample.txt` |
| Read the last 10 lines  | `tail sample.txt` |
## Finding & Filtering Data

| **Action**             | **Command**   |
| ---------------------- | ------------- |
| Cut the 1st field      | `cat test.txt |
| Cut the 1st column     | `cat test.txt |
| Find a keyword         | `cat test.txt |
| Sort alphabetically    | `cat test.txt |
| Sort numerically       | `cat test.txt |
| Remove duplicate lines | `cat test.txt |
| Count lines            | `cat test.txt |
| Show line numbers      | `cat test.txt |
## Advanced Processing

| **Action**           | **Command**   |
| -------------------- | ------------- |
| Print line 11        | `cat test.txt |
| Print lines 10-15    | `cat test.txt |
| Print lines below 11 | `cat test.txt |
| Print only line 11   | `cat test.txt |
## Zeek Log Filtering

| **Action**              | **Command**         |
| ----------------------- | ------------------- |
| Extract specific fields | `cat signatures.log |
## Useful CLI Use Cases

|**Use Case**|**Description**|
|---|---|
|`sort|uniq`|
|`sort|uniq -c`|
|`sort -nr`|Sort values numerically and recursively.|
|`rev`|Reverse string characters.|
|`cut -f 1`|Cut field 1 from the text.|
|`cut -d '.' -f 1-2`|Split by dots and keep the first two fields.|
|`grep -v 'test'`|Show lines **not** containing "test".|
|`grep -v -e 'test1' -e 'test2'`|Show lines **not** containing "test1" or "test2".|
|`file`|View file type and metadata.|
|`grep -rin Testvalue1 *|column -t|
