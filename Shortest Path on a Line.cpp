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

const LL MaxN = 1 + 1e5, INF = 1e18;

LL n, a[MaxN], x, y, z, m, s[MaxN];
vector<II> q[MaxN];

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

void Dijk(){
    fill(s, s + n, INF);
    s[0] = 0;
    priority_queue<II, vector<II>, greater<II> > pq;
    pq.push({0, 0});
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

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    for(int i = 0 ; i < m ; ++i){
        read(x);
        read(y);
        read(z);
        x--;
        y--;
        q[x].push_back({y, z});
        q[y].push_back({x, z});
    }
    for(int i = 1 ; i < n ; ++i) q[i].push_back({i - 1, 0});
    Dijk();
    if(s[n - 1] == INF) cout << -1 << endl;
    else cout << s[n - 1] << endl;

    return 0;
}