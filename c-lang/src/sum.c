#include <stdio.h>
int sum(int n, int a[]);

int main()
{
    int a[] = {10, 1023, 1415, 123524, 123124, 235234, 123123};

    int result = sum(3, a);
    printf("%d\n", result);
}

int sum(int n, int a[])
{
    if(n < 0)
    {
        return 0;
    }
    else
    {
        return sum(n-1, a) + a[n-1];
    }
}