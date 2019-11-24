// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e3;

LL n, a[MaxN], x, y, z, q, f[MaxN][MaxN], d[MaxN][MaxN];
priority_queue<II> price[MaxN];

void InOut(){
    #define TASK "TREE"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 0 ; i < n ; ++i){
        cin >> x >> y >> z;
        price[x].push({y, z});
    }
    for(int i = 1 ; i <= 1000 ; ++i){
        LL cnt = 0;
        while(cnt < 1000 && !price[i].empty()){
            II x = price[i].top();
            price[i].pop();
            cnt++;
            d[i][cnt] = x.first;
            if(x.first - x.second > 0) price[i].push({x.first - x.second, x.second});
        }
    }
    for(int i = 1 ; i <= 1000 ; ++i)
    for(int j = 1 ; j <= 1000 ; ++j) d[i][j] += d[i][j - 1];
    for(int i = 1 ; i <= 1000 ; ++i){
        for(int j = 0 ; j <= 1000 ; ++j){
            f[i][j] = f[i - 1][j];
            for(int h = 1 ; h <= 1000 ; ++h){
                if(i * h > j) break;
                f[i][j] = max(f[i][j], f[i - 1][j - i * h] + d[i][h]);
            }
        }
    }
    for(int te = 0 ; te < q ; ++te){
        cin >> x;
        cout << f[1000][x] << " ";
    }

    return 0;
}