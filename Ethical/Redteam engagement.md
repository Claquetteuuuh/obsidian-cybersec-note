# Rules of engagement
This is the official document that define the perimeter of the client.

| **Section Name**                          | **Section Details**                                                                          |
| ----------------------------------------- | -------------------------------------------------------------------------------------------- |
| Executive Summary                         | Overarching summary of all contents and authorization within RoE document                    |
| Purpose                                   | Defines why the RoE document is used                                                         |
| References                                | Any references used throughout the RoE document (HIPAA, ISO, etc.)                           |
| Scope                                     | Statement of the agreement to restrictions and guidelines                                    |
| Definitions                               | Definitions of technical terms used throughout the RoE document                              |
| Rules of Engagement and Support Agreement | Defines obligations of both parties and general technical expectations of engagement conduct |
| Provisions                                | Define exceptions and additional information from the Rules of Engagement                    |
| Requirements, Restrictions, and Authority | Define specific expectations of the red team cell                                            |
| Ground Rules                              | Define limitations of the red team cell's interactions                                       |
| Resolution of Issues/Points of Contact    | Contains all essential personnel involved in an engagement                                   |
| Authorization                             | Statement of authorization for the engagement                                                |
| Approval                                  | Signatures from both parties approving all subsections of the preceding document             |
| Appendix                                  | Any further information from preceding subsections                                           |
# Campain planning
The campain planning use the information and the goals of the RoE of the client.
It create multiple plan to indentify how and what the redteam will do.

Each red team will have his own method and documentation for the campain planning.

| **Type of Plan** | **Explanation of Plan**                                                              | **Plan Contents**                                            |
| ---------------- | ------------------------------------------------------------------------------------ | ------------------------------------------------------------ |
| Engagement Plan  | A global description of technical requirements of the red team.                      | CONOPS, Resource and Personnel Requirements, Timelines       |
| Operations Plan  | An expansion of the **Engagement Plan**. Goes further into specifics of each detail. | Operators, Known Information, Responsibilities, etc.         |
| Mission Plan     | The exact commands to run and execution time of the engagement.                      | Commands to run, Time Objectives, Responsible Operator, etc. |
| Remediation Plan | Defines how the engagement will proceed after the campaign is finished.              | Report, Remediation consultation, etc.                       |
# Engagement Documentation
This is an extension of the campain planning. 
Every plans doesn't need a documentation, they can be only sending an email for exemple.

## Engagement Plan:

| **Component**                  | **Purpose**                                                                                                                                       |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| CONOPS (Concept of Operations) | Non-technically written overview of how the red team meets client objectives and target the client.                                               |
| Resource plan                  | Includes timelines and information required for the red team to be successful—any resource requirements: personnel, hardware, cloud requirements. |
### CONOPS
It is a part of the engagement planning that detail an overview of the proceedings of an engagement. It's a penetration report summary.

It has to be **understood by a non technical reader**. And it have to be written at a **high level**, so you should details about common tooling, target, group...
Here is an outline of critical components **included in a CONOPS**:
- **Client name**
- **Service provider**
- **Timeframe**
- **General Objectives/Phrases**
- **Other training objectives** (Exfiltration)
- **High-Level Tools/Techniques planned to be used**
- **Threat group to emulate** (if any)
### Resource plan
This document detail an overview of dates, knowledge required, resource requirements.
It have to be written as a lists of subsections.
Here is an exemple:
**Header**:
- Personnel writing
- Dates 
- Customer
**Engagement Dates**
- Reconnaissance Dates
- Initial Compromise Dates
- Post-Exploitation and Persistence Dates
- Misc. Dates
**Knowledge Required** (optional)
- Reconnaissance
- Initial Compromise
- Post-Exploitation
**Resource Requirements**
- Personnel
- Hardware
- Cloud
- Misc.

![[Pasted image 20241231110802.png]]
## Operations Plan:

| **Component**          | **Purpose**                                                 |
| ---------------------- | ----------------------------------------------------------- |
| Personnel              | Information on employee requirements.                       |
| Stopping conditions    | How and why should the red team stop during the engagement. |
| RoE (optional)         | -                                                           |
| Technical requirements | What knowledge will the red team need to be successful.     |
This document provides specific details of the engagement and actions occuring.
The ROE can be placed here.
It shoud follow this schema:
**Header**:
- Personnel writing
- Dates
- Customer
**Halting/stopping conditions**
**Required/assigned personnel**
**Specific TTPs and attacks planned**
**Communications plan**
**Rules of Engagement** (optional)

![[Pasted image 20241231111604.png]]
## Mission Plan:

| **Component**                | **Purpose**                                                                                                                               |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| Command playbooks (optional) | Exact commands and tools to run, including when, why, and how. Commonly seen in larger teams with many operators at varying skill levels. |
| Execution times              | Times to begin stages of engagement. Can optionally include exact times to execute tools and commands.                                    |
| Responsibilities/roles       | Who does what, when.                                                                                                                      |
This is a cell-specific document that details the exact actions to be completed by operators.
Here is a list of the minimum detail that cells shoud include within the plan:
- Objectives
- Operators
- Exploits/Attacks
- Targets (users/machines/objectives)
- Execution plan variations
![[Pasted image 20241231112233.png]]
## Remediation Plan (optional):

| Component                | Purpose                                                                                                                                 |
| ------------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| Report                   | Summary of engagement details and report of findings.                                                                                   |
| Remediation/consultation | How will the client remediate findings? It can be included in the report or discussed in a meeting between the client and the red team. |

