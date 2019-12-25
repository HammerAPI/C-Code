/* Author: Daniel Hammer
 *
 * Creates a magic square of a user-inputted size
 *
 * Initializes a size*size grid (where size is user-inputted) with zeros
 * Begins with 1 in the center of the top row
 * Shifts up one row and to the right one column and places the next number
 * If the shift goes out of bounds, wrap it around
 * If the selected space already contains a number, shift down one row
 * Repeat until size^2 is reached and the square is full
 */

#include <stdio.h>

int main(void)
{
    // The size of the square, the sum of a given row/column/diagonal,
    // and the current coordinates
    int size, sum, y, x;

    // Loop until an odd number is entered
    do
    {
        printf("Please enter a size for the magic square: ");
        scanf("%d", &size);
    } while ((size % 2) != 1);



    // Set the coordinates of the first point to the middle of the first row
    y = 0;
    x = size / 2;
    sum = 0;



    // Initialize the square with zeros
    int magicSquare[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            magicSquare[i][j] = 0;
        }
    }




    // Set the first position to 1
    magicSquare[y][x] = 1;
    for (int i = 2; i <= (size * size); i++)
    {
        // Decrease y and increase x and, if they go out of bounds, wrap them
        if ((--y) < 0)
        {
            y = size - 1;
        }
        if ((++x) >= size)
        {
            x = 0;
        }

        // If the space is empty, set it to a new value
        if (magicSquare[y][x] == 0){
            magicSquare[y][x] = i; 
        }
        // If the space is NOT empty,
        // go back to the old coordinates and move down by 1
        else
        {
            // Go back to the previous coordinates, and wrap if needed
            if ((--x) < 0)
            {
                x = size - 1;
            }
            if ((++y) >= size)
            {
                y = 0;
            }
            // Set the space BELOW the occupied space to the next number
            magicSquare[++y][x] = i;
        }
    }


    // Print out the square and calculate the sum of the first row
    for (int i = 0; i < size; i++)
    {
        sum += magicSquare[i][0];
        for (int j = 0; j < size; j++)
        {
            printf("%4d", magicSquare[i][j]);
        }

        printf("\n\n");
    }
    printf("The sum of any given row, column, or diagonal is %d", sum);
}
