#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "int_stack.c"
#include "check_parenthesis.c"
#include <math.h>
#define MAX_LIM 200

    int in_prec(char x){
        if (x == '+' || x == '-') return 2;
        else if (x == '*' || x == '/') return 4;
        else if (x == '^') return 5;
        else if (x == '(') return 0;
        else return -1;
    }

    int out_prec(char x){
        if (x == '+' || x == '-') return 1;
        else if (x == '*' || x == '/' || x == '%') return 3;
        else if (x == '^') return 6;
        else if (x == '(') return 7;
        else if (x == ')') return 0;
        else return -1;
    } 


    int isOperand(char x){
        if (isalnum(x)) return 1;
        else return 0;
    }

    int isOperator(char x){
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^'){
            return 1;
        }
        else return 0;
    }

    int main(){
    stack *st;
    char str[MAX_LIM];
    printf("enter infix equation: ");
    scanf("%[^\n]s",str);
    printf("checking parenthesis...\n");
    if (check_parenthesis(str))
    {
        goto end;
    }
    

    char postfix[100];
    char s;
    bool alphabet_present = false;
    // printf("CHECK    %d\n",check_precedence(' '));

    int i = 0;
    int j = 0;
    while (i < strlen(str))
    {   

        if (isOperand(str[i])) {
            if (isalpha(str[i])) alphabet_present = true;
            postfix[j] = str[i];
            j = j+1;
        }
        if (out_prec(str[i]) == -1) {
            i = i+1; 
            continue;
        }
 
        else if (isEmpty(&st) || out_prec(str[i]) > in_prec(stacktop(&st))){
            push(str[i],&st);
            printf("pushed %c\n",str[i]);
        }
        else {
            while (out_prec(str[i]) <= in_prec(stacktop(&st)))
            {   
                if (isEmpty(&st)) break;
                if (out_prec(str[i]) == in_prec(stacktop(&st))) {
                    pop(&st);
                }
                else { 
                s = pop(&st);
                postfix[j] = s;
                j = j+1;
                printf("popped %c\n",s);
                }
            }
                if (out_prec(str[i]) != 0){ 
                push(str[i],&st); 
                printf("pushed %c\n",str[i]);
                }
            
        }
        i = i+1;
    }

    while (isEmpty(&st) == 0) {
        s = pop(&st); 
        postfix[j] = s;
        j = j +1;
        printf("popped %c\n",s);

    }


    printf("infix expression: %s \npostfix expression: %s\n",str,postfix);
    stackint *in;
    int k;
    if (!(alphabet_present)){ 
        for (i = 0; i < strlen(postfix); i++)
        {
            if (isdigit(postfix[i])){
                k = postfix[i] - '0';
                int_push(k,&in);
                printf("%d\n",k);
                
            }
            else {
                int r;
                int x = int_pop(&in);
                int y = int_pop(&in);
                switch (postfix[i])
                {
                case '+':
                    r = x + y;
                    int_push(r,&in);
                    break;
                case '-':
                    r = x - y;
                    int_push(r,&in);
                    break;
                case '*':
                    r = x * y;
                    int_push(r,&in);
                    break;
                case '/':
                    r = x/y;
                    int_push(r,&in);
                    break;
                case '^':
                    r = (int)(pow(((double)(x)),((double)(y))));
                    int_push(r,&in);
                    break;
                default:
                    printf("operator isn't supported\n");
                    break;
                }
            }
        }
        printf("evaluation of postfix expression: %d\n",int_stacktop(&in));
    }
    else {
        printf("can't evaluate alphabetic expressions\n");
    }
    



    end:

    return 0;
}