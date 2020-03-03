#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll peakValue(long long * arr, ll low, ll high, ll key){
    ll n = high + 1;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        // cout << "mid: " << mid << endl;
        // cout << "arr[mid]: " << arr[mid] << " arr[mid - 1]: " << arr[mid - 1] << endl;
        if(arr[mid] > arr[mid + 1]){
            return mid;
        }
        else{
            if(arr[mid] > arr[n - 1])
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    } 
    return -1;
}

ll simpleBinarySearch(long long * arr, ll low, ll high, ll key){
    // cout << "low: " << low << " high : " << high << endl;
    while(low <= high)
    {
        ll mid = low + (high - low) / 2;
        // cout << "mid: " << mid << endl;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
 
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
    ll key;
    cin >> key;
    ll peak = peakValue(arr, 0, n - 1, key);
    cout << "Peak index: " << peak << endl;
    ll ans;
    if(key <= arr[n - 1]){
        ans = simpleBinarySearch(arr, peak + 1, n - 1, key);
    }
    else{
        ans = simpleBinarySearch(arr, 0, peak, key);
    }
    cout << "Index: " << ans << endl;

    return 0;
}