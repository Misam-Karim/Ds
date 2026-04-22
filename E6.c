#include <stdio.h>
#include <stdlib.h>

#define size 3

void enQueue();
void deQueue();
void display();

int cQueue[size] , front = -1, rear = -1;

void main()
{
    int value , choice;
    printf("\n\nCoder: Zain Mohamed Saeed Kazi\n");

    while(1)
    {
        printf("\n----MENU----\n\n");

        printf("1.Enter new element\n");
        printf("2.Delete element\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted:");
            scanf("%d",&value);
            enQueue(value);
            break;

            case 2:
            deQueue();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("Thank you for using the program\n");
            exit(0);

            default:
            printf("Invalid option selected!!\nChoose again\n");
        }
    }
}

void enQueue(int n)
{
    if ((rear == size -1&&front==0)||(front == rear + 1))
    {
        printf("The Queue is already full!!\n");
    }
    else
    {
        if (rear == size -1 && front != 0)
        {
            rear = -1;
        }
        rear++;
        cQueue[rear] = n;
        
        if(front == -1)
        {
            front = 0;
        }
        printf("Insertion was successful!!\n");
    }
}

void deQueue()
{
    if (front == -1)
    {
        printf("The Queue is already empty!!\n");
    }
    else
    {
        printf("The deleted value is: %d\n", cQueue[front]);

        if (front == rear)
        {
            front = rear = -1;  // Queue becomes empty
        }
        else
        {
            front = (front + 1) % size;  // Circular increment
        }
    }
}

void display()
{
    if ((front == -1))
    {
        printf("The Queue is already empty!!\n");
    }
    else
    {
        if(front >rear)
        {
            for (int i = front; i<=size -1; i++)
            {
                printf("%d ", cQueue[i]);
            }
            for (int i = 0; i<=rear; i++)
            {
                printf("%d ", cQueue[i]);
            }
        }
        else
        {
            for (int i = front; i<=rear; i++)
            {
                printf("%d ", cQueue[i]);
            }
        }
    }
}
