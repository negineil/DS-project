#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int *size, int pos, int value) {
   if (pos < 0 || pos > *size) {
       printf("Invalid position\n");
       return;
   }

   for (int i = *size; i >= pos; i--) {
       arr[i] = arr[i - 1];
   }

   arr[pos] = value;
   (*size)++;
}

void delete(int arr[], int *size, int pos) {
   if (pos < 0 || pos >= *size) {
       printf("Invalid position\n");
       return;
   }

   for (int i = pos; i < *size - 1; i++) {
       arr[i] = arr[i + 1];
   }

   (*size)--;
}

int main() {
   int arr[MAX_SIZE];
   int size, choice, pos, value;

   printf("Enter the size of the array: ");
   scanf("%d", &size);

   printf("Enter the elements of the array:\n");
   for (int i = 0; i < size; i++) {
       scanf("%d", &arr[i]);
   }

   do {
       printf("\nChoose an operation:\n");
       printf("1. Insert an element\n");
       printf("2. Delete an element\n");
       printf("3. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               printf("Enter the position to insert: ");
               scanf("%d", &pos);
               printf("Enter the value to insert: ");
               scanf("%d", &value);
               insert(arr, &size, pos - 1, value);
               break;
           case 2:
               printf("Enter the position to delete: ");
               scanf("%d", &pos);
               delete(arr, &size, pos - 1);
               break;
           case 3:
               break;
           default:
               printf("Invalid choice\n");
       }

       printf("Array: ");
       for (int i = 0; i < size; i++) {
           printf("%d ", arr[i]);
       }
       printf("\n");
   } while (choice != 3);

   return 0;
}