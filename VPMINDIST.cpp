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
#define hash Slience_voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h) {
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m;

LL Check(LL k){
    LL temp = a[0], cnt = 1;
    for(int i = 1 ; i < n ; ++i)
    if(a[i] - k >= temp){
        temp = a[i];
        cnt++;
    }
    return cnt >= m;
}

void InOut(){
    #define TASK "VPMINDIST"
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    sort(a, a + n);
    LL l = 0, r = a[n - 1] - a[0];
    while(l < r){
        LL tg = (l + r + 1) / 2;
        if(Check(tg)) l = tg;
        else r = tg - 1;
    }
    cout << l << endl;

    return 0;
}