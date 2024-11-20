#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

int stack[MAX];
char post[MAX];
int top = -1;

void pushstack(int tmp);
void calculator(char c);

int main() {
    int i;
    printf("Insert a postfix notation: ");
    scanf("%s", post);

    for (i = 0; i < strlen(post); i++) {
        if (post[i] >= '0' && post[i] <= '9') {
            pushstack(i);
        }
        if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^') {
            calculator(post[i]);
        }
    }

    printf("\n\nResult: %d\n", stack[top]);
   
}

void pushstack(int tmp) {
    top++;
    stack[top] = (int)(post[tmp] - '0');
}

void calculator(char c) {
    int a, b, ans;
    a = stack[top];
    stack[top] = '\0';
    top--;
    b = stack[top];
    stack[top] = '\0';
    top--;

    switch (c) {
        case '+': ans = b + a; break;
        case '-': ans = b - a; break;
        case '*': ans = b * a; break;
        case '/': ans = b / a; break;
        case '^': ans = pow(b, a); break;
        default: ans = 0; break;
    }

    top++;
    stack[top] = ans;
}