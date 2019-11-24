// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], s;
vector<LL> pos, neg;
vector<pair<LL, LL> > result;

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
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        if(a[i] >= 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    sort(pos.begin(), pos.end());
    if(neg.empty()){
        LL k = pos[0], kq = 0;
        for(int i = 1 ; i < n - 1 ; ++i){
            kq += pos[i];
            result.push_back({k, pos[i]});
            k -= pos[i];
        }
        cout << kq << endl;
        result.push_back({pos[n - 1], k});
        for(auto i : result) cout << i.first << " " << i.second << endl;
    }
    else{
        LL k = neg[0], kq = 0;
        // cout << k << endl;
        for(int i = 0 ; i < pos.size() - 1 ; ++i){
            result.push_back({k, pos[i]});
            k -= pos[i];
        }
        neg[0] = k;
        kq = pos[pos.size() - 1];
        // cout << kq << endl;
        for(int i = 0 ; i < neg.size() ; ++i){
            result.push_back({kq, neg[i]});
            kq -= neg[i];
        }
        cout << kq << endl;
        for(auto i : result) cout << i.first << " " << i.second << endl;
    }

    return 0;
}