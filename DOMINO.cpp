// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

const LL MaxN = 1 + 1e3;

LL n, a[MaxN], sl[MaxN], vis[MaxN], d[MaxN][MaxN], x, y, m, ans, deg[MaxN], kq, kt[MaxN][MaxN];
vector<LL> q[MaxN];

void DFS(LL u){
    vis[u] = 1;
    kq += deg[u] % 2;
    deg[u] = 0;
    for(int i : q[u])
    if(!vis[i] && deg[i]) DFS(i);
}

void InOut(){
	#define TASK "DOMINO"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> m;
	for(int i = 0 ; i < m ; ++i){
        cin >> x >> y;
        kt[x][y] = 1;
        kt[y][x] = 1;
	}
	for(int i = 0 ; i <= n ; ++i)
    for(int j = i ; j <= n ; ++j)
    if(!kt[i][j]){
        q[i].push_back(j);
        q[j].push_back(i);
        deg[i]++;
        deg[j]++;
    }
    for(int i = 0 ; i <= n ; ++i)
    if(!vis[i] && deg[i]){
        kq = 0;
        DFS(i);
        if(kq == 0) ans++;
        else ans += kq / 2;
    }
    cout << ans << endl;

	return 0;
}
