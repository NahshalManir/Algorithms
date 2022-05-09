#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int size(int x)
{
    int s=0;
    while(x>0)
    {
        s++;
        x/=10;
    }

    return s;
}

int karatsuba(int a, int b)
{
    int m,x1,x2,y1,y2,z0,z1,z2;

    if(a<10 || b<10)
        return a*b;
    m=size(a)>=size(b) ? size(a):size(b);
    m=pow(10,m/2);

    x1=a%m;
    x2=a/m;
    y1=b%m;
    y2=b/m;

    z0=karatsuba(x1,y1);
    z1=karatsuba(x1+x2,y1+y2);
    z2=karatsuba(x2,y2);

    return (z2*pow(10,2*m))+((z1-z2-z0)*pow(10,m))+z0;
}

int main()
{
    printf("%d",karatsuba(256,987));
    //printf("%d %d",size(256),size(987));
    return 0;
}
