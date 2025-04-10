Digital Forensics and Incident Response covers the collection of forensic artifacts from digital device such as computers, media devices, and smartphones to investigate an incident.
It identify footprints left by an attacker.

DFIR helps security professionals in various ways, some of which are summarized below:

- Finding evidence of attacker activity in the network and sifting false alarms from actual incidents.
- Robustly removing the attacker,  so their foothold from the network no longer remains.
- Identifying the extent and timeframe of a breach. This helps in communicating with relevant stakeholders.
- Finding the loopholes that led to the breach. What needs to be changed to avoid the breach in the future?
- Understanding attacker behavior to pre-emptively block further intrusion attempts by the attacker.
- Sharing information about the attacker with the community.
# Artifacts
Artifacts are pieces of evidence.
The goal of the artifacts is to support a hypothesis or claim about attacker activity.
For exemple, if an attacker use register to maintain persistence we can said that register is an artifact.
# Evidence Preservation
We must maintain the integrity of the evidence we are collecting. For this reason certain best practices are established in the industry. 
A contaminated chain of custody raises questions about the integrity of the data.
# Order of volatility
Digital evidence is often volatile, it can be lost forever if not captured in time. For exemple the RAM will be lost when the computer is shut down. Some sources are more volatile as compared to others. 
# Timeline Creation
Once we have collected the artifacts and maintained their integrity, we need to present them understandably to fully use the information contained in them. A timeline of events needs to be created for efficient and accurate analysis.
# Incident Response
![[Pasted image 20250331150231.png]]

1. **Preparation**: Before an incident happens,  preparation needs to be done so that everyone is ready in case of an incident. Preparation includes having the required people, processes, and technology to prevent and respond to incidents.
2. **Identification**: An incident is identified through some indicators in the identification phase. These indicators are then analyzed for False Positives, documented, and communicated to the relevant stakeholders.
3. **Containment**: In this phase, the incident is contained, and efforts are made to limit its effects. There can be short-term and long-term fixes for containing the threat based on forensic analysis of the incident that will be a part of this phase.
4. **Eradication**: Next, the threat is eradicated from the network. It has to be ensured that a proper forensic analysis is performed and the threat is effectively contained before eradication. For example, if the entry point of the threat actor into the network is not plugged, the threat will not be effectively eradicated, and the actor can gain a foothold again.
5. **Recovery**: Once the threat is removed from the network, the services that had been disrupted are brought back as they were before the incident happened.
6. **Lessons Learned**: Finally, a review of the incident is performed, the incident is documented, and steps are taken based on the findings from the incident to make sure that the team is better prepared for the next time an incident occurs.