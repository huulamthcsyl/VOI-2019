// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, x, kq, d[MaxN], ma;
vector<LL> a;

LL isPrime(LL k){
    LL m = sqrt(k);
    for(int i = 2 ; i <= m ; ++i)
    if(k % i == 0) return 0;
    return 1;
}

LL GCD(LL a, LL b){
    if(a < b) swap(a, b);
    while(b){
        LL tg = b;
        b = a % b;
        a = tg;
    }
    return a;
}

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
    for(int i = 0 ; i < n ; ++i){
        cin >> x;
        if(isPrime(x)) kq++;
        else a.push_back(x);
    }
    for(int i = 0 ; i < a.size() ; ++i)
    for(int j = i + 1 ; j < a.size() ; ++j)
    if(GCD(a[i], a[j]) != 1){
        d[a[i]]++;
        d[a[j]]++;
    }
    cout << kq << endl;
    for(int i = 0 ; i < a.size() ; ++i)
    ma = max(ma, LL(a.size()) - d[a[i]]);
    cout << kq + ma << endl;

    return 0;
}