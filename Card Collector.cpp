// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN];
vector<III> q;
priority_queue<III> pq;

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
    cin >> n;
    cin >> h >> w;
    for(int i = 0 ; i < n ; ++i){
        cin >> x >> y >> z;
        q.push_back({z, {x, y}})
    }

    return 0;
}