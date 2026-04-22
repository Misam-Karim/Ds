#include <stdio.h>
#include <stdlib.h>
// Coder: Zain Mohamed Saeed Kazi
// UIN: 251P040
struct node
{
    int data;//stores values
    struct node *next;//stores address
};

struct node *last = NULL;//making last to null

// Insert at Beginning
void insert_begin(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    newnode->data = value;

    if(last == NULL)
    {
        last = newnode;
        last->next = last;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }
}

// Insert at End
void insert_end(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    newnode->data = value;

    if(last == NULL)
    {
        last = newnode;
        last->next = last;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
}

// Delete from Beginning
void delete_begin()
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = last->next;

    if(last->next == last)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete from End
void delete_end()
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = last->next;

    
    if(temp == last)
    {
        printf("Deleted: %d\n", last->data);
        free(last);//deleting the last node
        last = NULL;
        return;
    }

    
    while(temp->next != last)
    {
        temp = temp->next;
    }

    printf("Deleted: %d\n", last->data);

    temp->next = last->next;
    free(last);
    last = temp;
}

// Display
void display()
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = last->next;

    printf("Circular List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != last->next);

    printf("(back to head: %d)\n", last->next->data);//for getting the output with last input
}

// Main Function
int main()
{
    int choice, value;
    printf("Coder: Zain Mohamed Saeed Kazi\n");
    printf("UIN: 251P040\n");
    while(1)
    {
        printf("\n--- Circular Linked List (ADT) ---\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Delete Beginning\n");
        printf("4. Delete End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                delete_begin();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
