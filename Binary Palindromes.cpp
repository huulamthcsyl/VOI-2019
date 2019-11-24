// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], d[MaxN], t;
string s;
set<LL> se;

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
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n;
        d[0] = 0;
        d[1] = 0;
        se.clear();
        LL kq = 0;
        for(int i = 0 ; i < n ; ++i){
            cin >> s;
            for(int j = 0 ; j < s.length() ; ++j) d[s[j] - '0']++;
            se.insert(s.length());
        }
        for(int i : se){
            if(i % 2 == 0){
                if(d[0] < i / 2 || d[1] < i / 2) break;
                kq++;
                d[0] -= i / 2;
                d[1] -= i / 2;
                continue;
            }
            if(d[0] < (i + 1) / 2 && d[1] < (i + 1) / 2) break;
            kq++;
            if(d[0] > d[1]){
                d[0] -= (i + 1) / 2;
                d[1] -= i / 2;
            }
            else{
                d[1] -= (i + 1) / 2;
                d[0] -= i / 2;
            }
        }
        cout << kq << endl;
    }

    return 0;
}