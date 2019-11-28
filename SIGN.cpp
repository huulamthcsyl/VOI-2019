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

const LL MaxN = 1 + 1e3, up[4] = {-1, 0, 1, 0}, ri[4] = {0, 1, 0, -1};

LL n, a[MaxN][MaxN], m, k, kq, d[MaxN][MaxN], ans = 1e18;
vector<pair<LL, LL> > step;

inline LL Avaiable(LL x, LL y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void Loang(LL x, LL y){
    if(x == n - 1 && y == k - 1) return;
    for(int i = 0 ; i < 4 ; ++i){
        LL xx = x + up[i], yy = y + ri[i];
        if(Avaiable(xx, yy) && d[x][y] + a[xx][yy] < d[xx][yy]){
            d[xx][yy] = d[x][y] + a[xx][yy];
            Loang(xx, yy);
        }
    }
}

void InOut(){
    #define TASK "SIGN"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j) cin >> a[i][j];
    memset(d, 0x3f3f, sizeof d);
    for(int i = 0 ; i < m ; ++i){
        d[0][i] = min(d[0][i], a[0][i]);
        Loang(0, i);
    }
    step.push_back({n - 1, k - 1});
    for(int i = 0 ; i < m ; ++i)
    if(i != k && d[n - 1][i] < ans){
        ans = d[n - 1][i];
        if(step.size() == 2) step.pop_back();
        step.push_back({n - 1, i});
    }
    while(step.back().first != 0){
        LL x = step.back().first, y = step.back().second;
        for(int i = 0 ; i < 4 ; ++i){
            LL xx = x + up[i], yy = y + ri[i];
            if(Avaiable(xx, yy) && d[xx][yy] == d[x][y] - a[x][y]){
                step.push_back({xx, yy});
                break;
            }
        }
    }
    cout << ans + a[n - 1][k - 1] << " " << step.size() << endl;
    for(int i = step.size() - 1 ; i >= 0 ; --i) cout << step[i].first + 1 << " " << step[i].second + 1 << endl;

    return 0;
}