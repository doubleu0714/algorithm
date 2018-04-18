#include <stdio.h>

int fibonacci(int a);

int main()
{
    int a;
    
    printf("input decimal value : ");
    scanf("%d", &a);

    int result = fibonacci(a);
    printf("%d\n", result);   
}

int fibonacci(int a)
{
    if (a < 2) // base case
    {
        return a;
    }
    else // recursive case
    {
        return fibonacci(a - 1) + fibonacci(a - 2);
    }
}