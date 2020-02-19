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
        ll maxi = INT_MIN; ll mini = INT_MAX;
        ll temp1, temp2;
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] > maxi)
            {
                maxi = arr[i];
                temp1 = i;
            }
            if(arr[i] < mini)
            {
                mini = arr[i];
                temp2 = i;
            }
        }
        if(temp2 > temp1)
        {
            cout << maxi << " " << mini << endl; 
        }
        else
        {
            cout << mini << " " << maxi << endl;
        }
    }

    return 0;
}