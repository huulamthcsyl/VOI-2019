// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 3e5, INF = 1e18;

LL n, k, ans, kq;
pair<LL, LL> a[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
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
    read(n);
    read(k);
    for(int i = 0 ; i < n ; ++i){
        read(a[i].first);
        read(a[i].second);
    }
    LL j = 0;
    a[n].first = INF;
    for(int i = 0 ; i < n ; ++i){
        if(k < a[i + 1].first - a[i].second){
            kq = max(kq, a[i].second - a[j].first + k);
            while(j < i && k < a[i + 1].first - a[i].second){
                k += (a[j + 1].first - a[j].second);
                j++;
            }
        }
        if(k < a[i + 1].first - a[i].second){
            j = i + 1;
            continue;
        }
        k -= (a[i + 1].first - a[i].second);
        kq = max(kq, a[i + 1].second - a[j].first);
    }
    cout << kq << endl;

    return 0;
}