// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], t;
string s;
set<char> se;

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
        cin >> s;
        n = s.length();
        LL k = 1;
        se.clear();
        for(int i = 1 ; i <= n ; ++i)
        if(s[i] == s[i - 1]) k++;
        else{
            if(k % 2) se.insert(s[i - 1]);
            k = 1;
        }
        for(char i : se) cout << i;
        cout << endl;
    }

    return 0;
}