#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;


bool areEqual(int *arr1, long long * arr2, int n) 
{ 
    unordered_map<int, int> m; 
    for (int i = 0; i < n; i++) 
        m[arr1[i]]++; 

    for (int i = 0; i < n; i++) { 
        if (m.find(arr2[i]) == m.end()) 
            return false; 
        if (m[arr2[i]] == 0) 
            return false; 
  
        m[arr2[i]]--; 
    } 
    return true; 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll k; ll left; ll right;
        long long leftArr[n + 1], rightArr[n + 1];
        memset(leftArr, 0, sizeof(leftArr));
        memset(rightArr, 0, sizeof(rightArr));
        for(ll i = 1; i <= n; i++)
        {
            cin >> k;
            left = i - k;
            if(left <= 0)
            {
                left = 1;
            }
            right = i + k;
            if(right > n)
            {
                right = n;
            }
            leftArr[left]++;
            rightArr[right]++;
        }
        
        // for(ll i = 1; i <= n; i++)
        // {
        //     cout << leftArr[i] << " " << rightArr[i] << endl;
        // }

        int * dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = leftArr[1];
        for(ll i = 2; i <= n; i++)
        {
            dp[i] = leftArr[i] - rightArr[i - 1] + dp[i - 1];
        }
        long long health[n + 1];
        health[0] = 0;
        for(ll i = 1; i <= n; i++)
        {
            cin >> health[i];
        }
        bool ans = areEqual(dp, health, n + 1);
        if(ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }        
    }

    return 0;
}