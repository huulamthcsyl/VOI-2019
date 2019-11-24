//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 500005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "sale"

using namespace std;

typedef int mang[maxn];
typedef long double ld;

mang dp, d, r, g, p, td, sr;
int m, n, k;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> d[i], td[d[i]] = i;
    for (int i = 1; i <= 500000; i++) td[i] = max(td[i], td[i-1]);
    for (int i = 1; i <= m; i++) cin >> g[i];
    for (int i = 1; i <= m; i++) cin >> p[i];
    fill(sr, sr+500002, k+1);
    for (int i = 1; i <= k; i++) cin >> r[i], sr[r[i]] = i;
    for (int i = 500000; i >= 0; i--) sr[i] = min(sr[i], sr[i+1]);
    r[k+1] = 500001;
    memset(dp, 62, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int time_to_buy = max(0, d[i] - g[j]);
            int x = td[time_to_buy];
            dp[i] = min(dp[i], dp[x] + p[j]);
            int z = sr[time_to_buy+1];
            dp[i] = min(dp[i], dp[td[r[z]-1]] + p[j]/2);
        }
    //for (int i = 1; i <= n; i++) cout << dp[i] << "\n";
    cout << dp[n];
    return 0;
}
