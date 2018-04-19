#include <stdio.h>
#include <string.h>

void printString(int idx, const char *string);

int main()
{
    int idx = 0;
    char string[100];
    printf("input string value : ");
    scanf("%s", string);

    // 배열 크기는 100이므로
    if(strlen(string) > 100) {
        return -1;
    }
    printString(idx, string);
}

void printString(int idx, const char *string)
{
    if (idx >= strlen(string)) { // base case
        printf("\n");
        return;
    }
    
    printf("%c", string[idx]);
    printString(idx + 1, string);
}