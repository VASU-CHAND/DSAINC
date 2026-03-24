#include <stdio.h>

int main()
{
    int a[100], n, i, pos, elem, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter element to insert: ");
    scanf("%d", &elem);
    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    for(i = n - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = elem;
    n++;
    printf("Array after insertion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &j);
    for(i = j - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    printf("Array after deletion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
