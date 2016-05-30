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
void print_types();
void set_type_ceil(int type, double ceil);
double get_type_ceil(int type);
int get_type_ceil_defined(int type);

#endif // TRANSACTION_H_INCLUDED
