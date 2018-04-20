/*
 * 이진탐색 알고리즘
 * 이진 검색 알고리즘(binary search algorithm)은 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘이다.
 * 처음 중간의 값을 임의의 값으로 선택하여, 그 값과 찾고자 하는 값의 크고 작음을 비교하는 방식을 채택하고 있다. 
 * 처음 선택한 중앙값이 만약 찾는 값보다 크면 그 값은 새로운 최고값이 되며, 작으면 그 값은 새로운 최하값이 된다. 
 * 검색 원리상 정렬된 리스트에만 사용할 수 있다는 단점이 있지만, 검색이 반복될 때마다 목표값을 찾을 확률은 두 배가 되므로 속도가 빠르다는 장점이 있다.
 */
#include <stdio.h>

int binarysearch(int target, int data[], int begin, int end)
{
    // begin이 end값보다 크다면 찾기 실패 -1을 리턴한다.
    if(begin > end)
    {
        printf("Can't find target value in data array!\n");
        return -1;
    }
    // begin값이 end값보다 작거나 같다면
    else
    {
        // data[mid] 값이 target 값보다 작다면 data[mid+1...end] 배열에서 찾도록 recursive 호출
        int mid = (begin + end) / 2;
        if(data[mid] < target)
        {
            printf("find in data[mid + 1 ... end]\n");
            return binarysearch(target, data, mid + 1, end);
        }
        // data[mid] 값이 target 값보다 크다면 data[begin...mid-1] 배열에서 찾도록 recursive 호출
        else if (data[mid] > target)
        {
            printf("find in data[begin ... mid - 1]\n");
            return binarysearch(target, data, begin, mid - 1);
        }
        // data[mid] 값이 target 값과 같다면 data[mid]를 리턴하고 함수 종료
        else
        {
            return data[mid];
        }

    }
}

int main()
{
    // 오름차순으로 정렬된 fibonacci numbers
    int data[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946};
    int target;
    printf("input search value : ");
    scanf("%d", &target);
    int resultValue = binarysearch(target, data, 0, sizeof(data) / sizeof(int));
    printf("result value : %d\n", resultValue);
    return 0;
}