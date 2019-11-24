// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5, INF = 1e12;

LL n, a[MaxN], m, k, x, y, z, d[MaxN][21], kq = 1e18;
vector<II> q[MaxN];

struct Road{

    LL u, len, cnt;

    Road(LL _u = 0, LL _len = 0, LL _cnt = 0):u(_u), len(_len), cnt(_cnt){}

    bool operator > (const Road &op) const{
        return len > op.len;
    }

};

void Dijk(){
    memset(d, 0x3f3f3f3f, sizeof d);
    for(int i = 0 ; i <= k ; ++i) d[0][i] = 0;
    priority_queue<Road, vector<Road>, greater<Road> > pq;
    pq.push(Road(0 ,0, 0));
    while(!pq.empty()){
        Road x = pq.top();
        pq.pop();
        LL u = x.u, cnt = x.cnt;
        for(II v : q[u]){
            if(d[v.first][cnt] > d[u][cnt] + v.second){
                d[v.first][cnt] = d[u][cnt] + v.second;
                pq.push(Road(v.first, d[v.first][cnt], cnt));
            }
            if(cnt < k && d[u][cnt] < d[v.first][cnt + 1]){
                d[v.first][cnt + 1] = d[u][cnt];
                pq.push(Road(v.first, d[v.first][cnt + 1], cnt + 1));
            }
        }
    }
}

void InOut(){
    #define TASK "REVAMP"
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
        x--;
        y--;
        q[x].push_back({y, z});
        q[y].push_back({x, z});
    }
    Dijk();
    for(int i = 0 ; i <= k ; ++i) kq = min(kq, d[n - 1][i]);
    cout << kq << endl;

    return 0;
}