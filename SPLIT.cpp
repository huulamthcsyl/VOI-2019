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

LL n, a[MaxN], m, k, kq, g[MaxN][MaxN], f[MaxN][MaxN][11];
string s1, s2;

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
    cin >> n >> m >> k;
    cin >> s1;
    cin >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j)
    if(s1[i] == s2[j]) g[i][j] = g[i - 1][j - 1] + 1;
    for(int h = 1 ; h <= k ; ++h)
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j)
    if(s1[i] == s2[j]) f[i][j][h] = max(f[i - 1][j][h], max(f[i][j - 1][h], f[i - g[i][j]][j - g[i][j]][h - 1] + g[i][j]));
    else f[i][j][h] = max(f[i - 1][j][h], f[i][j - 1][h]);
    if(f[n][m][k] < k) cout << -1 << endl;
    else cout << f[n][m][k] << endl;

    return 0;
}