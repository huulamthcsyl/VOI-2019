// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 3e3, INF = 1e15;

LL n, a[MaxN], m, x, y, d[MaxN][MaxN], u1, v1, l1, u2, v2, l2, kq;
vector<LL> q[MaxN];

void Dijk(LL _u){
    for(int i = 1 ; i <= n ; ++i) d[_u][i] = INF;
    d[_u][_u] = 0;
    priority_queue<II, vector<II>, greater<II> > pq;
    pq.push({0, _u});
    while(!pq.empty()){
        II x = pq.top();
        pq.pop();
        LL u = x.second;
        for(int v : q[u])
        if(d[_u][u] + 1 < d[_u][v]){
            d[_u][v] = d[_u][u] + 1;
            pq.push({d[_u][v], v});
        }
    }
}

void InOut(){
    #define TASK "DSTRROAD"
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
        cin >> x >> y;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    for(int i = 1 ; i <= n ; ++i) Dijk(i);
    cin >> u1 >> v1 >> l1;
    cin >> u2 >> v2 >> l2;
    if(d[u1][v1] > l1 || d[u2][v2] > l2){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= n ; ++j){
        LL x1 = d[u1][i] + d[i][j] + d[j][v1];
        LL x2 = d[u2][i] + d[i][j] + d[j][v2];
        if(x1 <= l1 && x2 <= l2) kq = max(kq, m - (x1 + x2 - d[i][j]));
    }
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= n ; ++j){
        LL x1 = d[v1][i] + d[i][j] + d[j][u1];
        LL x2 = d[u2][i] + d[i][j] + d[j][v2];
        if(x1 <= l1 && x2 <= l2) kq = max(kq, m - (x1 + x2 - d[i][j]));
    }
    kq = max(kq, m - d[u1][v1] - d[u2][v2]);
    cout << kq << endl;

    return 0;
}