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
    long long arr2[m + 1];
    for(ll i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    ll last1 = n; ll last2 = m;
    long long ans[max(n, m)  + 1]; ll carry = 0;
    while(last1 != 0 && last2 != 0)
    {
        last1--; last2--; 
        // cout << "last1: " << last1 << " last2: " << last2 << endl;
        ll k = arr[last1] + arr2[last2] + carry;
        // cout << "k: " << k << endl;
        if(k > 9)
        {
            carry = k / 10;
            if(last1 == 0 && last2 == 0)
            {
                ans[0] = k;
                break;
            }
            ans[max(last1, last2)] = k % 10;
        }
        else
        {
            carry = 0;
            ans[max(last1, last2)] = k;
        } 
    }
    while(last1 != 0)
    {
        last1--;
        if(last1 == 0)
        {
            ans[last1] = arr[last1] + carry;
            break;
        }
        ans[last1] = arr[last1];
    }
    while(last2 != 0)
    {
        last2--;
        if(last2 == 0)
        {
            ans[last2] = arr2[last2] + carry;
            break;
        }
        ans[last2] = arr2[last2];
    }

    for(ll i = 0; i < max(n, m); i++)
    {
        cout << ans[i] << ", ";
    }
    cout << "END" << endl;

    return 0;
}