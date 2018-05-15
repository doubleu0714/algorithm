/**
 * 10개의 정수를 입력받아 Quick sort로 정렬하는 프로그램
 */
#include <stdio.h>

#define DATA_SIZE 10

void quicksort(int * data, int begin, int end);
int partition(int * data, int begin, int end);
void printDatas(int * datas, int size);

int main()
{
    // 1. 정수 10개를 입력 받는다.
    int i = 0;
    int datas[DATA_SIZE];
    while(i < DATA_SIZE)
    {
        scanf("%d", &datas[i]);
        i++;
    }
    // 2. 입력 받은 정수를 배열에 저장한다.
    // 3. quicksort 함수를 호출한다.

    quicksort(datas, 0, DATA_SIZE - 1);

    printDatas(datas, DATA_SIZE);
}

void quicksort(int * data, int begin, int end)
{
    // begin 이 end보다 작은 경우
    if(begin < end)
    {
        printDatas(data, DATA_SIZE);
        // data를 분할 하기 위해  partition함수를 호출하고 pivot의 위치를 받는다.
        int pivotIndex = partition(data, begin, end);
        // begin...pivot-1 index 까지 quicksort 함수를 재귀호출 한다.
        quicksort(data, begin, pivotIndex - 1);
        // pivot + 1 ... end 까지 quicksort 함수를 재귀호출 한다.
        quicksort(data, pivotIndex + 1, end);
    }
    // begin 이 end 보다 크거나 같은 경우는 아무것도 하지않는다.-> 크기가 1이면 더이상 recursion을 진행하지 않는다.
}

int partition(int * data, int begin, int end)
{
    // pivot 인덱스을 정한다.(중앙값)
    int pivotIndex = (begin + end) / 2;
    // storedIndex 값을 초기화 한다.
    int storedIndex = begin;
    // for begin...end
    for(int i = begin ; i <= end ; i++)
    {  
        printf("i=%d(%d), pivotIndex=%d(%d) : ", i, data[i], pivotIndex, data[pivotIndex]);
        // pivot의 인데스인 경우 건너 뛴다.
        if(i == pivotIndex)
        {
            printf("nothing to do\n");
            continue;
        }
        // pivot 값보다 작거나 같은 경우

        if(data[i] <= data[pivotIndex])
        {
            // data[i] <-> data[storedIndex]
            int tmp = data[storedIndex];
            data[storedIndex] = data[i];
            data[i] = tmp;
            // storedIndex값을 증가한다.
            storedIndex++;
            if(storedIndex == pivotIndex)
            {
                storedIndex++;
            }
        }

        printDatas(data, DATA_SIZE);
    }
    
    // pivot의 위치가 storedIndex보다 크다면 data[storedIndex] <-> data[pivotIndex]
    if(pivotIndex > storedIndex)
    {
        int tmp = data[pivotIndex];
        data[pivotIndex] = data[storedIndex];
        data[storedIndex] = tmp;
        return storedIndex;
    }
    // pivot의 위치가 storedIndex보다 작다면 data[storedIndex - 1] <-> data[pivotIndex]
    else if(pivotIndex < storedIndex)
    {
        int tmp = data[pivotIndex];
        data[pivotIndex] = data[storedIndex - 1];
        data[storedIndex - 1] = tmp;
        return storedIndex - 1;
    }
    printf("partition result :");
    printDatas(data, DATA_SIZE);
    return pivotIndex;
}

void printDatas(int * datas, int size)
{
    for(int i = 0  ; i < size ; i++)
    {
        i < size - 1 ? i == 0 ? printf("\"%d ", datas[i]) : printf("%d ", datas[i]) : printf("%d\"", datas[i]);
    }
    printf("\n");
}