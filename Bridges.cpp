// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], x, y, z, m, ch, kq, t, vis[MaxN], d[MaxN];
vector<LL> q[MaxN];

struct Edge{

    LL u, v, weight;

    Edge(LL _u = 0, LL _v = 0, LL _weight = 0):u(_u), v(_v), weight(_weight){}

} e[MaxN];

void InOut(){
    #define TASK "Bridges"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

void DFS(LL u, LL k){
    kq++;
    vis[u] = 1;
    for(int v : q[u])
    if(!vis[e[v].u + e[v].v - u] && e[v].weight >= k) DFS(e[v].u + e[v].v - u, k);
}

void Subtask1(){
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        x--;
        y--;
        q[x].push_back(i);
        q[y].push_back(i);
        e[i] = Edge(x, y, z);
    }
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> ch >> x >> y;
        x--;
        if(ch == 1){
            e[x] = Edge(e[x].u, e[x].v, y);
            continue;
        }
        kq = 0;
        memset(vis, 0, sizeof vis);
        DFS(x, y);
        cout << kq << endl;
    }

}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(n <= 1000 && m <= 1000) Subtask1();
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        d[i] = z;
    }
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> ch >> x >> y;
    }
    
    return 0;
}