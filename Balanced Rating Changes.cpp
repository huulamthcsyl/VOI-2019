// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], x, s, k, h;

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
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        s += a[i] / 2;
    }
    for(int i = 0 ; i < n ; ++i)
    if(a[i] % 2 == 0 || s == 0) cout << a[i] / 2 << endl;
    else if(s < 0){
        if(a[i] > 0){
            cout << a[i] / 2 + 1 << endl;
            s++;
        }
        else cout << a[i] / 2 << endl;
    }
    else{
        if(a[i] < 0){
            cout << a[i] / 2 - 1 << endl;
            s--;
        }
        else cout << a[i] / 2 << endl;
    }

    return 0;
}