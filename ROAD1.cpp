// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5, INF = 1e15;

LL n, a[MaxN], u, v, ch, l, m, s[MaxN], d[MaxN];
vector<II> q[MaxN];

void Dijk(){
    fill(s, s + n, INF);
    memset(d, 0, sizeof d);
    s[0] = 0;
    d[0] = 1;
    priority_queue<II, vector<II>, greater<II> > qu;
    qu.push({0, 0});
    while(!qu.empty()){
        II x = qu.top();
        qu.pop();
        LL u = x.second;
        if(x.first > s[u]) continue;
        for(auto v : q[u]){
            if(s[u] + v.second > s[v.first]) continue;
            if(s[u] + v.second == s[v.first]) d[v.first] = d[v.first] + d[u];
            else{
                s[v.first] = s[u] + v.second;
                d[v.first] = d[u];
                qu.push({s[v.first], v.first});
            }
        }
    }
}

void InOut(){
    #define TASK "ROAD1"
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
        cin >> ch >> u >> v >> l;
        u--;
        v--;
        q[u].push_back({v, l});
        if(ch == 2) q[v].push_back({u, l});
    }
    Dijk();
    cout << s[n - 1] << " " << d[n - 1] << endl;

    return 0;
}