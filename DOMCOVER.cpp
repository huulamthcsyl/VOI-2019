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

LL n, a[MaxN][4], d[MaxN][8][MaxN], kq[MaxN][MaxN], k;

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
	cin >> n >> k;
	for(int i = 1 ; i <= n ; ++i) cin >> a[i][1] >> a[i][2] >> a[i][3];
	d[1][0][0] = 0;
	d[1][6][1] = a[1][1] + a[1][2];
	d[1][3][1] = a[1][2] + a[1][3];
	kq[1][1] = -1e18;
	for(int i = 0 ; i < 8 ; ++i) kq[1][1] = max(kq[1][1], d[1][i][1]);
	for(int i = 2 ; i <= n ; ++i){
		for(int h = 1 ; h <= k ; ++h){
			for(int j = 0 ; j < 8 ; ++j) d[i][j][h] = -1e18;
			d[i][0][h] = kq[i - 1][h];
			if(h == 1) d[i][1][h] = max(d[i][1][h], kq[i - 2][h - 1] + a[i - 1][3] + a[i][3]);
			else d[i][1][h] = max(d[i][1][h], max(kq[i - 2][h - 1] + a[i - 1][3] + a[i][3], kq[i - 2][h - 2] + a[i - 1][1] + a[i - 1][2] + a[i - 1][3] + a[i][3]));
			d[i][2][h] = max(d[i][2][h], kq[i - 2][h - 1] + a[i - 1][2] + a[i][2]);
			if(h > 1) d[i][3][h] = max(d[i][3][h], max(kq[i - 1][h - 1] + a[i][2] + a[i][3], kq[i - 2][h - 2] + a[i - 1][2] + a[i][2] + a[i - 1][3] + a[i][3]));
			else d[i][3][h] = max(d[i][3][h], kq[i - 1][h - 1] + a[i][2] + a[i][3]);
			if(h == 1) d[i][4][h] = max(d[i][4][h], kq[i - 2][h - 1] + a[i - 1][1] + a[i][1]);
			else d[i][4][h] = max(d[i][4][h], max(kq[i - 2][h - 1] + a[i - 1][1] + a[i][1], kq[i - 2][h - 2] + a[i - 1][1] + a[i - 1][2] + a[i - 1][3] + a[i][1]));
			if(h > 1) d[i][5][h] = max(d[i][5][h], kq[i - 2][h - 2] + a[i - 1][1] + a[i][1] + a[i - 1][3] + a[i][3]);
			if(h > 1) d[i][6][h] = max(d[i][6][h], max(kq[i - 1][h - 1] + a[i][1] + a[i][2], kq[i - 2][h - 2] + a[i - 1][1] + a[i - 1][2] + a[i][1] + a[i][2]));
			else d[i][6][h] = max(d[i][6][h], kq[i - 1][h - 1] + a[i][1] + a[i][2]);
			if(h > 2) d[i][7][h] = max(d[i][7][h], kq[i - 2][h - 3] + a[i - 1][1] + a[i - 1][2] + a[i - 1][3] + a[i][1] + a[i][2] + a[i][3]);
			kq[i][h] = -1e18;
			for(int j = 0 ; j < 8 ; ++j) kq[i][h] = max(kq[i][h], d[i][j][h]);
		}
	}
	cout << d[2][1][1] << endl;

	return 0;
}
