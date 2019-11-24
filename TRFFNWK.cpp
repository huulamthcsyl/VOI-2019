// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5, INF = 1e15;

LL n, a[MaxN], x, y, z, m, k, u, v, s[MaxN], kq = INF;
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
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> u >> v;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        q[x].push_back({y, z});
    }
    // Dijk();
    // cout << s[n] << endl;
    for(int i = 0 ; i < k ; ++i){
        cin >> x >> y >> z;
        q[x].push_back({y, z});
        q[y].push_back({x, z});
        Dijk();
        kq = min(kq, s[v]);
        q[x].pop_back();
        q[y].pop_back();
    }
    if(kq == INF) cout << -1 << endl;
    else cout << kq << endl;

    return 0;
}