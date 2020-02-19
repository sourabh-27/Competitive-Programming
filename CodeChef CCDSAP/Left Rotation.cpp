#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, d;
    cin >> n >> d;
    ll arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    d = d % n;
    for(ll i = d; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    for(ll i = 0; i < d; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}