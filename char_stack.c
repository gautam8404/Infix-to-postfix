#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char data;
    struct Node * next;
} stack;



void push(char x, stack **top){
    stack *t;
    t = (stack *)malloc(sizeof(stack));
    if (t == NULL){
        printf("Stack Overflow");
        return;
    }
    else{
        t->data = x;
        t->next = (*top);
        (*top) = t;
    }
}

char pop(stack **top){
    stack *t;
    int x =-1;
    if (*top == NULL){
        printf("stack is empty\n");
    }
    else {
        t = (*top);
        (*top) = (*top)->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display(stack **top){
    stack *t;
    t = *top;
    while (t!=NULL)
    {
        printf("%c\n",t->data);
        t = t->next;
    }
    
}

void graphical_stack(stack **top){
    stack *t;
    t = (*top);
    while (t!=NULL)
    {
        printf("|%d|----->",t->data);
        t = t->next;
        if (t->next == NULL)
        {
            printf("|%d|\n",t->data);
            break;
        }
        
    }
        
}

char peek(stack **top,int pos){
    stack *t = (*top);
    if ((*top) == NULL){
        printf("stack is empty\n");
    }
    for (int i = 0; i < pos-1 && t != NULL; i++)
    {
        t = t->next;
    }
    if (t != NULL){
        return t->data;
    }
    else {
        return -1;
    }
}

int isEmpty(stack **top){
    if (*top == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

char stacktop(stack **top){
    if (*top == NULL){
        printf("stack is empty\n");
    }
    else { 
    return (*top)->data;
    }
}

void remove_element(stack **top, char x){
    stack *t=(*top);
    stack *s;
    if (isEmpty(&(*top)))
    {
        printf("stack is empty");
    }
    else { 
        if(t->data == x && t!= NULL) {
                (*top) = t->next;
                free(t);
                return;
        }
        while (t != NULL && t->data != x)
        {
            s = t;
            t = t->next;
        }
        if (t == NULL) {
            return;
        }
        s->next = t->next;
        free(t);
    }
}




