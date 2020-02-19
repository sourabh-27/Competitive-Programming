#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct triple{
    bool inc, dec;
};
 
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
        long long arr[n + 1]; long long copy[n + 1]; long long copy2[n + 1];
        struct triple arr2[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            copy[i] = arr[i];
            copy2[i] = arr[i];
        }

        copy[0] = 0; int flag = 0;
        arr2[0].inc = true;
        for(ll i = 1; i < n; i++)
        {
            if(arr[i] >= i && arr[i] > copy[i - 1] && flag == 0)
            {
                copy[i] = i;
                arr2[i].inc = true;
            }
            else
            {
                flag = 1;
                arr2[i].inc = false;
            }
        }
        copy2[n - 1] = 0; int flag2 = 0;
        arr2[n - 1].dec = true;
        for(ll i = n - 2; i >= 0; i--)
        {
            
            if(arr[i] >= n - (i + 1) && arr[i] > copy2[i + 1] && flag2 == 0)
            {
                copy2[i] = n - (i + 1);
                arr2[i].dec = true;
            }
            else
            {
                flag2 = 1;
                arr2[i].dec = false;
            }
        }
        // for(ll i = 0; i < n; i++)
        // {
        //     cout << arr2[i].inc << " ";
        // }
        // cout << endl;
        // for(ll i = 0; i < n; i++)
        // {
        //     cout << arr2[i].dec << " ";
        // }
        // cout << endl;
        int final = 0;
        for(ll i = 0; i < n; i++)
        {
            if(arr2[i].inc == 1 && arr2[i].dec == 1)
            {
                final = 1;
            }
        }
        if(final == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}