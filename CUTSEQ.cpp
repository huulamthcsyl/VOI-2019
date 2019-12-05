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

const LL MaxN = 1 + 2e2;

LL n, a[MaxN], x, d[MaxN][MaxN][MaxN];
string s;

LL Calc(LL i, LL j, LL k){
    if(d[i][j][k] != -1) return d[i][j][k];
    if(i > j) return d[i][j][k] = 0;
    if(i == j) return d[i][j][k] = (k + 1) * (k + 1);
    d[i][j][k] = Calc(i, j - 1, 0) + (k + 1) * (k + 1);
    for(int u = i ; u < j ; ++u)
    if(s[u] == s[j]) d[i][j][k] = max(d[i][j][k], Calc(u + 1, j - 1, 0) + Calc(i, u, k + 1));
    return d[i][j][k];
}

void InOut(){
    #define TASK "CUTSEQ"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    memset(d, 0xff, sizeof d);
    cout << Calc(0, n - 1, 0) << endl;

    return 0;
}
