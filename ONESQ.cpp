#include<bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const LL MaxN = 1 + 1e3;
LL n, kq, d, m, a[MaxN][MaxN], k = 1e18, ch;
 
void Solve1(){
       cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        cin >> ch;
        if(ch == '.') a[i][j] = a[i - 1][j] + 1;
        else a[i][j] = 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j)
        if(a[i][j] > 0){
            kq = max(kq, (a[i][j] + 1) * 2);
            d++;
            k = min(k, a[i][j]);
            kq = max(kq, (d + k) * 2);
        }
        else{
            d = 0;
            k = 1e18;
        }
    }
    cout << kq << endl;
}
 
void Try(LL x){
    LL k = 0, q[MaxN], l[MaxN], r[MaxN], vt[MaxN];
    for(int i = 1 ; i <= m + 1 ; ++i){
        while(k > 0 && a[x][i] < q[k]){
            r[vt[k]] = i - vt[k];
            k--;
        }
        if(a[x][i] == 0) continue;
        k++;
        q[k] = a[x][i];
        vt[k] = i;
        //cout << k << " ";
    }
    //cout << endl;
    //cout << k << endl;
    k = 0;
    for(int i = m ; i >= 0 ; --i){
        while(k > 0 && a[x][i] < q[k]){
            l[vt[k]] = vt[k] - i;
            k--;
        }
        if(a[x][i] == 0) continue;
        k++;
        q[k] = a[x][i];
        vt[k] = i;
    }
    //for(int i = 1 ; i <= m ; ++i) cout << r[i] << " ";
    //cout << endl;
    for(int i = 1 ; i <= m ; ++i) kq = max(kq, min(l[i] + r[i] - 1, a[x][i]));
    //cout << kq << endl;
}
 
int main(){
    #ifndef ONLINE_JUDGE
        // #define TASK "ONSEQ"
        // freopen(TASK".inp","r",stdin);
        // freopen(TASK".out","w",stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        cin >> ch;
        if(ch == 1) a[i][j] = a[i - 1][j] + 1;
        else a[i][j] = 0;
    }
    /*for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;*/
    //Try(3);
    //cout << a[3][5] << endl;
    for(int i = 1; i <= n ; ++i) Try(i);
    cout << kq << endl;
 
    return 0;
}