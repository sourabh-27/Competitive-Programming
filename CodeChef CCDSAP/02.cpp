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
        string str;
        cin >> str;
        ll n = str.length();
        ll arr[n + 2] = {0};
        for(ll i = 0; i < n; i++)
        {
            arr[i + 1] = arr[i];
            if(str[i] == '1')
            {
                arr[i + 1]++;
            }
        }

        ll maxi = 0;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j <= n; j++)
            {
                maxi = max(maxi, arr[j] - arr[i] + i - arr[i] + n - j - arr[n] + arr[j]);
                maxi = max(maxi, arr[i] + arr[n] - arr[j] + j - i - arr[j] + arr[i]);
            }
        }

        cout << n - maxi << endl;
    }

    return 0;
}