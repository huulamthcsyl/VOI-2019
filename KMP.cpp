// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

namespace KMP{
    int n;
    string s;
    int kmp[26];
    void KMP(){
        int j = kmp[1] = 0;
        for(int i = 2 ; i <= n ; ++i){
            while(j > 0 && s[i] != s[j + 1]) j = kmp[j];
            if(s[i] == s[j + 1]) j++;
            kmp[i] = j;
        }
        // kmp[i] = j max < i
        // s[1..j] là hậu tố của s[1..i]
    }
    void Next(){
        int nex[n][26];
        for(int i = 0 ; i <= n ; ++i)
        for(int c = 'A' ; c <= 'Z' ; ++c){
            int j = i;
            while(j > 0 && s[j + 1] != c) j = kmp[j];
            if(s[j + 1] == c) j++;
            nex[i][c] = j;
        }
    }
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

    return 0;
}