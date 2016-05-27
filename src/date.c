#include <stdio.h>
#include <stdlib.h>
#include "../include/date.h"

void date_print(Date* date)
{
    /*
    les if ici servent � mettre un 0 devant les nombres inferieurs a 10
    par souci d'esthetique
    */
    if((*date).day < 10)
        printf("0%d/",(*date).day);
    else
        printf("%d/",(*date).day);

    if((*date).month < 10)
        printf("0%d/",(*date).month);
    else
        printf("%d/",(*date).month);

    printf("%d",(*date).year);
}


  char* day_to_string(Date* date) {
    char* day_string = malloc(sizeof(char) * 3);
    sprintf(day_string, "%s%d", date->day < 10 ? "0" : "", date->day);
    return day_string;
  }

  char* month_to_string(Date* date) {
    char* month_string = malloc(sizeof(char) * 3);
    sprintf(month_string, "%s%d", date->month < 10 ? "0" : "", date->month);
    return month_string;
  }

  char* year_to_string(Date* date) {
    char* annee_string = malloc(sizeof(char) * 5);
    sprintf(annee_string, "%d", date->year);
    return annee_string;
  }

// <condition> ? <valeur si vrai> : <valeur si faux>

 char* date_to_string(Date* date) {
   char* r = malloc(sizeof(char) * 9);
   sprintf(r, "%s%s%s", day_to_string(date), month_to_string(date), year_to_string(date));
   return r;
 }

/*
renvoie 1 si date1 est plus grande que date2
donc si date1 est plus récente date2
*/
int date_compare(Date* date1, Date* date2)
{
    if((*date1).year > (*date2).year)
        return 1;
    else if((*date1).year < (*date2).year)
        return 0;
    else if((*date1).month > (*date2).month)
        return 1;
    else if((*date1).month < (*date2).month)
        return 0;
    else if((*date1).day > (*date2).day)
        return 1;

    return 0;
}


int number_of_days(Date* date)
{
    int res = (*date).day + (*date).month*30 + (*date).year*365;
    return res;
}



Date* create_date(int year, int month, int day)
{
    Date* res;
    res = malloc(sizeof(Date));
    (*res).year = year;
    (*res).month = month;
    (*res).day = day;
    return res;
}

void delete_date(Date* date)
{
    free(date);
}
