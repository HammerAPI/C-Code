/* Author: Daniel Hammer
 *
 * A program to print a one-month calendar
 *
 * Asks the user for the number of days in the month,
 * then asks what day the month begins on,
 * then prints the appropriate calendar
 */

#include <stdio.h>

int main(void)
{
    int numDays, startDay;

    // Asks for a valid month length
    // If the number of days is not 28-31, exit program
    printf("\nEnter the number of days in the month: ");
    scanf("%d", &numDays);
    if (numDays < 28 || numDays > 31)
    {
        printf("Error: That is not a valid number of days!");
        return 0;
    }


    // Ask for a valid starting day
    // If the starting day is not 1-7 (Sun-Sat), exit program
    printf("Enter the starting day of the week (1 - Sunday, 7 - Saturday): ");
    scanf("%d", &startDay);
    if (startDay < 1 || startDay > 7)
    {
        printf("Error: That is not a valid starting day!");
        return 0;
    }


    printf("\nS  M  T  W  R  F  S\n");
    // For every day prior to the starting day,
    // print a blank space
    for (int d = 1; d < startDay; d++)
    {
        printf("%-3s", "");
    }

    // Loop through the month, printing each date
    for (int i = 1; i <= numDays; i++)
    {
        // If the day is Saturday, reset the startDay counter
        if (startDay > 7)
        {
            printf("\n");
            startDay = 1;
        }
        printf("%-3d", i);
        startDay++;
    }

    return 0;
}
