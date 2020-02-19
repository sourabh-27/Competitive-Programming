#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    if(n % 2 != 0 || n < 2)
    {
        cout << 0 << endl;
    }
    else
    {
        ll x = 10;
        ll ans = 0;
        while(n / x > 0)
        {
            // cout << n / x << endl;
            ans = ans + (n / x);
            x = x * 5;
        }
        cout << ans << endl;
    }

    return 0;
}