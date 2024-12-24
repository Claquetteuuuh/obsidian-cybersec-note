# Session managements lifecycle
The session lifecycle is:
1. **Session creation**:  After the connection of the user and generating the value to store.
2. **Session tracking**: Everytime the user make a request, you can get the information stored in the session.
3. **Session expiration**: The application have to refuse the request if the session is expired.
4. **Session Termination**: The user remove the session from his browser.

![[Pasted image 20241220141638.png]]
## Session creation
### Insecure Session Transmission

In modern setups like Single Sign-On (SSO), session data often moves between the authentication server and application servers via the user’s browser. This creates a risk if the session is not transmitted securely.
A common issue is **insecure redirects**, where an **attacker can manipulate the redirect URL** after authentication, potentially stealing session data. This problem has been seen even in major systems like Oracle's SSO.

To prevent this:
- Only allow **trusted redirect URLs**.
- Use **signed and encrypted** session tokens.
- Always transmit data over **HTTPS**.
- Keep session tokens **short-lived and limited in scope**.
### Weak Session Values

Although less common today due to modern frameworks, weak session values can still occur, especially with custom implementations or AI-assisted code. For example, if a session value is just a **base64-encoded username**, an attacker could reverse engineer the process to guess or create session values, leading to account hijacking.

To prevent this:
- Use **secure, randomly generated** session values.
- Avoid encoding predictable information like usernames in session tokens.
- **Use established frameworks** that handle session creation securely.
## Session tracking
### Authorisation bypass
Authorisation bypass mean **there aren't sufficient checks** being performed on whether a user is allowed to perform the action they requested.
- **Vertical bypass**: Mean that you can perform an action reserved for a more privileged user.
- **Horizontal bypass**: Mean that you can perform an action on a dataset you can't access.
## Session termination
Session termination mean that you don't have a way to invalidate a session server-side. It's a problem if a threat actor is connected to an admin account for exemple.
To fix this problem you have to:
- Set an **expiration date for a session**
- Set a way to **invalidate a session** in server-side.

# Cookie VS Token
| **Cookie-Session Management**                                                                                                                             | **Token-Based Session Management**                                                                                                                                            |
| --------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Cookie is **automatically sent** by the browser with **each request**                                                                                     | Token has to be submitted **as a header with each request** using client-side JavaScript                                                                                      |
| Cookie attributes can be used to **enhance the browser's protection** of the cookie                                                                       | Tokens do **not have automatic security protections** enforced and should, therefore, be safeguarded against disclosures                                                      |
| Cookies can be **vulnerable to conventional client-side attacks such as CSRF**, where the browser is tricked into making a request on behalf of the user. | As the token is not automatically added to any request and **cannot be read from LocalStorage by other domains**, conventional client-side attacks such as CSRF are blocked.  |
| As cookies are locked to a specific domain, it can be **difficult to use them securely in decentralised web applications**.                               | Tokens **work well in decentralised web applications**, as they are managed through JavaScript and can often contain all the information required to verify the token itself. |
## Cookies attributes
**Secure**: Used to ensure that the cookie is only transmitted via secure HTTPS channels?
**HTTPOnly**: Indicates to the browser that the cookie value may not be read by client-side JavaScript.
**Expire**: Used to say when the cookie value is not valid and should be removed.
**SameSite**: help protect against CSRF attacks.