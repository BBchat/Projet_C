#include <stdio.h>
#include <stdlib.h>
#include "../include/chart.h"
#include "../include/transaction.h"
#include "../include/loaded_transactions.h"


//ne marche pas encore
void draw_expenses_chart(int chart_type, Date* starts, Date* ends, int size_x, int size_y)
{

        if(get_first_transaction() != NULL)
        {
        int number = count_transactions();
        Transaction* current_transaction = get_first_transaction();

        int day_origin = number_of_days(starts);
        int day_end = number_of_days(ends);
        double x_rate = ((double)size_x) / ((double)(day_end - day_origin));

        double max = 0;
        double min = 0;
        double amount = 0;

        int i;
        double chart[size_x];
        for(i=0; i<size_x; i++)
        {
            chart[i]=0;
        }
        for(i = 0; i<number+1; i++)
        {
            amount += (*current_transaction).amount;
            if(date_compare(starts,current_transaction->date)==0 && date_compare(current_transaction->date, ends)==0)
            {
                if(amount < min) {min = amount;}
                if(amount > max) {max = amount;}
                int k;
                for(k=(int)((number_of_days((*current_transaction).date)-day_origin)*x_rate); k<size_x; k++)
                {
                    chart[k]=amount;
                }
            }
            current_transaction = (*current_transaction).next;
        }

        double y_rate = ((double)size_y) / ((double)abs(max - min));
        chart[0] = (chart[0]-min)*y_rate;
        for(i=1; i<size_x; i++)
        {
            chart[i] = (chart[i]-min)*y_rate;
        }

        int j;
        printf("   EUR ^\n");
        for(j=size_y-1; j>-1; j--)
        {
            if(j%2 == 0)
            {
                int val = (int)(((double)(j+1))/y_rate) + min;
                if(val >= 0)
                {
                    if(abs(val) < 10 )
                        printf("      %d",val);
                    else if(abs(val) < 100 )
                        printf("     %d",val);
                    else if(abs(val) < 1000 )
                        printf("    %d",val);
                    else if(abs(val) < 10000 )
                        printf("   %d",val);
                    else if(abs(val) < 100000 )
                        printf("  %d",val);
                    else if(abs(val) < 1000000 )
                        printf(" %d",val);
                }
                else
                {
                    if(abs(val) < 10 )
                        printf("     %d",val);
                    else if(abs(val) < 100 )
                        printf("    %d",val);
                    else if(abs(val) < 1000 )
                        printf("   %d",val);
                    else if(abs(val) < 10000 )
                        printf("  %d",val);
                    else if(abs(val) < 100000 )
                        printf(" %d",val);
                    else if(abs(val) < 1000000 )
                        printf("%d",val);
                }
            }
            else
            {
                printf("       ");
            }
            printf("| ");
            for(i=0; i< size_x; i++)
            if(chart[i] >= j)
                {
                    printf("o");
                    chart[i] = -1;
                }
            else
                {
                    printf(".");
                }
            printf("\n");
        }
        printf("       ");
        printf("L");
        for(i=1; i<size_x+4; i++)
        {
            printf("-");
        }
        printf(">\n");
        printf("     ");
        date_print(starts);
        for(i=1; i<size_x-10; i++)
        {
            printf(" ");
        }
        date_print(ends);
        printf("\n");
        }
}
