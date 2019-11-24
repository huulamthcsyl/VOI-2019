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

const LL MaxN = 1 + 1e5;

LL n, d[MaxN];
LD kq;
pair<LD, LD> a[MaxN];
vector<LL> q;

void Caculate(){
    for(int i = 1 ; i < n ; ++i)
    kq += sqrt((a[q[i]].first - a[q[i - 1]].first) * (a[q[i]].first - a[q[i - 1]].first) + (a[q[i]].second - a[q[i - 1]].second) * (a[q[i]].second - a[q[i - 1]].second));
}

void Try(LL k){
    if(k == n){
        Caculate();
        return;
    }
    for(int i = 0 ; i < n ; ++i)
    if(!d[i]){
        d[i] = 1;
        q.push_back(i);
        Try(k + 1);
        q.pop_back();
        d[i] = 0;
    }
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
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i].first >> a[i].second;
    Try(0);
    LL gt = 1;
    for(int i = 2 ; i <= n ; ++i) gt *= i;
    cout << fixed << setprecision(6);
    cout << kq / gt << endl;

    return 0;
}