// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

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

const LL MaxN = 1 + 1e5;

LL n, m, x, y, z, t, kq[MaxN];
unordered_map<LL, LL> d[MaxN];

struct Paper{

    LL x1, y1, x2, y2;

    Paper(LL _x1 = 0, LL _y1 = 0, LL _x2 = 0, LL _y2 = 0):x1(_x1), y1(_y1), x2(_x2), y2(_y2){}

    bool operator < (const Paper &op) const{
        if(x1 < op.x1) return 1;
        if(y1 < op.y1) return 1;
        return 0;
    }

} a[MaxN];

struct Point{

    LL x, y, id;

    Point(LL _x = 0, LL _y = 0, LL _id = 0):x(_x), y(_y), id(_id){}

} p[MaxN];

void Check(LL x, LL y, LL id){
    for(int i = 0 ; i < n ; ++i)
    if(!d[i][id]){
        if(a[i].x1 <= x && x <= a[i].x2 && a[i].y1 <= y && y <= a[i].y2){
            kq[i]++;
            d[i][id] = 1;
        }
    }
}

void InOut(){
    #define TASK "PAINT"
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
    for(int i = 0 ; i < n ; ++i){
        read(x);
        read(y);
        read(z);
        read(t);
        a[i] = Paper(x, y, z, t);
    }
    for(int i = 0 ; i < m ; ++i){
        read(x);
        read(y);
        read(z);
        Check(x, y, z);
    }
    for(int i = 0 ; i < n ; ++i) cout << kq[i] << endl;

    return 0;
}