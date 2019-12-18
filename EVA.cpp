// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

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

const LL MaxN = 1 + 1e5, INF = 1e18;

LL n, a[MaxN], k, x, y, m, d[MaxN];
priority_queue<II, vector<II>, greater<II> > pq;
vector<LL> q[MaxN];

void InOut(){
    #define TASK "EVA"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    fill(d + 1, d + n + 1, INF);
    for(int i = 0 ; i < k ; ++i){
        cin >> x;
        d[x] = 0;
        pq.push({0, x});
    }
    cin >> m;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    while(!pq.empty()){
        II temp = pq.top();
        pq.pop();
        LL u = temp.second;
        for(int v : q[u])
        if(d[u] + 1 < d[v]){
            d[v] = d[u] + 1;
            pq.push({d[v], v});
        }
    }
    for(int i = 1 ; i <= n ; ++i) cout << d[i] << " ";

    return 0;
}