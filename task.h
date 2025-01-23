/**
 * @file task.h
 * @brief Header file for task manager
 * 
 * Contient la structure de donnees du gestionnaire de taches
 * ainsi que les prototypes de fonctions implementees dans task.c
 * 
 * @author Richard
 * @date 2025-01-23
 * @version 0.1
 */

#ifndef TASK_H
#define TASK_H

typedef struct {
	int id;			// Identifiant unique de la tache
	char description[256];	// Description de la tache
	int completed;		// 0 = non termine, 1 = termine
} Task;

void print_task(const Task *task);

#endif /* TASK_H */


