// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

#define y0 Sword Art Online
#define y1 Your lie in April
#define yn Darling in the Franxx
#define tm Plastic Memories
#define lr Charlotte
#define norm Weathering with you
#define left Violet Evergarden
#define have Date a live
#define ends Your name
#define prev Five centimeters per second
#define hash Slience voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h) {
    return uniform_int_distribution<LL>(l, h)(rng);
}

LL n, a[MaxN], kq, t;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
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
    read(t);
    for(int te = 0 ; te < t ; ++te){
        read(n);
        for(int i = 1 ; i <= n ; ++i) read(a[i]);
        LL kq = 0;
        sort(a + 1, a + n + 1);
        for(int i = 1 ; i <= n ; ++i) kq = max(kq, min(n - i + 1, a[i]));
        cout << kq << endl;
    }

    return 0;
}