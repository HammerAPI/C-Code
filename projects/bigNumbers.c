/* Author: Daniel Hammer
 *
 * Displays large numbers
 *
 */

#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 20
#define MAX_SEGMENTS 7
#define ROWS 4 
#define MULTIPLIER 4

/*       0
 *       _
 *     5|_|1        middle = 6
 *     4|_|1
 *       3
 */

// 2D array to represent the on/off states of a 7-segment number
int segments[MAX_DIGITS][MAX_SEGMENTS] = {
                        {1, 1, 1, 1, 1, 1, 0}, // 0
                        {0, 1, 1, 0, 0, 0, 0}, // 1
                        {1, 1, 0, 1, 1, 0, 1}, // 2
                        {1, 1, 1, 1, 0, 0, 1}, // 3
                        {0, 1, 1, 0, 0, 1, 1}, // 4
                        {1, 0, 1, 1, 0, 1, 1}, // 5
                        {1, 0, 1, 1, 1, 1, 1}, // 6
                        {1, 1, 1, 0, 0, 0, 0}, // 7
                        {1, 1, 1, 1, 1, 1, 1}, // 8
                        {1, 1, 1, 1, 0, 1, 1}}; // 9

// 2D array of digits to display in 7-segment format
char digits[ROWS][MAX_DIGITS * MULTIPLIER];

// Function prototypes
void clearDigitsArray();
void processDigit(int digit, int position);
void printDigitArray();




int main()
{
    int counter = 0;
    char ch;


    // Initializes the digit array to be empty
    clearDigitsArray();

    printf("Enter a number: ");
    while (counter < MAX_DIGITS && (ch = getchar()) != '\n')
    {
        if (isdigit(ch))
        {
            // Get the corresponding number from the numerical character
            // and process it into 7-segment format
            ch -= '0';
            processDigit(ch, counter++);
        }
    }

    printDigitArray();
}




// Initializes the digits array to blank spaces
void clearDigitsArray()
{
    for (int i = 0; i < MAX_DIGITS; i++)
    {
        for (int j = 0; j < (MAX_DIGITS * MULTIPLIER); j++)
        {
            digits[i][j] = ' ';
        }
    }
}




// Converts a passed number to 7-segment format and stores it in digits
// NOTE: This method was heavily inspired by the code found here:
// https://github.com/j-angus/cpama/blob/master/ch10/ch10pp07.c
void processDigit(int digit, int position)
{
    int pos = position * MULTIPLIER;

    for (int i = 0; i < ROWS; i++)
    {
        // Depending on which row is currently active, check to see if the
        // passed number has a character ('|' or '_') at a specified location
        // If so, activate it, and then continue down the line until breaking
        switch (i)
        {
            /*       0
             *       _
             *     5|_|1        middle = 6
             *     4|_|1
             *       3
             */
            case 0: if (segments[digit][0])
                    {
                        digits[i][pos + 1] = '_';
                    }
                    break;
            case 1: if (segments[digit][5])
                    {
                        digits[i][pos] = '|';
                    }
                    if (segments[digit][6])
                    {
                        digits[i][pos + 1] = '_';
                    }
                    if (segments[digit][1])
                    {
                        digits[i][pos + 2] = '|';
                    }
                    break;
            case 2: if (segments[digit][4])
                    {
                        digits[i][pos] = '|';
                    }
                    if (segments[digit][3])
                    {
                        digits[i][pos + 1] = '_';
                    }
                    if (segments[digit][2])
                    {
                        digits[i][pos + 2] = '|';
                    }
                    break;
        }
    }
}




// Prints the digits array
void printDigitArray()
{
    for (int i = 0; i < ROWS ; i++)
    {
        for (int j = 0; j < (MAX_DIGITS * MULTIPLIER); j++)
        {
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
}
