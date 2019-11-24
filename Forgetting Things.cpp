// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m;

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
    cin >> n >> m;
    if(n == 9 && m == 1){
        cout << 9 << " " << 10 << endl;
        return 0;
    }
    if(m - n > 1 || n > m){
        cout << -1 << endl;
        return 0;
    }
    if(n == m){
        cout << n * 10 << " " << n * 10 + 1 << endl;
        return 0;
    }
    cout << n << " " << m << endl;

    return 0;
}