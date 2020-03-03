#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll binarySearch(long long * arr, ll low, ll high, ll key){
    while(low <= high){
        ll mid = low + (high - low) / 2;
        cout << "mid: " << mid << endl;
        cout << "arr[mid]: " << arr[mid] << " arr[mid - 1]: " << arr[mid - 1] << endl;
        if(mid == 0 && arr[mid] == key){
            return mid;
        }
        if(arr[mid] == key && arr[mid - 1] != key)
        {
            cout << "index: " << mid << endl;
            return mid;
        }
        else if(arr[mid] >= key) {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    } 
    return -1;
}

ll binarySearch2(long long * arr, ll low, ll high, ll key){
    ll n = high;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        // cout << "mid: " << mid << endl;
        // cout << "arr[mid]: " << arr[mid] << " arr[mid - 1]: " << arr[mid - 1] << endl;
        if(mid == n && arr[mid] == key){
            return mid;
        }
        if(arr[mid] == key && arr[mid + 1] != key)
        {
            // cout << "index: " << mid << endl;
            return mid;
        }
        else if(arr[mid] <= key) {
            low = mid + 1;
        }
        else{
            high = mid - 1;
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
    ll key; cin >> key;
    ll low = 0; ll high = n - 1;
    ll ans = binarySearch(arr, low, high, key);
    ll ans2 = binarySearch2(arr, low, high, key);
    cout << "First index: " << ans << endl;
    cout << "Last index: " << ans2 << endl;
    return 0;
}