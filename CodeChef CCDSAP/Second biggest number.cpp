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
        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll i, j;
        for(i = n - 2; i >= 0; i--)
        {
            if(arr[i] < arr[i + 1])
            {
                break;
            }
        }
        cout << i << " i " << endl;
        if(i == -1)
        {
            cout << -1 << endl;
            continue;
        }

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] <= arr[i])
            {
                break;
            }
        }
        cout << j << " j " << endl;
        
        swap(arr[i], arr[j - 1]);
        sort(arr + i + 1, arr + n);
        for(i = 0; i < n; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }

    return 0;
}