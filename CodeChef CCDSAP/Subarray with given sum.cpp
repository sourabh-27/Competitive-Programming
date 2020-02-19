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
        ll n, s;
        cin >> n >> s;
        ll arr[n]; ll sum = 0, i, j = 0;
        for(i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for(i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            if(sum == s)
            {
                break;
            }
            while(sum > s)
            {
                // cout << "sum: " << sum << endl;
                sum -= arr[j];
                j++;
            }
            if(sum == s)
            {
                break;
            }
        }
        if(i <= n - 1)
        {
            cout << j + 1 << " " << i + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        
    }

    return 0;
}