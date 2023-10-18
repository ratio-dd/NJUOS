/* 实现简单的计算器 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 1000
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full!");
    }
}

double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty!");
        return 0.0;
    }
}

/*------------*/
char buf[BUFSIZE];
int bufp = 0; /* next avilable space in buf*/

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: Too many characters.\n");
    } else {
        buf[bufp++] = c;
    }
}

/*------------*/
double getop(char s[]) {
    int i, c;
    while ((s[0]= c = getch()) ==  ' ' || c=='\t')
    {;}
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        return c;
    }
    i = 0;
    if(isdigit(c)){
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}

int main() {
    int type;
    double op2;
    char s[MAXOP];
    if ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: devisor can't be 0");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;

            default:
                printf("error: Unknow command");
                break;
        }
    }
}