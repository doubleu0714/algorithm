#include <stdio.h>

int searchMaxValue(int begin, int end, int data[])
{
    // if begin < end 이면 분할해서 최대값 찾기
    // if begin >= end data[begin] 값을 리턴한다.
    if(begin == end)
    {
        // begin 값과 end값이 같은 경우는 길이가 1인 배열이란 의미이므로
        // data[begin] 혹은 data[end]를 리턴하고 recursion 종료
        return data[begin];
    }
    else if (begin < end)
    {
        // begin 이 end 보다 작은 경우는 recursion진행
        // begin과 end의 중간 값으로 배열을 나누어 앞의 앞 쪽 배열 값의 최대값과 뒤쪽 배열 값의 최대값을 구해 두 값중 최대값을 구한다.
        int middle = (begin + end) / 2;
        int maxValue1 = searchMaxValue(begin, middle, data);
        int maxValue2 = searchMaxValue(middle + 1, end, data);
        return maxValue1 > maxValue2 ? maxValue1 : maxValue2;
    }
    return 0;
}

int main()
{
    int data[] = {1,265,346,3,6858,34,235,457,34,325,643,537,7,235,235,57,856,78,43,23};
    int maxValue = searchMaxValue(0, sizeof(data) / sizeof(int), data);
    printf("max value : %d\n", maxValue);
    return 0;
}