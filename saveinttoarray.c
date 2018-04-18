#include <stdio.h>
#include <math.h>

void saveinttoarray(int begin, int end, int value, char data[], int datasize);

int main()
{
    int value = 12345678;
    int begin;
    int end;
    
    printf("input begin value : ");
    scanf("%d", &begin);
    printf("input end value : ");
    scanf("%d", &end);
    
    if(begin > end) return -1;

    char data[end - begin + 1];
    printf("size of data : %lu\n", sizeof(data));
    saveinttoarray(begin, end, value, data, sizeof(data));
    for(int i = 0 ; i < sizeof(data) ; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void saveinttoarray(int begin, int end, int value, char data[], int datasize)
{
    // if begin equal end
    // return
    if(begin > end)
    {
        return;
    }
    // end -1 한 값으로 재귀 호출 한다.(begin이전 값 들에 대해서는 판별하지 않아도 된다.)
    // 호출 한 뒤 배열에 해당 자리수를 저장한다.
    else
    {
        saveinttoarray(begin, end - 1, value, data, datasize);
        int tmp = value;
        int idx = 0;
        while(tmp != 0){
            tmp /= 10;
            idx++;
            if(tmp == 0)
            {
                break;
            }
        }
        printf("idx = %d, end = %d\n", idx, end);

        data[end - datasize] = (value / (int)pow(10, (idx - end))) % 10;
    }
} 