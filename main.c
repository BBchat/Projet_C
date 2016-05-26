#include <stdio.h>
#include <stdlib.h>
#include "include/ui_functions.h"
#include "include/transaction.h"
#include "include/parser.h"

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

    // char ***aze = parser("test.csv");
    // recup_tr2("test.csv");









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
    Date* b = create_date(1945,1,8);
    Transaction* test1 = create_transaction(a,50,0,"ceci est un test");
    Transaction* test2 = create_transaction(b,-0.5,0,"ceci est un autre test");
    Transaction_print(test1);
    printf("\n");
    Transaction_print(test2);

    delete_transaction(test1);

    return 0;

}
