#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define lam_tron cout<<fixed <<setprecision(2);
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
/*----------------------------------------------*/
int doc() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
const int M=1e5+5;
const ll mod=1e9+7;
const double esp=1e-1;
const long double pi=4*atan((long double)1);
/*----------------------------------------------*/
int n;
int a[4][4],dich;
int f[4][4];
unsigned long long dp[1005][70][4];
int main()
{
    freopen("nrow.inp","r",stdin);
    freopen("nrow.out","w",stdout);
    ios_base::sync_with_stdio(false);
    f[0][0]=0;f[0][1]=f[1][0]=1;f[0][2]=f[2][0]=2;f[1][1]=3;f[1][2]=f[2][1]=4;f[2][2]=5;
    cin>>n;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            char c;
            cin>>c;
            if(c=='Y') dich|=(1<<f[i][j]);
        }
    dp[1][0][0]=dp[1][0][1]=dp[1][0][2]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<(1<<6);j++)
            for(int mau=0;mau<3;mau++)
            {
                for(int mautr=0;mautr<3;mautr++)
                {
                    int state=j|(1<<f[mau][mautr]);
                    dp[i+1][state][mautr]+=dp[i][j][mau];
                }
            }
    }
    cout<<dp[n][dich][0]+dp[n][dich][1]+dp[n][dich][2];
    return 0;
}
