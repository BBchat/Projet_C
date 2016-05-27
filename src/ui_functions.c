#include <stdio.h>
#include <stdlib.h>
#include "../include/ui_functions.h"
#include "../include/loaded_transactions.h"


void clear_screen()
{
    if (WINDOWS == 1)
      system("cls");
    else
      system("clear");
}

void draw_title()
{
    printf("--------------------------------\n");
    printf("| GESTIONNAIRE DE BUDGET  2016 |\n");
    printf("--------------------------------\n");
    printf("\n");
    printf("0 - quitter \n");
    printf("1 - charger la session precedente \n");
    if(get_first_transaction() != NULL)
    {
        printf("2 - reprendre session \n");
        printf("3 - nouvelle session (la session en cours sera perdue)\n");
    }
    else
    {
        printf("2 - nouvelle session \n");
    }

}

void draw_mode1_ui()
{
    printf("--------------------------------\n");
    printf("| SESSION PRECEDENTE           |\n");
    printf("--------------------------------\n");
    printf("\n");
    printf("0 - retour \n");
}

