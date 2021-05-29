#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void moveSpace(char *s)
{
    char *p = s;
    while (*s != 0)
    {
        if (*s != ' ')
        {
            if (p != s)
            {
                *p = *s;
                *s = 0;
            }
            p++;
        }
        s++;
    }
}

int strlen_ext(char *s)
{
    int len = 0;
    while (*s++ != '\0')
    {
        len++;
    }
    return len;
}

char *replaceSpace(char *s)
{
    char *buf = (char *)malloc(sizeof(char) * 10000);
    memset(buf, 0, 10000);
    int size = 0;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            strncpy(buf + size, "%20", 3);
            size = size + 3;
        }
        else
        {
            strncpy(buf + size, s, 1);
            size++;
        }
        s++;
    }
    return buf;
}

int main()
{

    char *result = replaceSpace("We are happy.");
    printf("%s\n", result);
    char s[] = "   abc as df";
    printf("%s\n", s);
    moveSpace(s);
    printf("%s\n", s);
    printf("%d\n", strlen_ext("123456"));
    return 0;
}