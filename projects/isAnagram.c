/* Author: Daniel Hammer
 *
 * A program to determine if two words are anagrams
 *
 * Scans a word, counting how many times each letter in it occurs
 * Stores these counts in an array of 26 numbers
 * Scans another word and decreases the respective values in the array
 * by the number of times each letter in the new word occurs
 * Loops through the array and, if all values are 0, the words are anagrams
 */

#include <stdio.h>
#include <ctype.h>

#define SIZE ((int) (sizeof(alphabet) / sizeof(alphabet[0])))

int main(void)
{
    

    // Holds the number of times each letter in the scanned words appears
    int alphabet[26] = {0};
    char letter;

    

    // Scans the first word, incrementing the respective index of the array
    // for every time a letter occurs
    printf("Enter the first word: ");
    while ((letter = toupper(getchar())) != '\n')
    {
        if (isalpha(letter))
        {
            alphabet[letter - 'A']++;
        }
    }

    // Scans the second word, decrementing the respective index of the array
    // for every time a letter occurs
    printf("Enter the second word: ");
    while ((letter = toupper(getchar())) != '\n')
    {
        if (isalpha(letter))
        {
            alphabet[letter - 'A']--;
        }
    }

    // Loops through the array, checking to see if every index is 0
    // if at least one index is not 0, the words are not anagrams
    for (int i = 0; i < SIZE; i++)
    {
        if (alphabet[i] != 0)
        {
            printf("The words are not anagrams.");
            return 0;
        }
    }
    // If all indexes are 0, the words are anagrams
    printf("The words are anagrams.");
    return 0;
}
