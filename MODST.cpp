#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int const maxn = 1e5 + 5;

int n, p[maxn], lt[maxn];
int64_t ds = 0;
typedef pair<int, int> II;
typedef pair<int, II> III;
vector<II> e[10000007];

int doc()
{
    char c;
    for( c = getchar() ; ( c < '0' || c > '9') && c != '-' ; c =getchar());
    int ans , sgn ;
    if(c == '-') ans = 0 , sgn = -1;
    else ans = c - '0' , sgn = 1;
    for( c = getchar() ;  c >= '0' && c <= '9' ; c =getchar()) ans = ans * 10 + c - '0' ;
    return ans * sgn ;
}
void in(int64_t x)
{
    if(x < 0) putchar('-') , x = -x;
    if(x > 9) in(x / 10);
    putchar(x % 10 + '0');
}

int tim(int u)
{
    if(u == lt[u]) return u;
    return lt[u] = tim(lt[u]);
}

int main()
{
    // freopen("roads.inp", "r", stdin);
    // freopen("roads.out", "w", stdout);
    n = doc();
    int m = 0;
    for(int i = 1; i <= n; ++i) p[i] = doc(), m = max(m, p[i]);
    sort(p + 1, p + 1 + n);
    n = unique(p + 1, p + 1 + n) - p - 1;
    if(p[1] == 1){putchar('0') ;return 0;}
    for(int i = 1; i <= n; ++i) lt[i] = i;
    for(int u = 1; u < n; ++u)
    {
        int x = p[u], vt = u + 1;
        int v = upper_bound(p + vt, p + 1 + n, x) - p;
        if(v > 0 && v <= n){
            e[min(p[u] % p[v], p[v] % p[u])].push_back(II(u, v));
        }
        int j = 2;
        while(j * x <= p[n])
        {
            int v = lower_bound(p + vt, p + 1 + n, j * x) - p;
            if(v > 0 && v <= n){
              e[min(p[u] % p[v], p[v] % p[u])].push_back(II(u, v));
            }
            j = p[v] / x + 1;
            vt = v + 1;
        }
    }
    int dem = 0;
    for(int i = 0; i < m; ++i)
    for(II T : e[i])
    {
        int u = tim(T.fi), v = tim(T.se);
        if(u != v)
        {
            dem++;
            lt[u] = v;
            ds += i;
        }
        if(dem == n - 1) break;
    }
    in(ds);
}
