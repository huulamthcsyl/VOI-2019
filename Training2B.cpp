#include <bits/stdc++.h>
#define fi first
#define se second
#define getv(i, u) (e[i].first + e[i].second - u)
using namespace std;
typedef long long LL;
const LL maxn = 10 + 1e6;
LL n, m, t, p, k, cnt = 0;
LL gt[maxn], gtn[maxn], a[maxn], ts[maxn], ms[maxn], nt[maxn];

LL Pow(LL a, LL n)
{
    if (n == 0)
        return 1;
    LL t = Pow(a, n / 2);
    t = (t * t) % p;
    if (n % 2)
        return (t * a) % p;
    return t;
}
void Process(LL n)
{
    gt[0] = 1;
    for (int i = 1; i <= n; ++i)
        gt[i] = (gt[i - 1] * i) % p;

    gtn[n] = Pow(gt[n], p - 2);
    for (int i = n - 1; i >= 0; --i)
        gtn[i] = (gtn[i + 1] * (i + 1)) % p;

    return;
}
LL calcu(LL n, LL k)
{
    LL res = 1;
    for (int i = n - k; i <= n - 1; ++i)
        res = (res * i) % p;
    res = (res * gtn[k]) % p;

    return res;
}
void Sang()
{
    for(int i = 2 ; i <= 1e6 ; ++i)
    if(!nt[i]){
        a[++cnt] = i;
        for(int j = 2 ; i * j <= 1e6 ; ++j) nt[i * j] = 1;
    }
}
void PT(LL n, LL b[])
{
    //cout << n << '\n';
    for (int j = 1; j <= cnt && a[j] <= n; ++j)
    {
        LL val = a[j];

        while (val <= n)
        {
            b[a[j]] += n / val;
            //      cout << n << ' ' << val << ' ' << b[ a[j] ] << '\n';
            val *= a[j];
        }
    }

    return;
}
LL solve()
{
    LL res = 1;

    for (int i = 1; i <= cnt; ++i)
        ts[a[i]] -= ms[a[i]],
            res = (res * Pow(a[i], ts[a[i]])) % p;

    return res;
}
int main()
{
    #define TASK "FLOWERS"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t >> p;
    Process(1e6);
    Sang();
    for (int i = 1; i <= t; ++i)
    {
        cin >> n >> m >> k;
        LL ans = (Pow(m - 1, k) * m) % p, res = 0;
        //   cout << ans << '\n';
        if (p % 10 == 3)
        {
            if (n <= 1e6)
                res = (((gt[n - 1] * gtn[k]) % p) * gtn[n - 1 - k]) % p;
            else
                res = calcu(n, k);
        }
        else
        {
            //  if (n == 3)
            PT(n - 1, ts),
            PT(k, ms),
            PT(n - k - 1, ms);
            res = solve();
            //  if (n == 3)
            //    cout << ts[2] << '\n';
            memset(ts, 0, sizeof ts);
            memset(ms, 0, sizeof ms);
            // cout << res << '\n';
        }
        //      cout << gt[n - 1] << ' ' << gtn[k] << ' ' << gtn[n - 1 - k] << '\n';
        cout << (ans * res) % p << '\n';
    }

    return 0;
}
