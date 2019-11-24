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
#define Task "ABC"
#define Block 400

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m,  k = 0, step = 0;
int X[maxn], Y[maxn], L[maxn], R[maxn], res[maxn];
ll dx[maxn], dy[maxn], sub[maxn], a[maxn];

int Calc(ll val, int pos){
    for (int i = 1; i <= k; i++)
        if (L[i] <= pos && R[i] >= pos)
        {
            val -= X[i]; val -= (pos-L[i]) * Y[i];
            if (val <= 0) return i;
        }
    return 0;
}

void Lazy(){
	for (int i = 1; i <= n; i++) dx[i] = dy[i] = sub[i] = 0;
    for (int i = 1; i <= k; i++)
    {
        dx[L[i]] += X[i];
        dx[R[i]+1] -= X[i];
        dy[L[i]+1] += Y[i];
        dy[R[i]+1] -= Y[i];
        sub[R[i] + 1] += 1ll * Y[i] * (R[i] - L[i]);
    }
    long long add = 0;
    for (int i = 1; i <= n; i++)
    {
        ll val = a[i];
        dx[i] += dx[i-1];
        dy[i] += dy[i-1];
        a[i] -= dx[i];
        add += dy[i] - sub[i];
        a[i] -= add;
        if (res[i] < 0 && a[i] <= 0) res[i] = step + Calc(val, i);
    }
	step += k;
    k = 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    for (int x, i = 1; i <= n; i++) {
        cin >> x, a[i] = x - a[i];
        if (a[i] <= 0) res[i] = 0;
            else res[i] = -1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        k++;
        cin >> L[k] >> R[k] >> X[k] >> Y[k];
        if (k == Block || i == m) Lazy();
    }
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    return 0;
}
