/**
 * @file task.c
 * @brief fonctions de base pour le gestionnaire de tache
 *
 * Ce fichier contient l'implementation des fonctions utilisees pour 
 * le gestionnaire de tache comme l'affichage des taches
 *
 * @author Richard
 * @date 2025-01-25
 * @version 0.1
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

