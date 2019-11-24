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

const LL MaxN = 1 + 1e3, up[4] = {-1, 0, 1, 0}, ri[4] = {0, 1, 0, -1};

LL n, a[MaxN][MaxN], m, vis[MaxN][MaxN], ma, id[MaxN][MaxN], ncc, kq;
vector<II> pos[MaxN];

LL Avaiable(LL x, LL y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(LL x, LL y){
    pos[a[x][y]].push_back({x, y});
    vis[x][y] = 1;
    queue<II> q;
    q.push({x, y});
    while(!q.empty()){
        II temp = q.front();
        q.pop();
        LL u = temp.first, v = temp.second;
        vis[u][v] = 1;
        for(int i = 0 ; i < 4 ; ++i){
            LL xx = u + up[i], yy = v + ri[i];
            if(!Avaiable(xx, yy) || vis[xx][yy]) continue;
            if(a[xx][yy] == a[x][y]) q.push({xx, yy});
        }
    }
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
    read(n);
    read(m);
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j){
        read(a[i][j]);
        ma = max(ma, a[i][j]);
    }
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
    if(!vis[i][j]) BFS(i, j);
    for(int j = ma ; j > 0 ; --j){
        while(!pos[j].empty()){
            ncc++;
            queue<II> q;
            vector<II>::iterator it = pos[j].end();
            it--;
            II temp = *it;
            pos[j].pop_back();
            q.push(temp);
            while(!q.empty()){
                temp = q.front();
                q.pop();
                LL u = temp.first, v = temp.second;
                id[temp.first][temp.second] = 1;
                for(int i = 0 ; i < 4 ; ++i){
                    LL xx = u + up[i], yy = v + ri[i];
                    if(!Avaiable(xx, yy)) continue;
                    if(a[xx][yy] > a[u][v]) ncc--;
                    else if(a[xx][yy] == a[u][v] && id[xx][yy] == 0) 
                    q.push({xx, yy});
                }
            }
        }
        cout << j << " " << ncc << endl;
        kq = max(kq, ncc);
    }
    cout << kq << endl;

    return 0;
}