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

const LL MaxN = 1 + 3e5, MOD = 1e9 + 7;

LL n, a[MaxN], x, y, z, kq;

map<II, LL> d;
vector<II> q;

LL GCD(LL x, LL y){
    if(x < y) swap(x, y);
    while(y){
        LL tg = y;
        y = x % y;
        x = tg;
    }
    return x;
}

LL Mu(LL a, LL n){
    if(n == 0) return 1;
    LL tg = Mu(a, n / 2);
    if(n % 2) return (((tg * tg) % MOD) * a) % MOD;
    return (tg * tg) % MOD;
}

void InOut(){
	#define TASK "TRICOUNT"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
        cin >> x >> y >> z;
        LL m = GCD(x, y);
        x /= m;
        y /= m;
        if(x < 0){
            x *= -1;
            y *= -1;
        }
        d[{x, y}]++;
        if(d[{x, y}] == 1) q.push_back({x, y});
	}
	LL s = 0, s1 = 0;
	for(int i = 0 ; i < q.size() ; ++i){
        s += d[q[i]];
        s1 += d[q[i]] * d[q[i]];
	}
	for(int i = 0 ; i < q.size() ; ++i){
        LL x1 = s - d[q[i]], x2 = s1 - d[q[i]] * d[q[i]];
        kq = (kq + (d[q[i]] * (((x1 * x1 - x2) / 2) % MOD) % MOD)) % MOD;
	}
	cout << (kq * Mu(3, MOD - 2)) % MOD << endl;

	return 0;
}
