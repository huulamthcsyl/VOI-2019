// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], m, d[MaxN], kq;
vector<LL> prime;

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
    LL k = sqrt(min(m, n));
    kq = 1;
    for(int i = 2 ; i <= 1000 ; ++i)
    if(!d[i]){
        prime.push_back(i);
        for(int j = 2 ; j <= 1000000 / i ; ++j) d[i * j] = 1;
    }
    for(int i : prime)
    if(i > k) break;
    else if(n % i == 0 && m % i == 0) kq++;
    if(kq == 1 && m == n) cout << 2 << endl;
    else cout << kq << endl;

    return 0;
}