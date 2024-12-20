# Session managements lifecycle
The session lifecycle is:
1. **Session creation**:  After the connection of the user and generating the value to store.
2. **Session tracking**: Everytime the user make a request, you can get the information stored in the session.
3. **Session expiration**: The application have to refuse the request if the session is expired.
4. **Session Termination**: The user remove the session from his browser.

![[Pasted image 20241220141638.png]]
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
