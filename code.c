#include <stdio.h>
#include <stdlib.h>

int main() {
    float numerateur, denominateur, resultat;

    // Saisie des nombres
    printf("Entrez le numérateur : ");
    scanf("%f", &numerateur);

    printf("Entrez le dénominateur : ");
    scanf("%f", &denominateur);

    // Vérification des nombres négatifs
    if (numerateur < 0 || denominateur < 0) {
        printf("Erreur : Les nombres négatifs ne sont pas autorisés.\n");
        return 2;
    }

    // Vérification de la division par zéro
    if (denominateur == 0) {
        printf("Erreur : Division par zéro impossible.\n");
        return 1;
    }

    // Calcul et affichage du résultat
    resultat = numerateur / denominateur;
    printf("Le résultat de %.2f divisé par %.2f est : %.2f\n", 
           numerateur, denominateur, resultat);

    return 0;
}
