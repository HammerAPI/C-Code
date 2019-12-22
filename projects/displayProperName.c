/* Author: Daniel Hammer
 *
 * Takes an input of a first and last name,
 * prints the last name and first initial
 *
 * Accounts for whitespace before and after each name
 * Also capitalizes the first initial
 * does NOT alter capitalization for last name,
 * (That could override names like McCoy)
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char firstInitial, lastName;

    // Prompt for input and save the first initial
    printf("Enter a first and last name: ");

    // If there is whitespace before the name, ignore it
    if ((firstInitial = getchar()) == ' ')
    {
        while ((firstInitial = getchar()) == ' ');
    }
    
    // Loop through the rest of the first name as it isn't needed
    while ((lastName = getchar()) != ' ');

    // Loop through the last name, printing it out
    do
    {
        // If there is whitespace before the last name, ignore it
        if (lastName != ' ')
        {
            printf("%c", lastName);
        }
    } while ((lastName = getchar()) != '\n');

    // Print out the first initial
    printf(", %c.", toupper(firstInitial));
    return 0;
}
