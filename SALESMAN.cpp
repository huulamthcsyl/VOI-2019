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

const LL MaxN = 1 + 2e3, INF = 1e18;

LL n, a[MaxN][MaxN], d[MaxN][MaxN], kq = INF;

void InOut(){
	#define TASK "SALESMAN"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= n ; ++j) cin >> a[i][j];
    memset(d, 0x3f3f, sizeof d);
    d[1][2] = a[1][2];
    d[2][1] = a[1][2];
    for(int i = 3 ; i <= n ; ++i){
        for(int j = 1 ; j < i - 1 ; ++j){
            d[j][i] = min(d[j][i], d[j][i - 1] + a[i - 1][i]);
            d[i][i - 1] = min(d[i][i - 1], d[j][i - 1] + a[i][j]);
        }
        for(int j = 1 ; j < i - 1 ; ++j){
            d[i][j] = min(d[i][j], d[i - 1][j] + a[i][i - 1]);
            d[i - 1][i] = min(d[i - 1][i], d[i - 1][j] + a[j][i]);
        }
    }
    for(int i = 1 ; i < n ; ++i) kq = min(kq, min(d[i][n], d[n][i]));
    cout << kq << endl;

	return 0;
}
