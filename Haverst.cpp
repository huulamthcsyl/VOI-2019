// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], b[MaxN], m;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

LL Kt(LL pos, LL l, LL r, LL k){
    return (min(abs(a[pos] - b[l]), abs(b[r] - a[pos])) + (b[r] - b[l])) <= k;
}

LL Check(LL k){
    LL j = 0, j1 = 0;
    for(int i = 0 ; i < n ; ++i){
        while(j1 < m && Kt(i, j, j1, k)) j1++;
        j = j1;
    }
    if(j == m) return 1;
    return 0;
}

void InOut(){
    #define TASK "harvest"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        for(int i = 0 ; i < m ; ++i) cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        LL l = 0, r = 1e11;
        while(l < r){
            LL tg = (l + r) / 2;
            if(Check(tg)) r = tg;
            else l = tg + 1;
        }
        cout << l << endl;
    }

    return 0;
}