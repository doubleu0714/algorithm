/*
 * 미로찾기 로직
 * recursion으로 호출해 입구에서 부터 출구까지 길을 찾아감
 * 북 동 남 서 방향 순으로 판단한다.
 * 미로는 2차원 배열로 표시 하며 0은 길, 1을 벽이란 의미이다.
 */
#include <stdio.h>

typedef enum {false, true} boolean; // c 에서는 boolean type이 없기 때문에 typedef로 설정해 사용함
static const int PATH_WAY = 0; // 길 표시값
static const int WALL = 1; // 벽 표시값
static const int BLOCK = 2; // 가봤지만 결국 막혔던 길에 대한 표시값
static const int PATH = 3; // 가능한 길에 대한 표시값

static int maze[8][8] = {
    {0,0,0,0,0,0,0,1},
    {0,1,1,0,1,1,0,1},
    {0,0,0,1,0,0,0,1},
    {0,1,0,0,1,1,0,0},
    {0,1,1,1,0,0,1,1},
    {0,1,0,0,0,1,0,1},
    {0,0,0,1,0,0,0,1},
    {0,1,1,1,0,1,0,0}
};
static int NX = sizeof(maze[0]) / sizeof(int);
static int NY = sizeof(maze) / sizeof(maze[0]);

boolean findMaze(int x, int y)
{
    // x,y좌표가 0 보다 작거나 N(배열 size) 보다 크면 미로 밖이므로 false를 리턴
    if (x < 0 || y < 0 || x > NX - 1 || y > NY - 1)
    {
        printf("%d, %d is not PATH_WAY\n", x, y);
        return false;
    }
    // x,y좌표가 PATH_WAY 가 아니라면 벽이거나 막힌길이거나 판단중인 길이므로 false를 리턴
    else if (maze[x][y] != PATH_WAY)
    {
        printf("%d, %d --> %d is not PATH_WAY\n", x, y, maze[x][y]);
        return false;
    }
    else if (x == NX -1 && y == NY - 1)
    // x,y좌표가 N-1 과 같은 경우. 즉, goal인경우 PATH 값으로 설정 후 true를 리턴
    {
        printf("We've arrived at goal!!!\n");
        maze[x][y] = PATH;
        return true;
    }
    // 위의 경우를 제외하고는 recursion case
    else
    {
        // 해당 길을 방문하면 일단 PATH로 판단하고 PATH값으로 설정
        maze[x][y] = PATH;
        // 북, 동, 남, 서 방향 중 길이 있다면 true 를 리턴
        if(findMaze(x - 1, y) // 북
        || findMaze(x, y + 1) // 동
        || findMaze(x + 1, y) // 서
        || findMaze(x, y - 1)) // 남
        {
            return true;
        }
        // 리턴되지 않았다면 즉, 북, 동, 남, 서 가 모두 false 를 리턴했다면 BLOCK값으로 설정 후 false 를 리턴
        maze[x][y] = BLOCK;
        return false;
    }
}

void printMaze()
{
    for(int i = 0 ; i < NX ; i++)
    {
        for(int j = 0 ; j < NY ; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("NX = %d, NY = %d\n", NX, NY);
    printMaze();
    findMaze(0, 0);
    printMaze();
    return 0;
}