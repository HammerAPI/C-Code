/* Author: Daniel Hammer
 *
 * Simulates a game of craps
 *
 * Rolls two dice and sums their results
 * If the sum is 7 or 11, the player wins
 * If the sum is 2 or 3, the player loses
 * If neither, save the original roll as the point,
 * roll again until either the point or 7 is achieved
 * If the point is rolled again, add a win
 * If 7 is rolled, add a loss
 * After the game has concluded, ask the user to input 'Y' or 'y' to play again
 * If the player does not play again, print out the total wins/losses and exit
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


// Function prototypes
int roll(void);
int play(void);

int main(void)
{
    // Number of wins and losses, and a character to play again or not
    int wins = 0, losses = 0;
    char entry;

    // While the user does NOT enter anything OTHER than 'Y' or 'y',
    // continue playing the game
    do
    {
        // If play() returns a 1 (win), increase wins
        // else, increase the losses
        play() ? wins++ : losses++;

        printf("Would you like to play again? (Y/N)\n");
        scanf(" %c", &entry);
    } while (toupper(entry) == 'Y');

    // Print out the total number of wins and losses
    printf("Total score:\n");
    printf("%2d wins\n", wins);
    printf("%2d losses\n", losses);

    return 0;
}




// Roll two random numbers between 0-5, add them, and then add 2
// This ensures the roll is between 2 and 12, inclusively
int roll(void)
{
    return (rand() % 6) + (rand() % 6) + 2;
}




// Main program logic
int play(void)
{
    // Holds the original roll and subsequent rolls
    int point, newRoll;
    // Initializes the random function
    srand((unsigned) time(NULL));

    // Gets the initial roll
    point = roll();
    printf("You rolled a %d\n", point);
    
    // If the initial roll is 7 or 11, the player wins
    if (point == 7 || point == 11)
    {
        printf("You win!\n");
        return 1;
    }
    
    // If the initial roll is 2 or 3, the player loses
    else if (point == 2 || point == 3)
    {
        printf("You lose!\n");
        return 0;
    }

    // If the initial roll is none of those four cases, the game continues
    printf("Your point is: %d\n", point);

    // This loops until one of the conditions is met
    while (1)
    {
        // A new roll is generated
        newRoll = roll();
        printf("You rolled %d\n", newRoll);

        // If the new roll is equal to the original roll, the player wins
        if (newRoll == point)
        {
            printf("You win!\n");
            return 1;
        }

        // If the new roll is 7, the player loses
        else if (newRoll == 7)
        {
            printf("You lose!\n");
            return 0;
        }
    }
}
