// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef int LL;

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

const LL MaxN = 81, INF = MaxN * MaxN * 2 + 1;

LL n, a[MaxN][MaxN], m, b[MaxN][MaxN], kq = 1e9;
bitset<MaxN * MaxN * 4 + 3> d[MaxN][MaxN];

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
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j) cin >> a[i][j];
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j) cin >> b[i][j];
    d[1][1].set(a[1][1] - b[1][1] + INF, 1);
    d[1][1].set(b[1][1] - a[1][1] + INF, 1);
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        if(i == 1 && j == 1) continue;
        LL temp = abs(a[i][j] - b[i][j]);
        d[i][j] = (d[i - 1][j] << temp) | (d[i - 1][j] >> temp) | (d[i][j - 1] << temp) | (d[i][j - 1] >> temp);
    }
    for(int i = 0 ; i <= INF * 2 ; ++i)
    if(d[n][m][i]) kq = min(kq, abs(i - INF));
    cout << kq << endl;

    return 0;
}