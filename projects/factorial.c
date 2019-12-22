

#include <stdio.h>

long long factorial(long long num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return (num * factorial(num - 1));
    }
}

int main(void)
{
    long long num;

    printf("Enter an integer: ");
    scanf("%Ld", &num);

    printf("%Ld! = %Ld", num, factorial(num));
}
