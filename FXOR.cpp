// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], x, t;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

LL Tk(LL x, LL y, LL k, LL bit){
    LL l = x, r = y;
    while(l < r){
        LL tg = (l + r + 1) / 2;
        if((a[tg] >> k) & bit) l = tg;
        else r = tg - 1;
    }
    return l;
}

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
    read(n);
    for(int i = 0 ; i < n ; ++i) read(a[i]);
    sort(a, a + n);
    read(t);
    for(int te = 0 ; te < t ; ++te){
        LL lo = 0, hi = n - 1;
        read(x);
        LL i = log2(x - 1) + 1;
        cout << i << endl;
        while(lo < hi){
            if((x >> i) & 1) hi = Tk(lo, hi, i, 0);
            else lo = Tk(lo, hi, i, 1);
            cout << lo << " " << hi << endl;
            i--;
        }
        cout << a[lo] << " ";
    }

    return 0;
}