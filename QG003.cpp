// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, x, y, z, m;
II a[MaxN];
vector<II> q[MaxN];

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
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i].second >> a[i].first;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z;
        q[x].push_back({y, z});
        q[y].push_back({x, z});
    }

    return 0;
}