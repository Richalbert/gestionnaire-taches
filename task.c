/**
 * @file task.c
 * @brief fonctions de base pour le gestionnaire de tache
 *
 * Ce fichier contient l'implementation des fonctions utilisees pour 
 * le gestionnaire de tache comme l'affichage des taches
 *
 * @author Richard
 * @date 2025-01-23
 * @version 0.1
 */

#include <stdio.h>
#include "task.h"

void print_task(const Task *task) {
	printf("ID: %d | Description: %s | Status: %s\n",
			task->id, 
			task->description, 
			task->completed ? "Completed" : "Pending");
}	
