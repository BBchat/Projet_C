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
int date_compare(Date* date1, Date* date2);
int number_of_days(Date* date);

char* day_to_string(Date* date);
char* month_to_string(Date* date);
char* year_to_string(Date* date);
char* date_to_string(Date* date);
//char* date_to_string(Date* date);

#endif // DATE_H_INCLUDED
