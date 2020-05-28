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
    while(t--){
        ll n;
        cin >> n;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        ll ans = 0, count = 0;
        for(ll i = n - 1; i >= 0; i--){
            if(arr[i] - count <= 0){
                continue;
            }
            else{
                ans = ans + arr[i] - count;
                count++;
            }
        }
        cout << ans % mod << endl;
    }

    return 0;
}