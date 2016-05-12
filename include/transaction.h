#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include "../include/date.h"

struct Transaction{
Date* date;
double amount;
int type;
char* description;
}typedef Transaction;

void Transaction_print(Transaction* trs);
Transaction* create_transaction(Date* date, double amount, int type, char* description);
void delete_transaction(Transaction* trs);


#endif // TRANSACTION_H_INCLUDED
