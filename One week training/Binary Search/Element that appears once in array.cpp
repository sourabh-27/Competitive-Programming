#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll binarySearch(long long * arr, ll low, ll high){
    ll n = high + 1;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(mid == 0 && arr[mid] != arr[mid + 1]){
            return arr[mid];
        }
        if(mid == n - 1 && arr[mid - 1] != arr[mid]){
            return arr[mid];
        }
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]){
            return arr[mid];
        }
        if(mid % 2 == 0){
            if(arr[mid] == arr[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        else{
            if(arr[mid] == arr[mid - 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
}
 
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

        ll ans = binarySearch(arr, 0, n - 1);
        cout << ans << endl;
    }

    return 0;
}