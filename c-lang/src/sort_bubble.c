/*
 * Bubble sort 정렬 알고리즘
 * 원소가 N개인 배열 data[N]이 있다면 data[n] > data[n+1] 인 경우 두 자리를 바꾸어 주는 로직을 N-1 번 수행하면 최대 값이 data[N]에 존재하게된다.
 * 이후 data[N - 1] 배열을 대상으로 진행해 위의 로직을 N - 1번 반복한다.
 */
#include <stdio.h>

int main()
{
    int data[] = {5,4,3,2,1};
    int count = sizeof(data) / sizeof(int);
    int idx = 0;

    while(count > 1)
    {
        // bubble change N - 1
        while(idx < count - 1)
        {
            // data[n] > data[n + 1] 인 경우
            if(data[idx] > data[idx + 1])
            {
                // data[n] <-> data[n + 1]
                int tmp = data[idx + 1];
                data[idx + 1] = data[idx];
                data[idx] = tmp;
                for(int i = 0 ; i < sizeof(data) / sizeof(int) ; i++)
                {
                    printf("%d ", data[i]);
                }
                printf("\n");
            }
            idx++;
        }
        count--;
        idx = 0;
    }

    for(int i = 0 ; i < sizeof(data) / sizeof(int) ; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

