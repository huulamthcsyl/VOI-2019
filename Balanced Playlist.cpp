// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], kq[MaxN];
deque<LL> ma, mi;

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
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        a[i + n] = a[i + n * 2] = a[i];
    }
    LL j = 2;
    mi.push_back(1);
    ma.push_back(1);
    for(int i = 1 ; i <= n ; ++i){
        if(!mi.empty() && a[i - 1] == a[mi.front()]) 
            mi.pop_front();
        if(!ma.empty() && a[i - 1] == a[ma.front()]) 
            ma.pop_front();
        if(!mi.empty() && !ma.empty() && a[mi.front()] < a[(ma.front() + 1)] / 2){
            kq[i] = j;
            continue;
        }
        while(j <= 3 * n){
            if(!ma.empty() && !mi.empty() && a[j] < (a[ma.front()] + 1) / 2 || a[j] > a[mi.front()] * 2) 
                break;
            while(!mi.empty() && a[j] < a[mi.back()]) 
                mi.pop_back();
            mi.push_back(j);
            while(!ma.empty() && a[j] > a[ma.back()]) 
                ma.pop_back();
            ma.push_back(j);
            j++;
        }
        kq[i] = j - 1;
    }
    for(int i = 0 ; i < n ; ++i)
    if(kq[i] == 3 * n) cout << -1 << " ";
    else cout << kq[i] - i + 1 << " ";

    return 0;
}