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
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        ll count = 0;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                ll temp1 = i - 0; ll temp2 = j - 0;
                ll tem3 = i - 0; ll tem4 = j - 0;
                ll temp3 = n - 1 - i; ll temp4 = n - 1 - j;
                ll mini = min(temp1, temp2);
                mini = min(mini, min(temp3, temp4));
                if(mini != 0)
                {
                    mini = 1;
                }
                while(mini--)
                {
                    // cout << "i: " << i << " j: " << j << " mini: " << mini << endl;
                    temp1++; tem3--; //for rows
                    // cout << "temp1: " << temp1 << " tem3: " << tem3 << endl;
                    temp2++; tem4--; //for cols
                    // cout << "temp2: " << temp2 << " tem4: " << tem4 << endl;
                    // arr[temp1][j] != arr[i][temp2] || arr[tem3][j] != arr[i][tem4]
                    if(arr[temp1][j] != arr[tem3][j] || arr[i][temp2] != arr[i][tem4])
                    {
                        break;
                    }
                    else
                    {
                        count = count + 1;
                    }
                }
            }
        }
        count += n * m;
        cout << count << endl;
    }

    return 0;
}