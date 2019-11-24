// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN];

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0'||ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
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
