# Adversary
An adversary is an attacker or hacker, he do things against the system.
There are 2 types of adversary:
- **Adversary Operator**: The hacker or the person conducting the intrusion
- **Adversary Customer**: An entity that get benefit from the activity conducted in the intrusion.
# Victim
The **victim is the target** of the adversary. It's an opportunity for the attacker to get a foothold in the system. It can be:
- an organization
- a person
- an email address
- ip address
- domain
- ...

**Victim Personae**: people and organizations being targeted and whose assets are being attacked and exploited
**Victim Assets**: attack surface and include the set of systems, networks, email...
# Capability
This is the skills, tools, and techniques **used by the adversary**. It **exhibe the attacker's technique** (TTP).
**Capability Capacity**: All the vulnerabilities and exposures that the capability can use.
**Adversary Arsenal**: Set of capabilities.
# Infrastructure
This is the physical or logical interconnections that the adversary uses to deliver a capability or maintain control of capabilities.
There is 2 types of infrastructure:
- **Type 1 Infrastructure**: Controlled or owned by the adversary
- **Type 2 Infrastructure**: Controlled by an intermediary Sometimes the intermediary might or might not be aware of it. That is the infrastructure that **the victim will se as an attacker**. The goal is obfuscating the source and attribution of the activity.

**Service Providers**: The organization that provide essentials tool for the good working of the infrastructure of the attacker
# Event Meta Features
This permit to add valuables informations and intelligence to the model, the can be:
- **Timestamp**: The date of each events
- **Phase**: This is the phase of the action (recon, weapon, delivery,...)
- **Result**: Event if we don't know the result, we can tag it (success, failure, unknown)
- **Direction**: Victim-to-Infrastructure, Infrastructure-to-Victim, Infrastructure-to-Infrastructure, Adversary-to-Infrastructure, Infrastructure-to-Adversary, Bidirectional or Unknown.
- **Methodology**: The general classification (phishing, DDoS)
- **Resources**: It can be a software, knowledges, informations, hardwares, credentials,... 
