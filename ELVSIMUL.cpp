// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, b[MaxN], vis[MaxN], ntime, kq[MaxN];
II t[MaxN];
set<II> s, re;

void InOut(){
    #define TASK "ELVSIMUL"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i] >> b[i];
        t[i] = {a[i] + b[i], i};
    }
    sort(t, t + n);
    LL j = 0;
    for(int i = 0 ; i < n ; ++i)
    if(!vis[i]){
        vis[i] = 1;
        if(a[i] > ntime) ntime = a[i];
        ntime += (b[i] - 1);
        LL end = ntime + (b[i] - 1);
        kq[i] = end;
        while(j < n && t[j].first <= ntime + b[i]){
            if(!vis[t[j].second]) s.insert(t[j]);
            j++;
        }
        re.clear();
        for(auto k : s)
        if(b[k.second] <= b[i]){
            kq[k.second] = end;
            vis[k.second] = 1;
        } else re.insert(k);
        s = re;
        ntime = end;
    }
    for(int i = 0 ; i < n ; ++i) cout << kq[i] << endl;

    return 0;
}