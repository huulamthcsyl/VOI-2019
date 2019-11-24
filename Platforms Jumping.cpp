#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1e4;

LL n, m, d, sum, c[MaxN], b[MaxN];

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

void Print(LL x, LL y){
    for(int i = 0 ; i < x ; ++i) cout << y << " ";
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> d;
    for(int i = 0 ; i < m ; ++i){
        cin >> c[i];
        sum += c[i];
    }
    if(n - sum >= (m + 1) * d){
        cout << "NO" << endl;
        return 0;
    }
    d--;
    while(sum < n){
        LL kt = 0;
        for (int i = 0 ; i <= m ; ++i)
            if(b[i] < d){
                b[i]++;
                kt = 1;
                sum++;
                break;
            }
        if (!kt) break;
    }
    if (sum < n){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    c[m] = 0;
    LL sl = 0;
    for(int i = 0 ; i <= m ; ++i){
        while (b[i] --) cout << "0 ";
        sl++;
        while (c[i]--) cout << sl << ' ';
    }

    return 0;
}