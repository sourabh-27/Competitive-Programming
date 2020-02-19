#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll maxSubArraySum(long long * a, int size) 
{ 
    ll max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (ll i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
}
 
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
        long long arr[n + 1];
        ll total = 0;
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }

        ll maxi = max(maxSubArraySum(arr + 1, n - 1), maxSubArraySum(arr, n - 1));

        if(total > maxi)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}