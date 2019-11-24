// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], kq;

LL sumOfDigitsFrom1ToN(LL n) { 
    if(n < 10) return n * (n + 1) / 2; 

    LL d = log10(n); 
  
    LL *a = new LL[d + 1]; 
    a[0] = 0;
    a[1] = 45; 
    for(int i = 2 ; i <= d ; ++i) 
    a[i] = a[i - 1] * 10 + 45 * ceil(pow(10, i - 1)); 
  
    LL p = ceil(pow(10, d)); 
  
    LL msd = n / p; 

    return msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) + sumOfDigitsFrom1ToN(n % p); 
} 

LL sumOfDigitsFromxToy(LL x, LL y){
    return sumOfDigitsFrom1ToN(y) - sumOfDigitsFrom1ToN(x - 1);
}

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
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n - 1 ; ++i) kq = max(kq, sumOfDigitsFromxToy(min(a[i], a[i + 1]), max(a[i], a[i + 1])));
    cout << kq << endl;

    return 0;
}