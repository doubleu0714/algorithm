/* 
 * 팩토리얼을 Recursion으로 구현한 프로그램입니다.
 * 기본적인 정수의 factorial 을 계산합니다.
 */
#include <stdio.h>

int factorial(int i);

int main()
{
    int a;
    printf("input int value : ");
    scanf("%d", &a);

    int result = factorial(a);

    printf("%d! = %d\n", a, result);
}


int factorial (int i)
{
    //i 가 1보다 작거나 같은 경우 1을 리턴하고 종료한다.
    if (i <= 1)
    {
        return 1;
    }
    //i 가 1보다 크다면 i와 factorial(i-1)을 곱한다.
    else
    {
        return i * factorial(i - 1);
    }
    
}