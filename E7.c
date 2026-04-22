#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;  //Variable to store data
    struct node *next; //Pointer to store address of next node
};

struct node *head = NULL;  //Sets head pointer to NULL

void insert_begin()
{
    struct node *newnode;
    int item;

    newnode = (struct node*) malloc(sizeof(struct node));

    if (newnode==NULL)
    {
        printf("\nMemory Overflow");
        return;
    }
    
    printf("\nEnter Value: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = head;

    head = newnode;

    printf("\nNode inserted at beginning\n");
}

void insert_end()
{
    struct node *newnode, *temp;
    int item;
    newnode = (struct node*) malloc(sizeof(struct node));
    
    if (newnode==NULL)
    {
        printf("\nMemory Overflow");
        return;
    }

    printf("\nEnter the Value: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = NULL;
    
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next= newnode;
    }
    printf("\nInserted at the End");
}

void insert_position()
{
    struct node *newnode, *temp;
    int item;

    int pos, i;

    newnode = (struct node*) malloc(sizeof(struct node));

    if (newnode==NULL)
    {
        printf("\nMemory Overflow");
        return;
    }

    printf("\nEnter Position:");
    scanf("%d", &pos);

    printf("\nEnter Item: ");
    scanf("%d", &item);

    newnode->data = item;

    if(pos == 1)  //Deletable Code
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;

            if(temp==NULL)
            {
                printf("\nInvalid Position");
                return;
            }
        }
    }

    newnode->next = temp -> next;
    temp->next = newnode;

    printf("\nNode inserted at position\n");

}

void delete_begin()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("\nList is Empty");
        return;
    }

    temp = head;
    head = head ->next;

    free(temp);

    printf("\nNode deleted from Beginning");
}

void delete_end()
{
    struct node *temp,*prev;

    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }

    else
    {
        temp=head;

        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }

        prev->next=NULL;
        free(temp);
    }

    printf("Node deleted from End\n");
}

void delete_pos()
{
    struct node *temp,*nextnode;
    int pos,i;

    printf("Enter position: ");
    scanf("%d",&pos);

    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }

    temp=head;

    if(pos==1)
    {
        head=temp->next;
        free(temp);
    }
    else
    {
        for(i =1;i<pos-1; i++)
        {
            temp=temp->next;
        }

        nextnode=temp->next;
        temp->next=nextnode->next;

        free(nextnode);
    }

    printf("Node deleted from Position\n");
}

void display()
{
    struct node *temp;

    if(head==NULL)
    {
        printf("List empty\n");
    }
    else
    {
        temp=head;

        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }

        printf("NULL\n");
    }
}



int main()
{
    int value , choice;
    
    printf("Coder: Zain Mohamed Saeed Kazi");
    printf("\nUIN: 251P040");
    while(1)
    {
        printf("\n**** Linked List Menu ****\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            insert_begin();
            break;

            case 2:
            insert_end();
            break;

            case 3:
            insert_position();
            break;

            case 4:
            delete_begin();
            break;

            case 5:
            delete_end();
            break;

            case 6:
            delete_pos();
            break;

            case 7:
            display();
            break;

            case 8:
            exit(0);

            default:
            printf("\nInvalid Choice!!\nSelect Again\n");

        }
    
    }
    return 0;
}
