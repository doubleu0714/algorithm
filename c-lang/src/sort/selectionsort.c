/*
 * selection sort n 개의 배열 A[n] 에서 가장 최대 혹은 최소값을 찾은 후 A[last] 혹은 A[first]와 exchange 하는것
 */

/*
selectionsort(A[n], n)
{
    for last down to 2 {
        A[1...last] 중 가장 큰 값인 A[k]를 찾는다.
        A[k] <-> A[last];
    }
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeData(int * data, int datasize);
int findMaxIndex(int * data, int last);
void selectionSort(int * data, int last);

int main()
{
    int data[15];
    makeData(data, sizeof(data) / sizeof(int) - 1);

    printf("array init\n");
    for(int i = 0 ; i < sizeof(data) / sizeof(int) ; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    selectionSort(data, sizeof(data) / sizeof(int));
}

void selectionSort(int * data, int last)
{
    for(int i = last - 1 ; i > 0 ; i--)
    {
        int maxValueIndex = findMaxIndex(data, i);

        printf("step %d, data[%d] <-> data[%d] : ", last - i, i, maxValueIndex);

        int tmp = data[i];
        data[i] = data[maxValueIndex];
        data[maxValueIndex] = tmp;

        for(int j = 0 ; j < last ; j++)
        {
            printf("%d ", data[j]);
        }
        printf("\n");
    }
}

int findMaxIndex(int * data, int last)
{
    int maxValueIndex = 0;
    for(int i = 0 ; i < last ; i++)
    {
        if(data[maxValueIndex] < data[i])
        {
            maxValueIndex = i;
        }
    }
    printf("MAX VAL %d, ", data[maxValueIndex]);
    return maxValueIndex;
}

void makeData(int * data, int datasize) {
    srand(time(NULL)); // rand() 함수 실행마다 다른 값을 설정하기 위해 seed 설정
    
    for(int i = 0 ; i < datasize ; i++)
    {
        data[i] = rand() % 1000 + 1; // 1 ~ 1000난수 발생 : rand() % n --> 0 ~ n-1 난수 발생}
    }
}