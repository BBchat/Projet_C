#include "../include/transaction.h"
#include "../include/loaded_transactions.h"

double get_total_type_i(int i);
double get_in_type_i(int i);
double get_out_type_i(int i);

double total_out();
double total_in();

double i_comparedTo_total(int i);

double total_out_month(int m, int y);
double total_in_month(int m, int y);

double total_out_i_month(int m, int y, int i);
double total_in_i_month(int m, int y, int i);

double i_comparedTo_month(int m, int y, int i);

double total_out_year(int y);
double total_in_year(int y);

double month_comparedTo_year(int m, int y);
