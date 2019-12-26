using namespace std;
#include<bits/stdc++.h>
const int MAXN = 1+1e5;
const int LOGN = 17;
int n, q, logn;
int h[MAXN], dad[LOGN][MAXN];
vector< vector<int> > g;
void dfs(int u){
 int v;
 TR(g[u], it) if((v = *it) != dad[0][u]){
 h[v] = h[u]+1;
 dad[0][v] = u;
 dfs(v);
 }
}
int lca(int u, int v){
 if(h[u]<h[v]) swap(u, v);
 int delta = h[u]-h[v];
 FOR(i, 0, logn) if(delta&(1<<i)) u=dad[i][u];
 if(u==v) return u;
 FORD(i, logn-1, 0) if(dad[i][u] != dad[i][v])
 u = dad[i][u], v = dad[i][v];
 return dad[0][u];
}
int main(){
 cin >> n; g.resize(n);
 FOR(i, 1, n){
 int u, v;
 cin >> u >> v;
 u--; v--;
 g[u].push_back(v);
 g[v].push_back(u);
 }
 h[0] = 0; dad[0][0] = 0;
 dfs(0);
 for(logn=0; (1<<logn)<=n; ++logn);
 FOR(i, 1, logn) FOR(u, 0, n)
 dad[i][u] = dad[i-1][ dad[i-1][u] ];
 cin >> q;
 FOR(i, 0, q) {
 int u, v;
 cin >> u >> v;
 printf("LCA(%d, %d) = %d\n", u, v, lca(u-1, v-1)+1);
 }
 return 0;
}
