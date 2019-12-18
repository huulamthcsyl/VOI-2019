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

const LL MaxN = 1 + 1e3;

LL n, a[MaxN][MaxN], d[MaxN][MaxN][10], x;

inline LL Calc(LL x0, LL y0, LL x1, LL y1, LL ch){
    return d[x1][y1][ch] - d[x0 - 1][y1][ch] - d[x1][y0 - 1][ch] + d[x0 - 1][y0 - 1][ch];
}

LL Check(LL k){
    for(int i = 1 ; i <= n - k + 1 ; ++i)
    for(int j = 1 ; j <= n - k + 1 ; ++j)
    if(Calc(i, j, i + k - 1, j + k - 1, a[i][j]) == k * k) return 1;
    return 0;
}

void InOut(){
    #define TASK "MSQUARE"
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
    for(int j = 1 ; j <= n ; ++j){
        for(int k = 0 ; k < 10 ; ++k)
        d[i][j][k] = d[i - 1][j][k] + d[i][j - 1][k] - d[i - 1][j - 1][k];
        cin >> a[i][j];
        d[i][j][a[i][j]]++;
    }
    LL l = 1, r = 1000;
    while(l < r){
        LL tg = (l + r + 1) / 2;
        if(Check(tg)) l = tg;
        else r = tg - 1;
    }
    cout << l * l << endl;

    return 0;
}