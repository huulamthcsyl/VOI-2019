// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 2e5;

LL n, t;
pair<LL, LL> a[MaxN];

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
    for(int i = 0 ; i < n ; ++i) cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    for(int i = 0 ; i < n ; ++i){
        t += a[i].second;
        if(t > a[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}