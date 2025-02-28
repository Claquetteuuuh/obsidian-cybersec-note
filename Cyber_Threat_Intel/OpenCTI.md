OpenCTI is an open source platform created to give tools for:
- Analysing
- Visualising
- Storage
- Presentation
Of threat campaigns, malware and IOCs.
# Objective
Déveloped by  [French National cybersecurity agency (ANSSI)](https://www.ssi.gouv.fr/) (kokoriko), the main objective is to create a comprehensive tool that allows users to capitalise on technical and non technical information while developing relationships between each piece of information and its primary source.

It use [[Att&ck]] framework to structure the data.
# OpenCTI Data Model
![[Pasted image 20250228132105.png]]

According to OpenCTI, connectors fall under the following classes:

| Class                              | Description                                                  | Examples                  |
| ---------------------------------- | ------------------------------------------------------------ | ------------------------- |
| **External Input Connector**       | Ingests information from external sources                    | CVE, MISP, TheHive, MITRE |
| **Stream Connector**               | Consumes platform data stream                                | History, Tanium           |
| **Internal Enrichment Connector**  | Takes in new OpenCTI entities from user requests             | Observables enrichment    |
| **Internal Import File Connector** | Extracts information from uploaded reports                   | PDFs, STIX2 Import        |
| **Internal Export File Connector** | Exports information from OpenCTI into different file formats | CSV, STIX2 export, PDF    |
# Dashboard
If you want to master it, practice !
![[Pasted image 20250228133609.png]]

