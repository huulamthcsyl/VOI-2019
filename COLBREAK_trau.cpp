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

LL n, a[MaxN], w, m, b[MaxN], ans = 1e18;

LL Check1(LL k){
    LL len1 = 1, len2 = 1, r = 0;
    for(int i = 0 ; i < m ; ++i){
        if(a[i] > k) return -1;
        if(r + a[i] <= k) r += (a[i] + 1);
        else{
            len1++;
            r = a[i] + 1;
        }
    }
    k = w - k;
    r = 0;
    for(int i = 0 ; i < n ; ++i){
        if(b[i] > k) return 0;
        if(r + b[i] <= k) r += (b[i] + 1);
        else{
            len2++;
            r = b[i] + 1;
        }
    }
    ans = min(ans, max(len1, len2));
    return 1;
}


void InOut(){
    #define TASK "COLBREAK"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".ans","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(w);
    read(m);
    read(n);
    for(int i = 0 ; i < m ; ++i){
        read(a[i]);
    }
    for(int i = 0 ; i < n ; ++i){
        read(b[i]);
    }
    for(int i = 1 ; i <= w ; ++i) Check1(i);
    cout << ans << endl;
    return 0;
    

    return 0;
}