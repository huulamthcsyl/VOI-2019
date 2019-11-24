// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e4;

LL n, a[MaxN], m, x, y, d[MaxN], vis[MaxN];
long long kq[2];
char ch;
vector<LL> q[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void Dijk(LL _u){
    memset(d, 0x3f3f3f, sizeof d);
    d[_u] = 0;
    priority_queue<II, vector<II> ,greater<II> > pq;
    pq.push({0, _u});
    while(!pq.empty()){
        II x = pq.top();
        pq.pop();
        LL u = x.second;
        for(int v : q[u]){
            LL inc;
            if(a[v] == a[_u]) inc = 1;
            else inc = 4;
            if(d[u] + inc < d[v]){
                d[v] = d[u] + inc;
                pq.push({d[v], v});
            }
        }
    }
}

void InOut(){
    #define TASK "GYALPHA"
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
    for(int i = 0 ; i < n ; ++i){
        ch = getchar();
        if(ch == 'Y') a[i] = 1;
    }
    for(int i = 0 ; i < m ; ++i){
        read(x);
        read(y);
        x--;
        y--;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    for(int i = 0 ; i < n ; ++i){
        d[i] = 0;
        Dijk(i);
        for(int j = 0 ; j < n ; ++j)
        if(a[i] == a[j]) kq[a[i]] += d[j];
    }
    cout << kq[0] / 2 << " " << kq[1] / 2 << endl;

    return 0;
}