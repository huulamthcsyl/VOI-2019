// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5, INF = 1e9;

LL n, a[MaxN], d[26][MaxN], kq[MaxN];
string s;
vector<LL> q[26];

LL Check(LL k){
    memset(kq, 0, sizeof kq);
    for(int i = 0 ; i < n - k + 1 ; ++i){
        string s1 = s.substr(i, k);
        if(s.find(s1, i + k) != string::npos) return 1;
    }
    return 0;
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
    cin >> s;
    for(int i = 0 ; i < 26 ; ++i) q[i].push_back(n);
    for(int i = n - 1 ; i >= 0 ; --i){
        for(int j = 0 ; j < 26 ; ++j) d[j][i] = *(q[j].end() - 1);
        q[s[i] - 'a'].push_back(i);
    }
    // for(int i = 0 ; i < n ; ++i) cout << d[0][i] << " ";
    // cout << endl; 
    LL l = 0, r = n / 2;
    while(l < r){
        LL tg = (l + r + 1) / 2;
        if(Check(tg)) l = tg;
        else r = tg - 1;
    }
    cout << l << endl;

    return 0;
}