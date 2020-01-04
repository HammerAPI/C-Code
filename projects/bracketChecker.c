/* Author: Daniel Hammer
 *
 * Bracket checker
 *
 * Checks to see if entered brackets/braces/parentheses are nested properly
 * Scans input, pushing left braces to a stack,
 * when a right brace is detected, it pops the stack and compares to see if the
 * scanned value is a pair match for the popped value,
 * if no mismatches are found, the braces are nested properly
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 30

// Global variables
int stack[STACK_SIZE];
int *top = &stack[0];

// Method prototypes
bool isEmpty();
bool isFull();
void push(char);
char pop();
void stackUnderflow();
void stackOverflow();
bool canPop();

// Doesn't actually empty the stack, rather points the top to the beginning,
// making the program think the stack is empty
void makeEmpty()
{
    *top = 0;
}

bool isEmpty()
{
    return top == &stack[0];
}


bool isFull()
{
    return top == &stack[STACK_SIZE - 1];
}

// Adds a value to the top and increments the top
void push(char ch)
{
    if (isFull())
    {
        stackOverflow();
    }
    else
    {
        *top++ = ch;
    }
}

// Returns the top's current value and decrements the top
char pop()
{
    if (isEmpty())
    {
        stackUnderflow();
        return '0';
    }
    else
    {
        return *--top;
    }
}

// If the pointer is pointing to anything after the first element, return true
// else false
bool canPop()
{
    if (top > &stack[0])
    {
        return true;
    }
    return false;
}

void stackUnderflow()
{
    printf("Stack is empty!");
}

void stackOverflow()
{
    printf("Stack is full!");
}




int main()
{
    char ch, popped;

    printf("Enter parentheses/brackets/braces: ");

    // Loop through the user input
    while ((ch = getchar()) != '\n')
    {
        // If left-hand brace, push to stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        // If right-hand brace, compare with popped item
        if (ch == ')' || ch == '}' || ch == ']')
        {
            // If there are more left-hand items
            // ie. user entered '(()'
            if (canPop() == false){
                printf("Brackets are not nested properly");
                exit(EXIT_FAILURE);
            }
            popped = pop();
            if ((popped == '(' && ch != ')')
                    || (popped == '{' && ch != '}')
                    || (popped == '[' && ch != ']'))
            {
                printf("Brackets are not nested properly");
                return 0;
            }
        }
    }

    // If there are still items left in the stack that haven't been popped
    // ie. user entered '()]'
    if (isEmpty() == false)
    {
        printf("Brackets are not nested properly");
    }

    // Everything checks out!
    else
    {
        printf("Brackets are nested properly\n");
    }

    return 0;
}
