// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 5e5;

LL n, a[MaxN], f[MaxN], x, m, k, ma, kq, d[MaxN];
pair<LL, LL> b[MaxN];
vector<LL> q;

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void InOut(){
    #define TASK "SALE"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    read(k);
    for(int i = 0 ; i < n ; ++i){
        read(x);
        a[x] = 1;
        q.push_back(x);
        ma = max(ma, x);
    }
    for(int i = 0 ; i < m ; ++i) read(b[i].first);
    for(int i = 0 ; i < m ; ++i) read(b[i].second);
    for(int i = 0 ; i < k ; ++i){
        read(x);
        if(!a[x]) q.push_back(x);
        d[x] = 1;
    }
    sort(q.begin(), q.end());
    memset(f, 0x3f3f, sizeof f);
    LL sz = q.size();
    for(int i = 0 ; i < sz ; ++i){
        LL y = q[i];
        for(int j = 0 ; j < m ; ++j){
            LL v = b[j].second;
            if(d[y]){
                if(v % 2) v = v / 2 + 1;
                else v = v / 2;
            }
            for(int h = i ; h < sz ; ++h)
            if(y <= q[h] && q[h] < y + b[j].first) f[q[h]] = min(f[q[h]], kq + v);
            else break;
        }
        // cout << y << " " << f[y] << endl;
        if(a[y]) kq = f[y];
    }
    cout << f[ma] << endl;

    return 0;
}
