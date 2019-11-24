// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<string, LL> II;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], t, x, y;
string s, request;
vector<II> sta;

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
    cin >> n >> t;
    cin >> s;
    sta.push_back({s, 0});
    for(int te = 1 ; te <= t ; ++te){
        cin >> request;
        if(request == "toggle"){
            cin >> x;
            x--;
            s[x] = char(49 - s[x]);
            sta.push_back({s, te});
            continue;
        }
        LL kq = 0;
        cin >> x >> y;
        x--;
        y--;
        for(int i = sta.size() - 1 ; i >= 0 ; --i){
            LL kt = 1;
            string s1 = sta[i].first;
            for(int j = x ; j <= y ; ++j)
            if(s1[j] == '0'){
                kt = 0;
                break;
            }
            if(kt){
                if(i == sta.size() - 1) kq += (te - sta[i].second);
                else kq += (sta[i + 1].second - sta[i].second);
            }
        }
        cout << kq << endl;
    }

    return 0;
}