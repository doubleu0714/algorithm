#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} boolean; // c 에서는 boolean type이 없기 때문에 typedef로 설정해 사용함
void arr_init();
void put(int val);
int pop();
void print(int *datas, int size);
void increase_arr();
void max_heapify(int *heap, int heap_size, int heap_idx);
boolean is_leaf(int heap_size, int idx);


int *arr;
int size = 10;
int put_idx = 0;

int main()
{
    arr_init();
    // 4, 1, 3, 2, 16, 9, 10, 14, 8, 7
    //"16 14 10 8 7 9 3 2 4 1"
    print(arr, size);
    put(4);
    print(arr, size);
    put(1);
    print(arr, size);
    put(3);
    print(arr, size);
    put(2);
    print(arr, size);
    put(16);
    print(arr, size);
    put(9);
    print(arr, size);
    put(10);
    print(arr, size);
    put(14);
    print(arr, size);
    put(8);
    print(arr, size);
    put(7);
    print(arr, size);
    put(20);
    print(arr, size);
    put(150);
    print(arr, size);
    put(30);
    print(arr, size);
    printf("max val is [%d]\n", pop());
    print(arr, size);
    printf("max val is [%d]\n", pop());
    print(arr, size);
    printf("max val is [%d]\n", pop());
    print(arr, size);
    put(20);
    print(arr, size);
    put(150);
    print(arr, size);
    put(30);
    print(arr, size);
    printf("max val is [%d]\n", pop());
    print(arr, size);
    printf("max val is [%d]\n", pop());
    print(arr, size);
    printf("max val is [%d]\n", pop());
    print(arr, size);
}

void arr_init()
{
    arr = (int *)malloc(sizeof(int) * size);
    memset(arr, 0x00, sizeof(int) * size);
}

void increase_arr()
{
    printf("increase_arr was called!!\n");
    size++;
    int *tmp = (int *)malloc(sizeof(int) * size);
    memset(tmp, 0x00, size);

    for (int i = 0 ; i < size - 1 ; i++) {
        tmp[i] = arr[i];
    }

    free(arr);
    arr = tmp;
}

void put(int val)
{
    // printf("val is [%d]", val);
    // printf(",put_idx is [%d]", put_idx);
    // printf(", size is [%d]\n", size);

    if (put_idx > size - 1) increase_arr();

    arr[put_idx++] = val;
    int i = put_idx - 1;
    while ( i > 0 )
    {
        int parent_idx = (i + 1) / 2 - 1;
        int parent_val = arr[parent_idx];
        // printf("parent[%d] = %d\n", parent_idx, parent_val);
        if (parent_val < val)
        {
            // printf("exchange val(%d) <-> parent_val(%d)\n", val, parent_val);
            arr[parent_idx] = arr[i];
            arr[i] = parent_val;
        }
        i = (i + 1) / 2 - 1;
    }
}

int pop()
{
    int max_val = arr[0];
    arr[0] = arr[size - 1];   
    arr[size - 1] = max_val;
    size--;
    put_idx--;
    max_heapify(arr, size, 1);
    return max_val;
}

void print(int *datas, int size)
{
    for(int i = 0  ; i < size ; i++)
    {
        i < size - 1 ? i == 0 ? printf("\"%d ", datas[i]) : printf("%d ", datas[i]) : printf("%d\"", datas[i]);
    }
    printf("\n");
}

void max_heapify(int *heap, int heap_size, int heap_idx)
{
    // printf("max_heapify start====================\n");
    // printf("%s(heap[%d] = %d\n", "max_heapify", heap_idx, heap[heap_idx - 1]);
    // print(heap, heap_size);
    int child_idx, child_value;
    if (is_leaf(heap_size, heap_idx))
    {
        // printf("[%d] is leaf node\n", heap_idx);
        return;
    }
    else
    {
        int first_child_arr_idx = 2 * heap_idx - 1;
        int second_child_arr_idx = 2 * heap_idx > heap_size - 1 ? first_child_arr_idx : 2 * heap_idx;
        // printf("heap_idx is [%d], first_child_arr_idx is [%d], second_child_arr_idx is [%d]\n", heap_idx, first_child_arr_idx, second_child_arr_idx);
        child_idx = heap[first_child_arr_idx] > heap[second_child_arr_idx] ? first_child_arr_idx + 1 : second_child_arr_idx + 1;
        child_value = heap[child_idx - 1];
        // printf("child_idx is [%d], child_value is [%d]\n", child_idx, child_value);

        if (heap[heap_idx - 1] < child_value)
        {
            heap[child_idx - 1] = heap[heap_idx - 1];
            heap[heap_idx - 1] = child_value;
            max_heapify(heap, heap_size, child_idx);
        }
        else
        {
            return;
        }
    }
    // printf("max_heapify end====================\n");
}

boolean is_leaf(int heap_size, int idx)
{
    return heap_size < 2 * idx;
}