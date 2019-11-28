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

LL n, x, y, kq = 1e18, d1[MaxN], d2[MaxN];
pair<LL, LL> a[MaxN];
set<LL> s1, s2;

void InOut(){
    #define TASK "REDUCE"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> x >> y;
        a[i] = {x, y};
        d1[x]++;
        d2[y]++;
        s1.insert(x);
        s2.insert(y);
    }
    for(int i = 0 ; i < n ; ++i){
        if(d1[a[i].first] == 1) s1.erase(a[i].first);
        if(d2[a[i].second] == 1) s2.erase(a[i].second);
        auto it1 = s1.end();
        it1--;
        auto it2 = s2.end();
        it2--;
        kq = min(kq, (*it1 - *s1.begin()) * (*it2 - *s2.begin()));
        if(d1[a[i].first] == 1) s1.insert(a[i].first);
        if(d2[a[i].second] == 1) s2.insert(a[i].second);
    }
    cout << kq << endl;

    return 0;
}