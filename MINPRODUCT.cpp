// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], x;
multiset<LL> pos, neg;

void InOut(){
    #define TASK "MINPRODUCT"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> x;
        if(x >= 0) pos.insert(x);
        else neg.insert(x);
    }
    if(pos.size() && neg.size()){
        multiset<LL>::iterator it1 = pos.end();
        multiset<LL>::iterator it2 = neg.begin();
        cout << *it2 * *(--it1) << endl;
    } else if(pos.size()){
        multiset<LL>::iterator it1 = pos.begin();
        cout << *it1 * *(++it1) << endl;
    } else{
        multiset<LL>::iterator it2 = neg.end();
        cout << *(--it2) * *(--it2) << endl;
    }

    return 0;
}