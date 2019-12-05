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

const LL MaxN = 1 + 2e7;

LL n, a[16] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000}, d[MaxN], x, t, ma;
pair<LL, LL> c[51];

LL Calc(LL k){
    LL kq = 0;
    for(int i = 14 ; i >= 0 ; --i){
        kq += k / a[i];
        k %= a[i];
    }
    if(k) return 1e18;
    else return kq;
}

void InOut(){
	#define TASK "ODDCOIN"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// Subtask1::Solve();
	cin >> t;
	for(int te = 0 ; te < t ; ++te){
        cin >> x >> n;
        LL k = sqrt(n), kq = 1e18;
        if(x > k){
            for(int i = 0 ; i <= n / x ; ++i) kq = min(kq, i + Calc(n - i * x));
            cout << kq << endl;
            continue;
        }
        memset(d, 0x3f3f, sizeof d);
        d[0] = 0;
        for(int i = 1 ; i <= 200000 ; ++i){
            for(int j = 0 ; j < 15 ; ++j)
            if(a[j] <= i) d[i] = min(d[i], d[i - a[j]] + 1);
            else break;
            if(x <= i) d[i] = min(d[i], d[i - x] + 1);
        }
        if(n <= 200000){
            cout << d[n] << endl;
            continue;
        }
        for(int i = 0 ; i <= 200000 ; ++i)
        kq = min(kq, d[i] * (n / i) + d[n % i]);
        cout << kq << endl;
    }

	return 0;
}
