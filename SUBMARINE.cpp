// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, x, y, k;

void Print(LL k){
    cout << k << endl;
    exit(0);
}

void InOut(){
    #define TASK "SUBMARINE"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;
    if(k == 1) Print(0);
    if(k == n){
        if(k > m) Print(k - 1);
        Print(k);
    }
    if(k == m){
        if(k > n) Print(k - 1);
        if(k <= x || n - x + 1 >= k) Print(k + 1);
        Print(k);
    }
    if(k > n){
        if(k == m) Print(k - 1);
        if(y == 1 || y == m) Print(k - 1);
        Print(k);
    }
    if(k > m){
        if(k == n) Print(k - 1);
        if(x == 1 || x == n) Print(k - 1);
        Print(k);
    }
    if(n == 1){
        if(m == 1) Print(0);
        if(y == 1) Print(k - 1);
        if(k > y || m - y + 1 < k) Print(k - 1);
        Print(k);
    }
    if(m == 1){
        if(x == 1) Print(k - 1);
        if(k > x || n - x + 1 < k) Print(k - 1);
        Print(k);
    }
    if(x == 1){
        if(y == 1) Print(k);
        if(y < k || m - y + 1 < k) Print(k);
        Print(k + 1);
    }
    if(y == 1){
        if(x == 1) Print(k);
        if(x < k || n - x + 1 < k) Print(k);
        Print(k + 1);
    }
    if(x == n){
        if(y == m || y == 1) Print(k);
        if(y < k || m - y + 1 < k) Print(k);
        Print(k + 1);
    }
    if(y == m){
        if(x == n || x == 1) Print(k);
        if(x < k || n - x + 1 < k) Print(k);
        Print(k + 1);
    }
    if(k > x || n - x + 1 < k) Print(k + 1);
    if(k > y || m - y + 1 < k) Print(k + 1);
    Print(k + 2);

    return 0;
}