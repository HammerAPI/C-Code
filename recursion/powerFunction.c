/* Author: Daniel Hammer
 *
 * A more efficient, rec calculation of x^n
 *
 * Asks for an input of a number and an exponent
 * Then asks the user to choose a rec or non-rec power function
 * Both follow the same procedure,
 *      if n is even, x^n = (x^n/2)^2
 *      if n is odd, x^n = x(x^n-1)
 * The rec function simply calls itself (either by n/2 or n-1) until
 * n has been decremented to 0
 * Whereas the non-rec function simply performs the arithmetic
 * On small numbers, there is no noticeable difference
 * On larger numbers, however, the rec function is slower
 */

#include <stdio.h>

long long powerRec(long long x, long long n);
long long powerNonRec(long long x, long long n);

int main(void)
{
    long long x, n;
    int rec;

    // Two loops to ensure that 'x' and 'n' are both non-negative
    do
    {
        printf("Enter a non-negative number to calculate: ");
        scanf("%Ld", &x);
    } while (x < 0);

    do
    {
        printf("Enter a non-negative number to raise %Ld to: ", x);
        scanf("%Ld", &n);
    } while (n < 0);
    
    // Ensures that 'rec' is either 1 or 0
    do
    {
        printf("Solve using recursion? (1 - yes, 0 - no) ");
        scanf("%d", &rec);
    } while (!(rec == 1) && !(rec == 0));

    // If the user chose to solve recursively, call the rec function
    // If now, call the non-rec function
    printf("%Ld^%Ld = %Ld", x, n, rec ? powerRec(x, n) : powerNonRec(x, n));
    return 0;
}




// Non-recursive power function
long long powerNonRec(long long x, long long n)
{
    // Initializes an answer variable to be used
    long long ans = 1;

    // If 'n' is even,
    if ((n % 2) == 0)
    {
        // This is (x^n/2)
        for (long long i = 0; i < (n / 2); i++)
        {
            ans *= x;
        }
        // This is ()^2
        return ans * ans;
    }

    // If 'n' is odd
    else if ((n % 2) == 1)
    {
        //  This is (x^n-1)
        for (long long i = 0; i < (n - 1); i++)
        {
            ans *= x;
        }
        // This is x()
        return x * ans;
    }
    // Since 'n' can only be 0, even, or odd, this is never reached
    return 0;
}




// Recursive power function
long long powerRec(long long x, long long n)
{
    // If 'n' is zero, return 1,
    // else if 'n' is odd, return x(x^n-1),
    // else if 'n' is even, return (x^n/2)^2
    return n == 0 ? 1 : n % 2 ? x * powerRec(x, n - 1) :
        powerRec(x, n / 2) * powerRec(x, n / 2);
}

// The code below is identical in function to the code above
// The code above uses the ternary operator '?'
// Whereas the code below simply uses 'if' statements
/*long long power(long long x, long long n)
{
    // If 'n' is zero, return 1,
    if (n == 0)
    {
        return 1;
    }

    // else if 'n' is even, return (x^n/2)^2
    else if ((n % 2) == 0)
    {
        return power(x, n / 2) * power(x, n / 2);
    }

    // else if 'n' is odd, return x(x^n-1),
    else if ((n % 2) == 1)
    {
        return x * power(x, n - 1);
    }
    return 0;
}*/
