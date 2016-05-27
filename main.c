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

    return 0;

}
