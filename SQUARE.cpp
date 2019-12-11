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

LL n, a[MaxN], x1, x2, x3, x4, y1, y2, y3, y4;

void InOut(){
    #define TASK "SQUARE"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    LL l1 = min(x1, min(x2, min(x3, x4))), r1 = min(y1, min(y2, min(y3, y4)));
    LL l2 = max(x1, max(x2, max(x3, x4))), r2 = max(y1, max(y2, max(y3, y4)));
    // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    cout << max(l2 - l1, r2 - r1) * max(l2 - l1, r2 - r1) << endl;

    return 0;
}