// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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

#define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e6, MOD = 1e9 + 7;

LL n, a[MaxN], k, kq, gt[MaxN];

LL Mu(LL a, LL n){
    if(n == 0) return 1;
    LL tg = Mu(a, n / 2);
    if(n % 2) return (((tg * tg) % MOD) * a) % MOD;
    return (tg * tg) % MOD;
}

LL C(LL n, LL k){
    return (gt[n] * Mu((gt[k] * gt[n - k]) % MOD, MOD - 2)) % MOD;
}

void InOut(){
    #define TASK "B"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    gt[0] = 1;
    for(int i = 1 ; i <= 1e6 ; ++i) gt[i] = (gt[i - 1] * i) % MOD;
    for(int i = 0 ; i <= k ; ++i){
        LL x = k - i;
        if(abs(x - i) % n != 0) continue;
        kq = (kq + C(k, i)) % MOD;
    }
    cout << kq << endl;

    return 0;
}