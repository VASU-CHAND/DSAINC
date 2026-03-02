#include <stdio.h>

int main()
{ printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    int arr[n];
   printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
  printf("Enter the element to search: ");
    int key, found = 0;
    scanf("%d", &key);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at position %d", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found");

    return 0;
}
