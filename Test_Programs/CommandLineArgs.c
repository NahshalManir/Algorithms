#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for(int i=0;i<argc;i++)
    {
        printf("%d: %s", argv[i],argc);
    }

    return 0;
}
