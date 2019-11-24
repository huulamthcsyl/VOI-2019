// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, kq = 1, f[MaxN];
pair<LL, LL> a[MaxN];
stack<LL> ans;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void InOut(){
    #define TASK "GUIDE"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 1 ; i <= n ; ++i) read(a[i].first);
    for(int i = 1 ; i <= n ; ++i) read(a[i].second);
    f[1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        f[i] = 1;
        for(int j = 1 ; j < i ; ++j)
        if(a[j].first < a[i].first && a[j].second < a[i].second) f[i] = max(f[i], f[j] + 1);
        kq = max(kq, f[i]);
    }
    cout << kq << endl;
    LL l = 1e18, r = 1e18;
    for(int i = n ; i > 0 ; --i)
    if(f[i] == kq && a[i].first < l && a[i].second < r){
        ans.push(i);
        kq--;
        l = a[i].first;
        r = a[i].second;
    }
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}
