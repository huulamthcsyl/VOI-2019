// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, m, s, kq[MaxN];
pair<LL, LL> a[MaxN], b[MaxN];

LL Check(LL k){
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	LL j = 0, sum = 0;
	for(int i = 0 ; i < m ; i += k){
		while(j < n && b[j].first >= a[i].first){
			pq.push(b[j].second);
			j++;
		}
		if(pq.empty()) return 0;
		sum += pq.top();
		pq.pop();
	}
	if(sum <= s) return 1;
	else return 0;
}

void Trace(LL l){
	priority_queue<II, vector<II>, greater<II> > pq;
	LL j = 0, sum = 0;
	for(int i = 0 ; i < m ; i += l){
		while(j < n && b[j].first >= a[i].first){
			pq.push({b[j].second, b[i].first});
			j++;
		}
		for(int j = i ; j < i + l ; ++j) kq[a[j].second] = pq.top().second;
		pq.pop();
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
	cin >> n >> m >> s;
	for(int i = 0 ; i < m ; ++i){
        cin >> a[i].first;
        a[i].second = i;
	}
	for(int i = 0 ; i < n ; ++i) cin >> b[i].first;
	for(int i = 0 ; i < n ; ++i) cin >> b[i].second;
	sort(a, a + m);
	sort(b, b + n);
	reverse(a, a + m);
	reverse(b, b + n);
	// for(int i = 0 ; i < n ; ++i) cout << b[i].first << " " << b[i].second << endl;
	LL kt = 0, l = 0, r = m;
	if(!Check(m)){
		cout << "NO" << endl;
		return 0;
	}
	while(l < r){
		LL tg = (l + r) / 2;
		if(Check(tg)) r = tg;
		else l = tg + 1;
	}
	cout << "YES" << endl;
	Trace(l);
	for(int i = 0 ; i < m ; ++i) cout << kq[i] << " ";

	return 0;
}
