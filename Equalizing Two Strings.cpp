#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const LL maxn = 1 + 2e5;
 
LL n, q, d[200], pos[200];
string s1, s2;
 
LL Check(string s){
    LL kq = 0, kt = 1;
    while(1){
        kt = 0;
        for(int i = 0; i + 1 < n; ++i)
            if (s[i] > s[i + 1]) {
                kq++;
                kt = 1;
                swap(s[i], s[i + 1]);
            }
        if(kt == 0) break;
    }
    return kq % 2;
}

void Solve(){
    memset(d, 0, sizeof d);
    cin >> n;
    cin >> s1;
    cin >> s2;
    LL ans = 0, kt = 0;
    for (int i = 0; i < n; ++i){
        d[s1[i]]++;
        if (d[s1[i]] >= 2) kt = 1;
    }
    for (int i = 0; i < n; ++i){
        d[s2[i]] --;
        if (d[s2[i]] < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    if (kt) cout << "YES" << endl;
    else if (Check(s1) == Check(s2)) cout << "YES" << endl;
    else cout << "NO" << endl;
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
    cin >> q;
    for(int te = 0 ; te < q ; ++te) Solve();
    return 0;
}