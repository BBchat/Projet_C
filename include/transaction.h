#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include "../include/date.h"

typedef struct s_Transaction Transaction;
struct s_Transaction{
Date* date;
double amount;
int type;
char* description;
Transaction* next;
};

void Transaction_print(Transaction* trs);
Transaction* create_transaction(Date* date, double amount, int type, char* description);
void delete_transaction(Transaction* trs);


#endif // TRANSACTION_H_INCLUDED
