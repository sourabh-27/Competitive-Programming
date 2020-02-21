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
        ll n, k;
        cin >> n >> k;
        long long weight[n + 1]; ll total = 0;
        for(ll i = 0; i < n; i++)
        {
            cin >> weight[i];
            total += weight[i];
        }
        sort(weight, weight + n);
        ll weight1 = 0, weight2 = 0;
        for(ll i = 0; i < k; i++)
        {
            weight1 += weight[i];
        }
        for(ll i = n - 1; i > (n - 1 - k); i--)
        {
            weight2 += weight[i];
        }
        // cout << "weight1: " << weight1 << " weight2: " << weight2 << endl;
        ll ans1 = abs(weight1 - (total - weight1)); 
        ll ans2 = abs(weight2 - (total - weight2));
        cout << max(ans1, ans2) << endl;
    }

    return 0;
}