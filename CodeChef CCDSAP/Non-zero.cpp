#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n; 
        long long arr[n + 1];
        ll sum = 0; ll totalSum = 0;
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] == 0)
            {
                arr[i] += 1;
                sum = sum + 1;
                totalSum += arr[i];
            }
            else
            {
                totalSum += arr[i];
            }  
        }
        // cout << "totalSum: " << totalSum << endl;
        ll flag = 0;
        for(ll i = 0; i < n; i++)
        {
            if(arr[i] != -1)
            {
                flag = 1;
                break;
            }
        }
        if(totalSum != 0)
        {
            cout << sum << endl;
        }
        else
        {
            if(flag == 1)
            {
                cout << sum + 1 << endl;
            }
            else
            {
                cout << sum + 2 << endl;
            }
            
        }
        
    }

    return 0;
}