/* Author: Daniel Hammer
 * 
 * Recursive Fibonacci calculator
 *
 * Calculates the Fibonacci of a number using recursion
 */

#include <stdio.h>

// Fibonacci method
int fibonacci(int num)
{
    // If the number is 1 or less, return it because the fibonnaci
    // sequence is completed
    // If the number is greater than 1, return a function call of
    // the number - 1 plus the function call of number - 2
    return num <= 2 ? 1 : fibonacci(num - 2) + fibonacci(num - 1);
}

int main(void)
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Print the results using a function call
    // No need to create a, "answer" variable
    printf("Fibonacci term #%d = %d", num, fibonacci(num));
}
