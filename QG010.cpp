// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], x, y, z, t, m, s[MaxN];
vector<II> q[MaxN];

void Dijk(){
    priority_queue<II> pq;
    pq.push({0, 0});
    s[0] = 1e9;
    while(!pq.empty()){
        II x = pq.top();
        pq.pop();
        LL u = x.second;
        for(II v : q[u])
        if(min(v.second, s[u]) > s[v.first]){
            s[v.first] = min(v.second, s[u]);
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
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        x--;
        y--;
        q[x].push_back({y, z});
        q[y].push_back({x, z});
    }
    Dijk();
    for(int te = 0 ; te < t ; ++te){
        cin >> x;
        x--;
        cout << s[x] << endl;
    }

    return 0;
}