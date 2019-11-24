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

LL n, a[MaxN][MaxN], x, y, m, t, d[MaxN], d1[MaxN];
set<LL, greater<LL> > se, set_base;

namespace Subtask1{
    void Solve(){
        read(t);
        for(int te = 0 ; te < t ; ++te){
            read(x);
            read(y);
            LL kq = 1e18;
            for(int i = 0 ; i < n - x + 1 ; ++i)
            for(int j = 0 ; j < m - y + 1 ; ++j){
                LL ma = 0, s = 0;
                for(int h = i ; h < i + x ; ++h)
                for(int k = j ; k < j + y ; ++k){
                    ma = max(ma, a[h][k]);
                    s += a[h][k];
                }
                kq = min(kq, ma * (x * y) - s);
            }
            cout << kq << endl;
        }
    }
}

void InOut(){
    #define TASK "NMATRIX"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j) read(a[i][j]);
    if(n <= 30 && m <= 30){
        Subtask1::Solve();
        return 0;
    }
    read(t);
    for(int te = 0 ; te < t ; ++te){
        read(x);
        read(y);
        LL kq = 1e18, sum_base = 0;
        memset(d1, 0, sizeof d1);
        set_base.clear();
        for(int j = 0 ; j < y ; ++j)
        for(int i = 0 ; i < x ; ++i){
            sum_base += a[i][j];
            d1[a[i][j]]++;
            set_base.insert(a[i][j]);
        }
        for(int r = 0 ; r < n - x + 1 ; ++r){
            if(r > 0){
                for(int i = 0 ; i < y ; ++i){
                    sum_base -= a[r - 1][i];
                    d1[a[r - 1][i]]--;
                    if(d1[a[r - 1][i]] == 0) set_base.erase(a[r - 1][i]);
                    sum_base += a[r + x - 1][i];
                    d1[a[r + x - 1][i]]++;
                    set_base.insert(a[r + x - 1][i]);
                }
            }
            LL s = sum_base;
            memcpy(d, d1, sizeof d1);
            se = set_base;
            kq = min(kq, *se.begin() * (x * y) - s);
            for(int j = y ; j < m ; ++j){
                for(int i = r ; i < r + x ; ++i){
                    s -= a[i][j - y];
                    d[a[i][j - y]]--;
                    if(d[a[i][j - y]] == 0) se.erase(a[i][j - y]);
                    s += a[i][j];
                    d[a[i][j]]++;
                    se.insert(a[i][j]);
                }
                kq = min(kq, *se.begin() * (x * y) - s);
            }
        }
        cout << kq << endl;
    }

    return 0;
}