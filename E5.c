/*Name: Tariq Bhatkar Khalil
UIN : 251P032
Roll No : 31*/
#include <stdio.h>
#include <stdlib.h>

#define size 10

void enqueue();
void delqueue();
void display();

int queue[size] , front = -1 , rear = -1;

void main()
{
    int value , choice;
    printf("\n\nCoder : Tariq Bhatkar Khalil\n");

    while(1)
    {
        printf("\n----MENU----\n\n");

        printf("1.Enter new element\n2.Delete element\n3.Display queue\n4.Exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(value);
            break;

            case 2:
            delqueue(value);
            break;

            case 3:
            display();
            break;

            case 4:
            printf("Thank you for using the program\n");
            exit(0);

            default:
            printf("Invalie option selected!!\n");
            printf("Choose again\n");

        }
    }
}

void enqueue(int n)
{
    if (rear == size - 1)
    {
        printf("The Queue is already full!!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = n;
        printf("Insertion was succesful\n");

    }
}

void delqueue(int n)
{
    if (front > rear || (front == -1 && rear == -1))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The deleted value is: %d\n", queue[front]);
        front++;

        if(front > rear)
        {
            front= rear = -1;
        }
    }
}

void display()
{
    if (front > rear|| (front == -1 && rear == -1))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i = front; i <= rear ; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
