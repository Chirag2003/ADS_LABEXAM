#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void balanced_parentheses();
void inf_post();
void postfix();
void push(char item);
void pop();
void push1(char x);
char pop1();
int priority(char x);
void push2(int x);
int pop2();

int main()
{
    int choice;
    char exp[MAX];

    while (1)
    {
        printf("\n1. Balanced parentheses\n2. Infix Expression to Postfix Expression\n3. Solve postfix expression\n4. Exit.\n");
        printf("\nEnter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            balanced_parentheses();
            break;

        case 2:
            inf_post();
            break;

        case 3:
            postfix();

            break;

        case 4:
            return 0;
        default:
            printf("\nPlease Select only 1-4 option ----\n");
        }
    }

    return 0;
}

// Declaring a stack

struct stack
{
    char stk[MAX];
    int top;
} s;

// Balanced Parentheses Function

void balanced_parentheses()
{

    char exp[MAX];
    int i = 0;
    s.top = -1;
    printf("\nINPUT THE EXPRESSION : ");
    scanf("%s", exp);
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]); // Push the open bracket
            continue;
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') // If a closed bracket is encountered
        {
            if (exp[i] == ')')
            {
                if (s.stk[s.top] == '(')
                {
                    pop(); // Pop the stack until closed bracket is found
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if (exp[i] == ']')
            {
                if (s.stk[s.top] == '[')
                {
                    pop(); // Pop the stack until closed bracket is found
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if (exp[i] == '}')
            {
                if (s.stk[s.top] == '{') // v[6]9{5}j8+=-}}
                {
                    pop(); // Pop the stack until closed bracket is found
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
        }
    }
    if (s.top == -1)
    {
        printf("\nBALANCED EXPRESSION\n"); // Finally if the stack is empty, display that the expression is balanced
    }
}

// Push Function

void push(char item)
{
    if (s.top == (MAX - 1))
    {
        printf("Stack is Full\n");
    }
    else
    {
        s.top = s.top + 1; // Push the char and increment top
        s.stk[s.top] = item;
    }
}

// Pop Function

void pop()
{
    if (s.top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        s.top = s.top - 1; // Pop the char and decrement top
    }
}

char stack[100];
int top = -1;

// Infix to Postfix Function

void inf_post()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c ", *e);
        else if (*e == '(')
            push1(*e);
        else if (*e == ')')
        {
            while ((x = pop1()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
                printf("%c ", pop1());
            push1(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c ", pop1());
    }
}

//
void push1(char x)
{
    stack[++top] = x;
}

char pop1()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Postfix Equation Function

void postfix()
{
    char exp[20];
    char *e;
    int n1, n2, n3, num;
    printf("Enter the expression : ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;
            push2(num);
        }
        else
        {
            n1 = pop2();
            n2 = pop2();
            switch (*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push2(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n", exp, pop2());
}

void push2(int x)
{
    stack[++top] = x;
}

int pop2()
{
    return stack[top--];
}