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
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long ans[n + 1];
    ll maxi = arr[0];
    ans[0] = arr[0];
    cout << ans[0] << " ";
    for(ll i = 1; i < n; i++){
        ans[i] = maxi + arr[i];
        maxi = max(ans[i], maxi);
        cout << ans[i] << " ";
    }

    return 0;
}