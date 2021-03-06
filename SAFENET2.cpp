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

LL n, a[MaxN], x, y, m, vis[MaxN], root[MaxN], d[MaxN], kq, parent[MaxN];
vector<LL> q[MaxN];
stack<LL> s;

inline LL getRoot(LL u){
    if(u == root[u]) return u;
    return root[u] = getRoot(root[u]);
}

void DFS(LL u){
    s.push(u);
    vis[u] = 1;
    for(int v : q[u])
    if(vis[v]){
        v = getRoot(parent[v]);
        while(!s.empty() && s.top() != v){
            root[s.top()] = v;
            s.pop();
        }
    }
    for(int v : q[u])
    if(!vis[v]){
        parent[u] = v;
        DFS(v);
    }
    if(!s.empty() && s.top() == u) s.pop();
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
    cin >> n >> m;
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    for(int i = 1 ; i <= n ; ++i) root[i] = i;
    for(int i = 1 ; i <= n ; ++i)
    if(!vis[i]) DFS(i);
    for(int i = 1 ; i <= n ; ++i){
        d[getRoot(i)]++;
        kq = max(kq, d[getRoot(i)]);
    }
    cout << kq + 1 << endl;

    return 0;
}