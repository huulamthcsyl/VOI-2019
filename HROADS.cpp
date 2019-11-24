// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 3e5, INF = 1e18;

LL n, a[MaxN], x, y, z, m, ans, s[MaxN];
II d[MaxN];
set<LL> kq;
vector<LL> q[MaxN];

struct Edge{

    LL u, v, len;

    Edge(LL _u = 0, LL _v = 0, LL _len = 0):u(_u), v(_v), len(_len){}

    bool operator < (const Edge &op) const{
        return len < op.len;
    }

} e[MaxN];

void Dijk(LL u){
    fill(s + 1, s + n + 1, INF);
    s[u] = 0;
    priority_queue<II, vector<II>, greater<II> > pq;
    pq.push({0, u});
    while(!pq.empty()){
        II temp = pq.top();
        pq.pop();
        LL u = temp.second;
        for(int i : q[u]){
            LL v = e[i].u + e[i].v - u;
            if(s[u] + e[i].len < s[v]){
                s[v] = s[u] + e[i].len;
                d[v] = {e[i].len, i};
                pq.push({s[v], v});
                continue;
            }
            if(s[u] + e[i].len == s[v] && e[i].len < d[v].first){
                d[v] = {e[i].len, i};
                continue;
            }
        }
    }
}

void InOut(){
    #define TASK "HROADS"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    for(int i = 0 ; i < m ; ++i){
        read(x);
        read(y);
        read(z);
        e[i] = Edge(x, y, z);
        q[x].push_back(i);
        q[y].push_back(i);
    }
    read(x);
    Dijk(x);
    for(int i = 1 ; i <= n ; ++i) kq.insert(d[i].second);
    for(int i : kq) ans += e[i].len;
    cout << ans << endl;
    for(int i : kq) cout << i + 1 << " ";

    return 0;
}