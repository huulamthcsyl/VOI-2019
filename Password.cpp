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

const LL MaxN = 1 + 1e6, BASE = 337, MOD = 1e9 + 7;

LL n, a[MaxN], po[MaxN], d[MaxN];
string s;

inline LL getHash(LL l, LL r){
    return (d[r] - d[l - 1] * po[r - l + 1] + MOD * MOD) % MOD;
}

LL Check(LL k, LL hashCode){
    for(int i = 2 ; i <= n - k ; ++i)
    if(getHash(i, i + k - 1) == hashCode) return 1;
    return 0;
}

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.length();
    s = " " + s;
    po[0] = 1;
    for(int i = 1 ; i <= n ; ++i) po[i] = (po[i - 1] * BASE) % MOD;
    for(int i = 1 ; i <= n ; ++i) d[i] = (d[i - 1] * BASE + (s[i] - 'a' + 1)) % MOD;
    // for(int i = 1 ; i <= n ; ++i) cout << d[i] << " ";
    // cout << endl;
    // cout << (getHash(1, 8) == getHash(3, 10)) << endl;
    // cout << Check(8, getHash(1, 8)) << endl;
    for(int i = n ; i > 0 ; --i)
    if(getHash(1, i) == getHash(n - i + 1, n) && Check(i, getHash(1, i))){
        cout << s.substr(1, i) << endl;
        return 0;
    }
    cout << "Just a legend" << endl;

    return 0;
}