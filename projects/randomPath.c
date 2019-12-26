/* Author: Daniel Hammer
 *
 * A program to display a random path across a 10x10 array
 *
 * Generates an size*size grid (where size is determined by the user) and
 * attempts to create a path from A to Z by beginning in the center and
 * choosing a random direction to move over and over until either
 * 1 - a path to Z has been found
 * 2 - no legal path exists
 * Prints the final result
 *
 *
 * Possible improvements:
 *      - Turn the movement loop into an independent function
 *      - Get rid of the bars around the four sides of the box; looks nicer
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CENTER (size / 2)
#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3

int main(void)
{

    // count to iterate through the array of letters
    // direction to determine where the program will move
    // x and y coordinates to determine the current position
    // canMove to determine whether the program has a legitimate move
    // size to determine the size of the grid
    int count, direction, x, y, canMove, size;
    
    // Determines the size of the grid via user input
    printf("Enter a number for the size of the grid\n> ");
    scanf("%d", &size);
    printf("\nAttempting to generate a randomized path from A to Z\n");

    // Two dimensional array representing the grid
    char grid[size][size];

    // Setup the rand() function
    srand((unsigned) time(NULL));

    // If the grid is odd, the path begins in the center
    // If the grid is even, the path begins in the top left corner
    x = size % 2 == 1 ? CENTER : 0;
    y = size % 2 == 1 ? CENTER : 0;




    // Initialize the array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            {
                grid[i][j] = '.';
            }
        }
    }




    //Sets the current position to the first letter
    grid[y][x] = 'A';

    for (count = 1; count < 26;)
    {
        // If there is at least one legal position to move,
        // allow the program to make a movement
        if ((grid[y + 1][x] == '.' && (y + 1) < size)
                || (grid[y - 1][x] == '.' && (y - 1) >= 0)
                || (grid[y][x + 1] == '.' && (x + 1) < size)
                || (grid[y][x - 1] == '.' && (x - 1) >= 0))
        {
            canMove = 1;
        }
        // If not, stop the program
        else
        {
            printf("\nNo legal path was found after '%c'\n", 'A' + count - 1);
            break;
        }




        // While there is a legal movement,
        // generate a random direction and try to move there
        while (canMove == 1)
        {
            // Generates a random number (direction) 0-3
            direction = rand() % 4;

            // Each case functions the same
            // If the movement is within the bounds of the grid
            // AND the new space is unmarked (denoted by being '.'),
            // then assign the next letter to the new space,
            // and exit the movement loop
            switch (direction)
            {
                case DOWN: if ((y + 1) < size && grid[y + 1][x] == '.')
                        {
                            grid[++y][x] = 'A' + count;
                            canMove = 0;
                        }
                         break;
                case UP: if ((y - 1) >= 0 && grid[y - 1][x] == '.')
                        {
                            grid[--y][x] = 'A' + count;
                            canMove = 0;
                        }
                        break;
                case RIGHT: if ((x + 1) < size && grid[y][x + 1] == '.')
                        {
                            grid[y][++x] = 'A' + count;
                            canMove = 0;
                        }
                        break;
                case LEFT: if ((x - 1) >= 0 && grid[y][x - 1] == '.')
                        {
                            grid[y][--x] = 'A' + count;
                            canMove = 0;
                        }
                        break;
            }
        }
        // A move has been made, so increase the counter
        count++;
    }

    // Print the finalized grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
