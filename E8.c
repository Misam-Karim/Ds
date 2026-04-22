#include<stdio.h>
#include<stdlib.h>
/*Coder: Zain Mohamed Saeed Kazi
UIN: 251P040*/

struct node
{
    int data;
    struct node *next;
       
};
struct node *top=NULL;
void push()
{
    struct node*newnode;
    int value ;

    newnode=(struct node*)malloc(sizeof(struct node));
    
    if (newnode==NULL)
    {
        printf("\nStack overflow");
        return;
    }

    printf("\nenter value to push ");
    scanf("%d",&value);

    newnode->data=value;
    newnode->next=top;
    top=newnode;

    printf("\nelement inserted !!");

}

void pop()
{
    struct node*temp;
    if (top==NULL)
    {
        printf("\nstack underflow ");
        return;

    }
    temp=top;  
    top=top->next;
    printf("\npopped element:%d",temp->data);
    free(temp);
}

void display()
{
    struct node* temp = top;

    if (temp == NULL)
    {
        printf("\nstack underflow ");
        return;
    }

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    int choice;
    printf("Coder: Zain Mohamed Saeed Kazi\n");

    while(1)
    {
        printf("\n--- Stack using Linked List Menu ---\n");
        printf("1 Push\n");
        printf("2 Pop\n");
        printf("3 Display\n");
        printf("4 Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default: 
            printf("Invalid choice\n");
        }
    }return 0;
}
