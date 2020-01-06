/* Author: Daniel Hammer
 *
 * Converts decimal numbers to binary, hexadecimal, and octal
 *
 * Takes an input and then divides by 16, 8, or 2 and stores the remainder
 * Repeat this process until the number is 0, and then concatenates
 * the remainders
 */

#include <stdio.h>

void decimalToHex(int digit);
void decimalToBinary(int digit);
void decimalToOctal(int digit);

int main()
{
    int decimal;

    printf("Enter a number to convert: ");
    scanf("%d", &decimal);

    printf("\nIn hexadecimal: ");
    decimalToHex(decimal);

    printf("\nIn binary: ");
    decimalToBinary(decimal);

    printf("\nIn octal: ");
    decimalToOctal(decimal);
}

// Takes the remainder (% 16) of the number passed in and prints the character
// in the hex array at that index, then divides the number by 16 and repeats
void decimalToHex(int decimal)
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

// Takes the remainder (% 2) of the number passed in and prints the result
// Repeats this process until the number is 0
void decimalToBinary(int decimal)
{
    int binary[100], index = 0;
    while (decimal != 0)
    {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }
    index--;
    while (index >= 0)
    {
        printf("%d", binary[index--]);
    }
}

// Takes the remainder (% 8) of the number passed in and prints the result
// Repeats this process until the number is 0
void decimalToOctal(int decimal)
{
    int octal[100], index = 0;
    while (decimal != 0)
    {
        octal[index++] = decimal % 8;
        decimal /= 8;
    }
    index--;
    while (index >= 0)
    {
        printf("%d", octal[index--]);
    }
}
