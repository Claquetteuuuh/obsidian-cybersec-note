# Definition
This is an evidence-based knowledge about adversaries, this include:
- **Indicators**
- **Tactics**
- **motivations**
- **Actionnable device against them** 

Here is some definitions:
- **Data**: Discrete indicators associated with an adversary, such as IP addresses, URLs or hashes
- **Information:** A combination of multiple data points that answer questions such as “How many times have employees accessed tryhackme.com within the month?”
- **Intelligence:** The correlation of data and information to extract patterns of actions based on contextual analysis.
## Goal
The goal is to understand the **relationship between** your **operational environment** and your **adversary** and how to **defend your environment against attacks**.

To do this you can answer to these questions:
- **Who**’s **attacking** you?
- **What** are their **motivations**?
- **What** are their **capabilities**?
- **What** artefacts and **indicators of compromise** (IOCs) should you look out for?
## Gathering
- **Internal:**
    - Corporate security events such as vulnerability assessments and incident response reports.
    - Cyber awareness training reports.
    - System logs and events.
- **Community:**
    - Open web forums.
    - Dark web communities for cybercriminals.
- **External**
    - Threat intel feeds (Commercial & Open-source)
    - Online marketplaces.
    - Public sources include government data, publications, social media, financial and industrial assessments.
## Classification
**Strategic Intel**: High-level intel that looks into the organisation’s threat landscape, **patterns** and emerging threats.
**Technical Intel**: Looks into **evidence and artefacts** of attack used by an adversary. Can be used by IR (incidence response) teams to create a baseline attack surface to analyse and develop defence.
**Tactical Intel**: Assesses adversaries’ **tactics, techniques, and procedures** (TTPs).
**Operational Intel**: Looks into an adversary’s specific **motives and intent to perform an attack**. Security teams may use this intel to understand the critical assets in the organisation.
# CTI Lifecycle
![[Pasted image 20250223113104.png]]
## Direction
Defines the **objectives and the goal** so you must identify the followings parameters:
- Information **assets** and business **processes** that **require defending**.
- **Potentiel impact on losing the assets** or through process interruptions.
- **Sources** of data and intel **to be used** towards protection.
- **Tools and ressources** that are **required** to defend the assets.
## Collection
Once objectives have been defined, security analysts will **gather the required data** to address them. Analysts will do this by using **commercial**, **private and open-source resources** available. Due to the volume of data analysts usually face, **it is recommended to automate this phase** to provide time for triaging incidents.
## Processing
Raw **logs**, **vulnerability information**, malware and **network traffic** usually come in different formats and **may be disconnected** when used to investigate an incident. This phase **ensures that the data is extracted**, **sorted**, **organised**, **correlated** with appropriate **tags** and presented visually in a usable and understandable format to the analysts.
**SIEMs are valuable tools** for achieving this and allow quick parsing of data.
## Analysis
Once the information collection is done, analysts must **derive insights**:
- Investigating a potential threat through uncovering indicators and attack patterns.
- Defining an action plan to avert an attack and defend the infrastructure.
- Strengthening security controls or justifying investment for additional resources.
## Dissemination
Different organisational stakeholders will consume the intelligence in varying languages and formats. Analysts doesn't have the same langage compare to the C-suite members.
## Feedback
The final phase covers the most crucial part, as analysts rely on the responses provided by stakeholders to improve the threat intelligence process and implementation of security controls. Feedback should be regular interaction between teams to keep the lifecycle working.
