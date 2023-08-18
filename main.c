#include<stdlib.h>
#include<stdio.h>

typedef char *(FunctionPointer)(char *);

extern char * RunCS(FunctionPointer Foo, char *ptr);

char * Foo(char *ptr)
{
    ptr[0] = 'h';
    return ptr;
}

int main()
{
    char *ptr = (char *)malloc(sizeof(char) * 3);
    ptr[0] = 'H';
    ptr[1] = 'i';
    ptr[2] = '!';

    printf("%s\n", ptr);

    char * x = RunCS(&Foo, ptr);

    if(*x == '\0')
    {
        printf("error");
    }

    printf("%s\n", x);
}