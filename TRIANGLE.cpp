// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;

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

const LL MaxN = 1 + 1e5, eps = 1e-15;

LL n, a[MaxN], kq;

inline LL Avai(LL x, LL y, LL z){
    return x < (y + z) && x > abs(y - z) && y < (x + z) && y > abs(x - z) && z < (y + x) && z > abs(y - x);
}

LL Check(LL x, LL y, LL z){
    if(!Avai(x, y, z)) return 0;
    LL p = (x + y + z) / 2;
    LL hr = p * (p - x) * (p - y) * (p - z);
    // cout << p << endl;
    LL area = floor(sqrt(hr) + eps);
    if(LD(area) - sqrt(hr) > eps) return 0;
    if((x * y * z) % (4 * area)) return 0;
    if(area % p) return 0;
    return 1;
}

void InOut(){
    #define TASK "TRIANGLE"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    if(n % 2){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= n ; ++j){
        LL k = n - i - j;
        if(k <= 0) continue;
        kq += Check(i, j, k);
    }
    // cout << Check(60, 70, 110) << endl;
    cout << kq / 6 << endl;

    return 0;
}