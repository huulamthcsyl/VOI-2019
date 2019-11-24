// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 2e5;

LL n, a[MaxN], x, m, hmax, vis[MaxN], node[MaxN], kq;
vector<LL> q[MaxN];

void DFS(LL u, LL pr, LL h){
    hmax = max(h, hmax);
    for(int v : q[u])
    if(v != pr) DFS(v, u, h + 1);
}

void Solve(LL u){
    vis[u] = 1;
    if(q[u].empty()){
        node[u] = hmax * (m - 1) + 1;
        return;
    }
    node[u] = 1;
    for(int v : q[u])
    if(!vis[v]){
        Solve(v);
        kq = max(kq, node[u] + node[v]);
        node[u] = max(node[u], node[v] + 1);
    }
}

void InOut(){
    #define TASK "TREEPOW"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 2 ; i <= n ; ++i){
        cin >> x;
        q[x].push_back(i);
    }
    DFS(1, 0, 1);
    Solve(1);
    cout << kq << endl;

    return 0;
}