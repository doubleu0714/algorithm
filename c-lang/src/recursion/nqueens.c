/*
 * n queens problem
 * N * N 개의 체스 판에서 N개의 queen을 서로 간섭(같은 행, 같은 열, 대각선)하지 않도록 놓는 방법
 * 상태공간트리(State Space Tree)를 깊이우선탐색으로 실시
 * Backtracking 기법 : State space tree 를 깊이우선방식으로 탐색하면서 해당 노드가 해가 될 수 없을때 부모 노드(Back tracking)로 돌아와 다른 자식을 찾는 기법
 */
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} boolean; // c 에서는 boolean type이 없기 때문에 typedef로 설정해 사용함

void queens(int level);
boolean isPromise(int level);
void printBoard();

int board[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
};

int cols[8 + 1] = {0,0,0,0,0,0,0,0,0};
int count = 0;

void queens(int level)
{
    // 해당 level에서의 col값이 유효한 값인지 판단.
    if (!isPromise(level))
    {
        // 유효한 값이 아닌 경우 더이상 child node 에 대한 판단을 하지 않는다.
        return;
    }
    // 유효한 값인 경우 
    else
    {
        // level 값이 N 인 경우
        if (level == 8)
        {
            // leaf node 이므로 문제 해결됨.
            // 현재 board를 출력
            printBoard();
            return;
        }
        // level 값이 N 보다 작은 경우
        else if (level < 8)
        {
            // child node 에 대해서 진행
            for(int i = 0 ; i < 8 ; i++)
            {
                // 방문 컬럼 정보에 child node 의 컬럼을 기록
                cols[level + 1] = i;
                queens(level + 1);
            }
        }
    }
}

boolean isPromise(int level)
{
    if(level < 0 || level > 8)
    {
        printf("%d level is wrong level!!", level);
        return false;
    }

    for(int i = 1 ; i < level ; i++)
    {
        if(cols[i] == cols[level])
        {
            // 현재 체크중인 level 의 컬럼값과 상위 컬럼 값과 비교 후 같은게 있다면 false를 리턴
            // 같은 열에는 퀸이 올 수 없다.
            return false;
        }

        if((level - i) == abs(cols[i] - cols[level]))
        {
            // 한 대각선에는 퀸이 두개이상 올 수 없다.
            return false;
        }
    }

    return true;
}

void printBoard()
{
    printf("===============================\n");
    printf("case : %d\n", ++count);
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            if (j == cols[i + 1])
            {
                printf("%d ", 1);    
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("===============================\n");
}

int main()
{
    queens(0);
    return 0;
}