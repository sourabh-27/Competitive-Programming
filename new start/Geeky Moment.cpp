#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll x, y; ll arr[n], arr2[n];
        cin >> x >> y;
        arr[0] = x; arr2[0] = y;
        ll sum = 0;
        for(ll i = 1; i < n; i++)
        {
            cin >> x >> y;
            arr[i] = x; arr2[i] = y;
            if(x == arr[i - 1])
            {
                sum += y - arr2[i - 1];
            }
            else if(y == arr2[i - 1])
            {
                sum += x - arr[i - 1];
            }
            else if(x - arr[i - 1] > y - arr2[i -1])
            {
                sum += x - (y - arr2[i - 1] + arr[i - 1]) + y - arr2[i - 1];
            }
            else if(x - arr[i - 1]  < y - arr2[i - 1])
            {
                sum += y - (x - arr[i - 1] + arr2[i - 1]) + x - arr[i - 1];
            }
            else if(x - arr[i - 1] == y - arr2[i - 1])
            {
                sum += y - arr2[i - 1];
            }
            
            // cout << "i: " << i << " sum : " << sum << endl;
        }
        cout << sum << endl;
    }

    return 0;
}