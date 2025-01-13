# Importance
## Information security governance
This represents an organisation's established **structure, policies, method and guidelines** designed to guarantee the **privacy, reliability and accessibility of its information assets**.

It includes the following processes:
- **Strategy**: Setup a global strategy for the security of the information
- **Policies and procedures**: Setup policies on the usage and the protection of the informations assets
- **Risk management**: Identify the potential threats to the organisation's information assets and implement measures.
- **Performance measurement**: Establishing metrics and key performance indicators (KPIs)
- **Compliance**: Ensuring compliance with relevant regulations and best practices.
## Information security regulation
Governance and regulation are linked in the information security concept.
The regulation is the **legal and regulatory frameworks** that govern the use and protection of information assets.
Exemples: 
- GPDR
- Payment card industry data security standard (PCI DSS)
- Personal information protection and electronic documents act (PIPEDA)
- ...
## Key benefits
![[Pasted image 20241231115648.png]]
# Information security frameworks
It define the organisation's approach to information security, it includes:
- **Policies**: A formal statement that outlines the goals, principles and guidelines.
- **Standards**: A document establishing specific requirements for a particular process, product or service
- **Guidelines**: A document that provides recommendations and best practices.
- **Procedures**: Set of specific steps to start a task or process.
- **Baseline**: A set of minimum security standards or requirements that the organization or system must meet.
## Developing governance documents
Here are the steps used to develop policies, standards and guidelines:
- **Identify the scope and purpose**: Determine what the document will cover and why. (Password policy might be required to ensure robust and secure user password)
- **Research and review**: Research laws, regulations, standards, best practice to ensure your document is comprehensive and up-to-date.
- **Draft the document**: Follow the best practices for writing clear and concise policies, procedures, standards, guidelines, and baselines. It have to be aligned with the organisation's goals and values.
- **Review and approval**: Review by stakeholders, such as subject matter experts, legal and compliance teams.
- **Implementation and communication**: Communicate the document to all relevant employees and stakeholders, and ensure they understand their roles and responsabilities.
- **Review and update**: Review and update the document to ensure it remains relevant and practical. Make changes as per stakeholder's input
## Preparing a password policy
- **Define password requirements**: Minimul length, complexity and expiration.
- **Define password usage guidelines**: How passwords should be used, requiring unique password for each account, prohibiting the sharing of passwords and default passwords.
- **Define password storage and transmission guidelines**: How often passwords should be changed etc...
- **Communicate the policy**: Communicate the policy to all relevant employees and stakeholders.
- **Monitor compliance**: Monitor compliance with the password policy and ajust the policy as needed.
## Making an incident response procedure
- **Define incident types**: Unauthorised access, malware infections, or data breaches.
- **Define incident response roles and responsabilities**: Identify the stakeholders, like incident response team members, IT personnel, legal and compliance teams.
- **Detailed steps**: Develop step-by-step procedures for responding to each type of incident, including:
	- Containing the incident and preserving evidence
	- Analysis and investigation, identifying the root cause and the impact
	- Response and recovery, mitigating the incident, report and restore.
- **Report**: Document the incident response process for future reference.
- **Communicate** the incident response procedures.
- **Review** and update the incident response procedures
# Governance risk and compliance (GRC)
It is the monitoring of the global governance of the organisation. It focuse on the **monitoring**, the risk **management**, and the **compliance**.
It contains the three following components:
- **Governance component**: Guiding an organisation by setting its direction through information security strategy, it includes policies, standards, baselines, frameworks...
- **Risk management Component**: Identifying, assessing and prioritising risks to the organisation and implementing controls and mitigation strategies.
- **Compliance component**: Ensuring that the organisation meets its legal, regulatory and industry obligations.
# Privacy and data protection
## General data protection regulation (GDPR)
It is a data protection law implemented by the EU in may 2018 to protect personal data. [GPDR](https://gdpr-info.eu/)
The key point are:
- **Prior approval** must be obtained before collecting any personal data
- Personal data should be kept to a **minimum** and only collected when necessary
- **Adequate measures** are to be adopted to protect stored personal data.
![[Pasted image 20250102101729.png]]
In case of non conformity:
- **Tier 1**: more severe violations: unintended data collection, sharing data without consent,... Maximum penality amounting to 4% of the orgnisation's revenue or 20 million euros (whichever is higher).
- **Tier 2**: Less severe violations, data breach notifications, cyber policies, etc... The maximum is 2% of the organisation's revenue or 10 million euros (whichever is higher).
## Payment card industry data security standard (PCI DSS)
**[PCI DSS](https://www.pcisecuritystandards.org/)** is focused on maintaining secure card transactions and protecting against data theft and fraud. Used by businesses, primarily online, for card-based transactions. Etablished by major credit card brands (Visa, Mastercard & American Express). It requires:
- Strict control access to cardholder information
- Minitoring unauthorised access, using WAF and encryption.
[Learn about it](https://docs-prv.pcisecuritystandards.org/PCI%20DSS/Supporting%20Document/PCI_DSS-QRG-v4_0.pdf)
# Nist special publications
## Nist 800-53
It is a publication called "**Security and privacy controls for information systems and organisations**", developed by the National Institute of Standards and Technology, that provides a catalogue of security controls to protect the [[Pentest_Basics#La triade CIA]].
It incorporates:
- Best practices from multiple sources
- Industry standards
- Guidelines
- International frameworks
## Key points
![[Pasted image 20250102103913.png]]
## Developing and implementing NIST 800-53 based information security program
![[Pasted image 20250102104621.png]]
## Compliance best practices
![[Pasted image 20250102104543.png]]
# Information security management and compliance
## ISO/IEC 27001
It is an internationally recognised standard for requirements to **plan, develop, run, and update** an organisation's information security management system (ISMS).
it has the following core components:
- **Scope**: This specifies the ISMS's boundaries, including the covered assets and processes.
- **Information security policy**: A high-level document defining information security approach.
- **Risk assessment**: Identifying and evaluating the risks to the confidentiality, integrity and availability of the data.
- **Risk treatment**: Selecting and implementing controls to reduce the identified risks.
- **Statement of application (SoA)**: This document specifies which controls from the standard are applicale and which are not.
- **Internal audit**: Conducting periodic audits of the ISMS to ensure that it is operating effectively.
- **Management review**: Review the performance of ISMS.
![[Pasted image 20250102111412.png]]
## Service Organisation Control (SOC 2)
It is a **compliance/auditing framework**. Focuse on assessing the efficacy of a company's **data security based on the CIA triad**.
This framework is essential for service providers interacting with client data or ofering solutions that **process, store, or transmit sensitive data**.
- The audits are performed by independent auditors who evaluate whether an organization's security controls meet the established SOC 2 criteria.
- SOC 2 reports serve multiple purposes:
	- They demonstrate to customers, stakeholders, and regulators that an organization has proper security and privacy practices
	- They show that adequate controls are in place to protect customer data and systems
	- They provide detailed assessments of specific controls like physical security, network security, encryption, backup systems, and employee training.
	- They include findings and recommendations for improving security measures.
	- They can be shared with relevant parties to verify security compliance
![[Pasted image 20250102112243.png]]