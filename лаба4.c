#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int *a, int n)
{
    int i, j, t;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

void insert(int *a, int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void merge(int *a, int *tmp, int l, int m, int r)
{
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r)
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];

    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];

    for (i = l; i <= r; i++)
        a[i] = tmp[i];
}

void merge_sort(int *a, int *tmp, int l, int r)
{
    int m;

    if (l < r)
    {
        m = (l + r) / 2;
        merge_sort(a, tmp, l, m);
        merge_sort(a, tmp, m + 1, r);
        merge(a, tmp, l, m, r);
    }
}

int main()
{
    int sizes[4] = {10, 1000, 10000, 100000};
    double tb[4], ti[4], tm[4];
    int *base, *a, *tmp;
    clock_t st, en;
    int s, i;

    srand(time(NULL));

    for (s = 0; s < 4; s++)
    {
        base = (int*)malloc(sizes[s] * sizeof(int));
        a = (int*)malloc(sizes[s] * sizeof(int));
        tmp = (int*)malloc(sizes[s] * sizeof(int));

        for (i = 0; i < sizes[s]; i++)
            base[i] = rand() % 100000;

        for (i = 0; i < sizes[s]; i++) a[i] = base[i];
        st = clock();
        bubble(a, sizes[s]);
        en = clock();
        tb[s] = (double)(en - st) / CLOCKS_PER_SEC;

        for (i = 0; i < sizes[s]; i++) a[i] = base[i];
        st = clock();
        insert(a, sizes[s]);
        en = clock();
        ti[s] = (double)(en - st) / CLOCKS_PER_SEC;

        for (i = 0; i < sizes[s]; i++) a[i] = base[i];
        st = clock();
        merge_sort(a, tmp, 0, sizes[s] - 1);
        en = clock();
        tm[s] = (double)(en - st) / CLOCKS_PER_SEC;

        printf("Размер %d готов\n", sizes[s]);

        free(base);
        free(a);
        free(tmp);
    }

    printf("\n%-12s %10s %10s %10s %10s\n", "Алгоритм", "10", "1000", "10000", "100000");
    printf("%-12s %10.4f %10.4f %10.4f %10.4f\n", "Пузырек", tb[0], tb[1], tb[2], tb[3]);
    printf("%-12s %10.4f %10.4f %10.4f %10.4f\n", "Вставки", ti[0], ti[1], ti[2], ti[3]);
    printf("%-12s %10.4f %10.4f %10.4f %10.4f\n", "Слияние", tm[0], tm[1], tm[2], tm[3]);

    return 0;
}
