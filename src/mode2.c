#include <stdio.h>
#include <stdlib.h>
#include "../include/ui_functions.h"
#include "../include/loaded_transactions.h"
#include "../include/chart.h"
#include "../include/parser.h"
#include "../include/saver.h"
#include "../include/stats.h"


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
    print_types();
    printf("type de transaction ?\n");
    scanf("%d",&type);
    printf("description breve ? (utiliser des _ a la place des espaces svp)\n");
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
    printf("5 - sauvegarder la session \n");
    printf("6 - n'afficher qu'un type de transaction en particulier \n");
    printf("7 - definir des seuils \n");
}


void draw_stat_mode_ui()
{
    printf("MODE STATISTIQUES\n\n\n");
    printf("0 - retour\n");

    printf("1 - total depenses\n");
    printf("2 - total revenus\n");

    printf("3 - total transactions pour un type\n");
    printf("4 - total depenses pour un type\n");
    printf("5 - total revenus pour un type\n");

    printf("6 - comparaison d'un type sur le total\n");

    printf("7 - depenses sur un mois\n");
    printf("8 - revenus sur un mois\n");

    printf("9 - depenses d'un type sur un mois\n");
    printf("10 - revenus d'un type sur un mois\n");

    printf("11 - comparaison d'un type sur le total sur un mois (en pourcents)\n");

    printf("12 - depenses sur un an\n");
    printf("13 - revenus sur un an\n");

    printf("14 - comparaison d'un mois sur l'annee (en pourcents)\n");
}


void mode_graph()
{
    choice = -1;
    clear_screen();
    if(get_first_transaction() != NULL && get_first_transaction()->next != NULL )
        draw_expenses_chart(0,get_first_transaction()->date,get_last_transaction()->date,40,15);
    else
        printf("Pas assez de transactions \n\n");
    printf("\n0 - retour\n");
    while(choice != 0)
    {
        scanf("%d",&choice);
    }
}


void mode_ceil()
{
    clear_screen();
    print_types();
    printf("sur quel type voulez vous definir un seuil ?\n");
    int i;
    scanf("%d",&i);
    printf("quel seuil definissez vous ? (EUR)\n");
    double c;
    scanf("%lf",&c);

    set_type_ceil(i, c);
}


void mode_type()
{
    clear_screen();
    print_types();
    printf("quel type voulez vous afficher ?\n");
    int i;
    scanf("%d",&i);
    print_all_transactions_from_a_type(get_start_amount(),i);
    printf("0 - retour \n");
    scanf("%d",&i);
}


void stat_mode()
{
    int quit = 0;
    while(quit == 0)
    {
        clear_screen();
        draw_stat_mode_ui();
        scanf("%d",&choice);
        if(choice == 0){quit = 1;}
        if(choice == 1){clear_screen(); printf("%lf EUR\n", total_out());}
        if(choice == 2){clear_screen(); printf("%lf EUR\n", total_in());}
        if(choice == 3){clear_screen(); print_types(); printf("entrez le numero du type que vous cherchez\n"); int i; scanf("%d",&i); printf("%lf EUR\n", get_total_type_i(i));}
        if(choice == 4){clear_screen(); print_types(); printf("entrez le numero du type que vous cherchez\n"); int i; scanf("%d",&i); printf("%lf EUR\n", get_in_type_i(i));}
        if(choice == 5){clear_screen(); print_types(); printf("entrez le numero du type que vous cherchez\n"); int i; scanf("%d",&i); printf("%lf EUR\n", get_out_type_i(i));}
        if(choice == 6){clear_screen(); print_types(); printf("entrez le numero du type que vous cherchez\n"); int i; scanf("%d",&i); printf("%lf EUR\n", i_comparedTo_total(i));}
        if(choice == 7){clear_screen(); printf("entrez le mois\n"); int m; scanf("%d",&m); printf("entrez l'annee\n"); int y; scanf("%d",&y); printf("%lf EUR\n",  total_out_month(m, y));}
        if(choice == 8){clear_screen(); printf("entrez le mois\n"); int m; scanf("%d",&m); printf("entrez l'annee\n"); int y; scanf("%d",&y); printf("%lf EUR\n",  total_in_month(m, y));}
        if(choice == 9){clear_screen(); print_types(); printf("entrez le numero du type que vous cherchez\n"); int i; scanf("%d",&i);printf("entrez le mois\n"); int m; scanf("%d",&m); printf("entrez l'annee\n"); int y; scanf("%d",&y); printf("%lf EUR\n",  total_out_i_month(m, y,i));}
        if(choice == 10){clear_screen(); print_types(); printf("entrez le numero du type que vous cherchez\n"); int i; scanf("%d",&i);printf("entrez le mois\n"); int m; scanf("%d",&m); printf("entrez l'annee\n"); int y; scanf("%d",&y); printf("%lf EUR\n",  total_in_i_month(m, y,i));}
        if(choice == 11){clear_screen(); print_types(); printf("entrez le numero du type que vous cherchez\n"); int i; scanf("%d",&i);printf("entrez le mois\n"); int m; scanf("%d",&m); printf("entrez l'annee\n"); int y; scanf("%d",&y); printf("%lf pourcents\n",  i_comparedTo_month(m, y,i));}
        if(choice == 12){clear_screen(); printf("entrez l'annee\n"); int y; scanf("%d",&y); printf("%lf EUR\n",  total_out_year(y));}
        if(choice == 13){clear_screen(); printf("entrez l'annee\n"); int y; scanf("%d",&y); printf("%lf EUR\n",  total_in_year(y));}
        if(choice == 14){clear_screen(); printf("entrez le mois\n"); int m; scanf("%d",&m); printf("entrez l'annee\n"); int y; scanf("%d",&y); printf("%lf pourcents\n",  month_comparedTo_year(m, y));}
        if(quit == 0)
        {
            printf("0 - retour\n");
            scanf("%d",&choice);
        }
    }
}

void mode_2()
{
    int quit = 0;
    while(quit == 0)
    {
        clear_screen();
        draw_mode2_ui();
        scanf("%d",&choice);
        if(choice == 0) {quit = 1; save_transactions("last_session.cma");}
        if(choice == 1) {user_add_transaction();}
        if(choice == 2) {stat_mode();}
        if(choice == 3) {mode_graph();}
        if(choice == 4) {load_a_csv();}
        if(choice == 5) {save_in_csv(); save_transactions("last_session.cma");}
        if(choice == 6) {mode_type();}
        if(choice == 7) {mode_ceil();}
    }
}




