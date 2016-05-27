#include <stdio.h>
#include <stdlib.h>
#include "../include/ui_functions.h"
#include "../include/loaded_transactions.h"


int choice = 0;



void user_add_transaction()
{
    clear_screen();
    int day;
    int month;
    int year;
    double* amount = malloc(sizeof(double));
    int type;
    char* description = malloc(25*sizeof(char));

    printf("DATE\n");
    printf("jour ?\n");
    scanf("%d",&day);
    printf("mois ?\n");
    scanf("%d",&month);
    printf("annee ?\n");
    scanf("%d",&year);

    Date* date = create_date(year,month,day);

    printf("INFOS\n");
    printf("montant ?\n");
    scanf("%lf",&(*amount));
    printf("type de transaction ?\n");
    scanf("%d",&type);
    printf("description breve ?\n");
    scanf("%s",description);

    Transaction* trs = create_transaction(date,*amount,type,description);
    //Transaction_print(trs);
    add_transaction(trs);
}


void draw_mode2_ui()
{
    printf("--------------------------------\n");
    printf("| SESSION NOUVELLE             |\n");
    printf("--------------------------------\n");
    printf("\n");
    print_all_transactions(get_start_amount());
    printf("\n");
    printf("0 - retour \n");
    printf("1 - ajouter une transaction \n");
    printf("2 - menu statistiques \n");
    printf("3 - graphique du solde \n");
    printf("4 - charger un fichier csv \n");
}

void mode_2()
{
    int quit = 0;
    while(quit == 0)
    {
        clear_screen();
        draw_mode2_ui();
        scanf("%d",&choice);
        if(choice == 0) {quit = 1;}
        if(choice == 1) {user_add_transaction();}
        if(choice == 2) {}
        if(choice == 3) {}
    }
}


