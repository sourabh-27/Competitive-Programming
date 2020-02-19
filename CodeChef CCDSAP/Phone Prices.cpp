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
        ll n;
        cin >> n;
        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll mini = arr[0]; ll count = 1; ll index = 1;
        for(ll i = 1; i < n; i++)
        {
            index++;
            if(index > 5)
            {
                mini = min(arr[i- 1], min(arr[i - 2], min(arr[i - 3], min(arr[i - 4], arr[i - 5]))));
                // cout << "mini: " << mini << " i: " << i << endl;
            }
            if(arr[i] < mini)
            {
                count++; 
                // cout << "i : " << i << endl;
                mini = arr[i];
            }
        }
        cout << count << endl;
    }

    return 0;
}