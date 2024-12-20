#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char s[SIZE];
int top = -1;

void push(char elem) {
    s[++top] = elem;
}

char pop() {
    return s[top--];
}

int pr(char elem) {
    switch (elem) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 4;
    }
   
}

int main() {
    char infix[50], pofix[50], ch, elem;
    int i = 0, k = 0;

    printf("\n\nRead the Infix Expression ? ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            pofix[k++] = ch;
        else if (ch == ')') {
            while (s[top] != '(')
                pofix[k++] = pop();
            elem = pop();
        } else {
            while (pr(s[top]) >= pr(ch))
                pofix[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        pofix[k++] = pop();
    pofix[k] = '\0';

    printf("\n\nGiven Infix Expn: %s \n Postfix Expn: %s\n", infix, pofix);

    
}
