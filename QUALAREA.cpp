#include<bits/stdc++.h>

using namespace std ;


#define FOR( i , a , b ) for( ll i = a, _b = b ; i <= _b ; i ++ )

#define FOD( i , a , b ) for( ll i = a , _b = b ; i >= _b ; i -- )

#define fi first

#define se second

typedef long long ll ;

const ll MAXN = 100010 ;

const ll MAXL = 100000 ;

const ll INF = 1000000000 ;

const ll MOD = 1000000007 ;

typedef pair < ll , ll > ii ;

typedef pair < ll , ii > iii ;

//**********************************************************RHYMASTER*********************************************************

ll n ;

ll res = 0 ;

ii a[310] ;

ll ccw( ll i , ll j , ll k )
{
    ii u = ii( a[j].fi - a[i].fi , a[j].se - a[i].se ) ;
    ii v = ii( a[k].fi - a[j].fi , a[k].se - a[j].se ) ;

    ll ans = u.fi * v.se - v.fi * u.se ;

    if( ans > 0 ) return 1 ;
    if( ans < 0 ) return -1 ;
    return 0 ;
}

ll calc( ll U , ll V , ll K )
{
    ii u = a[U] ;
    ii v = a[V] ;
    ii k = a[K] ;

    return abs( ( v.fi - u.fi ) * ( k.se - u.se ) - ( k.fi - u.fi ) * ( v.se - u.se ) ) ;
}

void lam( ll u , ll v )
{
    ll am = 0 ;
    ll du = 0 ;

    ll cntam = 0 ;
    ll cntdu = 0 ;

    FOR( i , 1 , n ) if( i != u && i != v )
    {
        ll tmp = ccw( u , v , i ) ;

        if( tmp == 0 ) continue ;

        if( tmp == 1 )
        {
            du = max( du , calc( u , v , i ) ) ;

            cntdu ++ ;
        }
        else
        {
            am = max( am , calc( u , v , i ) ) ;

            cntam ++ ;
        }
    }

    if( cntam == 0 || cntdu == 0 ) du = 0 , am = 0 ;

    res = max( res , du + am ) ;
}

main()
{
    #define FILE "a"

    // freopen( FILE".inp" , "r" , stdin ) ;
    // freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    cin >> n ;

    FOR( i , 1 , n ) cin >> a[i].fi >> a[i].se ;

    FOR( i , 1 , n ) FOR( j , i + 1 , n ) lam( i , j ) ;

    cout << res ;
}