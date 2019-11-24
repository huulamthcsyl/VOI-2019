// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], kq, h, b[MaxN], k, s, vis[MaxN];

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0'||ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
}

void InOut(){
    #define TASK "LOCK"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(k);
    read(s);
    for(int i = 0 ; i < n ; ++i) read(a[i]);
        for(int i = 0 ; i < n ; ++i)
        if(!vis[i]){
            LL sum = 0;
            h = 0;
            for(int j = i ; vis[j] == 0 ; j = (j + s) % n){
                b[h] = a[j];
                vis[j] = 1;
                h++;
            }
            sort(b, b + h);
            for(int j = 0 ; j < h ; ++j) sum += abs(b[j] - b[h / 2]);
            kq += sum;
        }
        cout << kq << endl;

    return 0;
}
