#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
int main()
{
    fast;
    ll k; 
    cin >> k;
    ll gcd = 0;
    for(ll i = 1; i <= k; i++){
        for(ll j = 1; j <= k; j++){
            for(ll x = 1; x <= k; x++){
                gcd += __gcd(i, __gcd(j, x));
            }
        }
    }
    cout << gcd << endl;


    return 0;
}