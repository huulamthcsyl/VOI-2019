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

const LL MaxN = 1 + 1e3;

LL n, a[MaxN], d[MaxN][MaxN], k;

void InOut(){
    #define TASK "SNAKES"
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
    memset(d, 0x3f3f, sizeof d);
    LL ma = 0, s = 0;
    for(int i = 1 ; i <= n ; ++i){
        ma = max(ma, a[i]);
        s += a[i];
        d[i][0] = ma * i - s;
    }
    for(int i = 0 ; i < k ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            LL s = 0, ma = 0;
            for(int h = j + 1 ; h <= n ; ++h){
                ma = max(ma, a[h]);
                s += a[h];
                d[h][i + 1] = min(d[h][i + 1], d[j][i] + ma * (h - j) - s);
            }
        }
    }
    cout << d[n][k] << endl;

    return 0;
}