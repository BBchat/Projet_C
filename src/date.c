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
