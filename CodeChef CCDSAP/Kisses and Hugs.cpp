#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define mod 1000000009

ll power(ll base, ll exp)
{
    ll res = 1;
    while(exp > 0)
    {
        if(exp % 2 == 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return (res % mod);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll ans;
        // ans = power(2, ceil((((long double)n+1)/2))) + power(2, floor(((long double)n + 1)/2)) - 2;
        if(n % 2 == 1)
        {
            ans = (power(2, (n + 1) / 2) % mod + power(2, (n + 1) / 2) % mod) % mod - 2;
        }
        else
        {
            ans = (power(2, (n / 2) + 1) % mod + power(2, n / 2) % mod) % mod - 2;
        }
        
        // cout << "ceil " << ceil(((long double)n+1)/2) << endl;
        // cout << "floor " << floor(((long double)n + 1)/2) << endl;
        cout  << ans % mod << endl;
    }

    return 0;
}