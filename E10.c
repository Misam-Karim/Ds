#include <stdio.h>
#include <stdlib.h>

//Coder: Zain Mohamed Saeed Kazi
//UIN: 251P040
struct node {
    int data;
    struct node *left, *right;
};

// Create new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search node
void search(struct node* root, int key) {
    if (root == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (key == root->data) {
        printf("Element found.\n");
        return;
    }
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Find minimum (used in delete)
struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        printf("Tree is empty or element not found.\n");
        return root;
    }

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: Leaf node
        if (root->left == NULL && root->right == NULL) {
            free(root);
            printf("Leaf node deleted.\n");
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            printf("Node with one child deleted.\n");
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            printf("Node with one child deleted.\n");
            return temp;
        }

        // Case 3: Two children
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        printf("Node with two children deleted.\n");
    }
    return root;
}

// In-order traversal
void inorder(struct node* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    struct node* root = NULL;
    int choice, value;

    printf("Coder: Zain Mohamed Saeed Kazi\n");
    printf("UIN: 251P040");

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display (In-order)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Enter value to delete: ");
                    scanf("%d", &value);
                    root = deleteNode(root, value);
                }
                break;

            case 4:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
