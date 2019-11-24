// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], d[MaxN], b[MaxN], s, ans;

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
    for(int i = 0 ; i < n ; ++i){
        cin >> b[i];
        if(b[i] > a[i]) s += (a[i] - b[i]);
        d[i] = a[i] - b[i];
    }
    sort(d, d + n);
    for(int i = 0 ; i < n ; ++i){
        if(s >= 0) break;
        s += d[i];
        ans++;
    }
    if(s < 0) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}