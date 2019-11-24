// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;

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

const LL MaxN = 1 + 1e2, up[4] = {-1, 0, 1, 0}, ri[4] = {0, 1, 0, -1};

LL n, m, k, len, kq, mov[MaxN], dp[MaxN][MaxN][MaxN];
char a[MaxN][MaxN];
string s;
vector<LL> pos;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

namespace Subtask1{
    LL Avai(LL x, LL y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    LL Check(LL x, LL y){
        for(int i = 0 ; i < len ; ++i){
            x += up[mov[i]];
            y += ri[mov[i]];
            if(!Avai(x, y) || a[x][y] == '#') return 0;
        }
        return 1;
    }

    void Solve(){
        for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
        if(a[i][j] == '.' && Check(i, j)) kq++;
        cout << kq << endl;
    }
}

// inline LL Avai(LL x, LL y){
//     return x >= 0 && x < n && y >= 0 && y < m;
// }

// void Check(LL x, LL y, LL k){
//     if(!Avai(x, y) || a[x][y] == '#') return;
//     if(k == len && !d[x][y]){
//         // cout << x << " " << y << endl;
//         d[x][y] = 1;
//         kq++;
//         return;
//     }
//     if(mov[k] < 4){
//         Check(x + up[mov[k]], y + ri[mov[k]], k + 1);
//         return;
//     }
//     Check(x + up[0], y + ri[0], k + 1);
//     Check(x + up[1], y + ri[1], k + 1);
//     Check(x + up[2], y + ri[2], k + 1);
//     Check(x + up[3], y + ri[3], k + 1);
//     return;
// }

inline LL Avai(LL x, LL y){
    return x > 0 && x <= n && y > 0 && y <= m;
}

void Solve(LL x, LL y, LL status, LL t){
    LL x1 = x - up[status], y1 = y - ri[status];
    if(x1 && y1 && x1 <= n && y1 <= m) dp[x][y][t] = max(dp[x][y][t], dp[x1][y1][t - 1]);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> len;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        cin >> a[i][j];
        if(a[i][j] == '.') dp[i][j][0] = 1;
        else dp[i][j][0] = 0;
    }
    cin >> s;
    s = " " + s;
    for(int i = 1 ; i <= len ; ++i)
    if(s[i] == 'N') mov[i] = 0;
    else if(s[i] == 'E') mov[i] = 1;
    else if(s[i] == 'S') mov[i] = 2;
    else if(s[i] == 'W') mov[i] = 3;
    else mov[i] = 4;
    for(int t = 1 ; t <= len ; ++t)
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j)
    if(a[i][j] == '.'){
        if(mov[t] < 4) Solve(i, j, mov[t], t);
        else 
            for(int k = 0 ; k < 4 ; ++k) Solve(i, j, k, t);
    }
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j)
    if(dp[i][j][len]) kq++;
    cout << kq << endl;
    // cout << Solve(1, 1, 3) << endl;

    return 0;
}