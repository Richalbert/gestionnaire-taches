/**
 * @file main.c
 * @brief Point d'entre pour le gestionnaire de taches
 *
 * @author Richard
 * @date 2025-01-23
 * @version 0.1
 */

#include <stdio.h>
#include "task.h"

int main() {
    Task my_task = {1, "Apprendre le langage C", 0};
    print_task(&my_task);
    return 0;
}
