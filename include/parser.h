#include "../include/date.h"
#include "../include/transaction.h"

char*** parser(char *nomFichier);
char** split_line(char* line);
char* trimWhiteSpace(char *mot);

Date* recup_date(char*** date_collee, int ligne);
double recup_amount(char*** fichier_parse, int ligne);
int recup_type(char*** fichier_parse, int ligne);
char* recup_description(char*** fichier_parse, int ligne);

void recup_tr(char *NomFichier);
//void recup_transactions(char *NomFichier, int ligne);
