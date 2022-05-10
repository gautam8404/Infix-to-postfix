#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "char_stack.c"
#define MAX 100

    int check_parenthesis(char brackets[]){
    stack *br = NULL;
    
    int i = 0;
    while (i < strlen(brackets))
    {
        if (brackets[i] == '[' || brackets[i] == '{' || brackets[i] == '(' || brackets[i] == '<'){
            push(brackets[i],&br);

        }
        else if (brackets[i] == ']' || brackets[i] == '}' || brackets[i] == ')' || brackets[i] == '>')
        {   
            if (isEmpty(&br) == 1)
                {
                    printf("parenthesis are not balanced\n"); 
                    return 1;
                }
            if (stacktop(&br) == brackets[i] - 1 || stacktop(&br) == brackets[i] - 2)
            {                   
                char a = pop(&br);
                // printf("match found for %c and %c\n",a,brackets[i]);
            }
            
        }
        
        
        i++;
    }


    if (isEmpty(&br)){
        printf("parenthesis are balanced\n");
        return 0;
    }
    else {
        printf("parenthesis are not balanced\n");
        return 1;
    }

    

    return 0;
}