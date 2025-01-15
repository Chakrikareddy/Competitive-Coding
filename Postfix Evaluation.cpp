#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

void initstack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;  
    }
    return s->items[(s->top)--];  
}

int evaluatePostfix(char* expression) {
    struct Stack s;
    initstack(&s);  

    for (int i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];

        if (isdigit(token)) {
            push(&s, token - '0');
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

            switch (token) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default:
                    printf("Invalid operator: %c\n", token);
                    return -1;
            }
            push(&s, result);  
           } else {
                printf("Invalid character in expression: %c\n", token);
                return -1;
           }
        }
        return pop(&s);
        }
        int main() {
        char expression[] = "53+12-*";  // Postfix expression
        int result = evaluatePostfix(expression);
        if (result != -1) {
        printf("Result of postfix expression '%s' is: %d\n", expression, result);
        }
        return 0;
      }
