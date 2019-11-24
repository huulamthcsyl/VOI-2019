#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MaxN = 60;

LL n, k, comb[2 * MaxN + 2][2 * MaxN + 2], dp[2 * MaxN + 2][2 * MaxN + 2], h;

void InOut(){
    #define TASK "WBRACKET"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

string a[LL(2e6)], s;
LL m, sl = 0;

LL Check(string s){
    LL k = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == '(') k++;
        else k--;
        if(k < 0) return 1;
    }
    if(k > 0) return 1;
    return 0;
}

void Try(LL k){
    if(k == n){
        if(Check(s)){
            sl++;
            if(sl == h){
                cout << s << endl;
                exit(0);
            }
        }
        return;
    }
    for(int i = 0 ; i < 2 ; ++i){
        if(i == 0){
            s = s + '(';
            Try(k + 1);
            s.erase(s.length() - 1);
        }
        else{
            s = s + ')';
            Try(k + 1);
            s.erase(s.length() - 1);
        }
    }
}

int main() {
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    m = 0;
    Try(0);
    // n /= 2;
    // comb[0][0] = 1;
    // for (int i = 1; i <= 2 * n; ++i) {
    //     comb[i][0] = 1;
    //     for (int j = 1; j <= i; ++j) {
    //         comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    //     }
    // }
    // for (int i = 2 * n - 2; i >= 0; --i) {
    //     if (i % 2 == 0) {
    //         dp[i][0] = dp[i + 1][1] + comb[2 * n - i - 1][(2 * n - i) / 2];
    //     }
    //     for (int j = 1; j <= i; ++j) {
    //         dp[i][j] = dp[i + 1][j - 1] + dp[i + 1][j + 1];
    //     }
    // }

    // int extra = 0;
    // int i;
    // for (i = 1; i <= 2 * n; ++i) {
    //     if (dp[i][extra + 1] >= k) {
    //         cout << "(";
    //         extra += 1;
    //     } else {
    //         k -= dp[i][extra + 1];
    //         cout << ")";
    //         if (extra > 0) {
    //             extra -= 1;
    //         } else {
    //             break;
    //         }
    //     }
    // }
    // int open = (2 * n - i + 1) / 2;
    // for (i += 1; i <= 2 * n; ++i) {
    //     if (open && comb[2 * n - i][open - 1] >= k) {
    //         cout << "(";
    //         open -= 1;
    //     } else {
    //         if (open) {
    //             k -= comb[2 * n - i][open - 1];
    //         }
    //         cout << ")";
    //     }
    // }

    return 0;
}
