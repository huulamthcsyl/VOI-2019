// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], q;

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
    cin >> q;
    for(int te = 0 ; te < q ; ++te){
        cin >> n;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        sort(a, a + n);
        LL kq = 1;
        for(int i = 0 ; i < n - 1 ; ++i) 
        if(a[i + 1] - a[i] == 1){
            kq = 2;
            break;
        }
        cout << kq << endl;
    }

    return 0;
}