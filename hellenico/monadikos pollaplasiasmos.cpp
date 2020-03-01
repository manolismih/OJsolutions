#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
  
long long m;  
int emf[10];  
  
int digits (long long x)  
{  
    int ret=0;  
    while (x) x/=10, ret++;  
    return ret;  
}  
  
void analyze(int x)  
{  
    while (x)  
    {  
        emf[x%10]++;  
        x/=10;  
    }  
}  
  
void check(int x)  
{  
    memset(emf,0,sizeof(emf));  
    analyze(m);  
    analyze(x);  
    analyze(m*x);  
    for (int i=1; i<=9; i++)  
        if (emf[i] != 1) return;  
    printf("%d %d\n",x,m*x);  
    exit(0);  
}  
  
int main()  
{  
    freopen("digits.in","r",stdin);  
    freopen("digits.out","w",stdout);  
    scanf("%lld",&m);  
    int d = digits(m);  
    for (int i=1; d+digits(i)+digits(i*m)<10; i++)  
        check(i);  
    printf("0");  
}  
