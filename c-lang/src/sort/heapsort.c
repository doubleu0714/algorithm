#include <stdio.h>
typedef enum {false, true} boolean; // c 에서는 boolean type이 없기 때문에 typedef로 설정해 사용함

void heap_sort(int *array, int array_size);
void build_maxheap(int *array, int heapsize);
void max_heapify(int *heap, int heap_size, int heap_idx);
boolean is_leaf(int heap_size, int idx);
void print(int *datas, int size);


int main()
{
    // int array[] = {1, 14, 10, 8, 7, 9, 3, 2, 4, 16};
    // max_heapify(array, 10, 1);
    int array[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heap_sort(array, sizeof(array) / sizeof(int));
    printf("%s=========\n", "result");
    print(array, sizeof(array) / sizeof(int));
    return 0;
}

/**
 * build_maxheap(array, array_size)
 * DECLARE INTEGER idx
 * FOR idx <- array_size to 1
 *   EXCHANGE array[1] array[idx]
 *   max_heapify(array, array_size, 1)
 */
void heap_sort(int *array, int array_size)
{
    build_maxheap(array, array_size);
    for (int i = array_size ; i > 1 ; i--)
    {
        print(array, array_size);
        int root_value = array[0];
        array[0] = array[i - 1];
        array[i - 1] = root_value;
        max_heapify(array, i - 1, 1);
    }
}

/**
 * DECLARE INTEGER idx;
 * FOR idx <- heap_size to 1
 *   IF heap[idx] IS NOT LEAF
 *     max_heapify(heap, heap_size, idx)
 * */
void build_maxheap(int *array, int array_size)
{
    printf("build_maxheap start====================\n");
    for (int i = array_size / 2 ; i > 0 ; i--)
    {
        printf("array = ");
        print(array, array_size);
        max_heapify(array, array_size, i);
        printf("array = ");
        print(array, array_size);
    }
    printf("build_maxheap end====================\n"); 
}


/*
 * DECLARE INTEGER child_idx, child_value
 * IF heap[idx] is leaf
 *   RETURN
 * ELSE
 *   child_idx <- heap[2 * heap_idx] > heap[(2 * heap_idx)] ? 2 * heap_idx : 2 * heap_idx
 *   child_value <- heap[child_idx]
 *   IF heap[heap_idx] LT child_value
 *     heap[child_idx] <- heap[heap_idx]
 *     heap[heap_idx] <- child_value
 *     max_heapify(heap, child_idx)
 *   ELSE
 *     RETURN
 */
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

void print(int *datas, int size)
{
    for(int i = 0  ; i < size ; i++)
    {
        i < size - 1 ? i == 0 ? printf("\"%d ", datas[i]) : printf("%d ", datas[i]) : printf("%d\"", datas[i]);
    }
    printf("\n");
}