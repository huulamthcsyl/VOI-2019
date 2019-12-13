// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long LL;

#define y0 Sword_Art_Online
#define y1 Your_lie_in_April
#define yn Darling_in_the_Franxx
#define tm Plastic_Memories
#define lr Charlotte
#define norm Weathering_with_you
#define left Violet_Evergarden
#define have Date_a_live
#define ends Your_name
#define prev Five_centimeters_per_second
#define hash Slient_voice

#define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e6;

LL n, a[MaxN], m, x, y, id[MaxN], low[MaxN], num[MaxN], ntime, vis[MaxN], ncc, kt[MaxN], t, kq[MaxN], sum[MaxN];
vector<LL> q[MaxN];
vector< pair<LL, LL> > q1[MaxN];

struct Edge{

    LL u, v, id;

    Edge(LL _u = 0, LL _v = 0, LL _id = 0):u(_u), v(_v), id(_id){}

    bool operator < (const Edge &op) const{
        if(u == op.u) return v < op.v;
        return u < op.u;
    }

} e[MaxN], ne[MaxN];

map<Edge, LL> d;

void DFS(LL u, LL pr){
    num[u] = low[u] = ++ntime;
    vis[u] = 1;
    for(int i : q[u]){
        LL v = e[i].u + e[i].v - u;
        if(v == pr) continue;
        if(num[v]) low[u] = min(low[u], num[v]);
        else{
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[v] && d[Edge(u, v)] == 1) kt[e[i].id] = 1;
        }
    }
}

void mergeNode(LL u){
    vis[u] = 1;
    id[u] = ncc;
    for(int i : q[u]){
        LL v = e[i].u + e[i].v - u;
        if(vis[v]) continue;
        if(kt[e[i].id]) continue;
        mergeNode(v);
    }
}

void Calc(LL u){
    vis[u] = 1;
    for(auto i : q1[u]){
        LL v = ne[i.first].u + ne[i.first].v - u;
        if(vis[v]) continue;
        Calc(v);
        if(sum[v] > 0){
            if(i.second == 0) kq[i.first] = 1;
            else kq[i.first] = 2;
        }
        else if(sum[v] < 0){
            if(i.second == 0) kq[i.first] = 2;
            else kq[i.first] = 1;
        }
        sum[u] += sum[v];
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
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y;
        x--;
        y--;
        if(x == y) continue;
        d[Edge(x, y)]++;
        d[Edge(y, x)]++;
        e[i] = Edge(x, y, i);
        q[x].push_back(i);
        q[y].push_back(i);
    }
    for(int i = 0 ; i < n ; ++i)
    if(!vis[i]) DFS(i, i);
    // for(int i = 0 ; i < m ; ++i) cout << kt[i] << " ";
    // cout << endl;
    memset(vis, 0, sizeof vis);
    for(int i = 0 ; i < n ; ++i)
    if(!vis[i]){
        mergeNode(i);
        ncc++;
    }
    // for(int i = 0 ; i < n ; ++i) cout << id[i] << " ";
    // cout << endl;
    for(int i = 0 ; i < m ; ++i){
        LL u = e[i].u, v = e[i].v;
        if(id[u] == id[v]) continue;
        ne[i] = Edge(id[u], id[v], i);
        q1[id[u]].push_back({i, 0});
        q1[id[v]].push_back({i, 1});
    }
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> x >> y;
        x--;
        y--;
        sum[id[x]]++;
        sum[id[y]]--;
    }
    memset(vis, 0, sizeof vis);
    for(int i = 0 ; i < n ; ++i)
    if(!vis[i]) Calc(i);
    for(int i = 0 ; i < m ; ++i)
    if(kq[i] == 1) cout << 'L';
    else if(kq[i] == 2) cout << 'R';
    else cout << 'B';

    return 0;
}