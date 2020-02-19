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
    ll arr[n + 1];
    ll mini = INT_MAX; ll maxi = INT_MIN;
    ll sum = 0;
    int flag = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
        sum = sum + arr[i];
    }
    if(sum == k)
    {
        flag = 1;
    }
    else
    {
        ll temp = k - sum;
        if(temp > mini && temp < maxi)
        {
            for(ll i = 0; i < n; i++)
            {
                if(temp == arr[i])
                {
                    flag = 2;
                    break;
                }
            }
            if(flag != 2)
            {
                flag = 1;
            }
        }
    }

    if(flag == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}