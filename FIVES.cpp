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

const LL MaxN = 1 + 2e3;

LL n, a[MaxN], t, l, r, d[MaxN][MaxN], kq[MaxN][MaxN];

namespace Subtask1{
    void Solve(){
        for(int te = 0 ; te < t ; ++te){
            read(l);
            read(r);
            LL ans = 0;
            l--;
            r--;
            for(int i = l ; i <= r ; ++i)
            for(int j = i + 1 ; j <= r ; ++j)
            for(int k = j + 1 ; k <= r ; ++k)
            if(a[l] > a[i] && a[i] < a[j] && a[j] > a[k] && a[k] < a[r]) ans++;
            cout << ans << endl;
        }
    }
}

namespace Subtask2{
    void Solve(){
        for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
        for(int k = i + 1 ; k < j ; ++k)
        if(a[k] > a[i] && a[k] > a[j]) d[i][j]++;
        memset(kq, 0xff, sizeof kq);
        for(int te = 0 ; te < t ; ++te){
            read(l);
            read(r);
            l--;
            r--;
            if(kq[l][r] != -1){
                cout << kq[l][r] << endl;
                continue;
            }
            LL ans = 0;
            for(int i = l + 1 ; i < r ; ++i)
            for(int j = i + 1 ; j < r ; ++j)
            if(a[i] < a[l] && a[j] < a[r]) ans += d[i][j];
            kq[l][r] = ans;
            cout << ans << endl;
        }
    }
} 


void InOut(){
    #define TASK "FIVES"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(t);
    for(int i = 0 ; i < n ; ++i) read(a[i]);
    if(n <= 100 && t <= 100){
        Subtask1::Solve();
        return 0;
    }
    Subtask2::Solve();

    return 0;
}