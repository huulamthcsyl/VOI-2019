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

LL n, a[MaxN], m;
string s;
vector<LL> ans;

inline LL Check(LL x, LL y){
    if(abs(x - n) <= 1 && abs(y - m) <= 1) return 1;
    return 0;
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
    cin >> n >> m;
    cin >> s;
    LL x = 0, y = 0;
    LL len = s.length();
    for(int i = 0 ; i <= len ; ++i){
        if(Check(x, y)) ans.push_back(i);
        if(i == len) break;
        if(s[i] == 'D') y++;
        if(s[i] == 'L') x--;
        if(s[i] == 'R') x++;
        if(s[i] == 'U') y--;
    }
    if(ans.size() == 0) cout << -1 << endl;
    else for(int i : ans) cout << i << endl;

    return 0;
}