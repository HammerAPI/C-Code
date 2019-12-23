/* prints a table of compound interest
 */

#include <stdio.h>

// The size of the array
#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
// The initial balance to use in the program
#define INITIAL_BALANCE 100.0

int main(void)
{
    int i, lowRate, numYears, year;
    // The array of values to calculate
    double value[5];

    

    // User input and variable assignment
    printf("Enter an interest rate: ");
    scanf("%d", &lowRate);
    printf("Enter a number of years to calculate: ");
    scanf("%d", &numYears);



    // Loop through and print out the rate increments
    // Each increment is 1% higher than the previous
    // Also set the starting amount for each rate to the initial balance
    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++)
    {
        printf("%6d%%", lowRate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");


    // For every year, print the year and, for every interest rate,
    // compound the initial balance with the provided rate,
    // and change the value of the appropriate array element
    for (year = 1; year <= numYears; year++)
    {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++)
        {
            value[i] += (lowRate + i) / 100.0 * value[i];
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }
    return 0;
}
