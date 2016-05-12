#include <stdio.h>
#include <stdlib.h>
#include "../include/transaction.h"
#include "../include/date.h"

void Transaction_print(Transaction* trs)
{
    date_print((*trs).date);
    printf("  |  %lf EUR  |  %d  |  %s", (*trs).amount, (*trs).type, (*trs).description);
}


Transaction* create_transaction(Date* date, double amount, int type, char* description)
{
    Transaction* res;
    res = malloc(sizeof(Transaction));
    (*res).date = date;
    (*res).amount = amount;
    (*res).description = description;
    (*res).type = type;
    return res;
}

void delete_transaction(Transaction* trs)
{
    delete_date((*trs).date);
    free(trs);
}
