#include <stdio.h>

void calculatebinary(int a);

int main()
{
    
    int a;
    printf("input int value : ");
    scanf("%d", &a);

    printf("binary -> : ");
    calculatebinary(a);
    printf("\n");
}

void calculatebinary(int a)
{
    if(a < 2)
    {
        printf("%d", a);
    }
    else
    {
        calculatebinary(a/2);
        printf("%d", a % 2);
    }
    
} 