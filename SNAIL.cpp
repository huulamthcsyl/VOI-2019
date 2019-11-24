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

LL n, a[MaxN], s, vt, x, k, ma = -1e18, m;

void InOut(){
    #define TASK "SNAIL"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(k);
    read(n);
    if(n == 1){
        read(x);
        if(x <= 0){
            cout << "-1 -1" << endl;
            return 0;
        }
        cout << (k - 1) / x << " " << 0 << endl;
        return 0;
    }
    for(int i = 0 ; i < n ; ++i){
        read(a[i]);
        s = max(LL(0), s + a[i]);
        if(s >= k){
            cout << 0 << " " << i << endl;
            return 0;
        }
        m += a[i];
    }
    if(m <= 0){
        cout << "-1 -1" << endl;
        return 0;
    }
    LL kt = 1;
    for(int i = 1 ; i < n ; ++i)
    if(a[i] != a[0]){
        kt = 0;
        break;
    }
    if(kt){
        cout << (k - 1) / m << " " << (k - (k - 1) / m * m) / a[0] - 1 << endl;
        return 0;
    }
    LL i = 0, h = 0, kq = 0;
    while(h < k){
        h += a[i];
        if(h < 0) h = 0;
        if(h >= k){
            cout << kq << " " << i << endl;
            return 0;
        }
        if(i + 1 < n) i++;
        else{
            kq++;
            i = 0;
        }
    }

    return 0;
}