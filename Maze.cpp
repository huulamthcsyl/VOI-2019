// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e3, up[4] = {-1, 0, 1, 0}, ri[4] = {0, 1, 0, -1};

LL n, m, k, vis[MaxN][MaxN], kq[MaxN][MaxN], sl, h;
char a[MaxN][MaxN];

LL Avai(LL x, LL y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void DFS(LL x, LL y){
    vis[x][y] = 1;
    sl++;
    if(sl == h - k){
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j)
            if(vis[i][j] == 0 && a[i][j] == '.') cout << "X";
            else cout << a[i][j];
            cout << endl;
        }
        exit(0);
    }
    for(int i = 0 ; i < 4 ; ++i){
        LL xx = x + up[i], yy = y + ri[i];
        if(!Avai(xx, yy)) continue;
        if(a[xx][yy] == '#') continue;
        if(vis[xx][yy] == 0) DFS(xx, yy);
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
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j){
        cin >> a[i][j];
        if(a[i][j] == '.') h++;
    }
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
    if(a[i][j] == '.'){
        DFS(i, j);
        break;
    }

    return 0;
}
