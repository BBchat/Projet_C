#include <stdio.h>
#include <stdlib.h>
#include "../include/parser.h"
#include "../include/date.h"
#include "../include/transaction.h"
#include "../include/loaded_transactions.h"
#include "../include/ui_functions.h"


char*** parser(char *nomFichier) {

  char  **donnees_brutes    = malloc(100*sizeof(char*));
  char ***donnees_formatees = malloc(100*sizeof(char*));

  FILE *ptr;

  ptr = fopen(nomFichier, "r");

  int i = 0;

  do {
    donnees_brutes[i] =  malloc(150*sizeof(char));
  } while(fgets(donnees_brutes[i++], 150, ptr) != NULL);


  for (i--; i>=0; i--) {
    donnees_formatees[i] = split_line(donnees_brutes[i]);
  }

  return donnees_formatees;
}

char** split_line(char* ligne) {

  char* tmp = malloc(150*sizeof(char));
  char** splited_line = malloc(50*sizeof(char*));
  int i = 0;
  int j = 0;
  int k = 0;

  while(ligne[i] != '\0') {
    tmp[j++] = ligne[i++];

    if (ligne[i] == ',' || ligne[i] == '\0') {
      tmp[j] = '\0';

      splited_line[k++] = trim(tmp);

      tmp = malloc(150*sizeof(char));
      j = 0;
      i++;
    }
  }

  return splited_line;
}

  char* trim(char* mot) {
    int i = 0;
    if (mot[i] == ' ') {
      mot++;
      }
    while (mot[i+1] != '\0') {
      i++;
    };
    if (mot[i] == '\n') {
      mot[i] = '\0';
      }
    return mot;
  }

  Date* recup_date(char*** fichier_parse, int ligne) {
       char j1 = fichier_parse[ligne][0][0];
       char j2 = fichier_parse[ligne][0][1];
       char j[3] = {j1, j2, '\0'};
         int jour = atoi(j);

       char m1 = fichier_parse[ligne][0][2];
       char m2 = fichier_parse[ligne][0][3];
       char m[3] = {m1, m2, '\0'};
         int mois = atoi(m);

       char a1 = fichier_parse[ligne][0][4];
       char a2 = fichier_parse[ligne][0][5];
       char a3 = fichier_parse[ligne][0][6];
       char a4 = fichier_parse[ligne][0][7];
       char a[5] = {a1, a2, a3, a4, '\0'};
         int annee = atoi(a);

     return create_date(annee, mois, jour);
     }

     double recup_amount(char*** fichier_parse, int ligne) {
       return atof(fichier_parse[ligne][1]);
     }

     int recup_type(char*** fichier_parse, int ligne) {
       return atoi(fichier_parse[ligne][2]);
     }

     char* recup_description(char*** fichier_parse, int ligne) {
       return fichier_parse[ligne][3];
     }

     // void recup_transactions(char *NomFichier, int ligne) {
     //   char ***fichier_parser = parser(NomFichier);
     //   Transaction* transaction;
     //
     //     Date* date = recup_date(fichier_parser, ligne);
     //     double montant = recup_amount(fichier_parser, ligne);
     //     int type = recup_type(fichier_parser, ligne);
     //     char* blabla = recup_description(fichier_parser, ligne);
     //
     //     transaction = create_transaction(date, montant, type, blabla);
     //     Transaction_print(transaction);
     //
     //   }

     void recup_tr(char *NomFichier) {
         char ***fichier_parser = parser(NomFichier);
         int i=0;
         Transaction* transaction;
         while (*(fichier_parser + i + 1) != '\0') {
           Date* date = recup_date(fichier_parser, i);
           double montant = recup_amount(fichier_parser, i);
           int type = recup_type(fichier_parser, i);
           char* blabla = recup_description(fichier_parser, i);

           transaction = create_transaction(date, montant, type, blabla);
           //Transaction_print(transaction);
           add_transaction(transaction);
           i++;
           }
         }


void load_a_csv()
{
    clear_screen();
    char* url = malloc(100*sizeof(char));
    printf("entrez une adresse de fichier\n");
    scanf("%s",url);
    recup_tr(url);
}
