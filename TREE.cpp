// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], x, y, d[MaxN], deg[MaxN], kq;
vector<LL> q[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void DFS(LL u, LL pr){
    if(deg[u] == 1){
        if(a[u] >= 1) kq += (a[u] - 1), d[u] = 1;
        return;
    }
    for(int v : q[u])
    if(v != pr){
        DFS(v, u);
        d[u] += d[v];
    }
    if(d[u] < a[u]){
        kq += (a[u] - d[u]);
    }
    else{
        kq += (d[u] - a[u]);
        d[u] = a[u];
    }
}

void InOut(){
    #define TASK "TREE"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 0 ; i < n ; ++i) read(a[i]);
    for(int i = 0 ; i < n - 1 ; ++i){
        read(x);
        read(y);
        x--;
        y--;
        deg[x]++;
        deg[y]++;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    DFS(0, -1);
    cout << kq << endl;

    return 0;
}
