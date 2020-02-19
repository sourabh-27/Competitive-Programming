#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, s;
        cin >> n >> s;
        ll arr[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll maxi = INT_MIN; ll sum = 0;
        ll ans = 0; ll maxIndex;
        for(ll i = 0; i < n; i++)
        {
            if(maxi < arr[i])
            {
                maxi = arr[i];
                maxIndex = i + 1;
            }
            sum += arr[i];
            if(sum <= s)
            {
                ans = 0;
            }
            else if(sum - maxi <= s)
            {
                ans = maxIndex;
            }
        }
        cout << ans << endl;
    }

    return 0;
}