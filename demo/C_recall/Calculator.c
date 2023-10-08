#include <stdio.h>
#include <stdlib.h>

#define MAXOP 1000
#define NUMBER '0'
#define MAXVAL 100

int main(){
    int type;
    double op2;
    char s[MAXOP];
    if((type = getop(s))!=EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break;
        case '-':
            op2 = pop();
            push(pop()-op2);
            break;
        case '*':
            push(pop()*pop());
            break;
        case '/':
            op2 = pop();
            if (op2!=0.0)
            {
                push(pop()/op2);
            }else{
                printf("error: devisor can't be 0");
            }
            break;
        case '\n':
            printf("\t%.8g\n",pop());
            break;
        
        default:
            printf("error: Unknow command");
            break;
        }
    }
}

int sp = 0;
double val[MAXVAL];

double pop(void){

}
void push(double){

}
double getop(char[]){

}