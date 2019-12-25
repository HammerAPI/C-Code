/* Author: Daniel Hammer
 * 
 * Recursive factorial calculator
 *
 * Calculates the factorial of a number using recursion
 */

#include <stdio.h>

// Factorial method
long long factorial(long long num)
{
    // If the number is 1, return 1, because multiplying by 1 yields no change
    // If the number is greater than 1, return the number
    // multiplied by a function call to the number - 1
    return num == 1 ? 1 : num * factorial(num - 1);
}

int main(void)
{
    long long num;

    printf("Enter an integer: ");
    scanf("%Ld", &num);

    // Print the results using a function call
    // No need to create a, "answer" variable
    printf("%Ld! = %Ld", num, factorial(num));
}
