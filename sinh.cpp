#include<bits/stdc++.h>

using namespace std ;


#define FOR( i , a , b ) for( ll i = a , _b = b ; i <= _b ; i ++ )

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

const string NAME = "ABC" ;

const ll nTest = 1 ;

// random tu l - > h

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll Rand( ll l , ll h )
{
    return uniform_int_distribution < ll >( l , h )( rng ) ;
}

bool a[MAXN] ;

main()
{
    FOR( iTest , 1 , nTest )
    {
        ofstream inp( ( NAME + ".inp" ).c_str() ) ;

        // Code phan sinh test o day
        // su dung inp thay cho cout trong phan in t�t ra code nay

        ll n = Rand( 100000 , 100000 ) ;
        ll m = Rand( n - 1 , n * 2 ) ;
        ll k = Rand( 2 , 5 ) ;

        inp << n << ' ' << k << ' ' << m << endl ;

        memset( a , false , sizeof a ) ;

        FOR( i , 1 , k )
        {
            ll tmp = Rand( 1 , n ) ;

            while( a[tmp] ) tmp = Rand( 1 , n ) ;

            a[tmp] = true ;

            inp << tmp << ' ' ;
        }

        inp << endl ;
        

        FOR( i , 2 , n ) inp << i << ' ' << Rand( 1 , i - 1 ) << ' ' << Rand( 1 , INF ) << endl ;

        FOR( i , n , m )
        {
            ll u = Rand( 1 , n ) ;
            ll v = Rand( 1 , n ) ;

            while( v == u ) v = Rand( 1 , n ) ;

            inp << u << ' ' << v << ' ' << Rand( 1 , INF ) << endl ;
        }

        inp.close() ;

        /*system( ( NAME + ".exe" ).c_str() ) ;
        system( ( NAME + "_trau.exe" ).c_str() ) ;

        if( system( ( "fc " + NAME + ".out " + NAME + ".ans" ).c_str() ) != 0 )
        {
            cout << "Test " << iTest << ": WRONG!\n" ;

            return 0 ;
        }

        cout << "Test " << iTest << ": CORRECT!\n" ;*/
    }
}
