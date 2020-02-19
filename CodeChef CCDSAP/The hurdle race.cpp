#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll count = 0; ll maxi = INT_MIN;
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        maxi = max(maxi, x);
    }
    if(k >= maxi)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << maxi - k << endl;
    }

    return 0;
}