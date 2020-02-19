#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, g, b;
        cin >> n >> g >> b;
        ll find;
        if(n % 2 == 0)
        {
            find = n / 2;
        }
        else
        {
            find = (n / 2) + 1;
        }
        // cout << "find: " << find << endl;
        ll ans = n / g;
        if(ans == 0)
        {
            cout << n << endl;
        }
        else
        {
            ll sum = find;
            ll ans2 = find / g;
            if(find % g == 0)
            {
                sum = sum + ((ans2 - 1) * b);
                // cout << "sum: " << sum << endl;
            }
            else
            {
                sum = sum + (ans2 * b);
            }
            if(sum < n)
            {
                sum = n;
            }
            cout << sum << endl;
        }
        
    }

    return 0;
}