#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r1, c1, r2, c2;
    scanf("%d %d", &r1, &c1);
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
        return 0;

    int *a = malloc(r1 * c1 * sizeof(int));
    int *b = malloc(r2 * c2 * sizeof(int));
    int *c = malloc(r1 * c2 * sizeof(int));

    for (int i = 0; i < r1 * c1; i++)
        scanf("%d", a + i);

    for (int i = 0; i < r2 * c2; i++)
        scanf("%d", b + i);

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            *(c + i * c2 + j) = 0;
            for (int k = 0; k < c1; k++)
                *(c + i * c2 + j) += (*(a + i * c1 + k)) * (*(b + k * c2 + j));
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%d ", *(c + i * c2 + j));
        printf("\n");
    }

    free(a);
    free(b);
    free(c);
    return 0;
}
