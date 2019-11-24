// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 10 + 1e6;

LL n, a[MaxN], m, k, t, p, lt[MaxN], md[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

LL Mu(LL a, LL n){
    if(n == 0) return 1;
    LL tg = Mu(a, n / 2);
    if(n % 2) return (((tg * tg) % p) * a) % p;
    return (tg * tg) % p;
}

void InOut(){
    #define TASK "FLOWERS"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(t);
    read(p);
    lt[0] = 1;
    for(LL i = 1 ; i <= 1000000 ; ++i) lt[i] = (lt[i - 1] * i) % p;
    md[1000000] = Mu(lt[1000000], p - 2);
    for(LL i = 999999 ; i >= 0 ; --i) md[i] = (md[i + 1] * (i + 1)) % p;
    for(int te = 0 ; te < t ; ++te){
        read(n);
        read(m);
        read(k);
        LL x1 = (m * (Mu(m - 1, k))) % p;
        if(p == 998244353){
            if(n > LL(1e6)){
                LL x = 1;
                for(int i = n - k ; i <= n - 1 ; ++i) x = (x * i) % p;
                x = (x * lt[k]) % p;
                cout << (x * x1) % p << endl;
            }
            else{
                LL x2 = lt[n - 1] % p;
                LL x3 = (md[n - k - 1] * md[k]) % p;
                cout << (((x1 * x2) % p) * x3) % p << endl;
            }
        }
    }

    return 0;
}