// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], t, r, p, s;
string st;

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
        cin >> r >> p >> s;
        LL x1 = 0, x2 = 0, x3 = 0;
        cin >> st;
        for(int i = 0 ; i < n ; ++i)
        if(st[i] == 'R') x1++;
        else if(st[i] == 'P') x2++;
        else x3++;
        if((min(x2, s) + min(x3, r) + min(x1, p)) < (n + 1) / 2){
            cout << "NO" << endl;
            continue;
        }
        string kq = "";
        for(int i = 0 ; i < n ; ++i){
            if(st[i] == 'R'){
                if(p){
                    kq += "P";
                    p--;
                } else kq += ".";
                continue;
            }
            if(st[i] == 'P'){
                if(s){
                    kq += "S";
                    s--;
                } else kq += ".";
                continue;
            }
            if(st[i] == 'S'){
                if(r){
                    kq += "R";
                    r--;
                } else kq += ".";
                continue;
            }
        }
        for(int i = 0 ; i < n ; ++i)
        if(kq[i] == '.'){
            if(p) kq[i] = 'P', p--;
            else if(r) kq[i] = 'R', r--;
            else kq[i] = 'S', s--;
        }
        cout << "YES" << endl;
        cout << kq << endl;
    }

    return 0;
}