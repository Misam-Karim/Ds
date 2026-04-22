/*Name: Zain Mohamed Saeed Kazi
UIN: 251P040
Roll No: 37*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void push(int value);
void pop();
void display();
void peek();

int stack[SIZE];
int top = -1;

int main()
{
    int value , choice;
    
    while(1)
    {
        printf("\n**** Stack Menu ****\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            push(value);
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("\nInvalid Choice!!\nSelect Again\n");

        }
    
    }
    return 0;
}

void push(int value)
{
    if(top == SIZE -1){
        printf("\nThe Stcak is already full!!\n");
    }
    else{
        top++;
        stack[top]= value;
        printf("\n Insertion is Successful");
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack is already empty!!\n");
    }
    else{
        printf("\nDeleted Element:%d", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("\nStack is Empty!!");
    }
    else
    {
        printf("\nStack Elements are:\n");
        for(i=top; i >=0; i--){
            printf("%d ", stack[i]);
        }
    }
}
