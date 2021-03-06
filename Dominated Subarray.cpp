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

const LL MaxN = 1 + 2e5;

LL n, a[MaxN], t, d[MaxN];

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
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        LL j = 0;
        fill(d + 1, d + n + 1, 0);
        LL kq = n, kt = 0;
        for(int i = 0 ; i < n ; ++i){
            d[a[i]]++;
            if(d[a[i]] == 1) continue;
            kt = 1;
            while(d[a[j]] != 2){
                d[a[j]]--;
                j++;
            }
            kq = min(kq, i - j + 1);
            d[a[j]]--;
            j++;
        }
        if(kt == 0) cout << -1 << endl;
        else cout << kq << endl;
    }

    return 0;
}