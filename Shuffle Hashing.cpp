// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const LL MaxN = 10 + 1e2;

LL n, a[MaxN], q, d[MaxN][MaxN], d1[MaxN];
string s1, s2;

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
    cin >> q;
    for(int te = 0 ; te < q ; ++te){
        cin >> s1;
        cin >> s2;
        LL n = s1.length(), m = s2.length();
        s2 = " " + s2;
        s1 = " " + s1;
        memset(d, 0, sizeof d);
        memset(d1, 0, sizeof d1);
        for(int i = 1 ; i <= m ; ++i){
            for(int j = 0 ; j <= 25 ; ++j) d[i][j] = d[i - 1][j];
            d[i][s2[i] - 'a']++;
        }
        LL ans = 0;
        for(int i = 1 ; i <= n ; ++i) d1[s1[i] - 'a']++;
        for(int i = 1 ; i <= m - n + 1 ; ++i){
            LL kt = 1;
            for(int j = 0 ; j <= 25 ; ++j)
            if(d[i + n - 1][j] - d[i - 1][j] != d1[j]){
                kt = 0;
                break;
            }
            if(kt){
                ans = 1;
                break;
            }
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}