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

const LL MaxN = 1 + 1e3;

LL n, f[MaxN][MaxN], kq;
II a[MaxN];

inline LL ccw(II x, II y, II z){
    return (y.first - x.first) * (y.second + x.second) + (z.first - y.first) * (z.second + y.second) + (x.first - z.first) * (x.second + z.second);
}

inline LL cmp(II x, II y){
    return ccw({0, 0}, x, y) < 0;
}

void InOut(){
	#define TASK "DPOLY"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; ++i) cin >> a[i].first >> a[i].second;
	sort(a, a + n, cmp);
	// for(int i = 0 ; i < n ; ++i) cout << a[i].first << " " << a[i].second << endl;
	for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < i ; ++j){
            f[i][j] = 3;
            for(int k = 0 ; k < j ; ++k)
            if(ccw(a[k], a[j], a[i]) < 0) f[i][j] = max(f[i][j], f[j][k] + 1);
            kq = max(kq, f[i][j]);
        }
	}
	cout << kq << endl;

	return 0;
}
