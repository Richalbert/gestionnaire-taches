/**
 * @file task.h
 * @brief Header file for task manager
 * 
 * Contient la structure de donnees du gestionnaire de taches
 * ainsi que les prototypes de fonctions implementees dans task.c
 * 
 * @author Richard
 * @date 2025-01-24
 * @version 0.2
 */

#ifndef TASK_H
#define TASK_H

#define MAX_TASKS 100

/**
 * @brief Stucture pour contenir les informations sur une tache
 *
 */
typedef struct {
    int id;                 // Identifiant unique de la tache
    char description[256];  // Description de la tache
    int completed;          // 0 = non termine, 1 = termine
} Task;

/**
 * @brief Stucture pour gerer un tableau dynamique de tache
 *
 */
typedef struct {
    Task tasks[MAX_TASKS];      // Tableau de taches  
    int count;                  // Nombre de taches actuelles
} TaskManager;

void print_task(const Task *task);
void init_task_manager(TaskManager *manager);
int add_task(TaskManager *manager, const char *description);
void print_all_tasks(const TaskManager *manager);

#endif /* TASK_H */
