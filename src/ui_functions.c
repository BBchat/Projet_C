#include <stdio.h>
#include <stdlib.h>
#include "../include/ui_functions.h"

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
    printf("2 - charger une session depuis une adresse \n");
    printf("3 - creer une nouvelle session \n");
}

void draw_mode1_ui()
{
    printf("--------------------------------\n");
    printf("| SESSION PRECEDENTE           |\n");
    printf("--------------------------------\n");
    printf("\n");
    printf("0 - retour \n");
}

void draw_mode2_ui()
{
    printf("--------------------------------\n");
    printf("| SESSION CHARGEE               |\n");
    printf("--------------------------------\n");
    printf("\n");
    printf("0 - retour \n");
}

void draw_mode3_ui()
{
    printf("--------------------------------\n");
    printf("| SESSION NOUVELLE             |\n");
    printf("--------------------------------\n");
    printf("\n");
    printf("0 - retour \n");
}
