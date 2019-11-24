// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 2e5;

LL n, a[MaxN], vis[MaxN], kq[MaxN], t;
vector<LL> q;

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
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n;
        for(int i = 1 ; i <= n ; ++i) cin >> a[i];
        memset(vis, 0, sizeof vis);
        for(int i = 1 ; i <= n ; ++i)
        if(!vis[i]){
            vis[i] = 1;
            q.clear();
            q.push_back(i);
            LL st = i;
            while(a[st] != i){
                st = a[st];
                vis[st] = 1;
                q.push_back(st);
            }
            for(int i : q) kq[i] = q.size();
        }
        for(int i = 1 ; i <= n ; ++i) cout << kq[i] << " ";
        cout << endl;
    }

    return 0;
}