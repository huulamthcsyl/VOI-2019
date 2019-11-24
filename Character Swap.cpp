// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e3;

LL n, a[MaxN], t, d[MaxN], m;
string s2, s1;
char ch1, ch2;
pair<LL, LL> kq[MaxN];

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

LL Solve(string& s1, string& s2){
    LL i = 0;
    while(i < n && s1[i] == s2[i]) i++;
    if(i == n) return 0;
    LL pos = i, vt, kt = 0;
    for(int i = pos + 1; i < n ; ++i)
    if(s1[i] == s1[pos]){
        vt = i;
        kt = 1;
    }
    if(kt){
        swap(s2[pos], s1[vt]);
        kq[m] = {vt + 1, pos + 1};
        m++;
        return Solve(s1, s2) + 1;
    }
    for(int i = pos + 1 ; i < n; i++)
    if (s2[i] == s1[pos]) vt = i;
    swap(s1[pos + 1], s2[vt]);
    kq[m] = {pos + 2, vt + 1};
    m++;
    return Solve(s1, s2) + 1;
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n;
        cin >> s1;
        cin >> s2;
        memset(d, 0, sizeof d);
        LL kt = 1;
        for(int i = 0 ; i < n ; ++i) d[s1[i] - 'a']++;
        for(int i = 0 ; i < n ; ++i) d[s2[i] - 'a']++;
        for(int i = 0 ; i < 26 ; ++i)
        if(d[i] % 2){
            kt = 0;
            break;
        }
        if(!kt){
            cout << "No" << endl;
            continue;
        }
        m = 0;
        Solve(s1, s2);
        if(m > 2 * n){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        cout << m << endl;
        for(int i = 0 ; i < m ; ++i) cout << kq[i].first << " " << kq[i].second << endl;
    }

    return 0;
}