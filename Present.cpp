// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], t;

inline LL Read(){
    bool Neg = false;
    char c;
    while(c = getchar(), c < '0' || c > '9')
    if (c == '-') Neg = !Neg;
    LL x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    return Neg ? -x : x;
}

inline void Write(LL x){
    if (x < 0){
        putchar('-');
        x = -x;
    }
    LL p = 1;
    while(p <= x / 10) p *= 10;
    for(; p > 0; p /= 10){
        putchar(x / p + '0');
        x %= p;
    }
}

void InOut(){
	#define TASK "presents"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	t = Read();
    for(int te = 0 ; te < t ; ++te){
        n = Read();
        LL m = n * n + 1;
        for(int i = 2 ; i <= n ; ++i)
        if(m % i == 0){
            cout << i << " " << m / i << endl;
            break;
        }
    }

	return 0;
}
