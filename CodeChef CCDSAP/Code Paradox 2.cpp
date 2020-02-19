#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> vec;
    for(ll i = n - 1; i >= 0; i--)
    {
        ll mini = arr[i]; ll maxi = arr[i]; ll ans = i;
        for(ll j = i - 1; j >= 0; j--)
        {
            if(arr[j] == (maxi + 1) || arr[j] == (mini - 1))
            {
                if(arr[j] == maxi + 1)
                {
                    maxi = maxi + 1;
                }
                if(arr[j] == mini - 1)
                {
                    mini = mini - 1;
                }
                ans = j;
                // cout << "i: " << i << " ans: " << ans << endl;
            }
            else
            {
                vec.push_back(ans + 1);
                break;
            }
        }
    }

    cout << "1" << " ";
    for(ll i = n - 2; i >= 0; i--)
    {
        cout << vec[i] << " ";
    }

    return 0;
}