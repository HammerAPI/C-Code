/* Author: Daniel Hammer
 *
 * A program to read an ISBN code and display each section of it
 *
 * Reads each integer, separating at each dash
 */
#include <stdio.h>

int main(void)
    {
        int gsiPrefix, groupIdentifier, publisherCode, itemNumber, checkDigit;

        // Asks the user for an input
        printf("Enter an ISBN: ");
        scanf("%d-%d-%d-%d-%d", &gsiPrefix, &groupIdentifier, &publisherCode, &itemNumber, &checkDigit);

        // Prints each element of the ISBN
        printf("GSI Prefix: %d\n", gsiPrefix);
        printf("Group Identifier: %d\n", groupIdentifier);
        printf("Publisher Code: %d\n", publisherCode);
        printf("Item Number: %d\n", itemNumber);
        printf("Check Digit: %d\n", checkDigit);
    }
