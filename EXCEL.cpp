// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 10 + 1e2, MOD = 2147483648;

int n, m, kq[MaxN][MaxN];
string a[MaxN][MaxN];
char ch;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void InOut(){
    #define TASK "EXCEL"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

pair<int, int> ToaDo(string& s){
    int i = 0, y = 0, x = 0;
    int n = s.length();
    while(i < n && !isdigit(s[i])){
        y = y * 25 + s[i] - 64;
        i++;
    }
    while(i < n && isdigit(s[i])){
        x = x * 10 + s[i] - '0';
        i++;
    }
    return {x, y};
}

LL Calc(int x, int y){
    if(kq[x][y] != -1) return kq[x][y];
    int len = a[x][y].length();
    if(isdigit(a[x][y][0])){
        int k = 0;
        for(int i = 0 ; i < len ; ++i) k = k * 10 + a[x][y][i] - '0';
        return kq[x][y] = k % MOD;
    }
    int i = 1, ans = 0;
    string s = "";
    while(i < len){
        if(a[x][y][i] == '+'){
            pair<int, int> td = ToaDo(s);
            s = "";
            ans = (1LL * ans + Calc(td.first, td.second)) % MOD;
            i++;
        }
        else{
            s += a[x][y][i];
            i++;
        }
    }
    pair<int, int> td = ToaDo(s);
    ans = (1LL * ans + Calc(td.first, td.second)) % MOD;
    return kq[x][y] = ans;
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cin >> n >> m;
    read(n);
    read(m);
    LL i = 1, j = 1;
    while(1){
        ch = getchar();
        if(ch == ' ') continue;
        string s = "";
        while(ch != ' ' && ch != '\n' && ch != EOF){
            s += ch;
            ch = getchar();
        }
        a[i][j] = s;
        j++;
        if(ch == EOF) break;
        if(ch == '\n'){
            i++;
            j = 1;
            continue;
        }
    }
    memset(kq, 0xff, sizeof kq);
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j) kq[i][j] = Calc(i, j);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j) cout << kq[i][j] % MOD << " ";
        cout << endl;
    }

    return 0;
}