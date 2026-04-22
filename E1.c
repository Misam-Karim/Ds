/*Name: Zain Mohamed Saeed Kazi
UIN: 251P040
Roll No: 37*/
#include <stdio.h>
int size = 5;
void Display(int arr[])
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void Insertion(int value, int index, int arr[])
{
    if (index < 0 || index > size || size >= 10)
    {
        printf("Invalid index or array full\n");
        return;
    }
    for (int i = size; i > index; i--)
        arr[i] = arr[i - 1];
    arr[index] = value;
    size++;
    printf("Value inserted successfully\n");
}
void Deletion(int index, int arr[])
{
    if (index < 0 || index >= size)
    {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    printf("Value deleted successfully\n");
}
int main()
{
    int arr[10], choice, val, index;
    for (int i = 0; i < size; i++)
    {
        printf("Enter value at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("\nMenu\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value and index: ");
            scanf("%d %d", &val, &index);
            Insertion(val, index, arr);
            break;
        case 2:
            printf("Enter index to delete: ");
            scanf("%d", &index);
            Deletion(index, arr);
            break;
        case 3:
            Display(arr);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
