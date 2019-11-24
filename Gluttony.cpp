// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 2e5;

LL n, a[MaxN], b[MaxN], m;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

LL Check(LL k){
    LL kq = 0;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] * b[i] <= k) continue;
        kq += a[i] - k / b[i];
    }
    return kq <= m;
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n ; ++i) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);
    LL l = 0, r = 1e12;
    while(l < r){
        LL tg = (l + r) / 2;
        if(Check(tg)) r = tg;
        else l = tg + 1;
    }
    cout << l << endl;

    return 0;
}