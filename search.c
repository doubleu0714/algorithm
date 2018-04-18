#include <stdio.h>

int search(int begin, int end, int * data, int target)
{
    // base case : if begin is greater then end, return -1
    if (begin > end)
    {
        return -1;
    }
    // else 
    else
    {
        // if data[begin - 1] value is equal target
        if(data[begin - 1] == target) {
            // return target that we want search value and end recursion
            return target;
        } else {
            // if data[begin - 1] value isn't equal target
            // call function recursively
            return search(begin + 1, end, data, target);
        }

    }

}

int main()
{
    int data[] = {1,2,3,4,135,25,34,14,63,656,234,36,547,25,358,277,85,46};
    int begin, end, target;
    printf("input begin value : ");
    scanf("%d", &begin);
    printf("input end value : ");
    scanf("%d", &end);
    printf("input target value : ");
    scanf("%d", &target);
    printf("begin = %d, end = %d, target = %d\n", begin, end, target);

    int searchResult = search(begin, end, data, target);

    printf("search result value = %d\n", searchResult);
}


