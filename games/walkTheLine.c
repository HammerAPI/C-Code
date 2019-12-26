/* Author: Daniel Hammer
 *
 * A program to display a random path across a 10x10 array
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void)
{
    char visited[SIZE][SIZE];
    int count, x, y;
    char direction;
    count = 0;
    x = 0;
    y = 0;

    srand((unsigned) time(NULL));


    printf("\n--- Initial Grid ---\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            visited[i][j] = '.';
            //printf("%2c", visited[i][j]);
        }
        //printf("\n");
    }


    while (1)
    {
        printf("\n");
        visited[x][y] = 'X';
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                printf("%2c", visited[i][j]);
            }
            printf("\n");
        }
        //direction = rand() % 4;

        printf("Use WASD to navigate the box and press 'x' to exit");
        scanf("%c", &direction);

        switch (direction)
        {
            case 's': if ((x + 1) < SIZE && visited[x + 1][y] == '.')
                    {
                        x++;
                    }
                    break;
            case 'w': if ((x - 1) >= 0 && visited[x - 1][y] == '.')
                    {
                        x--;
                    }
                    break;
            case 'd': if ((y + 1) < SIZE && visited[x][y + 1] == '.')
                    {
                        y++;
                    }
                    break;
            case 'a': if ((y - 1) >= 0 && visited[x][y - 1] == '.')
                    {
                        y--;
                    }
                    break;
            case 'x': exit(0);
                      break;
        }

        if (visited[x][y] == '.')
        {
            printf("(%d,%d)", x, y);
            count++;
        }
    }
}
