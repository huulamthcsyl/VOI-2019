// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, d[MaxN], ma, k, x, y;
priority_queue<II, vector<II>, greater<II> > l, r;
vector<LL> result;

struct Segment{

    LL l, r, id;

    Segment(LL _l = 0, LL _r = 0, LL _id = 0):l(_l), r(_r), id(_id){}

    bool operator < (const Segment &op) const{
        if(l < op.l) return 1;
        if(l == op.l && r > op.r) return 1;
        return 0;
    }

} a[MaxN];

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
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x >> y;
        ma = max(ma, y);
        a[i] = Segment(x, y, i);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1 ; i <= n ; ++i) cout << a[i].l << " " << a[i].r << endl;
    LL m = 1, sl = 0, first = 1, h = 1;
    for(int i = 1 ; i <= ma ; ++i){
        while(m <= n && a[m].l == i){
            sl++;
            d[a[i].id] = 1;
            m++;
        }
        while(sl > k){
            result.push_back(a[first].id);
            d[a[first].id] = 0;
            sl--;
            first++;
        }
        while(h <= n && a[h].r == i){
            if(d[h]) sl--;
            d[h] = 0;
            h++;
        }
    }
    cout << result.size() << endl;
    for(int i : result) cout << i << " ";

    return 0;
}