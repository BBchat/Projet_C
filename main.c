#include <stdio.h>
#include <stdlib.h>
#include "include/ui_functions.h"
#include "include/transaction.h"
#include "include/parser.h"
#include "include/loaded_transactions.h"
#include "include/saver.h"
#include "include/chart.h"
#include "include/stats.h"
#include "include/mode2.h"

//transaction types definition
int TRANSFERT = 0;
int WITHDRAWAL = 1;
int REAL_ESTATE = 2;
int HOBBY = 3;
int MISCELLANEOUS = 4;
int TRAVEL = 5;
double start_amount = 0;

int main()
{

    int choice = 0;
    int quit = 0;
    /* charte des modes :
    0 : ecran titre
    1 : session precedente
    2 : charger une session
    3 : nouvelle session
    */

    while(quit == 0)
    {
        clear_screen();
        draw_title();
        scanf("%d",&choice);
        if(choice == 0) {quit = 1;}
        if(choice == 1) {}
        if(choice == 2) {mode_2();}
        if(choice == 3)
        {
            delete_all_transactions();
            mode_2();
        }
    }

    return 0;
}


int get_start_amount()
{
    return start_amount;
}
