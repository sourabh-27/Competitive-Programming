#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll binarySearch(long long * arr, ll low, ll high){
    ll n = high;
    while(high - low > 1){
        ll mid = low + (high - low) / 2;
        // cout << "mid: " << mid << endl;
        if(arr[mid] < arr[0] && arr[mid] < arr[mid - 1]){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return low;
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll ans = binarySearch(arr, 0, n);
    cout << "Index: " << ans << endl;

    return 0;
}