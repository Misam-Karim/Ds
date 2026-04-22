/*Name: Zain Mohamed Saeed Kazi
UIN: 251P040
Roll No: 37*/
#include<stdio.h>   
#include<ctype.h> 
#include<math.h> 

int stack[50];
int top = -1;

void push(int x)
{
    stack[++top] = x; 
}

int pop()
{
    if(top == - 1)
    {
        return -1;
    }
    else
    {
        return stack[top--]; 
    }
}

int main()
{
    
    printf("Coder: Zain Mohamed Saeed Kazi\n\n");
    char exp[50]; 
    int i = 0, op1,op2, result;

    printf("Enter the infix expression: ");
    scanf("%s", &exp); 

    while(exp[i] != '\0') 
    {
        if (isdigit(exp[i])) 
        {
            push(exp[i] - '0'); 
        }
        else
        {
                op1 = pop();

                op2 = pop();

                switch (exp[i])
                {
                case '+':
                    push(op2 + op1);
                    break;

                case '-':
                    push(op2 - op1);
                    break;

                case '*':
                    push(op2 * op1);
                    break;
                
                case '/':
                    push(op2/op1);
                    break;
                
                case '^':
                    push(pow(op2,op1));
                
                default:
                    break;
                }
            }
            i++; 
        

         
        
    }

    result = pop();
    printf("\nThe result of the postfix expression %s = %d\n",exp,result);



    return 0;
}
