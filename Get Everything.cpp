// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6, INF = 1e12;

LL n, a[MaxN], d[MaxN], m, x, y, t, kq[MaxN], s;

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
    cin >> n >> m;
    fill(kq + 1, kq + (1 << n) + 1, INF);
    for(int i = 0 ; i < m ; ++i){
        cin >> a[i] >> y;
        LL k = 0;
        for(int j = 0 ; j < y ; ++j){
            cin >> x;
            x--;
            k |= (1 << x);
        }
        d[i] = k;
        // cout << k << endl;
    }
    for(int i = 0 ; i <= (1 << n) - 1 ; ++i)
    for(int j = 0 ; j < m ; ++j) 
    kq[i | d[j]] = min(kq[i | d[j]], kq[i] + a[j]);
    // for(int i = 1 ; i <= (1 << n) - 1 ; ++i) cout << kq[i] << " ";
    // cout << endl;
    if(kq[(1 << n) - 1] == INF) cout << -1 << endl;
    else cout << kq[(1 << n) - 1] << endl;

    return 0;
}