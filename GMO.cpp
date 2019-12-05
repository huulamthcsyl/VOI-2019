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

const LL MaxN = 1 + 1e4;

LL n, a[MaxN], d[10010][5010];
string s1, s2;

void InOut(){
	#define TASK "GMO"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s1;
	cin >> s2;
	cin >> a['A'] >> a['C'] >> a['G'] >> a['T'];
	LL n = s1.length(), m = s2.length();
	s1 = " " + s1;
	s2 = " " + s2;
	LL ma = 0;
	for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        if(s1[i] == s2[j]) d[i][j] = max(d[i][j], d[i - 1][j - 1] + a[s1[i]]);
        else d[i][j] = d[i][j - 1];
        ma = max(ma, d[i][j]);
    }
    LL k = 0;
    for(int i = 1 ; i <= m ; ++i) k += a[s2[i]];
    cout << k - ma << endl;

	return 0;
}
