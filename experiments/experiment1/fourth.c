#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    int arr[r][c];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
            sum += arr[i][j];
        printf("Row %d Sum = %d\n", i + 1, sum);
    }

    for (int j = 0; j < c; j++)
    {
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += arr[i][j];
        printf("Column %d Sum = %d\n", j + 1, sum);
    }

    return 0;
}
