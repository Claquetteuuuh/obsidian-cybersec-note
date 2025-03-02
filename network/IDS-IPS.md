# Intrusion Detection System (IDS)
IDS is a **passive monitoring** solution for **detecting** **malicious activities/patterns**, **abnormal incidents**, and **policy violations**.
There are **2 main types**

| **Network Intrusion Detection System (NIDS)**    | It **scan the entire subnet**. If a **signature** is detected, it **raise an alert**. (for exemple [[Snort_Usage]]) |
| ------------------------------------------------ | ------------------------------------------------------------------------------------------------------------- |
| **Host-based Intrusion Detection System (HIDS)** | It scan only one device's endpoint. If a **signature** is detected, it **raise an alert**.                    |
# Intrusion Prevention System (IPS)
This is an **active protecting** solution for **preventing malicious activities/patterns**, **abnormal incidents**, and **policy violations**. His goal is to **stopping/preventing/terminating** it.
**There are 4 main types of IPS systems**

| **Network Intrusion Prevention System (NIPS)**                                     | It scan the **entire subnet**, if he detect a menace through the **signature**, the connection is terminated. (for exemple [[Snort_Usage]]) |
| ---------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| **Behaviour-based Intrusion Prevention System (Network Behaviour Analysis - NBA)** | It scan the **entire subnet**, if he detect a menace through the **behaviour**, the connection is terminated                          |
| **Wireless Intrusion Prevention System (WIPS)**                                    | It monitor the traffic of **wireless network**. If a **signature is identified**, the connection is terminated                        |
| **Host-based Intrusion Prevention System (HIPS)**                                  | It **actively protects** the traffic from a **single endpoint device**.                                                               |
# Detection/Prevention Techniques

| **Technique**       | **Approach**                                                                                                                                                                                                                   |
| ------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Signature-Based** | This technique relies on **rules that identify the specific patterns** of the known malicious behaviour. This model helps **detect known threats**.                                                                            |
| **Behaviour-Based** | This technique identifies **new threats with new patterns** that pass through signatures. The model compares the known/normal with **unknown/abnormal behaviours**. This model helps detect previously unknown or new threats. |
| **Policy-Based**    | This technique compares detected activities with **system configuration** and **security policies**. This model helps detect policy violations.                                                                                |
