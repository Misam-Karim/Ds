#include <stdio.h>
#include <stdlib.h>

/*Coder: Zain Mohamed Saeed Kazi
UIN: 251P040*/
struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    int value;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &value);

    if (newnode == NULL) {
        printf("\nOverflow");
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d Inserted Successfully", value);
}

void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("\nUnderflow");
        return;
    }

    temp = front;
    printf("%d Deleted Successfully", front->data);
    
    front = front->next;
    
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
}

void display() {
    struct node *temp;

    if (front == NULL) {
        printf("\nQueue is Empty");
        return;
    }

    temp = front;

    printf("\nQueue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    int choice, value;
    
    printf("Coder: Zain Mohamed Saeed Kazi\n");
    printf("UIN: 251P040");

    while (1) {
        printf("\n\n--- Queue Menu ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit Successful");
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}
