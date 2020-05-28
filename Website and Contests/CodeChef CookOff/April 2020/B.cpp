#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;

ll power(ll x, unsigned int y)  
{  
    ll res = 1;
    x = x % mod;
    if(x == 0) return 0;
    while(y > 0)  
    {    
        if (y & 1)  
            res = (res*x) % mod;  
        y = y >> 1;
        x = (x * x) % mod;  
    }  
    return res;  
}  
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, a;
        cin >> n >> a;
        ll ans = 1; ll sum = 0;
        for(ll i = 1; i <= n; i++){
            ans = 1;
            // for(ll j = 0; j < 2 * i - 1; j++){
            //     // ans = ans * a;
            //     ans = ((ans % mod) * (a % mod)) % mod;
            // }
            ans = ((ans % mod) * (power(a, (2 * i - 1)) % mod) % mod);
            // cout << "ans: " << ans << endl;
            a = ((a % mod) * (ans % mod))  % mod;
            // a = a * ans;
            sum = ((sum % mod) + (ans % mod)) % mod;
        }
        cout << sum % mod << endl;
    }


    return 0;
}