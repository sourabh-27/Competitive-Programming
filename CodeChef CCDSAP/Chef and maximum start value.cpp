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
        ll n;
        cin >> n;
        ll arr2[n];

        ll arr[1000001];
        memset(arr, 0, sizeof(arr));
        ll maxi = INT_MIN;

        for(ll i = 0; i < n; i++)
        {
            cin >> arr2[i];
            ll k = arr[arr2[i]];
            maxi = max(maxi, k);
            for(ll j = 1; j <= sqrt(arr2[i]); j++)
            {
                if(arr2[i] % j == 0)
                {
                    if(arr2[i] / j == j)
                    {
                        arr[j]++;
                    }
                    else
                    {
                        arr[j]++;
                        arr[arr2[i] / j]++;
                    } 
                }
            }
        }
        cout << maxi << endl;
    }

    return 0;
}