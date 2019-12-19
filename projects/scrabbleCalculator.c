/* Author: Daniel Hammer
 *
 * A program to calculate the value of a word played in Scrabble'
 * 
 * Scans each letter and adds its value to the total running sum
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char letter;
    int val = 0;

    printf("Which word do you wish to play?\n> ");

    // Loops through every letter of the entered word
    while ((letter = toupper(getchar())) != '\n')
    {
        // Determines how many points to add to the total, given a word
        // Case fall-through allows for the absence of duplicate code
        switch (letter)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U': val += 1;
                      break;
            case 'D':
            case 'G': val += 2;
                      break;
            case 'B':
            case 'C':
            case 'M':
            case 'P': val += 3;
                      break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y': val +=4;
                      break;
            case 'K': val += 5;
                      break;
            case 'J':
            case 'X': val += 8;
                      break;
            case 'Q':
            case 'Z': val += 10;
                      break;
        }
    }
    printf("The value of the word is: %d", val);
    return 0;
}


