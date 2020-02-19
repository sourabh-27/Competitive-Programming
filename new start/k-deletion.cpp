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
    long long* arr = new long long[n];
    ll totalSum = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        totalSum += arr[i];
    }

    ll sum = 0; ll maxi = INT_MIN;
    for(ll i = 0; i < n - k + 1; i++)
    {
        for(ll j = i; j <i + k; j++)
        {
            sum += arr[j];
        }
        // cout << sum << "sum" << endl;   
        ll z = totalSum - sum;
        // cout << "z : " << z << endl;
        sum = 0;
        maxi = max(maxi, z);
    }

    // cout << totalSum << "UP" << endl;
    cout << maxi << endl;


    return 0;
}