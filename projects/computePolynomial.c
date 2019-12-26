/* Author: Daniel Hammer
 *
 * Computes the value of the following polynomial
 * 3x^5 + 2x^4 - 5x^3 - x^2 +7x - 6
 *
 * Asks the user to input a value for x, then passes that value to a function
 * Returns the calculated answer
 */


#include <stdio.h>

// Method prototype; prevents compiler errors due to defining calc below main
int calc(int x);

int main(void)
{
    int x;
    printf("Enter a value for x: ");
    scanf("%d", &x);


    printf("The value of the function\n");
    printf("3x^5 + 2x^4 - 5x^3 - x^2 +7x - 6\n");
    printf("Where x = %d is: %d", x, calc(x));
    return 0;
}


int calc(int x)
{
    return 3 * (x*x*x*x*x) + 2 * (x*x*x*x) - 5 * (x*x*x) - (x*x) + 7 * (x) - 6;
}
