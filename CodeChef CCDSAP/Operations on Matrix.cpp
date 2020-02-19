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
        ll n, m, q;
        cin >> n >> m >> q;
        // cout << "q : " << q << endl;
        long long int arr[m + 1][n + 1];
        for(ll i = 1; i <= m; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                arr[i][j] = 0;
            }
        }
        while(q--)
        {
            // cout << "q: " << q << endl;
            ll x, y;
            cin >> x >> y;
            if(x <= m && y <= n)
            {
                for(ll i = 1; i <= n; i++)
                {
                    arr[x][i] += 1;
                }
                for(ll i = 1; i <= m; i++)
                {
                    arr[i][y] += 1;
                }
            }
            // for(ll i = 1; i <= m; i++)
            // {
            //     for(ll j = 1; j <= n; j++)
            //     {
            //         cout << arr[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
        ll count = 0;
        for(ll i = 1; i <= m; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                if(arr[i][j] % 2 != 0)
                {
                    count++;
                }
                // cout << arr[i][j];
            }
        }
        cout << count << endl;
    }

    return 0;
}