#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

typedef struct Node Node;


// Stack functions
void push(int elem);
int pop();
int peek();
int isEmpty();

// Helper functions
int isNumber(int num);
int isOperator(char ch);

// Main logic function
int evalPostfix(char *exp);


int main() {
    char *postfixExp;

    printf("Enter postfix expression : ");
    scanf("%s", postfixExp);

    printf("Evaluation of expression : %d \n", evalPostfix(postfixExp));

    return 0;
}


void push(int elem) {
    if (top == NULL) {
        top = malloc(sizeof(Node));
        top->data = elem;
        top->next = NULL;
        return;
    }

    Node *t = malloc(sizeof(Node));
    t->data = elem;
    t->next = top;

    top = t;
}

int pop() {
    if (top == NULL)
        return -1;

    Node *t = top;
    top = top->next;

    int elem = t->data;
    free(t);

    return elem;
}

int peek() {
    if (top->data)
        return top->data;
    else 
        return -1;
}

int isEmpty() {
    if (top == NULL)
        return 1;
    else 
        return 0;
}

int isNumber(int num) {
    if (num >= 0 && num <= 9)
        return 1;
    return 0;
}

int isOperator(char ch) {
    switch(ch) {
        case '+': 
        case '-': 
        case '*': 
        case '/': 
        case '%': 
        case '^': return 1;
    }
    return 0;
}

int eval(int num1, int num2, char op) {
    switch(op) {
        case '+': return num2 + num1;
        case '-': return num2 - num1;
        case '*': return num2 * num1;
        case '/': return num2 / num1;
        case '%': return num2 % num1;
        case '^': return num2 ^ num1;
    }
    return -1;
}

int evalPostfix(char *exp) {
    int num1, num2, res;
    char ch;

    int i;
    for (i=0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if (isNumber(atoi(&ch)) && !isOperator(ch))
            push(atoi(&ch));

        else if (isOperator(ch)) {
            if (isEmpty())
                return 404;

            num1 = pop();
            num2 = pop();

            if (!num1 || !num2)
                return 404;

            res = eval(num1, num2, ch);
            push(res);  
        }
    }

    res = pop();
    return res;
}