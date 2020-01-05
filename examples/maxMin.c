#include <stdio.h>

#define N 10

void maxMin(int a[], int n, int *max, int *min);

int main()
{
    // Integer array, pointer, and largest/smallest value
    int b[N], *i, big, small;

    printf("Enter %d numbers: ", N);
    // Uses a pointer to iterate through the array
    for (i = b; i < b + N; i++)
    {
        scanf("%d", i);
    }

    // Finds the max and min numbers
    maxMin(b, N, &big, &small);

    printf("Largest: %d\nSmallest: %d\n", big, small);
    return 0;
}

void maxMin(int a[], int n, int *max, int *min)
{
    // Integer pointer
    int *i;

    // Initialize the locations where *max and *min point to be the first
    // value entered
    *max = *min = a[0];

    // Loop through the array, comparing *max and *min with the current *i
    for (i = a; i < a + n; i++)
    {
        // If the current element is greater than the current max, replace it
        if (*i > *max)
        {
            *max = *i;
        }
        // If the current element is less than the current min, replace it
        else if (*i < *min)
        {
            *min = *i;
        }
    }
}
