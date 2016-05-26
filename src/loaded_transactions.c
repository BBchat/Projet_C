#include <stdlib.h>
#include <stdio.h>
#include "../include/transaction.h"
#include "../include/date.h"
#include "../include/loaded_transactions.h"

Transaction* first_transaction;
Transaction* last_transaction;

void add_transaction(Transaction* trs)
{
    if(first_transaction == NULL)
    {
        first_transaction = trs;
        last_transaction = trs;
        (*trs).next = NULL;
    }
    else
    {
        (*last_transaction).next = trs;
        last_transaction = trs;
        (*last_transaction).next = NULL;
        sort_transaction_by_date();
    }
}

void print_all_transactions()
{
    Transaction* current_transaction = first_transaction;
    while(current_transaction != NULL)
    {
        Transaction_print(current_transaction);
        printf("\n");
        current_transaction = (*current_transaction).next;
    }
}


int count_transactions()
{
    int res = 0;
    Transaction* current_transaction = first_transaction;
    while(current_transaction != NULL)
    {
        current_transaction = (*current_transaction).next;
        if(current_transaction != NULL)
            res += 1;
    }
    return res;
}


void sort_transaction_by_date()
{
    int number = count_transactions();
    if(number > 0)
    {
        Transaction* T_array[number];
        Transaction* current_transaction = first_transaction;
        int i;
        for(i = 0; i<number+1; i++)
        {
            T_array[i] = current_transaction;
            current_transaction = (*current_transaction).next;
        }

        int j;
        for(j=1; j<number+1; j++)
        {
            for(i=0; i<j+1; i++)
            {
                if( date_compare((*T_array[i]).date, (*T_array[j]).date) == 1)
                {
                    Transaction* temp = T_array[i];
                    T_array[i] = T_array[j];
                    T_array[j] = temp;
                }
            }
        }

        first_transaction = T_array[0];
        current_transaction = first_transaction;

        for(i=1; i<number+1; i++)
        {
            (*current_transaction).next = T_array[i];
            current_transaction = T_array[i];
        }

        last_transaction = T_array[number];
        (*last_transaction).next = NULL;
    }
}
