/**
 * @file main.c
 * @brief Point d'entre pour le gestionnaire de taches
 *
 * @author Richard
 * @date 2025-01-25
 * @version 0.3
 */

#include <stdio.h>
#include <string.h>
#include "task.h"

#define FILENAME "tasks.txt"


/**
 * @brief Affiche le menu de gestion de taches
 *
 */
int main() {
    //Task 3y_task = {1, "Apprendre le langage C", 0};
    //print_task(&my_task);
    //return 0;

    TaskManager manager;
    init_task_manager(&manager);

    // Charge les taches depuis un fichier
    load_tasks_from_file(&manager, FILENAME);

    printf("=== Gestionnaire de taches ===\n");

    char description[256];
    while (1) {
        printf("\n1. Ajouter une tache");
        printf("\n2. Afficher les taches");
        printf("\n3. Sauvegarger et quitter\n");
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
                save_tasks_to_file(&manager, FILENAME);
                printf("Au revoir !\n");
                return 0;
        
            default:
                printf("Choix invalide\n");
        }
    }

    return 0;
}
