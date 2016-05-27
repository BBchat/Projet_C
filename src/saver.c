#include <stdio.h>
#include <stdlib.h>
#include "../include/saver.h"
#include "../include/transaction.h"
#include "../include/date.h"
#include "../include/loaded_transactions.h"

void save_transactions(char* name) {
  FILE *ptr;
  Transaction* current_trs = get_first_transaction();

  ptr=fopen(name,"w");
  while (current_trs != NULL) {
    fprintf(ptr, "%s, ", date_to_string(current_trs->date));
    fprintf(ptr, "%lf, %d, %s\n", (*current_trs).amount, (*current_trs).type, (*current_trs).description);
    current_trs = (*current_trs).next;
  }
  fclose(ptr);
}
