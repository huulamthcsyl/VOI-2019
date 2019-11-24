// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], d[MaxN];
string s1, s2;

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
    cin >> s1;
    cin >> s2;
    LL m = s2.length();
    for(int i = m - 2 ; i >= 0 ; --i) d[s2[i] - 'a']++;
    n = s1.length();
    LL kq = m;
    for(int i = 1 ; i < n ; ++i) kq += (m - d[s1[i] - 'a']);
    cout << kq << endl;

    return 0;
}