// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], k, le, ri, kq;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

struct Dis{

    LL l, r, dis;

    Dis(LL _l = 0, LL _r = 0, LL _dis = 0):l(_l), r(_r), dis(_dis){}

    bool operator < (const Dis& op) const{
        return dis < op.dis;
    }

};

priority_queue<Dis> pq;

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
    read(k);
    for(int i = 1 ; i <= n ; ++i) read(a[i]);
    sort(a, a + n);
    for(int i = 2 ; i <= n ; ++i) pq.push(Dis(i - 1, i, a[i] - a[i - 1]));
    while(1){
        Dis x = pq.top();
        pq.pop();
        if(x.r <= le || x.l >= n - ri + 1) continue;
        kq = x.dis;
        LL er = min(x.l - le, n - x.r - ri + 1);
        if(er > k) break;
        k -= er;
        if(x.l - le < n - x.r - ri + 1) le += er;
        else ri += er;
    }
    cout << kq << endl;

    return 0;
}