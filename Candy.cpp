// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 5e2, INF = 1e18;

LL n, a[MaxN][MaxN], kq, d[MaxN][MaxN], m, x, y, z, cnt[MaxN][MaxN];
pair<LL, LL> e[10001];

inline LL Read(){
    bool Neg = false;
    char c;
    while(c = getchar(), c < '0' || c > '9')
    if (c == '-') Neg = !Neg;
    LL x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    return Neg ? -x : x;
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
	n = Read(); m = Read();
    memset(d, 0x3f3f3f, sizeof d);
	for(int i = 0 ; i < m ; ++i){
        x = Read(); y = Read(); z = Read();
        x--;
        y--;
        a[x][y] = z;
        a[y][x] = z;
        d[x][y] = z;
        d[y][x] = z;
        cnt[x][y] = 1;
        cnt[y][x] = 1;
        e[i] = {x, y};
	}
	for(int i = 0 ; i < n ; ++i) d[i][i] = 0;
	for(int k = 0 ; k < n ; ++k)
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j){
        if(d[i][k] + d[k][j] < d[i][j]){
            d[i][j] = d[i][k] + d[k][j];
            cnt[i][j] = cnt[i][k] * cnt[k][j];
        }
        if(d[i][k] + d[k][j] == d[i][j]){
            cnt[i][j] += (cnt[i][k] * cnt[k][j]);
        }
    }
    for(int i = 0 ; i < n ; ++i) cnt[i][i] = 1;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j) cout << cnt[i][j] << " ";
        cout << endl;
    }
	for(int t = 0 ; t < m ; ++t){
        kq = 0;
        LL u = e[t].first, v = e[t].second;
        for(int i = 0 ; i < n ; ++i)
        for(int j = i + 1 ; j < n ; ++j){
            if(d[i][u] + a[u][v] + d[v][j] == d[i][j] && cnt[i][u] * cnt[v][j] == cnt[i][j]) kq++;
            if(d[i][v] + a[v][u] + d[u][j] == d[i][j] && cnt[i][v] * cnt[u][j] == cnt[i][j]) kq++;
        }
        cout << kq << endl;
	}

	return 0;
}
