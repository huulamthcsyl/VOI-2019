// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], pos[MaxN], k, t;
string s;

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
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n >> k;
        cin >> s;
        LL m = 0;
        for(int i = 0 ; i < n ; ++i)
        if(s[i] == '0'){
            pos[m] = i;
            m++;
        }
        for(int i = 0 ; i < m ; ++i){
            if(pos[i] - i <= k){
                swap(s[i], s[pos[i]]);
                k -= (pos[i] - i);
                continue;
            }
            swap(s[pos[i]], s[pos[i] - k]);
            break;
        }
        cout << s << endl;
    }

    return 0;
}