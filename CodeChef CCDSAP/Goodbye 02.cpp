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
        ll arr[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int flag = 0;
        for(ll i = 0; i < n - 1; i++)
        {
            if(abs(arr[i] - arr[i + 1]) >= 2)
            {
                cout << "Yes" << endl;
                cout << i + 1 << " " << i + 2 << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout << "No" << endl;
        }
    }

    return 0;
}