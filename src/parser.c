#include <stdio.h>
#include <stdlib.h>
#include "../include/parser.h"

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

      splited_line[k++] = tmp;

      tmp = malloc(150*sizeof(char));
      j = 0;
      i++;
    }
  }

  return splited_line;
}

char *trimWhiteSpace() {
  
}
