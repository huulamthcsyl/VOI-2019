// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, k, x, t, y, z, root[MaxN], nt, query, vis[MaxN], ma, f[MaxN], d[MaxN];
vector<II> q[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

struct Edge{
    
    LL u, v, len;

    Edge(LL _u = 0, LL _v = 0, LL _len = 0):u(_u), v(_v), len(_len){}

    bool operator < (const Edge& op) const{
        return len < op.len;
    }

} e[MaxN];

LL getRoot(LL u){
    if(u == root[u]) return u;
    return root[u] = getRoot(root[u]);
}

void DFS(LL u){
    vis[u] = 1;
    for(auto i : q[u])
    if(!vis[i.first]){
        f[i.first] = max(f[u], i.second);
        if(d[i.first]) ma = max(ma, f[i.first]);
        DFS(i.first);
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
    read(n);
    read(m);
    read(t);
    for(int i = 0 ; i < t ; ++i){
        read(x);
        x--;
        d[x] = 1;
        query = x;
    }
    for(int i = 0 ; i < m ; ++i){
        read(x);
        read(y);
        read(z);
        x--;
        y--;
        e[i] = Edge(x, y, z);
    }
    sort(e, e + m);
    for(int i = 0 ; i < n ; ++i) root[i] = i;
    for(int i = 0 ; i < m ; ++i){
        LL u = e[i].u, v = e[i].v, len = e[i].len;
        LL ru = getRoot(u), rv = getRoot(v);
        if(ru == rv) continue;
        root[ru] = rv;
        q[u].push_back({v, len});
        q[v].push_back({u, len});
    }
    DFS(query);
    for(int i = 0 ; i < t ; ++i) cout << ma << " ";

    return 0;
}