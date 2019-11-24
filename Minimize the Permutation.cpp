// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 10 + 1e2;

LL n, a[MaxN], nxt[MaxN], t;

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
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        LL mi = 1e18;
        memset(nxt, 0, sizeof nxt);
        nxt[n] = n;
        for(int i = n - 1 ; i >= 0 ; --i){
            nxt[i] = nxt[i + 1];
            if(a[i] < mi){
                nxt[i] = i;
                mi = a[i];
            }
        }
        LL i = 0, i1 = 0;
        while(i < n){
            i = nxt[i];
            for(int j = i ; j > i1 ; --j) 
            if(a[j] < a[j - 1]) swap(a[j], a[j - 1]);
            i1 = i;
            i++;
        }
        for(int i = 0 ; i < n ; ++i) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}