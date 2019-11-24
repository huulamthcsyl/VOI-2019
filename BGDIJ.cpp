// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5, INF = 1e9;

LL n, a[MaxN], u, v, m, x, y, z, s[MaxN];
vector<II> q[MaxN];

void Dijk(){
    fill(s + 1, s + n + 1, INF);
    s[u] = 0;
    priority_queue<II, vector<II>, greater<II> > pq;
    pq.push({0, u});
    while(!pq.empty()){
        II x = pq.top();
        pq.pop();
        LL u = x.second;
        for(II v : q[u])
        if(s[u] + v.second < s[v.first]){
            s[v.first] = s[u] + v.second;
            pq.push({s[v.first], v.first});
        }
    }
}

void InOut(){
    #define TASK "BGDIJ"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> u >> v;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        q[x].push_back({y, z});
        q[y].push_back({x, z});
    }
    Dijk();
    if(s[v] == INF) cout << -1 << endl;
    else cout << s[v] << endl;

    return 0;
}