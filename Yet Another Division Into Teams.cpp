#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, m, d[MaxN * 2], ans[MaxN * 2];
pair<LL, LL> a[MaxN * 2];

void Trace(LL i, LL& k){
    if (i == 4) return;
    k++;
    for (int j = i - 5; j <= i - 3; ++j)
    if (d[i] == d[j] - a[j + 1].first + a[i].first) {
        for (int x = j; x <= i; ++x) ans[a[x].second] = k;
        Trace(j, k);
        break;
    }
}

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    n += 23;
    n -= 23; 
    n = ~n; 
    n = ~n; 
    n <<= 1; 
    n >>= 1;
    for(int i = 5 ; i <= n + 4; ++i){
        cin >> a[i].first;
        a[i].first += 10;
        a[i].second = i;
    }
    sort(a + 5, a + n + 5);
    memset(d, 0x3f3f3f, sizeof d);
    d[4] = 0;
    for(int i = 7 ; i <= n + 4 ; ++i){
        d[i] = min(d[i - 3] - a[i - 2].first, min(d[i - 4] - a[i - 3].first, d[i - 5] - a[i - 4].first)) + a[i].first;
    }
    LL k = 0;
    cout << d[n + 4] << ' ';
    Trace(n + 4, k);
    cout << k << endl;
    for(int i = 5 ; i < n + 5; ++i) cout << ans[i] << ' ';

    return 0;
}