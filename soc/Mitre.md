# ATT&CK
The Att&ck framework is a big database on the adversary tactics and techniques based on real-world.
https://attack.mitre.org/
For exemple here you can see that in the Initial Access method you have phishing for exemple:
![[Pasted image 20250224184756.png]]
## Usage
When you go to see the details of a technique, you can see the mitigations method, data sources for detection
Here is a tool based on the ATT&CK framework:
https://mitre-attack.github.io/attack-navigator//#layerURL=https%3A%2F%2Fattack.mitre.org%2Fgroups%2FG0008%2FG0008-enterprise-layer.json
# CAR
[Car](https://car.mitre.org/analytics/) is a knowledge database based on Att&ck but it give practical pseudo-code to understand how thing work.
For exemple:
https://car.mitre.org/analytics/CAR-2020-09-001/
# MITRE ENGAGE
https://engage.mitre.org/starter-kit/
This framework use an Adversary Engagement Approach. It is done with:
- **Cyber Denial**: Prevent the adversary's ability to conduct their operations
- **Cyber Deception**: Intentionally plant artifacts to mislead the adversary

The matrix https://engage.mitre.org/matrix
![[Pasted image 20250224184812.png]]
- **Prepare** the set of operational actions that will lead to your desired outcome
- **Expose** adversaries when they trigger your deployed deception activities
- **Affect** adversaries by performing actions that will have a negative impact on their operations
- **Elicit**(obtain) information by observing the adversary and learn more about their modus operandi 
- **Understand** the outcomes of the operational actions
# D3FEND
https://d3fend.mitre.org/
D3FEND is A knowledge graph of cybersecurity countermeasures.
For exemple:
![[Pasted image 20250224184855.png]]
# ATT&CK Emulation Plans
## CTID
The [Center of Threat-Informed Defense](https://mitre-engenuity.org/cybersecurity/center-for-threat-informed-defense/) organizations consists of various companies from around the globe. Their objective is to conduct research on cyber threats and their TTPs.
## Adversary Emulation Library & ATT&CK® Emulations Plans
The [Adversary Emulation Library](https://medium.com/mitre-engenuity/introducing-the-all-new-adversary-emulation-plan-library-234b1d543f6b) is a public library making adversary emulation plans a free resource for blue/red teamers
There are several [ATT&CK® Emulation Plans](https://github.com/center-for-threat-informed-defense/adversary_emulation_library) currently available: [APT3](https://attack.mitre.org/resources/adversary-emulation-plans/), [APT29](https://github.com/center-for-threat-informed-defense/adversary_emulation_library/tree/master/apt29), and [FIN6](https://github.com/center-for-threat-informed-defense/adversary_emulation_library/tree/master/fin6). They are step by step guide on how to mimic the specific threat group.
# ATT&CK and Threat intelligence
**Threat Intelligence (TI)** or **Cyber Threat Intelligence (CTI)** is the information attributed to the adversary. By using it as a defender we can make better decisions. 