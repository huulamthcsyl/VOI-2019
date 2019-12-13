// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

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

// #define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
	return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
	t = 0; char ch = getchar(); int f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 2e5;

LL n, a[MaxN], kq, k, m, root[MaxN], vis[MaxN], d[MaxN], mark[MaxN], kt[MaxN], rt, x, y, z, h;
vector<LL> q[MaxN];

struct Edge{

    LL u, v, len;

    Edge(LL _u = 0, LL _v = 0, LL _len = 0):u(_u), v(_v), len(_len){}

    bool operator < (const Edge &op) const{
        return len < op.len;
    }

} e[MaxN], ne[MaxN];

inline LL getRoot(LL u){
    if(u == root[u]) return u;
    return root[u] = getRoot(root[u]);
}

void DFS(LL u){
    vis[u] = 1;
    if(d[u]) mark[u] = 1;
    for(int i : q[u]){
        LL v = ne[i].u + ne[i].v - u;
        if(vis[v]) continue;
        DFS(v);
        if(!mark[v]) kt[i] = 1;
        mark[u] = max(mark[u], mark[v]);
    }
}

void InOut(){
	#define TASK "KUPROAD"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n >> k >> m){
        memset(d, 0, sizeof d);
        memset(mark, 0, sizeof mark);
        memset(kt, 0, sizeof kt);
        memset(vis, 0, sizeof vis);
        h = 0;
        for(int i = 0 ; i < n ; ++i) q[i].clear();
        kq = 0;
        for(int i = 0 ; i < k ; ++i){
            cin >> rt;
            rt--;
            d[rt] = 1;
        }
        for(int i = 0 ; i < m ; ++i){
            cin >> x >> y >> z;
            x--;
            y--;
            e[i] = Edge(x, y, z);
        }
        sort(e, e + m);
        for(int i = 0 ; i < n ; ++i) root[i] = i;
        for(int i = 0 ; i < m ; ++i){
            LL u = e[i].u, v = e[i].v;
            LL ru = getRoot(u), rv = getRoot(v);
            if(ru == rv) continue;
            root[ru] = rv;
            ne[h] = Edge(u, v, e[i].len);
            q[u].push_back(h);
            q[v].push_back(h);
            h++;
        }
        // for(int i = 0 ; i < h ; ++i) cout << ne[i].u << " " << ne[i].v << " " << ne[i].len << endl;
        DFS(rt);
        for(int i = 0 ; i < h ; ++i)
        if(!kt[i]) kq += e[i].len;
        cout << kq << endl;
	}

	return 0;
}
