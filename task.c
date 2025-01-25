/**
 * @file task.c
 * @brief fonctions de base pour le gestionnaire de tache
 *
 * Ce fichier contient l'implementation des fonctions utilisees pour 
 * le gestionnaire de tache comme l'affichage des taches
 *
 * @author Richard
 * @date 2025-01-25
 * @version 0.3
 */

#include <stdio.h>
#include <string.h>
#include "task.h"

/**
 * @brief Affiche une tache
 *
 * @param *task Un pointeur sur la tache
 */
void print_task(const Task *task) {
    printf("ID: %d | Description: %s | Status: %s\n",
        task->id, 
        task->description, 
        task->completed ? "Completed" : "Pending");
}

/**
 * @brief Initialise le gestionnaire de tache
 *
 * @param *manager Pointeur sur le tableau de taches
 */
void init_task_manager(TaskManager *manager) {
    manager->count = 0; // Initialise le gestionnaire a vide
}

/**
 * @brief Ajout une tache au gestionnaire de tache
 *
 * @param *manager Un pointeur sur le tableau des taches 
 * @param *description un pointeur sur la chaine de caractere
 *
 * @return La reussite ou l'echec de l'ajout d'une nouvelle tache 
 */
int add_task(TaskManager *manager, const char *description) {

    /* Verifier la capacite disponible */

    if (manager->count >= MAX_TASKS) {
        printf("Erreur: Limite de taches atteinte.\n");
        return -1;
    }

    /* Ajout d'une nouvelle tache */

    // manager->count represente l'index de la tache dans le tableau;
    // manager->tasks[manager->count] designe la prochaine tache vide
    // &manager->tasks[manager->count] donne l'adresse de la prochaine tache 

    Task *new_task = &manager->tasks[manager->count];

    /* Assigner un ID uniqiue a la tache */

    new_task->id = manager->count + 1;

    /* Copier la description */ 

    // on limite la copie a la taille max du champ description (256) 
    // pour eviter un debordement memoire

    strncpy(new_task->description, description, sizeof(new_task->description) - 1);
    new_task->description[sizeof(new_task->description) - 1] = '\0'; 

    /* Par defaut une nouvelle tache est non terminee */

    new_task->completed = 0;

    manager->count++;
    return 0;
}

/**
 * @brief Affiche toutes les taches
 *
 * @param *manager Un pointeur le tableau des taches
 */
void print_all_tasks(const TaskManager *manager) {
    if (manager->count == 0) {
        printf("Aucune tache a afficher|n");
        return;
    }

    for (int i = 0; i < manager->count; i++) {
        print_task(&manager->tasks[i]);
    }
}

/**
 *  @brief Sauvegarde les taches dans un fichier
 *
 *  @param const TaskManager *manager : Pointeur sur le tableau des taches
 *      const signifie au compilateur que les modifications sont interdites
 *  @param const char *filename : nom du fichier
 *
 *  @return l'echec ou la reussite de la sauvegarde
 */
int save_tasks_to_file(const TaskManager *manager, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    for (int i = 0; i < manager->count; i++) {

        // const garanti aucune modification de la tache pointee par task
        const Task *task = &manager->tasks[i];
        fprintf(file, "%d;%s;%d\n", 
            task->id, task->description, task->completed);
    }

    fclose(file);
    return 0;
}

/**
 *  @brief  Charge les taches depuis un fichier
 *
 *  @param  *manager : pointeur sur le tableau de tache
 *  @param  *filename : nom du fichier
 *
 *  @return la reussite ou l'echec du chargement
 */
int load_tasks_from_file(TaskManager *manager, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("\nLe fichier n'existe pas\n");
        return 0;
    }

    manager->count = 0;
    while (!feof(file)) {
        Task *task = &manager->tasks[manager->count];

        if (strlen(task->description) >= 256) {
            fprintf(stderr, "Erreur : description trop longue\n");
            return -1;
        }

        if (fscanf(file, "%d;%255[^;];%d\n", 
            &task->id,          //adresse ou stocker le 1er entier 
            task->description,  //pointeur vers un tableau de caractere
            &task->completed)   //adresse ou stocker le dernier entier
            == 3) {     // fscanf rerourne le nb de champ lus
            manager->count++;
        }
    }

    fclose(file);
    return 0;
}

