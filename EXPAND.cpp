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

const LL MaxN = 1 + 1e3, up[4] = {-1, 0, 1, 0}, ri[4] = {0, 1, 0, -1};

LL n, d[10], x, y, m, b[10], k, ma;
queue<II> q[10];
char a[MaxN][MaxN];

LL Avaiable(LL x, LL y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void Loang(LL u){
    for(int r = 0 ; r < b[u] ; ++r){
        LL sz = q[u].size();
        if(sz == 0) break;
        for(int j = 0 ; j < sz ; ++j){
            II x = q[u].front();
            q[u].pop();
            for(int i = 0 ; i < 4 ; ++i){
                LL xx = x.first + up[i], yy = x.second + ri[i];
                if(Avaiable(xx, yy) && a[xx][yy] == '.'){
                    a[xx][yy] = char(u + '0');
                    q[u].push({xx, yy});
                }
            }
        }
    }
}

void InOut(){
	#define TASK "EXPAND"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= k ; ++i) cin >> b[i];
	for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j){
        cin >> a[i][j];
        if(isdigit(a[i][j])){
            q[a[i][j] - '0'].push({i, j});
        }
    }
    while(1){
        LL cnt = 0;
        for(int i = 1 ; i <= k ; ++i){
            Loang(i);
            cnt += (q[i].size() == 0);
        }
        if(cnt == k) break;
    }
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
    if(a[i][j] != '#') d[a[i][j] - '0']++;
    for(int i = 1 ; i <= k ; ++i) cout << d[i] << " ";

	return 0;
}
