#include <stdio.h>
#include <string.h>

void printStringDesc(int idx, const char *string);

int main()
{
    unsigned long idx = 0;
    char string[100];
    printf("input string value : ");
    scanf("%s", string);
    idx = strlen(string) - 1;
    // 배열 크기는 100이므로
    if(strlen(string) > 100) {
        return -1;
    }
    printStringDesc(idx, string);
}

void printStringDesc(int idx, const char *string)
{
    if (idx < 0) { // base case
        printf("\n");
        return;
    }
    
    printf("%c", string[idx]);
    printStringDesc(idx - 1, string);
}