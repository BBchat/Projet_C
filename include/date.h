#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

struct Date{
int year;
int month;
int day;
}typedef Date;

void date_print(Date* date);
Date* create_date(int year, int month, int day);
void delete_date(Date* date);

#endif // DATE_H_INCLUDED
