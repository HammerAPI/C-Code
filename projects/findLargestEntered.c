/* Author: Daniel Hammer
 *
 * A program to find the largest number entered
 *
 * Prompts for an entry, the compares it to the existing largest
 * if it is larger, set it as the new largest and repeat
 */

#include <stdio.h>

int main(void)
{
    float largest, num;

    // Loops until the user enters 0 to stop
    while (num != 0)
    {
        printf("Enter a number, or 0 to stop:\n");
        scanf("%f", &num);

        // If the largest is currently smaller than the entered number,
        // set the number as the new largest
        if (largest <= num)
        {
            largest = num;
        }
    }
    printf("The largest number entered was: %f", largest);
    return 0;
}
