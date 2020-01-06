/* Classifies a hand of cards
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

int rankNum[NUM_RANKS];
int suitNum[NUM_SUITS];
bool straight, flush, four, three;
int pairs;

void readCards(void);
void analyzeHand(void);
void printResult(void);

// Calls the program logic in an infinite loop
int main(void)
{
    for (;;)
    {
        readCards();
        analyzeHand();
        printResult();
    }
}

// Reads the cards into global variables
// Checks for bad/duplicate cards
void readCards(void)
{
    bool cardExists[NUM_RANKS][NUM_SUITS];
    char ch, rankCh, suitCh;
    int rank, suit;
    bool badCard;
    int cardsRead = 0;

    // Initializes the card array to false
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        rankNum[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++)
        {
            cardExists[rank][suit] = false;
        }
    }

    for (suit = 0; suit < NUM_SUITS; suit++)
    {
        suitNum[suit] = 0;
    }

    while (cardsRead < NUM_CARDS)
    {
        badCard = false;
        printf("Enter a card: ");
        rankCh = getchar();
        switch (rankCh)
        {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 't': rank = 8; break;
            case 'j':
            case 'J': rank = 9; break;
            case 'q':
            case 'Q': rank = 10; break;
            case 'k': 
            case 'K': rank = 11; break;
            case 'a': 
            case 'A': rank = 12; break;
            default: badCard = true;
        }

        suitCh = getchar();
        switch (suitCh)
        {
            case 'c':
            case 'C': suit = 0; break;
            case 'd':
            case 'D': suit = 1; break;
            case 'h':
            case 'H': suit = 2; break;
            case 's':
            case 'S': suit = 3; break;
            default: badCard = true;
        }

        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ')
            {
                badCard = true;
            }
        }

        if (badCard)
        {
            printf("Bad card; ignored.\n");
        }
        else if (cardExists[rank][suit])
        {
            printf("Duplicate card; ignored.\n");
        }
        else
        {
            rankNum[rank]++;
            suitNum[suit]++;
            cardExists[rank][suit] = true;
            cardsRead++;
        }
    }

}

// Determines the grouping of the cards in the hand and stores the result in
// global variable
void analyzeHand(void)
{
    int numConsec = 0;
    int rank, suit;
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    // Check for a flush
    for (suit = 0; suit < NUM_SUITS; suit++)
    {
        if (suitNum[suit] == NUM_CARDS)
        {
            flush = true;
        }
    }

    // Check for a straight
    rank = 0;
    while (rankNum[rank] == 0)
    {
        rank++;
    }
    for (; rank < NUM_RANKS && rankNum[rank] > 0; rank++)
    {
        numConsec++;
    }
    if (numConsec == NUM_CARDS)
    {
        straight = true;
        return;
    }

    // Checks for 4-of-kind, 3-of-kind, and pairs
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        if (rankNum[rank] == 4)
        {
            four = true;
        }
        if (rankNum[rank] == 3)
        {
            three = true;
        }
        if (rankNum[rank] == 2)
        {
            pairs++;
        }
    }
}

// Prints the result of the card combination in the hand
void printResult(void)
{
    if (straight && flush) printf("Straight flush");
    else if (four)                  printf("Four of a kind");
    else if (three && pairs == 1)   printf("Full house");
    else if (flush)                 printf("Flush");
    else if (straight)              printf("Straight");
    else if (three)                 printf("Three of a kind");
    else if (pairs == 2)            printf("Two pairs");
    else if (pairs == 1)            printf("Pair");
    else                            printf("High card");
}
