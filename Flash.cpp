// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 2208, up[] = {-1, 0, 1, 0}, ri[] = {0, 1, 0, -1}, INF = 1e9;

LL n, m, u, v, tu, tv, d[MaxN][MaxN], kq, k;
queue<pair<LL, LL> > q;
char a[MaxN][MaxN];

inline LL Read(){
    bool Neg = false;
    char c;
    while(c = getchar(), c < '0' || c > '9')
    if (c == '-') Neg = !Neg;
    LL x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    return Neg ? -x : x;
}

LL Avai(LL x, LL y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void Loang(){
    d[u][v] = 0;
    q.push({u, v});
    while(!q.empty()){
        pair<LL, LL> t = q.front();
        q.pop();
        LL x = t.first, y = t.second;
        if(x == tu && y == tv) break;
        for(int i = 0 ; i < 4 ; ++i)
        for(int j = 1 ; j <= k ; ++j){
            LL xx = x + up[i] * j, yy = y + ri[i] * j;
            if(!Avai(xx, yy)) break;
            if(a[xx][yy] == '#') break;
            if(d[x][y] >= d[xx][yy]) break;
            if(d[x][y] + 1 < d[xx][yy]){
                d[xx][yy] = d[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
}

void InOut(){
	#define TASK "flash"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n = Read();
	m = Read();
	k = Read();
	for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j) a[i][j] = getchar();
        getchar();
	}
	u = Read(); v = Read(); tu = Read(); tv = Read();
	u--;
	v--;
	tu--;
	tv--;
	for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j) d[i][j] = INF;
    Loang();
    if(d[tu][tv] == INF) cout << -1 << endl;
    else cout << d[tu][tv] << endl;
    /*for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j) cout << "(" << trace[i][j].first << "," << trace[i][j].second << ")" << " ";
        cout << endl;
    }*/
    // Test
	return 0;
}
