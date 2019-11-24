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

LL n, a[MaxN], prv[MaxN], after[MaxN], k;
string s, s1;

void InOut(){
    #define TASK "Chips"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".ans","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cin >> s;
    for(int i = 1 ; i < n ; ++i) prv[i] = i - 1;
    prv[0] = n - 1;
    for(int i = 0 ; i < n - 1 ; ++i) after[i] = i + 1;
    after[n - 1] = 0;
    for(int j = 0 ; j < k ; ++j){
        s1 = "";
        for(int i = 0 ; i < n ; ++i){
            if(s[prv[i]] != s[i] && s[after[i]] != s[i]) s1 += s[prv[i]];
            else s1 += s[i];
        }
        s = s1;
    }
    cout << s << endl;

    return 0;
}