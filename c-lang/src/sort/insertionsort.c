/*
 * Insertion sort 삽입정력
 * 크기가 n 인 배열 A[n] 에서 lastIdx - 1 값부터 0까지 A[lastIdx] 값보다 작은 값이 나온 인덱스의 뒤에 A[lastIdx] 값을 삽입힌다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int * data, int datasize);
void makeData(int * data, int datasize);

int main()
{
    int data[15];
    makeData(data, sizeof(data) / sizeof(int));

    printf("array init\n");
    for(int i = 0 ; i < sizeof(data) / sizeof(int) ; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    insertionSort(data, sizeof(data) / sizeof(int));
}

void insertionSort(int * data, int datasize)
{
    
    // for currentIdx <- 1 up to datasize
    for(int currentIdx = 1 ; currentIdx < datasize ; currentIdx++)
    {
        int currentValue = data[currentIdx];
        // for targetIdx <- currentIdx - 1 down to 0 
        for(int targetIdx = currentIdx - 1 ; targetIdx > -1 ; targetIdx--)
        {
            int targetValue = data[targetIdx];
            printf("data[%d] = currentValue %d, data[%d] = targetValue %d\n", currentIdx, currentValue, targetIdx, targetValue);
            // if A[currentIdx] > A[targetIdx] then A[targetIdx + 1] <- A[currentIdx]
            if (currentValue > targetValue)
            {
                data[targetIdx + 1] = currentValue;
                break;
            }
            // ifelse then A[targetIdx + 1] <- A[i]
            else
            {
                data[targetIdx + 1] = targetValue;
                data[targetIdx] = currentValue;
            }

            for(int j = 0 ; j < datasize ; j++)
            {
                printf("%d ", data[j]);
            }
            printf("\n");
        }
    }
}

void makeData(int * data, int datasize)
{
    srand(time(NULL)); // rand() 함수 실행마다 다른 값을 설정하기 위해 seed 설정
    
    for(int i = 0 ; i < datasize ; i++)
    {
        data[i] = rand() % 1000 + 1; // 1 ~ 1000난수 발생 : rand() % n --> 0 ~ n-1 난수 발생}
    }
}
