[Maltego](https://www.maltego.com/) est un outils de reconnaissance très efficace qui nous permet de gagner beaucoup de temps lors de notre reconnaissance passive.

# Usage

On peut commencer en partant d'un serveur DNS.
Pour cela on va choisir l'infrastructure `DNS Name` dans le panneau à gauche.
On va ensuite saisir le nom de domaine sur lequel nous voulons travailler.

![[Maltego1.png]]

## DNS to IP

Si l'on souhaite voir toutes les IPs vers lequel pointe ce DNS, il nous suffit d'effectuer un clique droit sur la bulle et de sélectionner "To IP address \[DNS\]"
Nous allons ensuite obtenir quelque chose comme ceci:
![[Maltego2.png]]

## IP to DNS

On peut ensuite récupérer tous les serveurs DNS qui tourne sur cette IP.
1) Clique droit sur l'IP.
2) DNS from IP
3) To DNS Name from passive DNS

Nous allons ensuite avoir quelque chose comme cela: 
![[Maltego3.png]]

Pour plus de fonctionnalité voir https://www.maltego.com/transform-hub/.

