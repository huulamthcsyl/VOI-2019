// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], pos[26][MaxN], ma;
string kq;
string s;
vector<LL> q[MaxN];

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0'||ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
}

inline bool Gr(string s1, string s2){
    if(s1.length() > s2.length()) return 1;
    else if(s1.length() < s2.length()) return 0;
    LL n = s1.length();
    for(int i = 0 ; i < n ; ++i)
    if(s1[i] > s2[i]) return 1;
    return 0;
}

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.length();
    if(n == 1){
        cout << s << endl;
        return 0;
    }
    s = s + " ";
    for(int i = 0 ; i < n ; ++i){
        pos[s[i] - 'a'][a[s[i] - 'a']] = i;
        a[s[i] - 'a']++;
    }
    for(int i = 0 ; i < 26 ; ++i)
    if(a[i]){
        string s1 = "";
        while(1){
            char ch = s[pos[i][0]];
            LL kt = 1;
            for(int j = 0 ; j < a[i] ; ++j)
            if(pos[i][j] >= n || s[pos[i][j]] != ch){
                kt = 0;
                break;
            } else pos[i][j]++;
            if(!kt) break;
            s1 += ch;
            if(a[i] >= ma && Gr(s1, kq)){
                ma = a[i];
                kq = s1;
            }
        }
    }
    cout << kq.length() << endl;

    return 0;
}
