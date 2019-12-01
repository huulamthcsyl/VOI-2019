#include <stdio.h>
//#include <conio.h>
 
long long has[100001],A[100001],B[100001],KQ=0;
 
void kt(int n,int a[],long long x[])
{
    int t=0,max,flag=0;
    while(t++<n+1)
    {
        if(a[t]==1)
        {
                 if(KQ<1)
                      KQ = 1;
                flag = 1;
                max = 1;
        }
        else if(flag!=0)
        {
            if(a[t]>max) max = a[t];
            if(max<=t && x[t]-x[t-max]==has[max] && KQ<max)
                KQ = max;
        }
    }
}
                 
int main()
{
    #define TASK "NKLP"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".ans","w",stdout);
    int n,a[100001],b[100001];
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[n+1-i] = a[i];
    }
    A[0]= 0; B[0] = 0;has[0] =0;
    for(int i = 1;i<=n;i++)
    {
        has[i] = has[i-1]+i*i + i + 1;
        A[i] = A[i-1]+a[i]*a[i] + a[i] +1;
        B[i] = B[i-1]+b[i]*b[i]+b[i]+1;
    }
    kt(n,a,A);kt(n,b,B);
    printf("%lld",KQ);
   // getch();
}
 