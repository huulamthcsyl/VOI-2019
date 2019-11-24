// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define y0 Sword_Art_Online
#define y1 Your_lie_in_April
#define yn Darling_in_the_Franxx
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

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e6;

LL n, k, x, y, kq, m, cnt, pos;
pair<LL, LL> a[MaxN];

void InOut(){
    #define TASK "FESTIVALS"
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
    for(int i = 0 ; i < n ; ++i){
        read(x);
        read(y);
        if(y - x + 1 >= k) cnt++;
        else{
            LL x1 = x % k, y1 = y % k;
            if(y1 >= x1){
                a[m] = {x1, 1};
                m++;
                a[m] = {y1 + 1, -1};
                m++;
                continue;
            }
            a[m] = {0, 1};
            m++;
            a[m] = {y1 + 1, -1};
            m++;
            a[m] = {x1, 1};
            m++;
            a[m] = {k, -1};
            m++;
        }
    }
    sort(a, a + m);
    // for(int i = 0 ; i < m ; ++i) cout << a[i].first << " " << a[i].second << endl;
    LL i = 0, s = 0;
    while(i < m){
        s += a[i].second;
        while(i < m && a[i + 1].first == a[i].first){
            i++;
            s += a[i].second;
        }
        if(s > kq){
            kq = s;
            pos = a[i].first;
        }
        i++;
    }
    cout << kq + cnt << " " << pos << endl;

    return 0;
}