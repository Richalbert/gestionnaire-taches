/**
 * @file main.c
 * @brief Point d'entre pour le gestionnaire de taches
 *
 * @author Richard
 * @date 2025-01-23
 * @version 0.1
 */

#include <stdio.h>
#include <string.h>
#include "task.h"

/**
 * @brief Affiche le menu de gestion de taches
 *
 */
int main() {
    //Task my_task = {1, "Apprendre le langage C", 0};
    //print_task(&my_task);
    //return 0;

    TaskManager manager;
    init_task_manager(&manager);

    printf("=== Gestionnaire de taches ===\n");

    char description[256];
    while (1) {
        printf("\n1. Ajouter une tache");
        printf("\n2. Afficher les taches");
        printf("\n3. Quitter");
        printf("\nChoix : ");
        int choix;
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Description de la tache : ");
                getchar();  // Pour consommer le '\n' laisse par scanf
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Supprime le '\n'
                add_task(&manager, description);
                break;

            case 2:
                print_all_tasks(&manager);
                break;

            case 3:
                printf("Au revoir !\n");
                return 0;
        
            default:
                printf("Choix invalide\n");
        }
    }

    return 0;
}
