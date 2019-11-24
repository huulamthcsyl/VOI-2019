// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 10 + 1e5;

LL n, a[MaxN], s, l, r, kq;

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
    read(l);
    read(r);
    n += 2;
    for(int i = 0 ; i < n ; ++i){
        read(a[i]);
        s += a[i];
    }
    sort(a, a + n);
    for(int i = 0 ; i < n ; ++i){
        LL s1 = s - a[i];
        LL lo = s1 - r, hi = s1 - l;
        // cout << lo << " " << hi << endl;
        LL fi = lower_bound(a, a + n, lo) - a, se = upper_bound(a, a + n, hi) - a;
        kq += (se - fi);
        if(lo <= a[i] && a[i] <= hi) kq--;
        // cout << kq << endl;
    }
    cout << kq / 2 << endl;

    return 0;
}