// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 10 + 1e6;

LL n, a[MaxN], x, d[MaxN], kq;

void InOut(){
	#define TASK "MINARROWS"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	kq = n;
	for(int i = 0 ; i < n ; ++i){
        cin >> x;
        if(d[x + 1]){
            d[x + 1]--;
            kq--;
        }
        d[x]++;
	}
	cout << kq << endl;

	return 0;
}
