// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, x, y, l, d[MaxN], kq;

void InOut(){
    #define TASK "CONTACT"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> l;
        d[y]++;
        d[y + l + 1]--;
    }
    for(int i = 1 ; i <= n ; ++i){
        d[i] = d[i - 1] + d[i];
        if(d[i] == 0) kq++;
    }
    if(kq == 0) cout << 0 << endl;
    else cout << (1 << kq) << endl;

    return 0;
}