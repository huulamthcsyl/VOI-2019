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

LL n, kq, ans, vis[MaxN], kt[MaxN], x, y, z;

struct Range{

    LL x, y, range;

    Range(LL _x = 0, LL _y = 0, LL _range = 0):x(_x), y(_y), range(_range){}

} a[MaxN];

inline LL Dis(Range x, Range y){
    return (x.x - y.x) * (x.x - y.x) + (x.y- y.y) * (x.y - y.y);
}

void DFS(LL u){
    kt[u] = 1;
    vis[u] = 1;
    kq++;
    for(int i = 0 ; i < n ; ++i)
    if(!vis[i] && Dis(a[u], a[i]) <= a[u].range * a[u].range) DFS(i);
}

void InOut(){
    #define TASK "MAXPING"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> x >> y >> z;
        a[i] = Range(x, y, z);
    }
    for(int i = 0 ; i < n ; ++i)
    if(!kt[i]){
        memset(vis, 0, sizeof vis);
        kq = 0;
        DFS(i);
        ans = max(kq, ans);
    }
    cout << ans << endl;

    return 0;
}