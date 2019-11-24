// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 2e5;

LL n, a[MaxN], q1, q2, f[MaxN], g[MaxN], d[MaxN], k, b[MaxN];

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
    cin >> n >> k;
    for(int i = 1 ; i < n ; ++i){
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    for(int i = 1 ; i < n ; ++i){
        cin >> b[i];
        g[i] = g[i - 1] + b[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        d[i] = min(q1 + f[i - 1], q2 + g[i - 1] + k);
        q1 = min(q1, d[i] - f[i - 1]);
        q2 = min(q2, d[i] - g[i - 1]);
        cout << d[i] << " ";
    }

    return 0;
}