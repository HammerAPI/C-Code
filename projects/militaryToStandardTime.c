/* Author: Daniel Hammer
 *
 * A program to convert military (24 hour) time 
 * to standard (12 hour) time
 *
 * Takes a user input, checks if it falls within
 * a specified range, then alters the value
 */

#include <stdio.h>

int main(void)
{
    int hr, min;

    // Scans for user input
    printf("Please enter a 24-hour time in the format XX:XX\n");
    scanf("%d:%d", &hr, &min);

    // Checks the validity of the entered numbers
    if (hr > 24 || hr < 0 || min < 0 || min >= 60)
    {
        printf("Error: That is not a valid time!");
        return 1;
    }

    // Checks to see if the value is a rollover point
    if (hr == 0 || hr == 24)
    {
        hr = 12;
    }

    // If pm, convert the military hour to standard and print
    if (hr > 12 && hr <= 24)
    {
        hr = (hr % 12);
        printf("The time is %d:%02d pm", hr, min);
    }
    // if am, do nothing and print
    else
    {
        printf("The time is %d:%02d am", hr, min);
    }
}
