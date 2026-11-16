#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, col;
    double **a, max, tmp;

    printf("Введите N и M: ");
    if (scanf("%d %d", &n, &m) != 2) { printf("Ошибка ввода\n"); return 1; }

    // printf("n=%d m=%d\n", n, m);

    if (n < 3 || m < 3)
    {
        printf("Размеры должны быть >= 3\n");
        return 1;
    }

    a = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++)
        a[i] = (double*)malloc(m*sizeof(double));

    printf("Элементы:\n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (scanf("%lf", &a[i][j]) != 1)
            {
                printf("Ошибка ввода элемента\n");
                for (i=0; i<n; i++) free(a[i]);
                free(a); return 1;
            }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) printf("%6.2f ", a[i][j]);
        printf("\n");
    }

    for (i = 0; i < n && i < m; i++)
        if (a[i][i] < 0) a[i][i] = -a[i][i];

    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) printf("%6.2f ", a[i][j]);
        printf("\n");
    }

    col = -1;
    max = 0;
    for (j = 0; j < m; j++)
        if (a[1][j] >= -1.2 && a[1][j] <= 4.7)
            if (col == -1 || a[1][j] > max)
            {
                max = a[1][j];
                col = j;
            }

    if (col == -1)
        printf("Нет подходящих элементов\n");
    else
    {
        printf("Максимум: %.2f (столбец %d)\n", max, col+1);

        tmp = a[1][col];
        a[1][col] = a[2][2];
        a[2][2] = tmp;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) printf("%6.2f ", a[i][j]);
            printf("\n");
        }
    }

    for (i = 0; i < n; i++) free(a[i]);
    free(a);
    return 0;
}
