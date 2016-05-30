#include <stdio.h>
#include <stdlib.h>
#include "../include/transaction.h"
#include "../include/date.h"

int types_number = 7;
char types[7][20] = {"immobilier","virement","loisir","voyage","nourriture","maison","divers"};


void print_types()
{
    int i;
    for(i=0; i< types_number; i++)
    {
        printf("%d : %s\n",i,types[i]);
    }
}

void Transaction_print(Transaction* trs)
{
    date_print((*trs).date);
    printf("  |  %lf EUR  |  %s  |  %s", (*trs).amount, types[(*trs).type], (*trs).description);
}


Transaction* create_transaction(Date* date, double amount, int type, char* description)
{
    Transaction* res;
    res = malloc(sizeof(Transaction));
    (*res).date = date;
    (*res).amount = amount;
    (*res).description = description;
    (*res).type = type;
    (*res).next = NULL;
    return res;
}

void delete_transaction(Transaction* trs)
{
    delete_date((*trs).date);
    free(trs);
}
