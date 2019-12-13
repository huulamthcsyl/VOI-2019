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

const LL MaxN = 1 + 5e5;

LL n, a[MaxN], subtask, kq, ans = 1e18, x, y;

LL GCD(LL x, LL y){
    if(x < y) swap(x, y);
    while(y){
        LL tg = y;
        y = x % y;
        x = tg;
    }
    return x;
}

void Calc(){
    LL m = GCD(a[1], a[2]);
    for(int i = 3 ; i <= n ; ++i) m = GCD(m, a[i]);
    if(m > 1) ans = min(ans, kq);
}

void Try(LL k){
    if(k == n + 1){
        Calc();
        return;
    }
    for(int i = 0 ; i < 4 ; ++i){
        if(i == 0) Try(k + 1);
        if(i == 1){
            a[k]--;
            kq += y;
            Try(k + 1);
            kq -= y;
            a[k]++;
        }
        if(i == 2){
            a[k]++;
            kq += y;
            Try(k + 1);
            kq -= y;
            a[k]--;
        }
        if(i == 3 && a[k - 1] == 0){
            LL temp = a[k];
            a[k] = 0;
            kq += x;
            Try(k + 1);
            kq -= x;
            a[k] = temp;
        }
    }
}

void InOut(){
	#define TASK "HSGS"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> subtask;
	cin >> n >> x >> y;
	for(int i = 1 ; i <= n ; ++i) cin >> a[i];
	Try(1);
	cout << ans << endl;

	return 0;
}
