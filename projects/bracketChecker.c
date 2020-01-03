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
int top = 0;

// Method prototypes
bool isEmpty();
bool isFull();
void push(char);
char pop();
void stackFlow();

// Doesn't actually empty the stack, rather points the top to the beginning,
// making the program think the stack is empty
void makeEmpty()
{
    top = 0;
}

bool isEmpty()
{
    return top == 0;
}


bool isFull()
{
    return top == STACK_SIZE;
}

// Adds a value to the top and increments the top
void push(char ch)
{
    if (isFull())
    {
        stackFlow();
    }
    else
    {
        stack[top++] = ch;
    }
}

// Returns the top's current value and decrements the top
char pop()
{
    if (isEmpty())
    {
        stackFlow();
        return 0;
    }
    else
    {
        return stack[--top];
    }
}

// If empty, stack underflow
// If full, stack overflow
void stackFlow()
{
    if (isEmpty())
    {
        printf("Stack is empty!");
    }
    else if (isFull())
    {
        printf("Stack is full!");
    }
    exit(EXIT_FAILURE);
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
