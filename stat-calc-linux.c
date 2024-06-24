#include <stdio.h>
#include <math.h>
#include <string.h>
#include "mystat.h"

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

// Function to set terminal text color using ANSI escape codes
void set_color(const char* color) {
    printf("%s", color);
}

int main(void) {
    clear_screen();
    set_color("\033[1;37m\033[44m"); // Set background color (Blue) and text (Bright white)
    
    int N, i, input;
    char contd;
    float y[10];

    // Title formatting
    printf("\033[1;37m"); // Set text color to bright white
    printf("****PROJECT ON STATISTICAL CALCULATOR****\n");
    printf("Author: Sankhadip Roy\n\n");
    set_color("\033[0m"); // Reset text color to default
    printf("Press Enter to proceed\n");
    getchar(); // wait for enter key

    while (1) {
        set_color("\033[1;35m"); // Set text color to bright magenta
        printf("\n1. Mean\t2. Median\n3. Mode\t4. Variance\n5. Standard deviation\n6. Skewness\n");
        set_color("\033[1;36m"); // Set text color to cyan
        printf("\nEnter your choice: ");
        scanf("%d", &input);

        if (input >= 1 && input <= 6) {
            printf("Enter the value of N: ");
            scanf("%d", &N);
            printf("Enter %d real numbers:\n", N);
            for (i = 0; i < N; i++) {
                scanf("%f", &y[i]);
            }

            switch (input) {
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
                    printf("Ans of variance: %0.2f\n", variance(N, y));
                    break;
                case 5:
                    printf("Ans of standard deviation: %0.2f\n", sqrt(variance(N, y)));
                    break;
                case 6:
                    if (mode(N, y) == 0)
                        printf("Skewness can't be calculated\n");
                    else
                        printf("Ans of skewness: %0.2f\n", (mean(N, y) - mode(N, y)) / sqrt(variance(N, y)));
                    break;
            }
        } else {
            set_color("\033[1;31m"); // Set text color to red
            printf("Wrong choice, please choose from 1-6\n");
            set_color("\033[0m"); // Reset text color to default
            continue;
        }

        set_color("\033[1;33m"); // Set text color to yellow
        printf("\n\nDo you want to use it again?\n");
    here:
        printf("If yes press Y, else press N: ");
        fflush(stdin);
        scanf(" %c", &contd); // Added space before %c to consume newline
        if (contd == 'Y' || contd == 'y')
            continue;
        else if (contd == 'N' || contd == 'n')
            break;
        else {
            set_color("\033[1;31m"); // Set text color to red
            printf("Wrong entry\n");
            set_color("\033[1;33m"); // Set text color to yellow
            goto here;
        }
    }

    set_color("\033[0m"); // Reset text color to default
    return 0;
}
