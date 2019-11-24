// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, x, y, deg[MaxN], kq[MaxN], ans, vis[MaxN], ma;
vector<LL> q[MaxN];
priority_queue<LL> pq;

void DFS(LL u){
    vis[u] = 1;
    kq[u] = pq.top();
    pq.pop();
    for(int v : q[u])
    if(!vis[v]){
        DFS(v);
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
    for(int i = 0 ; i < n - 1 ; ++i){
        cin >> x >> y;
        q[x].push_back(y);
        q[y].push_back(x);
        deg[x]++;
        deg[y]++;
        if(deg[x] > deg[ma]) ma = x;
        if(deg[y] > deg[ma]) ma = y;
    }
    for(int i = 0 ; i < n ; ++i){
        cin >> x;
        pq.push(x);
        ans += x;
    }
    ans -= pq.top();
    DFS(ma);
    cout << ans << endl;
    for(int i = 1 ; i <= n ; ++i) cout << kq[i] << " ";

    return 0;
}