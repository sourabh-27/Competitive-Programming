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
        ll n, m;
        cin >> n >> m;
        ll arr[n + 1][m + 1];
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
            }
        }
        
        ll count = 0;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                ll minDist = min(i - 1, min(n - i, min(m - j, j - 1)));
                ll left = j, right = j; ll up = i, down = i;
                while(minDist--)
                {
                    left--; up--;
                    right++; down++;
                    // for palindrome
                    if(arr[up][j] != arr[down][j] || arr[i][left] != arr[i][right])
                    {
                        break;
                    }
                    // if(minDist != 1)
                    // {
                    //     if(arr[up][j] != arr[i][left] || arr[down][j] != arr[i][right])
                    //     {
                    //         break;
                    //     }
                    // }
                    else
                    {
                        count++;
                    }
                }
            }
        }
        count += n * m;
        cout << count << endl;
    }

    return 0;
}