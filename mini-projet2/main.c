#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_contact 100
#define max_lenght 100

typedef struct contact {
    char nom[max_lenght];
    char num[max_lenght];
    char email[max_lenght];
} contact;

int main() {
    contact contacts[max_contact];
    int choix, i, j;
    int nbr = 0;

    printf("Gestion de contacts\n");

    do {
        printf("1. Ajouter un contact\n");
        printf("2. Modifier un contact\n");
        printf("3. Supprimer un contact\n");
        printf("4. Afficher tous les contacts\n");
        printf("5. Rechercher un contact\n");
        printf("Entrez votre choix :\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (nbr < max_contact) {
                    printf("Entrez le nom du contact : ");
                    scanf("%s", contacts[nbr].nom);
                    printf("Entrez le numéro du contact : ");
                    scanf("%s", contacts[nbr].num);
                    printf("Entrez l'email du contact : ");
                    scanf("%s", contacts[nbr].email);
                    nbr++;  // Increment after adding a contact
                } else {
                    printf("Vous avez dépassé le nombre maximum de contacts.\n");
                }
                break;

            case 2: {
                char contact_modifier[max_lenght];
                printf("Entrez le nom du contact à modifier : ");
                scanf("%s", contact_modifier);
                for (i = 0; i < nbr; i++) {
                    if (strcmp(contact_modifier, contacts[i].nom) == 0) {
                        printf("Entrez le nouveau numéro : ");
                        scanf("%s", contacts[i].num);
                        printf("Entrez le nouvel email : ");
                        scanf("%s", contacts[i].email);
                        break;
                    }
                }
                break;
            }

            case 3: {
                char contact_supprimer[max_lenght];
                printf("Entrez le nom du contact à supprimer : ");
                scanf("%s", contact_supprimer);
                for (i = 0; i < nbr; i++) {
                    if (strcmp(contact_supprimer, contacts[i].nom) == 0) {
                        for (j = i; j < nbr - 1; j++) {
                            strcpy(contacts[j].nom, contacts[j + 1].nom);
                            strcpy(contacts[j].num, contacts[j + 1].num);
                            strcpy(contacts[j].email, contacts[j + 1].email);
                        }
                        nbr--;  // Decrease the number of contacts after deletion
                        printf("Le contact a été supprimé.\n");
                        break;
                    }
                }
                break;
            }

            case 4:
                if (nbr > 0) {
                    for (i = 0; i < nbr; i++) {
                        printf("Nom : %s\nNuméro : %s\nEmail : %s\n", contacts[i].nom, contacts[i].num, contacts[i].email);
                    }
                } else {
                    printf("Aucun contact à afficher.\n");
                }
                break;

            case 5: {
                char contact_rechercher[max_lenght];
                printf("Entrez le nom du contact à rechercher : ");
                scanf("%s", contact_rechercher);
                for (i = 0; i < nbr; i++) {
                    if (strcmp(contacts[i].nom, contact_rechercher) == 0) {
                        printf("Voici le contact trouvé :\n");
                        printf("Nom : %s\nNuméro : %s\nEmail : %s\n", contacts[i].nom, contacts[i].num, contacts[i].email);
                        break;
                    }
                }
                break;
            }

            default:
                printf("Choix non valide.\n");
        }
    } while (choix != 0);

    return 0;
}
