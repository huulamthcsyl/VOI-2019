// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e3, INF = 1e15;

LL n, a[MaxN], d[MaxN][MaxN], x, y, z, m, t;

void InOut(){
    #define TASK "BGFLOYD"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= n ; ++j)
    if(i != j) d[i][j] = INF;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
        d[y][x] = min(d[y][x], z);
    }
    for(int k = 1 ; k <= n ; ++k)
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= n ; ++j)
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> x >> y;
        if(d[x][y] == INF) cout << -1 << endl;
        else cout << d[x][y] << endl;
    }

    return 0;
}