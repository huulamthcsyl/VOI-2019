// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5, MOD = 1e9 + 7, BASE = 337;

LL n, a[MaxN], pw[MaxN], b[MaxN], x, y, l, r;
string s;

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0'||ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
}

inline LL Calc1(LL l, LL r){
    return (a[r] - a[l - 1] * pw[r - l + 1] + MOD) % MOD;
}

inline LL Calc2(LL l, LL r){
    return (b[l] - b[r + 1] * pw[r - l + 1] + MOD) % MOD;
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
    cin >> s;
    n = s.length();
    s = " " + s;
    pw[0] = 1;
    for(int i = 1 ; i <= n ; ++i) pw[i] = (pw[i - 1] * BASE) % MOD;
    for(int i = 1 ; i <= n ; ++i){
        a[i] = (a[i - 1] * BASE + s[i] - 'a') % MOD;
    }
    for(int i = n ; i > 0 ; --i){
        b[i] = (b[i + 1] * BASE + s[i] - 'a') % MOD;
    }
    for(int i = 0 ; i < n ; ++i){
        read(x);
        read(y);
        read(l);
        read(r);
        if(x > r || y < l || (x <= l && r <= y)){
            if(Calc1(l, r) == Calc2(l, r)) cout << "Yes" << endl;
            else cout << "No" << endl;
            continue;
        }
        if(x < l && l <= y && y <= r){
            LL x1 = (Calc2(l, y) + (Calc1(y + 1, r) * pw[y - l]) % MOD + MOD) % MOD;
            LL x2 = Calc2(y + 1, r);
        }
    }
    // cout << LL(Calc1(3, 4) == Calc2(3, 4)) << endl;

    return 0;
}
