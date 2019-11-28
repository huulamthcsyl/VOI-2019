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

const LL MaxN = 1 + 1e5, BASE = 2e7;

LL n, m, k, x, y, z, t, kq;
pair<LL, LL> pos;

class Rectangle{
    public:
        LL x0, y0, x1, y1;

        Rectangle(LL _x0 = 0, LL _y0 = 0, LL _x1 = 0, LL _y1 = 0):x0(_x0), y0(_y0), x1(_x1), y1(_y1){}
} a[MaxN];

inline LL Check(LL r, LL x, LL y){
    if(a[r].x0 > x + k - 1) return 0;
    if(a[r].y0 > y + k - 1) return 0;
    if(a[r].x1 < x) return 0;
    if(a[r].y1 < y) return 0;
    return 1;
}

LL Calc(LL x, LL y){
    LL ans = 0;
    for(int i = 0 ; i < m ; ++i)
    if(Check(i, x, y)) ans++;
    return ans;
}

void Solve1(){
    for(int i = 1 ; i <= n - k + 1 ; ++i)
    for(int j = 1 ; j <= n - k + 1 ; ++j){
        LL temp = Calc(i, j);
        if(temp > kq){
            kq = temp;
            pos = {i, j};
        }
    }
    cout << kq << endl;
    cout << pos.first << " " << pos.second << endl;
}

void Solve2(){
    for(int i = 0 ; i <= BASE / m ; ++i){
        LL x = Rand(1, n);
        LL y = Rand(1, n);
        if(Calc(x, y) > kq){
            kq = Calc(x, y);
            pos = {x, y};
        }
    }
    cout << kq << endl;
    cout << pos.first << " " << pos.second << endl;
}

void InOut(){
    #define TASK "PAPERS"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0 ; i < m ; ++i){
        cin >> x >> y >> z >> t;
        a[i] = Rectangle(x, y, z, t);
    }
    if((n - k + 1) * (n - k + 1) * m <= BASE) Solve1();
    else Solve2();

    return 0;
}
