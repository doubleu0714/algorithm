#include <stdio.h>

double power(double base, int exponent);

int main()
{
    
    double base; // 밑
    int exponent; // 지수
    printf("input base value : ");
    scanf("%lf", &base); // base 값을 입력 받는다.
    printf("input exponent value : ");
    scanf("%d", &exponent); // exponent 값을 입력 받는다.

    double result = power(base, exponent);
    printf("%lf^%d = %lf\n", base, exponent, result);
}

double power(double base, int exponent)
{
    // base case : exponent 가 1이면 base를 리턴
    if(exponent == 0)
    {
        return 1;
    }
    // base case : exponent 가 1이면 base를 리턴
    if (exponent == 1)
    {
        return base;
    }
    // recursive case : base * power(base, exponent -1)
    else
    {
        // base * base ^ (exponent - 1)
        return base * power(base, exponent - 1);
    }
}