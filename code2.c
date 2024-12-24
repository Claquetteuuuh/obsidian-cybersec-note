#include <stdio.h>
#include <stdlib.h> // Nécessaire pour atof()

int main(int argc, char *argv[]) {
    float numerateur, denominateur, resultat;

    // Vérification du nombre d'arguments
    if (argc != 3) {
        printf("Usage : %s <numerateur> <denominateur>\n", argv[0]);
        return 1;
    }

    // Conversion des arguments en nombres réels
    numerateur = atof(argv[1]);
    denominateur = atof(argv[2]);

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
