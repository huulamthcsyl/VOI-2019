// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e4;

LL n, a[MaxN], m;
string s[MaxN];
char ch;
unordered_map<string, char> d;

inline LL scan( LL &a )
{
    bool minus = false ;

    LL res = 0 ;

    char c ;

    c = getchar() ;

    while( true )
    {
        if( c == '-' ) break ;

        if( c >= '0' && c <= '9' ) break ;

        c = getchar() ;
    }

    if( c == '-' ) minus = true ;
    else res = c - '0' ;

    while( true )
    {
        c = getchar() ;

        if( c < '0' || c > '9' ) break ;

        res = res * 10 + ( c - '0' ) ;
    }
    if( minus ) a = -res ;
    else a = res ;

    return 0 ;
}

inline void print( LL n )
{
    if( n < 0 ) putchar( '-' ) , n = -n ;

    LL N = n, rev , count = 0 ;

    rev = N ;

    if( N == 0 )
    {
        putchar( '0' ) ;

        return ;
    }

    while( ( rev % 10 ) == 0 )
    {
        count ++ ;

        rev /= 10 ;
    }

    rev = 0 ;

    while( N != 0 )
    {
        rev = ( rev << 3 ) + ( rev << 1 ) + N % 10 ;

        N /= 10 ;
    }

    while( rev != 0 )
    {
        putchar( rev % 10 + '0' ) ;

        rev /= 10 ;
    }

    while( count -- ) putchar('0') ;
}


LL Check(LL k){
    // cout << k << endl;
    for(int i = 0 ; i < m ; ++i){
        string s1 = s[i].substr(0, n - k);
        d[s1]++;
        // cout << s[i] << " " << s1 << endl;
        if(d[s1] > 1) return 0;
    }
    return 1;
    // cout << endl;
}

void InOut(){
	#define TASK "ROWCUT"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scan(n);
	scan(m);
	for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            ch = getchar();
            s[j] += ch;
        }
        ch = getchar();
    }
    LL l = 0, r = n;
    while(l < r){
        LL tg = (l + r + 1) / 2;
        if(Check(tg)) l = tg;
        else r = tg - 1;
    }
    if(l == 0) print(-1);
    else print(l);

	return 0;
}
