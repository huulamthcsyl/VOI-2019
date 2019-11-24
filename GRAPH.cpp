// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e6, INF = 1e18;

LL n, a[MaxN], m, x, y, s[MaxN];
vector<LL> in, out;
vector<II> q[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void BFS(){
    fill(s, s + n, INF);
    s[0] = 0;
    queue<II> qu;
    qu.push({0, 0});
    while(!qu.empty()){
        II x = qu.front();
        qu.pop();
        LL u = x.second;
        if(u == n - 1) continue;
        for(II v : q[u])
        if(s[u] + v.second < s[v.first]){
            s[v.first] = s[u] + v.second;
            qu.push({s[v.first], v.first});
        }
    }
}

void InOut(){
    #define TASK "GRAPH"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    for(int i = 0 ; i < m ; ++i){
        read(x);
        read(y);
        x--;
        y--;
        q[x].push_back({y, 0});
        q[y].push_back({x, 1});
    }
    BFS();
    if(s[n - 1] != INF) cout << s[n - 1] << endl;
    else cout << -1 << endl;

    return 0;
}