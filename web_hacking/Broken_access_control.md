# Access control
This is a mechanism to control which users are allowed to access a particular resource or system.
- **Discretionary Access Control (DAC)**: In this type of access control it determine who is allowed to access a resource and perfom what action. This is commonly used in operating systems and file systems. It is the liberty to control and access your resource.![[Pasted image 20250320092508.png]]
- **Mandatory Access Control (MAC)**: This is used in highly secure evironment such as government and military systems. In this system only specific individuals with particular security clearances can access certains area and this is non-negociable![[Pasted image 20250320092814.png]]
- **Role-Based Access Control (RBAC)**: In this type, it is the role that define the level of access to the resource. It is commonly used in entreprise systems.![[Pasted image 20250320093006.png]]
- **Attribute Based Access Control (ABAC)**: This type use multiple attribute to identify the user and know if he is authorized, for exemple: roles, the hour or the location.![[Pasted image 20250320095020.png]]
# Broken access control
- **Horizontal privilege escalation**: this is when an user can access the data of another user that have the same access level.
- **Vertical privilege escalation**: this is when an user can access data that is only for user that have a higher access level.
- **Insufficient access control checks**: occur when access control checks are not performed correctly or consistently, this allow an attacker to bypass them.
- **Insecure direct object references (IDOR)**: occur when an user can access a resource by exploiting a weakness in the application's access control mechanisms.
