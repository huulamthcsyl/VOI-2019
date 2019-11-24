// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5, MOD = 7 + 1e9;

LL n, a[MaxN], d[MaxN], m, kq = 1, f[MaxN];
string s;

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
    cin >> s;
    n = s.length();
    for(int i = 0 ; i < n ; ++i)
    if(s[i] == 'm' || s[i] == 'w'){
        cout << 0 << endl;
        return 0;
    }
    LL k = 1;
    for(int i = 1 ; i < n ; ++i)
    if(s[i] == s[i - 1] && (s[i - 1] == 'n' || s[i - 1] == 'u')) k++;
    else{
        if(k > 1){
            d[m] = k;
            m++;
            k = 1;
        }
    }
    if(k > 1){
        d[m] = k;
        m++;
    }
    f[1] = 1;
    f[2] = 2;
    for(int i = 3 ; i <= n ; ++i) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    for(int i = 0 ; i < m ; ++i)
    kq = (kq * f[d[i]]) %  MOD;
    cout << kq << endl;

    return 0;
}