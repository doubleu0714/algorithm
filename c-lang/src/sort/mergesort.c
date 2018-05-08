/**
 * 10개의 정수를 입력 받아 merge sort 로 정렬하는 프로그램
 */
#include <stdio.h>

typedef enum {false, true} boolean; // c 에서는 boolean type이 없기 때문에 typedef로 설정해 사용함
void printDatas(int * datas, int size);
void divideData(int * datas, int begin, int end);
void mergeData(int * datas, int begin, int middle, int end);

int main()
{
    int i = 0;
    int datas[10];
    while(i < 10)
    {
        scanf("%d", &datas[i]);
        i++;
    }

    printDatas(datas, sizeof(datas) / sizeof(int));

    divideData(datas, 0, 9);

    // 결과 데이터를 출력
    printDatas(datas, sizeof(datas) / sizeof(int));
    return 0;
}

/**
 * 길이가 n인 배열을 반으로 분할 하는 함수
 */
void divideData(int * datas, int begin, int end)
{
    // base case : begin 값이 end값 보다 크거나 같으면 정렬을 종료한다.
    if(begin < end)
    {
        // begin이 end보다 작으면 middle값을 구한 후 begin...middle, (middle + 1)...end 각각의 영역을 분할을 계속한다.
        // 배열의 크기가 1일때(begin == end) 까지 분할을 계속한다.
        int middle = (begin + end) / 2;
        printf("begin : %d, middle : %d, end : %d\n", begin, middle, end);
        divideData(datas, begin, middle);
        divideData(datas, middle + 1, end);
        mergeData(datas, begin, middle, end);
    }
}

/**
 * begin...middle, (middle + 1)...end 배열을 오름차순으로 합치는 함수
 */
void mergeData(int * datas, int begin, int middle, int end)
{
    int tmpDatas[10];
    int tmpIdx = begin, i = begin, j = middle + 1;

    while(i <= middle && j <= end)
    {
        if(datas[i] <= datas[j])
        {
            tmpDatas[tmpIdx++] = datas[i++];
        }
        else
        {
            tmpDatas[tmpIdx++] = datas[j++];
        }
    }

    while(i <= middle)
    {
        tmpDatas[tmpIdx++] = datas[i++];
    }

    while(j <= end)
    {
        tmpDatas[tmpIdx++] = datas[j++];
    }
    
    for(int i = begin ; i <= end ; i++)
    {
        datas[i] = tmpDatas[i];
    }
    printf("begin : %d, middle : %d, end : %d => ", begin, middle, end);
    printDatas(datas, 10);
}

void printDatas(int * datas, int size)
{
    for(int i = 0  ; i < size ; i++)
    {
        i < size - 1 ? i == 0 ? printf("\"%d ", datas[i]) : printf("%d ", datas[i]) : printf("%d\"", datas[i]);
    }
    printf("\n");
}