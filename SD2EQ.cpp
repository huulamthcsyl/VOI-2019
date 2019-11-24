// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], d1[MaxN], d2[MaxN], mi, s, kq = -1e18;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
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
    read(n);
    for(int i = 1 ; i <= n ; ++i) read(a[i]);
    d1[0] = -1e18;
    s = 0;
    mi = 0;
    for(int i = 1 ; i <= n ; ++i){
        s += a[i];
        d1[i] = max(d1[i - 1], s - mi);
        mi = min(mi, s);
    }
    s = 0;
    mi = 0;
    d2[n + 1] = -1e18;
    for(int i = n ; i ; --i){
        s += a[i];
        d2[i] = max(d2[i + 1], s - mi);
        mi = min(mi, s);
    }
    // for(int i = 1 ; i <= n ; ++i) cout << d1[i] << " ";
    // cout << endl;
    // for(int i = 1 ; i <= n ; ++i) cout << d2[i] << " ";
    // cout << endl;
    for(int i = 1 ; i < n ; ++i) kq = max(kq, d1[i] + d2[i + 1]);
    cout << kq << endl;

    return 0;
}