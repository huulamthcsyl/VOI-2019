// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL, LD> II;

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

const LL MaxN = 1 + 3e5;
const LD eps = 1e-9, INF = 1e18;

LL n, m, x, y;
LD s[MaxN];
pair<LL, LL> a[MaxN], b[MaxN];
vector<II> q[MaxN];
LD dis;

inline LD Distance(pair<LL, LL> x, pair<LL, LL> y){
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

void Dijk(){
    fill(s + 1, s + n + 1, INF);
    s[1] = 0;
    priority_queue<II, vector<II>, greater<II> > pq;
    pq.push({0, 1});
    while(!pq.empty()){
        II temp = pq.top();
        pq.pop();
        LL u = temp.second;
        for(II v : q[u])
        if(s[u] + v.second < s[v.first]){
            s[v.first] = s[u] + v.second;
            pq.push({s[v.first], v.first});
        }
    }
}

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
    cin >> dis;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i].first >> a[i].second;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = i + 1 ; j <= n ; ++j){
        LD k = Distance(a[i], a[j]);
        if(k <= dis){
            // cout << i << " " << j << " " << k << endl;
            q[i].push_back({j, k});
            q[j].push_back({i, k});
        }
    }
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y;
        q[x].push_back({y, 0});
        q[y].push_back({x, 0});
    }
    // for(II i : q[1]) cout << i.first << endl;
    // cout << (Distance(a[1], a[5]) <= dis) << endl;
    Dijk();
    cout << fixed << setprecision(0);
    if(s[n] == INF) cout << -1 << endl;
    else cout << s[n] * 1000 << endl;

    return 0;
}