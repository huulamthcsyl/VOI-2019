// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], x, m, root[MaxN], kq, k;

LL getRoot(LL u){
    return u == root[u] ? u : root[u] = getRoot(root[u]);
}

struct Edge{

    LL u, v, l;

    Edge(LL _u = 0, LL _v = 0, LL _l = 0):u(_u), v(_v), l(_l){}

    bool operator < (const Edge &op) const{
        return l < op.l;
    }

} e[MaxN];

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
    for(int i = 1 ; i <= n ; ++i)
    for(int j = i ; j <= n ; ++j){
        cin >> x;
        e[m] = Edge(i - 1, j, x);
        m++;
    }
    sort(e, e + m);
    for(int i = 0 ; i <= n ; ++i) root[i] = i;
    for(int i = 0 ; i < m ; ++i){
        LL u = e[i].u, v = e[i].v, l = e[i].l;
        LL ru = getRoot(u), rv = getRoot(v);
        if(ru == rv) continue;
        root[ru] = rv;
        kq += l;
    }
    cout << kq << endl;

    return 0;
}