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
        ll arr[n + 1]; ll sum[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for(ll i = 0; i < n - 1; i++)
        {
            sum[i] += sum[i + 1];
        }
        long double;
        vector<long double> vec;
        for(ll i = 0; i < n - 1; i++)
        {
            
        }
    }

    return 0;
}