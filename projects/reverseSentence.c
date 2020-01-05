/* Author: Daniel Hammer
 *
 * Reverses a sentence
 *
 * Takes a string input and iterates backwards over it
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 30

int main()
{
    // Character array to hold the sentence and a temporary character to edit
    char sentence[MAX_LENGTH], ch;

    // Index to hold position in the array
    int index = 0;

    printf("Enter a message: ");
    // Loop through the sentence, building the array
    while ((ch = getchar()) != '\n')
    {
        sentence[index++] = ch;
    }

    printf("Reversed: ");
    // Loop backwards from the index, printing the statement
    for (int i = index; i >= 0; i--)
    {
        printf("%c", sentence[i]);
    }

    /* Also works:
    while (index >= 0)
    {
        printf("%c", sentence[index--]);
    }
    */

    return 0;
}
