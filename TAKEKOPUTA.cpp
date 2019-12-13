// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LD, LL> ID;

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

LL n, s, t, x, y, k, vex[MaxN];
LD d[MaxN];
pair<LL, LL> a[MaxN][MaxN];
vector<pair<LL, LD> > q[MaxN];

inline LD Area(II x, II y, II z){
    return abs((y.first - x.first) * (x.second + y.second) + (z.first - y.first) * (z.second + y.second) + (x.first - z.first) * (x.second + z.second));
}

inline LD Len(II x, II y){
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

inline LD Dis(II x, II y, II z){
    return Area(x, y, z) / Len(y, z);
}

void Dijk(){
    fill(d, d + n, 1e18);
    d[s] = 0;
    priority_queue<ID, vector<ID>, greater<ID> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        ID temp = pq.top();
        pq.pop();
        LL u = temp.second;
        for(auto v : q[u])
        if(d[u] + v.second < d[v.first]){
            d[v.first] = d[u] + v.second;
            pq.push({d[v.first], v.first});
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
    cin >> n >> s >> t;
    cout << fixed << setprecision(9);
    s--;
    t--;
    for(int i = 0 ; i < n ; ++i){
        cin >> vex[i];
        for(int j = 0 ; j < vex[i] ; ++j) cin >> a[i][j].first >> a[i][j].second;
    }
    for(int i = 0 ; i < n ; ++i)
    for(int j = i + 1 ; j < n ; ++j){
        LD temp = 1e18;
        for(int x = 0 ; x < vex[i] ; ++x)
        for(int y = 0 ; y < vex[j] ; ++y)
        if(Area(a[i][x], a[j][y], a[j][(y + 1) % vex[j]]) != 0) temp = min(temp, Dis(a[i][x], a[j][y], a[j][(y + 1) % vex[j]]));
        else{
            if(a[i][x].first == a[j][y].first && a[j][y].first == a[j][(y + 1) % vex[j]].first) temp = min(temp, (LD)min(abs(a[i][x].second - a[j][y].second), abs(a[i][x].second - a[j][(y + 1) % vex[j]].second)));
            else temp = min(temp, (LD)min(abs(a[i][x].first - a[j][y].first), abs(a[i][x].first - a[j][(y + 1) % vex[j]].first)));
        }
        for(int x = 0 ; x < vex[j] ; ++x)
        for(int y = 0 ; y < vex[i] ; ++y)
        if(Area(a[j][x], a[i][y], a[i][(y + 1) % vex[i]]) != 0) temp = min(temp, Dis(a[j][x], a[i][y], a[i][(y + 1) % vex[i]]));
        else{
            if(a[j][x].first == a[i][y].first && a[i][y].first == a[i][(y + 1) % vex[i]].first) temp = min(temp, (LD)min(abs(a[j][x].second - a[i][y].second), abs(a[j][x].second - a[i][(y + 1) % vex[i]].second)));
            else temp = min(temp, (LD)min(abs(a[j][x].first - a[i][y].first), abs(a[j][x].first - a[i][(y + 1) % vex[i]].first)));
        }
        for(int x = 0 ; x < vex[i] ; ++x)
        for(int y = 0 ; y < vex[j] ; ++y)
        temp = min(temp, Len(a[i][x], a[j][y]));
        q[i].push_back({j, temp});
        q[j].push_back({i, temp});
    }
    Dijk();
    cout << d[t] << endl;

    return 0;
}