#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    ll arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll dp[4 * n] = {0}; ll dp2[4 * n] = {0};
    ll count = 0; int flag = 0;
    for(ll i = 0; i < n - 1; i++)
    {
        // cout << "arr[i] : " << arr[i] << " arr[i + 1] : " << arr[i + 1]  << endl;
        if(arr[i] < arr[i + 1] && flag == 0)
        {
            flag = 1;
            if(i == n - 2)
            {
                count++;
                dp[n - 1] = count;
            }
        }
        else if(arr[i] > arr[i + 1] && flag == 1)
        {
            flag = 0;
            count++;
            dp[i] = count;
        }   
        // cout << "flag : " << flag << endl;
    }
    ll temp = 1;
    for(ll i = 0; i < n; i++)
    {
        if(dp[i] == temp)
        {
            temp++;
            continue;
        }
        dp[i] = temp;
    }
    for(ll i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl; 
    // cout << count << endl;
    ll count2 = 0; flag = 0;
    for(ll i = n - 1; i > 0; i--)
    {
        // cout << "arr[i] : " << arr[i] << " arr[i + 1] : " << arr[i + 1]  << endl;
        if(arr[i] < arr[i + 1] && flag == 0)
        {
            flag = 1;
            if(i == n - 2)
            {
                count2++;
                dp2[n - 1] = count2;
            }
        }
        else if(arr[i] > arr[i + 1] && flag == 1)
        {
            flag = 0;
            count2++;
            dp2[i] = count2;
        }   
        // cout << "flag : " << flag << endl;
    }

    temp = 1;
    for(ll i = 0; i < n; i++)
    {
        if(dp2[i] == count2)
        {
            count2--;
            dp2[i] = temp;
            temp++;
            continue;
        }
        dp2[i] = temp;
    }

    for(ll i = 0; i < n; i++)
    {
        cout << dp2[i] << " ";
    }

return 0;
}