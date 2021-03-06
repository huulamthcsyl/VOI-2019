// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;

#define y0 Sword_Art_Online
#define y1 Your_lie_in_April
#define yn Darling_in_the_Franxx
#define tm Plastic_Memories
#define lr Charlotte
#define norm Weathering_with_you
#define left Violet_Evergarden
#define have Date_a_live
#define ends Your_name
#define prev Five_centimeters_per_second
#define hash Slient_voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e6;

LL n, a[MaxN], t, block, x, y, d[MaxN], kq[MaxN];
set<LL> s;

class Query{
    public:
        LL l, r, id;

        Query(LL _l = 0, LL _r = 0, LL _id = 0):l(_l), r(_r), id(_id){}

        bool operator < (const Query &op) const{
            if(l / block != op.l / block) return l / block < op.l / block;
            return r < op.r;
        }

} q[MaxN];

void InOut(){
    #define TASK "DQUERY"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    cin >> t;
    block = sqrt(n);
    for(int i = 0 ; i < t ; ++i){
        cin >> x >> y;
        q[i] = Query(x, y, i);
    }
    sort(q, q + t);
    // for(int i = 0 ; i < t ; ++i) cout << q[i].l << " " << q[i].r << endl;
    LL prvl = 1, prvr = 1, cnt = 0;
    for(int i = 0 ; i < t ; ++i){
        while(prvl < q[i].l){
            d[a[prvl]]--;
            if(d[a[prvl]] == 0) cnt--;
            prvl++;
        }
        while(prvl > q[i].l){
            d[a[prvl - 1]]++;
            if(d[a[prvl - 1]] == 1) cnt++;
            prvl--;
        }
        while(prvr <= q[i].r){
            d[a[prvr]]++;
            if(d[a[prvr]] == 1) cnt++;
            prvr++;
        }
        while(prvr > q[i].r + 1){
            d[a[prvr - 1]]--;
            if(d[a[prvr - 1]] == 0) cnt--;
            prvr--;
        }
        kq[q[i].id] = cnt;
    }
    for(int i = 0 ; i < t ; ++i) cout << kq[i] << endl;

    return 0;
}