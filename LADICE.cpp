// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 3e5;

LL n, a[MaxN];
vector<LL> q[MaxN];

inline LL Read(){
    bool Neg = false;
    char c;
    while(c = getchar(), c < '0' || c > '9')
    if (c == '-') Neg = !Neg;
    LL x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    return Neg ? -x : x;
}

LL Solve(LL u){
    for(int v : q[u])
    if(!xu[v]){
        xu[v] = u;
        xv[u] = v;
        return 1;
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
	n = Read();
	m = Read();
	for(int i = 1 ; i <= n ; ++i){
        x = Read();
        y = Read();
        q[i].push_back(x);
        q[i].push_back(y);
	}
	for(int i = 1 ; i <= n ; ++i)
    if(findV(i)) cout << "LADICA" << endl;
    else cout << "SMECE" << endl;

	return 0;
}
