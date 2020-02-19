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
        ll n, k1, k2;
        cin >> n >> k1 >> k2;
        ll maxi1 = INT_MIN, maxi2 = INT_MIN;
        ll arr[k1 + 1], arr2[k2 + 1];
        for(ll i = 0; i < k1; i++)
        {
            cin >> arr[i];
            maxi1 = max(maxi1, arr[i]);
        }
        
        for(ll i = 0; i < k2; i++)
        {
            cin >> arr2[i];
            maxi2 = max(maxi2, arr2[i]);
        }
        if(maxi1 > maxi2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}