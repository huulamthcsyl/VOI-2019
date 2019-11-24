// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 10 + 3e5;

LL n, a[MaxN], kq, ma, mi, ma1[MaxN], cnt;

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
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    for(int i = 1 ; i <= n ;){
        mi = a[i];
        LL ma = a[i], pos = i;
        for(int j = i + 1 ; j <= n ; ++j)
        if(a[j] < a[i]) break;
        else if(a[j] >= ma){
            ma = a[j];
            pos = j;
        }
        i = pos + 1;
        kq++;
    }
    cout << kq << endl;

    return 0;
}
