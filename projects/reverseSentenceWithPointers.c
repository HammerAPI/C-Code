/* Author: Daniel Hammer
 *
 * Reverses a sentence using pointers
 *
 * Takes a user input, then iterates through while increasing a pointer
 * Then loops backwards from that input at the pointer's index
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
    // Sentence array and temporary character
    char sentence[MAX_LENGTH], ch;
    // Character pointer pointed at the beginning of the array
    char *cptr = sentence;

    printf("Enter a message: ");
    // Take a line of input
    while ((ch = getchar()) != '\n')
    {
        // Set the value of the array at the pointer's index to ch,
        // then increment the pointer
        *cptr++ = ch;

        /* Same as
         * *cptr = ch;
         * cptr++;
         */
    }

    printf("Reversed: ");
    // Decrement the pointer (to get the correct index) and loop backwards
    for (cptr--; cptr >= sentence; cptr--)
    {
        printf("%c", *cptr);
    }

    return 0;
}
