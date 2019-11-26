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

LL n, a[MaxN], x, d[MaxN], kq, l[MaxN], r[MaxN], s, b[MaxN];

void InOut(){
    #define TASK "REWARD"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 1 ; i <= n ; ++i){
        read(b[i]);
        d[b[i]]++;
    }
    l[1] = d[1];
    for(int i = 2 ; i <= 1e4 ; ++i) l[i] = max(l[i - 1], l[i - 2] + d[i] * i);
    r[10000] = d[10000] * 10000;
    for(int i = 1e4 - 1 ; i > 0 ; --i) r[i] = max(r[i + 1], r[i + 2] + d[i] * i);
    for(int i = 1 ; i <= 1e4 ; ++i) kq = max(kq, l[i] + r[i] - d[i] * i);
    cout << kq << endl;

    return 0;
}
