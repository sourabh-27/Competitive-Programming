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
        ll n, k;
        cin >> n >> k;
        ll arr[n + 1];
        ll total_sum = 0;
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            total_sum += arr[i];
        }
        sort(arr, arr + n);
        ll son = 0;
        for(ll i = 0; i < k; i++)
        {
            son += arr[i];
        }
        // cout << "total_sum: " << total_sum << endl;
        // cout << "son : " << son << endl;
        ll father = total_sum - son;
        cout << abs(father - son) << endl;
    }

    return 0;
}