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

LL n, a[MaxN], t, m;

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
        read(m);
        for(int i = 0 ; i < n ; ++i) read(a[i]);
        if(n == 2){
            cout << -1 << endl;
            continue;
        }
        if(m < n){
            cout << -1 << endl;
            continue;
        }
        LL ans = 0;
        LL mi1 = 1e18, vt1 = 0, mi2 = 1e18, vt2 = 0;
        for(int i = 0 ; i < n ; ++i)
        if(a[i] < mi1){
            mi1 = a[i];
            vt1 = i + 1;
        }
        for(int i = 0 ; i < n ; ++i)
        if(a[i] < mi2 && i != (vt1 - 1)){
            mi2 = a[i];
            vt2 = i + 1;
        }
        for(int i = 0 ; i < n ; ++i) ans += (a[i] + (a[(i + 1) % n]));
        for(int i = 0 ; i < m - n ; ++i) ans += (mi1 + mi2);
        cout << ans << endl;
        for(int i = 1 ; i < n ; ++i) cout << i << " " << i + 1 << endl;
        cout << 1 << " " << n << endl;
        for(int i = 0 ; i < m - n ; ++i) cout << vt1 << " " << vt2 << endl;
    }

    return 0;
}