#include "../include/date.h"
#include "../include/transaction.h"

void add_transaction(Transaction* trs);
void print_all_transactions(double start_amount);
void sort_transaction_by_date();
int count_transactions();
Transaction* get_first_transaction();
Transaction* get_last_transaction();
void delete_all_transactions();
void print_all_transactions_from_a_type(double start_amount, int type);
