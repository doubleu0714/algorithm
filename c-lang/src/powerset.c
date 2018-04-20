/*
 * 멱집합 구하기
 * 주어진 집합의 모든 부분집합을 구하시오
 * 집합 {a,b,c,d}가 있다면 모든 부분집합은 a를 제외한 {b,c,d}의 부분집합과 {b,c,d}의 부분집합에 a 를 포함해서 구할 수 있다.
 * 이 문제 또한 상태공간트리 풀어 낼 수 있으머 상태공간트리로 문달었을때 leaf node 들이 부분집합이 된다.
 */
#include <stdio.h>

typedef enum {false, true} boolean;

boolean flag[] = {false, false, false, false};
char data[] = {'A', 'B', 'C', 'D'};

void powerset(int level)
{
    // level이 집합의 갯수와 같을 때
    if (level == sizeof(data))
    {
        printf("{");
        // flag 배열이 include 인 idx 에 해당하는 집합 요소를 출력한다.
        for (int i = 0 ; i < sizeof(data) ; i++)
        {
            if (flag[i])
            {
                printf(" %c ", data[i]);
            }
            else
            {
                printf("   ");
            }
        }
        printf("}\n");
        // 부모 노드로 리턴한다.
        return;
    }
    // level이 집합의 갯수보다 작을 때
    else
    {
        // 집합의 idx(level - 1) 와 동일한 idx 로 flag 배열에 true(include)로 설정한다.
        flag[level] = true;
        // child node(level + 1) 를 recursion으로 호출한다.
        powerset(level + 1);
        // 집합의 idx(level - 1) 와 동일한 idx 로 flag 배열에 false(exclude)로 설정한다.       
        flag[level] = false;
        // child node(level + 1) 를 recursion으로 호출한다.
        powerset(level + 1);
    }
}

int main()
{
    powerset(0);
    return 0;
}