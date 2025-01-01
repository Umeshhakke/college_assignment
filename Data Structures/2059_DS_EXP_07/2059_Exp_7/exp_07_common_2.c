/*
Implement infix to prefix
Name: Umesh Hakke
Roll No: 2059
S.Y (A)
Batch S4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char push(char operator1[], int *top, char infix[], int i);
int operatorPrecedence(char a);
void reverse(char *str);
void infixToPrefix(char *infix, char *prefix);

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}

void infixToPrefix(char *infix, char *prefix) {
    int top = -1;
    char operator1[MAX];
    reverse(infix);
    int length = strlen(infix);
    int k = 0;

    for (int i = 0; i < length; i++) {
        if (isalnum(infix[i])) {
            prefix[k++] = infix[i];
        } else if (infix[i] == ')') {
            operator1[++top] = infix[i];
        } else if (infix[i] == '(') {
            while (top != -1 && operator1[top] != ')') {
                prefix[k++] = operator1[top--];
            }
            top--; 
        } else {
            while (top != -1 && operatorPrecedence(operator1[top]) >= operatorPrecedence(infix[i])) {
                prefix[k++] = operator1[top--];
            }
            operator1[++top] = infix[i];
        }
    }

    while (top != -1) {
        prefix[k++] = operator1[top--];
    }

    prefix[k] = '\0';
    reverse(prefix);
}

char push(char operator1[], int *top, char infix[], int i) {
    if (*top == MAX - 1) {
        return 'f';
    }
    operator1[++(*top)] = infix[i];
    return 't';
}

int operatorPrecedence(char a) {
    if (a == '*' || a == '/') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

void reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

