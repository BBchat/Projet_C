#include <stdio.h>
#include <stdlib.h>
#include "include/ui_functions.h"
#include "include/transaction.h"
#include "include/parser.h"
#include "include/loaded_transactions.h"
#include "include/saver.h"
#include "include/chart.h"

//transaction types definition
int TRANSFERT = 0;
int WITHDRAWAL = 1;
int REAL_ESTATE = 2;
int HOBBY = 3;
int MISCELLANEOUS = 4;
int TRAVEL = 5;


int main()
{
    double start_amount = 0;
    int choice = 0;
    int quit = 0;
    int mode = 0;
    /* charte des modes :
    0 : ecran titre
    1 : session precedente
    2 : charger une session
    3 : nouvelle session
    */

    /*TEST DU PARSER
    int i, j;
    char ***aze = parser("test.csv");
    */


    while(quit == 0)
    {
        clear_screen();
        if(mode == 0)
        {
            draw_title();
            scanf("%d",&choice);
            if(choice == 0) {quit = 1;}
            if(choice == 1) {mode = 1;}
            if(choice == 2) {mode = 2;}
            if(choice == 3) {mode = 3;}
        }
        else if(mode == 1)
        {
            draw_mode1_ui();
            scanf("%d",&choice);
            if(choice == 0) {mode = 0;}
        }
        else if(mode == 2)
        {
            draw_mode2_ui();
            scanf("%d",&choice);
            if(choice == 0) {mode = 0;}
        }
        else if(mode == 3)
        {
            draw_mode3_ui();
            scanf("%d",&choice);
            if(choice == 0) {mode = 0;}
        }
    }

    // test
    // recup_tr("test.csv");
    // print_all_transactions();
    Date* da = create_date(2016, 5, 26);
    Transaction* trans = create_transaction(da, 50, 4, "encore un test !");
    //save_transaction(trans, "test2.txt");
    // printf("%d", (*trans).amount);

    printf("%s\n", date_to_string(da));


    // save_tr(trans, "test3.csv");
    // test parser
    /*
    recup_tr("test.csv");
    print_all_transactions();
    */

    //test diagramme
    /*Date* a = create_date(1995,9,11);
    Date* b = create_date(1965,4,1);
    Date* c = create_date(1955,1,8);
    Date* d = create_date(1975,2,8);
    Date* e = create_date(1945,1,15);
    Date* f = create_date(1985,1,9);

    printf("%d",date_compare(e,a));

    Transaction* test1 = create_transaction(a,-1,0,"ceci est un test");
    Transaction* test2 = create_transaction(b,2,0,"ceci est un autre test");
    Transaction* test3 = create_transaction(c,2,0,"ceci est un test");
    Transaction* test4 = create_transaction(d,-1,0,"ceci est un autre test");
    Transaction* test5 = create_transaction(e,2,0,"ceci est un test");
    Transaction* test6 = create_transaction(f,-1,0,"ceci est un autre test");

    add_transaction(test1);
    add_transaction(test2);
    add_transaction(test3);
    add_transaction(test4);
    add_transaction(test5);
    add_transaction(test6);

    //ne marche pas encore
    draw_expenses_chart(0,(*get_first_transaction()).date,(*get_last_transaction()).date,50,20);

    print_all_transactions(start_amount);
*/
    return 0;

}
