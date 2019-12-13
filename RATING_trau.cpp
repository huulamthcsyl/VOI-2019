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

const LL MaxN = 1 + 1e5;

LL n, a[MaxN], subtask, q, k, l, r, d[MaxN];

namespace Subtask1{
    void Solve(){
        cin >> n >> q;
        for(int i = 1 ; i <= n ; ++i) cin >> a[i];
        for(int te = 0 ; te < q ; ++te){
            cin >> k >> l >> r;
            for(int i = l ; i <= r ; ++i) k = abs(k - a[i]);
            cout << k << endl;
        }
    }
}

namespace Subtask2{
    void Solve(){
        cin >> n >> q;
        for(int i = 1 ; i <= n ; ++i){
            cin >> a[i];
            d[i] = d[i - 1] + a[i];
        }
        for(int te = 0 ; te < q ; ++te){
            cin >> k >> l >> r;
            cout << k - (d[r] - d[l - 1]) << endl;
        }
    }
}

void InOut(){
    #define TASK "RATING"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".ans","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> subtask;
    Subtask1::Solve();

    return 0;
}
