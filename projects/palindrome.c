/* Author: Daniel Hammer
 *
 * Checks if a word is a palindrome
 *
 * Gets an input from the user, then compares the beginning and last
 * letters of the message until a difference is found or the middle is reached
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 30

bool isPalindrome(char words[], char *rightPtr);

int main()
{
    // Holds user input
    char sentence[MAX_LENGTH], ch;

    // Iterates through the sentence, starting at the beginning
    char *ptr = sentence;

    // Stores the input letter by letter in the array
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n')
    {
        // Removes non-letters and whitespace
        if (isalpha(ch) && (ch != ' ')){
            *ptr++ = tolower(ch);
        }
    }
    // Decrements the pointer to remove the termination character
    *ptr--;

    printf("The message %s a palindrome",
            isPalindrome(sentence, ptr) ? "is" : "is not");
}

// Takes the current pointer and array as input
bool isPalindrome(char words[], char *rightPtr)
{
    // Creates a left-hand pointer initialized at the beginning of the array
    char *leftPtr = words;

    // Perform while the left index is lower than the right index
    while (leftPtr < rightPtr)
    {
        // Iterate through and check if they are not equal
        if (*leftPtr++ != *rightPtr--)
        {
            return false;
        }
    }
    return true;
}
