#include<bits/stdc++.h>

using namespace std ;


#define FOR( i , a , b ) for( ll i = a , _b = b ; i <= _b ; i ++ )

#define FOD( i , a , b ) for( ll i = a , _b = b ; i >= _b ; i -- )

#define fi first

#define se second

typedef long long ll ;

const ll MAXN = 1000010 ;

const ll MAXL = 1000000 ;

const ll INF = 1000000000 ;

const ll MOD = 1000000007 ;

typedef pair < ll , ll > ii ;

typedef pair < ll , ii > iii ;

//**********************************************************RHYMASTER*********************************************************

ll n , m , k ;

ll a[1010] ;
ll b[1010] ;
ll c[MAXN] ;
ll sc[MAXN] ;
ll d[MAXN] ;
ll sd[MAXN] ;

bool check( ll v )
{
    ll j = m , cnt = 0 ;

    FOR( i , 1 , n )
    {
        while( c[i] + d[j] >= v && j > 0 ) j -- ;

        cnt += m - j ;
    }

    if( cnt >= k ) return true ;
    else return false ;
}

main()
{
    #define FILE "ABC"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".ans" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    cin >> n >> m >> k ;

    FOR( i , 1 , n ) cin >> a[i] ;
    FOR( i , 1 , m ) cin >> b[i] ;

    ll cntn = 0 ;

    FOR( i , 1 , n ) FOR( j , 1 , n ) c[++ cntn] = a[i] + a[j] ;

    ll cntm = 0 ;

    FOR( i , 1 , m ) FOR( j , 1 , m ) d[++ cntm] = b[i] + b[j] ;

    n = cntn ;
    m = cntm ;

    sort( c + 1 , c + n + 1 ) ;
    sort( d + 1 , d + m + 1 ) ;

    FOR( i , 1 , n ) sc[i] += sc[i - 1] + c[i] ;
    FOR( i , 1 , m ) sd[i] += sd[i - 1] + d[i] ;

    ll l = 1 , r = 1e12 , mid ;

    ll res ;

    while( l <= r )
    {
        mid = ( l + r ) / 2 ;

        if( check( mid ) )
        {
            l = mid + 1 ;

            res = mid ;
        }
        else r = mid - 1 ;
    }

    r = m ;

    ll ans = 0 , cnt = 0 ;

    FOR( i , 1 , n )
    {
        ll tmp = res - c[i] ;

        while( d[r] > tmp && r > 0 ) r -- ;

        cnt += m - r ;

        ans += sd[m] - sd[r] + c[i] * ( m - r ) ;
    }

    cout << ans + res * ( k - cnt ) ;
}
