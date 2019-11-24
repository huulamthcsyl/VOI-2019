// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e2;

LL n, a[MaxN], f[MaxN][MaxN];
pair<LL, LL> b[MaxN];

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    cin >> m;
    for(int i = 0 ; i < m ; ++j) cin >> b[i].first >> b[i].second;
    for(int i = 0 ; i < n ; ++i){
        memset(f, 0, sizeof f);
        for(int i = 1 ; i <= a[i] ; ++i)
        for(int j = 0 ; j < m ; ++j)
        if(i >= b[j].first) f[i] = max(f[i], f[i - b[j].first] + b[j].second);
    }

    return 0;
}