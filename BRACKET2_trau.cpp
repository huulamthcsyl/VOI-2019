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

LL n, a[MaxN], ch, t, quest, x, y;
string s;

LL Check(LL x, LL y){
    LL sum = 0;
    for(int i = x ; i <= y ; ++i){
        if(s[i] == '(') sum++;
        else sum--;
        if(sum < 0) return 0;
    }
    if(sum == 0) return 1;
    return 0;
}

void InOut(){
    #define TASK "BRACKET2"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".ans","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    cin >> s;
    s = " " + s;
    for(int te = 0 ; te < t ; ++te){
        cin >> quest;
        char ch;
        if(quest == 1){
            cin >> x >> ch;
            s[x] = ch;
            continue;
        }
        cin >> x >> y;
        if(Check(x, y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}