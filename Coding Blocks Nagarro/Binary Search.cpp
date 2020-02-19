#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll m;
    cin >> m;

    sort(arr, arr + n);

    ll left = 0; ll right = n - 1;

    ll flag = 0;
    while(left <= right)
    {
        ll mid = left + (right - left) / 2;
        if(arr[mid] == m)
        {
            flag = 1;
            cout << mid << endl;
            break;
        }
        if(arr[mid] > m)
        {
            right = mid - 1;
        }
        else
        {
            left = mid;
        }
    }
    if(flag == 0)
    {
        cout << -1 << endl;
    }
    

    return 0;
}