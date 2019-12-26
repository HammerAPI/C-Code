/* Author: Daniel Hammer
 *
 * A program to display all of the prime numbers within a specified range
 *
 * Asks the user for an input and displays all primes up to the input
 */

#include <stdio.h>

/* Logical method
 * Determines if the number is a prime or not
 * and returns the appropriate integer value
 */
int isPrime(int num)
{
    for (int x = 2; x < num; x++)
    {
        /* If the remainder when divided is 0,
         * then x is a factor of the number
         * and the number is not prime
         */
        if (num % x == 0)
        {
            return -1;
        }
    }

    // Else, the number is prime
    return 1;
}


int main(void)
{
    // Allocate space to hold user input
    int input;

    // Prompt the user for input
    printf("Please enter an upper bound integer\n");
    scanf("%d", &input);

    printf("The prime numbers up to %d are:\n", input);
    
    /* Loop up to the inputted number,
     * displaying all primes until the input is reached
     */
    for (int x = 1; x <= input; x++)
    {
        if (isPrime(x) == 1)
        {
            printf("%d, ", x);
        }
    }
}
