#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    printf("What's your number?\n");
    scanf("%d",&i); // & operator was missing
    printf("Number was:%d",i);
    return 0;
}

void 