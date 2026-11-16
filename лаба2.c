#include <stdio.h>

int found = 0;

// сумма делителей числа n, не считая самого n
int sum_del(int n, int d)
{
    int s;

    if (d == 0)
        return 0;

    if (n % d == 0)
        s = d;
    else
        s = 0;

    return s + sum_del(n, d - 1);
}

int perfect(int n)
{
    if (n < 2)
        return 0;

    if (sum_del(n, n / 2) == n)
        return 1;

    return 0;
}

void check(int n, int m)
{
    if (n > m)
        return;

    if (perfect(n))
    {
        printf("%d ", n);
        found = 1;
    }

    check(n + 1, m);
}

int main()
{
    int n, m;

    printf("Введите N и M: ");

    if (scanf("%d %d", &n, &m) != 2)
    {
        printf("Ошибка ввода\n");
        return 1;
    }

    if (n < 0 || m < 0)
    {
        printf("Числа должны быть неотрицательными\n");
        return 1;
    }

    if (n > m)
    {
        printf("N должно быть не больше M\n");
        return 1;
    }

    check(n, m);

    if (!found)
        printf("Совершенных чисел нет");

    printf("\n");

    return 0;
}
