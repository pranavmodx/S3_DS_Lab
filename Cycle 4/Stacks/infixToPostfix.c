#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char ch;
    struct Node *next;
} *top = NULL;

typedef struct Node Node;


// Stack functions
void push(char ch);
char pop();
char peek();
int isEmpty();

// Helper functions
int inPrec(char ch);
int outPrec(char ch);
int isOperator(char ch);
int isOperand(char ch);

// Main logic function
void infixToPostfix(char *infixExp, char *postfixExp);


int main() {
    char *infixExp;
    char postfixExp[100] = "";

    printf("Enter an infix expression : ");
    scanf("%s", infixExp);

    infixToPostfix(infixExp, postfixExp);
    printf("Postfix expression : %s \n", postfixExp);

    return 0;
}

void push(char ch) {
    if (top == NULL) {
        top = malloc(sizeof(Node));
        top->ch = ch;
        top->next = NULL;
        return;
    }

    Node *t = malloc(sizeof(Node));
    t->ch = ch;
    t->next = top;

    top = t;
}

char pop() {
    if (top == NULL)
        return -1;

    Node *t = top;
    top = top->next;

    char ch = t->ch;
    free(t);

    return ch;
}

char peek() {
    if (top->ch)
        return top->ch;
    else 
        return '~';
}

int isEmpty() {
    if (top == NULL)
        return 1;
    else 
        return 0;
}

int inPrec(char ch) {
    switch(ch) {
        case '(': return 0;
        case '+': 
        case '-': return 2;
        case '*': 
        case '/': 
        case '%': return 4;
        case '^': return 6;
    }
    return -1;
}

int outPrec(char ch) {
    switch(ch) {
        case '(': return 100;
        case '+': 
        case '-': return 1;
        case '*': 
        case '/': 
        case '%': return 3;
        case '^': return 5;
    }
    return -1;
}

int isOperator(char ch) {
    switch(ch) {
        case '+': 
        case '-': 
        case '*': 
        case '/': 
        case '%': 
        case '^': 
        case '(': return 1;
    }
    return 0;
}

int isOperand(char ch) {
    if ((ch >= 65 && ch <=90) || (ch >= 97 && ch <= 122)) 
        return 1;
    return 0;
}

void infixToPostfix(char *infixExp, char *postfixExp) {
    int i;
    char ch;

    for (i=0; infixExp[i] != '\0'; i++) {
        if (isOperand(infixExp[i]))
            strncat(postfixExp, &infixExp[i], 1);

        else if (isOperator(infixExp[i])) {
            if (isEmpty() || outPrec(infixExp[i]) > inPrec(peek()))
                push(infixExp[i]);

            else {
                while (!isEmpty() && outPrec(infixExp[i]) < inPrec(peek())) {
                    ch = pop();
                    strncat(postfixExp, &ch, 1);
                }
                push(infixExp[i]);
            }
        }
         
        else if (infixExp[i] == ')') {
            while (peek() != '(') {
                ch = pop();

                if (isEmpty()) {
                    strcpy(postfixExp, "Invalid expression");
                    return;
                }
                strncat(postfixExp, &ch, 1);
            }
            
            pop();
        }
    }

    while (!isEmpty()) {
        if (peek() == '(') { 
            strcpy(postfixExp, "Invalid expression");
            return;
        }

        ch = pop();
        strncat(postfixExp, &ch, 1);
    }
}
