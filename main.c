#include <stdio.h>
#include <stdlib.h>
#include "include/ui_functions.h"
#include "include/transaction.h"
#include "include/parser.h"
#include "include/loaded_transactions.h"

//transaction types definition
int TRANSFERT = 0;
int WITHDRAWAL = 1;
int REAL_ESTATE = 2;
int HOBBY = 3;
int MISCELLANEOUS = 4;
int TRAVEL = 5;


int main()
{
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


    for (i = 0; i < 2; i++) {
      for(j = 0; j < 4; j++){
        printf("%s - %d %d\n", aze[i][j], i, j);
        //puts(aze[i][j]);
      }
    }
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

    //tests
    Date* a = create_date(1995,9,11);
    Date* b = create_date(1965,4,1);
    Date* c = create_date(1945,1,8);
    Date* d = create_date(1945,2,8);
    Date* e = create_date(1947,1,15);
    Date* f = create_date(1945,1,9);

    printf("%d",date_compare(e,a));

    Transaction* test1 = create_transaction(a,50,0,"ceci est un test");
    Transaction* test2 = create_transaction(b,-0.5,0,"ceci est un autre test");
    Transaction* test3 = create_transaction(c,45,0,"ceci est un test");
    Transaction* test4 = create_transaction(d,-35,0,"ceci est un autre test");
    Transaction* test5 = create_transaction(e,5645,0,"ceci est un test");
    Transaction* test6 = create_transaction(f,11,0,"ceci est un autre test");

    add_transaction(test1);
    add_transaction(test2);
    add_transaction(test3);
    add_transaction(test4);
    add_transaction(test5);
    add_transaction(test6);

    print_all_transactions();

    return 0;
}
