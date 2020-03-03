#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

bool func(long long * arr, ll c, ll n, ll mid){
    // cout << "checking for distance: " << mid << endl;
    ll count = 1;
    ll lastPos = arr[0];
    for(ll i = 1; i < n; i++){
        if(arr[i] - lastPos >= mid){
            count++;
            lastPos = arr[i];
        }
        if(count == c){
            return true;
        }
    }
    // cout << "count: " << count << endl;
    return false;
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, c;
        cin >> n >> c;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        ll low = -1; ll high = arr[n - 1] - arr[0];
        // cout << "low: " << low << " high: " << high << endl;
        // cout << check(3, arr, n, 3);
        
        while(high - low > 1){
            ll mid = low + (high - low) / 2;
            // cout << "mid: " << mid << endl;
            if(func(arr, c, n, mid)){
                low = mid;
                // cout << "Yes" << endl;
            }
            else{
                high = mid;
            }
        }
        cout << low << endl;
    }

    return 0;
}