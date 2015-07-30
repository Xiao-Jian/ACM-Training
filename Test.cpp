#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<complex>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;
#define max(a,b)  (a>b?a:b)
#define min(a,b)  (a<b?a:b)
#define eps 1e-8
#define zero(x)   (((x)>0?(x):-(x))<eps)


int main()
{

    char s1[] = "1110";
    char s2[] = "1101";
    puts(s1);
    puts(s2);
    printf( "%d\n", strcmp(s1,s2));
    if( strcmp(s1, s2) )
        puts("1");
    else if( strcmp(s1,s2) )
        puts( "2");
    else
        puts("0");
}
