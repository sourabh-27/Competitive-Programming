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
        ll n, k;
        cin >> n >> k;
        ll temp = k / n;
        ll temp2 = k % n;
        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for(ll i = 0; i < n / 2; i++)
        {
            while(temp--)
            {
                arr[i] = arr[i] ^ arr[n - i - 1];
                arr[n - i - 1] = arr[i] ^ arr[n - i - 1];
            }
            temp = k / n;
        }
        for(ll i = 0; i < temp2; i++)
        {
            arr[i] = arr[i] ^ arr[n - i - 1];
        }
        if(n % 2 != 0 && k > n / 2)
        {
            arr[n / 2] = 0;
        }
        for(ll i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}