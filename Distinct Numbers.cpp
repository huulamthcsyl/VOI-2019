// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 3e5;

LL n, a[MaxN], d[MaxN], x, m, id[MaxN];
vector<LL> q[MaxN];

LL cmp(LL x, LL y){
    return d[x] < d[y];
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
    for(int i = n - 1 ; i >= 0 ; --i){
        cin >> x;
        d[x]++;
        if(d[x] == 1){
            id[m] = x;
            m++;
        }
    }       
    sort(id, id + m, cmp);
    LL h = n;
    for(int i = 1 ; i <= m ; ++i){
        cout << min(n / i, h) << endl;
        h -= d[id[m - i]];
    }
    for(int i = m ; i < n ; ++i) cout << 0 << endl;

    return 0;
}