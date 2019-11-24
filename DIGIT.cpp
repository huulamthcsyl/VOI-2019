// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m;
string s1, s2, kq;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void InOut(){
    #define TASK "DIGIT"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s1;
    cin >> s2;
    n = s1.length();
    m = s2.length();
    if(n < m){
        if(s2[0] > 1) kq += char(s2[0] - 1);
        for(int i = 0 ; i < m - 1 ; ++i) kq += "9";
        cout << kq << endl;
    }
    else{
        cout << s2 << endl;
    }

    return 0;
}