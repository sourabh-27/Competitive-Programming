#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

bool isPrime(ll n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll f;
        cin >> f;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        ll ans = 0;
        for(ll i = n - 1; i >= 0; i--)
        {
            if(isPrime(arr[i]))
            {
                if(f == 0)
                {
                    break;
                }
                if(f > 0)
                {
                    ans = ans + arr[i];
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}