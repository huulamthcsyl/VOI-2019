// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5, INF = 1e12;
 
LL n, a[MaxN], m, x, y, z, d1[MaxN], d2[MaxN], kq = INF;
vector<II> q[MaxN], q1[MaxN];

struct Edge{

    LL u, v, len;

    Edge(LL _u = 0, LL _v = 0, LL _len = 0):u(_u), v(_v), len(_len){}

} e[MaxN];
 
void Dijk1(){
    fill(d1, d1 + n, INF);
    priority_queue<II, vector<II>, greater<II> > qu;
    d1[0] = 0;
    qu.push({0, 0});
    while(!qu.empty()){
        II x = qu.top();
        qu.pop();
        LL u = x.second;
        for(auto v : q[u])
        if(d1[u] + v.second < d1[v.first]){
            d1[v.first] = d1[u] + v.second;
            qu.push({d1[v.first], v.first});
        }
    }
}
 
void Dijk2(){
    fill(d2, d2 + n, INF);
    priority_queue<II, vector<II>, greater<II> > qu;
    d2[n - 1] = 0;
    qu.push({0, n - 1});
    while(!qu.empty()){
        II x = qu.top();
        qu.pop();
        LL u = x.second;
        for(auto v : q1[u])
        if(d2[u] + v.second < d2[v.first]){
            d2[v.first] = d2[u] + v.second;
            qu.push({d2[v.first], v.first});
        }
    }
}
 
void InOut(){
    #define TASK "SHORTEST"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
}
 
int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        x--;
        y--;
        q[x].push_back({y, z});
        q1[y].push_back({x, z});
        e[i] = Edge(x, y, z);
    }
    Dijk1();
    Dijk2();
    for(int i = 0 ; i < m ; ++i){
        LL k = e[i].len + d1[e[i].u] + d2[e[i].v];
        if(k > d1[n - 1]) kq = min(kq, k);  
    }
    if(kq == INF) cout << -1 << endl;
    else cout << kq << endl;
 
    return 0;
} 