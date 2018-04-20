/*
 * blob내 의 셀 갯수 구하기
 * 2차원 배열내 임의의 한 점(x,y)가 주어졌을 때 이 점이 속하는 blob내의 모든 셀(배열내 값이 1인것)의 갯수를 찾는다.
 * 임의의 한점이 blob가 아니라면 0을 리턴
 * 이미 카운팅한 값은 2로 표시해 중복되지 않도록 한다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {false, true} boolean; // c 에서는 boolean type이 없기 때문에 typedef로 설정해 사용함

static int blob[8][8];
static const int NX = 8;
static const int NY = 8;

static const int NOT_BLOB = 0;
static const int COUNT = 1;
static const int VISITED = 2;

int countcells(int x, int y)
{
    // x, y 가 0보다 작거나 배열 사이즈보다 큰 경우 카운팅 되지 않도록 하기위해 0을 리턴 -> recursion종료
    if(x < 0 || y < 0 || x > NX -1 || y > NY - 1)
    {
        printf("%d, %d isn't count target!\n", x, y);
        return 0;
    }
    // blob[x][y]가 1아닌 경우는 카운팅 대상이 아니므로(blob가 아니거나(0), 이미 카운팅함(2))0을 리턴 -> recursion종료
    else if(blob[x][y] != COUNT) {
        printf("%d, %d -> %d isn't count target!\n", x, y, blob[x][y]);
        return 0;
    } 
    // 그외의 경우는 recursion case
    else
    {
        // 현재의 blob[x][y]를 COUNTED 값으로 설정(중복 counting방지)
        blob[x][y] = VISITED;
        // 1 + 북 + 북동 + 동 + 동남 + 남 + 남서 + 서 + 서북 을 리턴한다.
        int countValue = COUNT
                        + countcells(x - 1, y) // 북
                        + countcells(x - 1, y + 1) // 북동
                        + countcells(x, y + 1) // 동
                        + countcells(x + 1, y + 1) // 동남
                        + countcells(x + 1, y) // 남
                        + countcells(x + 1, y - 1) // 남서
                        + countcells(x, y - 1) // 서
                        + countcells(x - 1, y - 1); // 서북
        return countValue;
    }
}

/*
 * blob 배열 값을 랜덤으로 생성하는 함수
 */
void makeBlob() {
    srand(time(NULL)); // rand() 함수 실행마다 다른 값을 설정하기 위해 seed 설정
    
    for(int i = 0 ; i < NX ; i++)
    {
        for(int j = 0 ; j < NY ; j++)
        {
            blob[i][j] = rand() % 2; // 0 ~ 1난수 발생 : rand() % n --> 0 ~ n-1 난수 발생
        }
    }
}

void printBlob() {
    for(int i = 0 ; i < NX ; i++)
    {
        for(int j = 0 ; j < NY ; j++)
        {
            printf("%d ", blob[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    makeBlob();
    printBlob();
    int x, y;
    printf("input x, y value : ");
    scanf("%d%d", &x, &y);
    int resultValue = countcells(x, y);
    printf("count cells in a blob : %d\n", resultValue);
    printBlob();
}