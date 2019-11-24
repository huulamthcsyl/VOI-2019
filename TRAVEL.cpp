// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 10 + 1e5, INF = 1e18;

LL n, a[MaxN], m, q, t, b[MaxN];
II x;

LL Calc(LL u, LL l, LL r){
    if(l <= u && r <= u) return u - min(l, r);
    if(l >= u && r >= u) return max(l, r) - u;
    return min(abs(u - l), abs(u - r)) + max(l, r) - min(l, r);
}

void InOut(){
    #define TASK "TRAVEL"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    for(int i = 1 ; i <= m ; ++i) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for(int te = 0 ; te < q ; ++te){
        cin >> t;
        LL l = lower_bound(a + 1, a + n + 1, t) - a;
        LL r = lower_bound(b + 1, b + m + 1, t) - b;
        if(l > n) l--;
        if(r > m) r--;
        LL l1 = a[l], l2 = a[l], r1 = b[r], r2 = b[r];
        if(l > 1) l2 = a[l - 1];
        if(r > 1) r2 = b[r - 1];
        LL kq = INF;
        kq = min(kq, Calc(t, l1, r1));
        kq = min(kq, Calc(t, l2, r1));
        kq = min(kq, Calc(t, l1, r2));
        kq = min(kq, Calc(t, l2, r2));
        cout << kq << endl;
    }

    return 0;
}
