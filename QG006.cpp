// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6, INF = 1e18;

LL n, a[MaxN], x, logn, d[MaxN][32], l[MaxN], r[MaxN], kq = INF;
vector<LL> q[MaxN];

void DFS(LL u, LL pr){
    for(int i = 1 ; i <= logn ; ++i) d[u][i] = i;
    for(int v : q[u])
    if(v != pr){
        DFS(v, u);
        for(int i = 1 ; i <= logn ; ++i)
        l[i] = min(l[i - 1], d[v][i]);
        for(int i = logn ; i > 0 ; --i)
        r[i] = min(r[i + 1], d[v][i]);
        for(int i = 1 ; i <= logn ; ++i)
        d[u][i] += min(l[i - 1], r[i + 1]);
    }
}

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x;
        q[x].push_back(i);
    }
    logn = log2(n);
    l[0] = INF;
    r[logn + 1] = INF;
    DFS(1, 0);
    for(int i = 1 ; i <= logn ; ++i) kq = min(kq, d[1][i]);
    cout << kq << endl;

    return 0;
}