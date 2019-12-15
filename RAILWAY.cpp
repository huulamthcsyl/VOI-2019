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

const LL MaxN = 1 + 3e5, INF = 1e18;

LL n, a[MaxN], d[MaxN], mi[MaxN], kq, x, y, z, s, trace[MaxN], m, ma = -1e18, pos;
vector<LL> q[MaxN];
vector<LL> ans;

struct Edge{

    LL u, v, len;

    Edge(LL _u = 0, LL _v = 0, LL _len = 0):u(_u), v(_v), len(_len){}

} e[MaxN];

void Dijk(){
    fill(d + 1, d + n + 1, INF);
    d[s] = a[s];
    priority_queue<II, vector<II>, greater<II> > pq;
    mi[s] = a[s];
    pq.push({d[s], s});
    while(!pq.empty()){
        II temp = pq.top();
        pq.pop();
        LL u = temp.second, len = temp.first;
        for(int i : q[u]){
            LL v = e[i].v;
            LL tlen = len;
            tlen -= mi[u];
            if(tlen + e[i].len + min(a[v], mi[u]) < d[v]){
                d[v] = tlen + e[i].len + min(a[v], mi[u]);
                mi[v] = min(a[v], mi[u]);
                trace[v] = i;
                pq.push({d[v], v});
            }
        }
    }
}

void InOut(){
	#define TASK "RAILWAY"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1 ; i <= n ; ++i) cin >> a[i];
	for(int i = 1 ; i <= m ; ++i){
        cin >> x >> y >> z;
        e[i] = Edge(x, y, z);
        q[x].push_back(i);
	}
	Dijk();
	for(int i = 1 ; i <= n ; ++i)
    if(d[i] != INF && d[i] > ma){
        ma = d[i];
        pos = i;
    }
    cout << ma << " " << pos << endl;
    while(trace[pos]){
         ans.push_back(trace[pos]);
         LL temp = pos;
         pos = e[trace[pos]].u;
         trace[temp] = 0;
    }
    cout << ans.size() << endl;
    for(int i = ans.size() - 1 ; i >= 0 ; --i) cout << ans[i] << " ";

	return 0;
}
