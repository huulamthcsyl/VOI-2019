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

const LL MaxN = 1 + 3e5;

LL n, mark[MaxN], m;
vector<LL> cl[3], q[MaxN];
pair<LL, LL> a[MaxN];

LL Check(LL u, LL color = 1) {
    mark[u] = color;
    cl[2 - color].push_back(u);
    LL ans = 1;
    for(int v : q[u]){
        if(!mark[v] && !Check(v, 3 - mark[u])) ans = 0;
        if(mark[v] == color) ans = 0;
    }
    return ans;
}

void InOut(){
	#define TASK "RHETORIC"
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
	for(int i = 1 ; i <= m ; ++i) cin >> a[i].first >> a[i].second;
	LL l = 1, r = m;
	/*for(int i = 1 ; i <= 5 ; ++i){
        q[a[i].first].push_back(a[i].second);
        q[a[i].second].push_back(a[i].first);
	}
	cout << Check(1) << endl;*/
	while(l < r){
        LL tg = (l + r + 1) / 2;
        cl[1].clear();
        cl[0].clear();
        fill(mark + 1, mark + n + 1, 0);
        for(int i = 1 ; i <= n ; ++i) q[i].clear();
        for(int i = 1 ; i <= tg ; ++i){
            q[a[i].first].push_back(a[i].second);
            q[a[i].second].push_back(a[i].first);
        }
        if(Check(a[l].first)) l = tg;
        else r = tg - 1;
	}
	cout << l + 1 << endl;

	return 0;
}
