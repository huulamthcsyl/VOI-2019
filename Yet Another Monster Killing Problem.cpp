// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

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

LL n, a[MaxN], m, t;
II b[MaxN];
vector<II> q;

void Solve(){
    read(n);
    for(int i = 0 ; i < n ; ++i) read(a[i]);
    read(m);
    LL temp = 0;
    for(int i = 0 ; i < n ; ++i){
        read(b[i].second);
        read(b[i].first);
        temp = max(temp, b[i].second);
    }
    sort(b, b + m);
    if(*max_element(a, a + n) > temp){
        cout << -1 << endl;
        return;
    }
    q.clear();
    LL ma = 0;
    for(int i = 0 ; i < m ; ++i)
    if(b[i].second > ma){
        ma = b[i].second;
        q.push_back(b[i]);
    }
    LL i = 0, kq = 0;
    while(i < n){
        LL k = 0, ma = 0;
        while(i + k < n){
            ma = max(ma, a[i + k]);
            LL pos = Tk(ma, k);
            if(pos == -1) break;
            k++;
        }
        kq++;
    }
    cout << kq << endl;
}

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(t);
    for(int te = 0 ; te < t ; ++te) Solve();

    return 0;
}