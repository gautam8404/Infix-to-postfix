#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node_int{
    int data;
    struct Node_int * next;
} stackint;



void int_push(int x, stackint **top){
    stackint *t;
    t = (stackint *)malloc(sizeof(stackint));
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

int int_pop(stackint **top){
    stackint *t;
    int x =-1;
    if (*top == NULL){
        printf("stack is empty");
    }
    else {
        t = (*top);
        (*top) = (*top)->next;
        x = t->data;
        free(t);
    }
    return x;
}

void int_display(stackint **top){
    stackint *t;
    t = *top;
    while (t!=NULL)
    {
        printf("%c\n",t->data);
        t = t->next;
    }
    
}

void int_graphical_stack(stackint **top){
    stackint *t;
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

int int_peek(stackint **top,int pos){
    stackint *t = (*top);
    if ((*top) == NULL){
        printf("stack is empty");
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

int int_isEmpty(stackint **top){
    if (*top == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

int int_stacktop(stackint **top){
    if (*top == NULL){
        printf("stack is empty");
    }
    else { 
    return (*top)->data;
    }
}

void int_remove_element(stackint **top, int x){
    stackint *t=(*top);
    stackint *s;
    if (int_isEmpty(&(*top)))
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