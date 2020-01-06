/* Author: Daniel Hammer
 *
 * Converts decimal digits to hex digits
 *
 * Takes the remainder by 16 of a number and prints a character from the hex
 * array at it's index, then divides the original number by 16 and repeats
 */

#include <stdio.h>

void digitToHex(int digit);

int main()
{
    int decimal;

    printf("Enter a number to convert: ");
    scanf("%d", &decimal);

    printf("In hexadecimal: ");
    digitToHex(decimal);
}

// Takes the remainder of the number passed in and prints the character in the
// hex array at that index, then divides the number by 16 and repeats
void digitToHex(int decimal)
{
    int hex[100], index = 0;
    char *hexCode = "0123456789ABCDEF";

    while (decimal != 0)
    {
        hex[index++] = hexCode[decimal % 16];
        decimal /= 16;
    }
    index--;
    while (index >= 0)
    {
        printf("%c", hex[index--]);
    }
}
