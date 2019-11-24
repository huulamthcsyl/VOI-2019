//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "fine"

using namespace std;

typedef long long ll;
typedef long double ld;

priority_queue < ll, vector <ll>, greater <ll> > PQ;

int n;
pii a[maxn];
long long res = 0, start = 0;

void Clear(long long time)
{
    while (!PQ.empty() && start + PQ.top() <= time){
        start += PQ.top();
        res += start;
        PQ.pop();
    }

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        res -= a[i].F;
        Clear(a[i].F);
        if (!PQ.empty())
        {
            int x = PQ.top(); PQ.pop();
            PQ.push(start + x - a[i].F);
        }
        start = a[i].F;
        PQ.push(a[i].S);
    }
    Clear(1e18);
    cout << res;
    return 0;
}
