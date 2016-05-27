#include <stdio.h>
#include <stdlib.h>
#include "../include/chart.h"
#include "../include/transaction.h"
#include "../include/loaded_transactions.h"


//ne marche pas encore
void draw_expenses_chart(int chart_type, Date* starts, Date* ends, int size_x, int size_y)
{
        int number = count_transactions();
        Transaction* current_transaction = get_first_transaction();

        int day_origin = number_of_days(starts);
        int day_end = number_of_days(ends);
        double x_rate = ((double)size_x) / ((double)(day_end - day_origin));

        double max = (*current_transaction).amount;
        double min = max;
        double amount = max;

        int i;
        double chart[size_x];
        for(i=0; i<size_x; i++)
        {
            chart[i]=0;
        }
        for(i = 0; i<number+1; i++)
        {
            amount += (*current_transaction).amount;
            if(amount < min) {min = amount;}
            if(amount > max) {max = amount;}

            chart[(int)((number_of_days((*current_transaction).date)-day_origin)*x_rate)] = amount;
            printf("%d \n", (int)((double)((number_of_days((*current_transaction).date)-day_origin))*x_rate));
            current_transaction = (*current_transaction).next;
        }

        double y_rate = size_y / abs(max - min);
        chart[0] = (chart[0]-min)*y_rate;
        for(i=1; i<size_x; i++)
        {
            if(chart[i]==0)
            {
                chart[i] = chart[i-1];
            }
            else
            {
                chart[i] = (chart[i]-min)*y_rate;
            }

        }

        int j;
        for(j=size_y-1; j>-1; j--)
        {
            for(i=0; i< size_x; i++)
            if(chart[i] > j)
                {
                    printf("H");
                }
            else
                {
                    printf("o");
                }
            printf("\n");
        }
}
