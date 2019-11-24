// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5, esp = 1e-12;

LL n, k, kq;
pair<LL, LL> a[MaxN];

inline double Area(II x, II y, II z){
    return abs((y.first - x.first) * (y.second + x.second) + (z.first - y.first) * (z.second + y.second) + (x.first - z.first) * (x.second + z.second)) * double(1);
}

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
    read(n);
    read(k);
    for(int i = 0 ; i < n ; ++i){
        read(a[i].first);
        read(a[i].second);
    }
    for(int i = 0 ; i < n ; ++i)
    for(int j = i + 1 ; j < n ; ++j){
        if(double(k) - Area({0, 0}, a[i], a[j]) / sqrt((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second)) < esp) kq++;
    }
    cout << kq << endl;

    return 0;
}
