// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], s, x, y, z, kq;
unordered_map<LL, LL> d;
vector<II> q[MaxN];

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
}

void DFS(LL u, LL pr){
    for(II v : q[u])
    if(v.first != pr){
        s += v.second;
        d[s]++;
        if(s == 0 && d[0] > 1) kq++;
        DFS(v.first, u);
        d[s]--;
        s -= v.second;
    }
}

void InOut(){
    #define TASK "RBTRAVEL"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 0 ; i < n - 1 ; ++i){
        read(x);
        read(y);
        read(z);
        x--;
        y--;
        if(!z) z--;
        q[x].push_back({y, z});
        q[y].push_back({x, z});
    }
    for(int i = 0 ; i < n ; ++i) DFS(i, -1);
    cout << kq / 2 << endl;

    return 0;
}
