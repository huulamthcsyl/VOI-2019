// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], kq, sl, nxt[MaxN], pos[MaxN], b[MaxN];
string s;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void Check(LL k){
    if(k == 0){
        kq = max(kq, n - b[0]);
        return;
    }
    LL m = 0, vt = 0;
    while(vt < n && b[vt] >= k){
        vt = pos[b[vt] - k];
        vt = nxt[vt] + 1;
        m++;
    }
    if(m > 1) kq = max(kq, k * m + m - 1);
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
    cin >> n;
    cin >> s;
    nxt[n] = n;
    for(int i = n - 1 ; i >= 0 ; --i){
        if(s[i] == '0') b[i] = b[i + 1] + 1;
        else b[i] = b[i + 1];
        pos[b[i + 1]] = i;
        if(s[i] == '1') nxt[i] = i;
        else nxt[i] = nxt[i + 1];
    }
    for(int i = 0 ; i < n ; ++i) Check(i);
    cout << kq << endl;

    return 0;
}