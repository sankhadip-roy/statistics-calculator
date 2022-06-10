#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "mystat.h"
int main(void)
{
    int N, i, input;
    char contd;
    float y[10];
    printf("\x1b[34m");
    printf("****PROJECT ON STATISTIC CALCULATOR****");
    printf("\nPRESENTED BY:\nSANKHADIP ROY\n");
    printf("\x1b[32m");
    printf("Enter any key to proceed");
    getch();
    printf("\x1b[35m");
    while (1)
    {
        printf("\x1b[35m");
        printf("\n1.Mean\t2.Median\n3.Mode\t4.Variance\n5.Standard deviation\n6.Skewness\n");
        printf("\x1b[36m");
        printf("\nEnter your choice: ");
        scanf("%d", &input);
        if (input >= 1 && input <= 6)
        {
            printf("Enter the value of N\n");
            scanf("%d", &N);
            printf("Enter %d real numbers \n", N);
            for (i = 0; i < N; i++)
            {
                scanf("%f", &y[i]);
            }
            switch (input)
            {
            case 1:
                printf("Ans of mean: %0.2f\n", mean(N, y));
                break;
            case 2:
                printf("Ans of median: %0.2f\n", median(N, y));
                break;
            case 3:
                mode(N, y);
                break;
            case 4:
                printf("Ans of varience: %0.2f\n", variance(N, y));
                break;
            case 5:
                printf("Ans of standard deviation: %0.2f\n", sqrt(variance(N, y)));
                break;
            case 6:
                if (mode(N, y) == 0)
                    printf(" so skewness can't be calculated\n");
                else
                    printf("Ans of skewness : %0.2f\n", (mean(N, y) - mode(N, y)) / sqrt(variance(N, y)));
                break;
            }
        }
    
    else
    {
        printf("\x1b[31m");
        printf("Wrong choice, please choose from 1-6\n");
        printf("\x1b[0m");
        continue;
    }
    printf("\x1b[33m");
    printf("\n\nDo you want to use it again\n");
here:
    printf("If yes press Y else press N\n");
    fflush(stdin);
    scanf("%c", &contd);
    if (contd == 'Y' || contd == 'y')
        continue;
    else if (contd == 'N' || contd == 'n')
        break;
    else
    {
        printf("\x1b[31m");
        printf("\nWrong entry\n\n");
        printf("\x1b[33m");
        goto here;
    }
}
printf("\x1b[0m");
return 0;
}
