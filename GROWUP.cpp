// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], kq[MaxN], x, y, l, r, b[MaxN], t;

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
}

void InOut(){
    #define TASK "GROWUP"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    memset(kq, 0xff, sizeof kq);
    for(int i = 1 ; i <= n ; ++i) read(a[i]);
    for(int i = 1 ; i <= n ; ++i){
        read(b[i]);
        if(a[i] >= b[i]) kq[i] = 0;
    }
    read(t);
    for(int te = 1 ; te <= t ; ++te){
        read(l);
        read(r);
        read(x);
        read(y);
        LL k = x;
        for(int i = l ; i <= r ; ++i){
            a[i] += k;
            if(kq[i] == -1 && a[i] >= b[i]) kq[i] = te;
            k += y;
        }
    }
    for(int i = 1 ; i <= n ; ++i) cout << kq[i] << " ";

    return 0;
}
