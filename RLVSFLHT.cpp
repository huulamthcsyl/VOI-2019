// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5, INF = 1e18;

LL n, a[MaxN], x, y, z, k, m, s[MaxN], e[MaxN], d[MaxN];
II trace[MaxN];

struct Edge{

    LL v, len, id;

    Edge(LL _v = 0, LL _len = 0, LL _id = 0):v(_v), len(_len), id(_id){}

    bool operator > (const Edge &op) const{
        return len > op.len;
    }

};

vector<Edge> q[MaxN];

void Dijk(){
    fill(s + 1, s + n + 1, INF);
    s[1] = 0;
    memset(trace, 0, sizeof trace);
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    pq.push(Edge(1, 0, 0));
    while(!pq.empty()){
        Edge x = pq.top();
        pq.pop();
        LL u = x.v;
        for(auto v : q[u])
        if(s[u] + v.len < s[v.v]){
            s[v.v] = s[u] + v.len;
            trace[v.v] = {u, v.id};
            pq.push(Edge(v.v, s[v.v], v.id));
        } else if(s[u] + v.len == s[v.v] && v.id == 0){
            trace[v.v] = {u, v.id};
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
    cin >> n >> m >> k;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        q[x].push_back(Edge(y, z, 0));
        q[y].push_back(Edge(y, z, 0));
    }
    for(int i = 0 ; i < k ; ++i){
        cin >> y >> z;
        q[1].push_back(Edge(y, z, 1));
        e[i] = y;
    }
    Dijk();
    LL u = n;
    while(u != 1){
        if(trace[u].second == 1) d[trace[u].first] = 1;
        u = trace[u].first;
    }
    LL kq = k;
    for(int i = 0 ; i < k ; ++i)
    if(d[e[i]]) kq--;
    cout << kq << endl;

    return 0;
}