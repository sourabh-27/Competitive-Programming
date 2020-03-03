#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll rowBinarySearch(long long ** arr, ll mid, ll low, ll high, ll row, ll n){
    while(low <= high){
        ll mid2 = low + (high - low) / 2;
        if(mid2 == 0 && arr[row][mid2] <= mid){
            return mid2 + 1;
        }
        if(arr[row][mid2] <= mid && arr[row][mid2 + 1] > mid){
            return mid2 + 1;
        }
        if(arr[row][mid2] > mid){
            high = mid2 - 1;
        }
        else{
            low = mid2 + 1;
        }
    }
}

ll rowBinarySearch2(long long ** arr, ll mid, ll low, ll high, ll row, ll n){
    while(high - low > 1){
        ll mid2 = low + (high - low) / 2;
        // cout <<  "mid2: " << mid2 << endl;
        if(arr[row][mid2] > mid){
            high = mid2;
        }
        else{
            low = mid2;
        }
    }
    // cout << "low: " << low << endl;
    return low + 1;
}

ll count2(long long ** arr, ll mid, ll n){
    ll count = 0;
    for(ll i = 0; i < n; i++){
        // for(ll j = 0; j < n; j++){
        //     if(arr[i][j] <= mid){
        //         count++;
        //     }
        // }
        count = count + rowBinarySearch2(arr, mid, 0, n, i, n);
    }
    // cout << "count : " << count << endl;
    return count;
}

ll binarySearch(long long ** arr, ll low, ll high, ll k, ll n){
    while(high - low > 1){
        ll mid = low + (high - low) / 2;
        // cout << "mid: " << mid << endl;
        if(count2(arr, mid, n) < k){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long ** arr = new long long *[n + 1];
    for(ll i = 0; i <= n; i++){
        arr[i] = new long long[n + 1];
    }
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    ll k;
    cin >> k;

    ll maxi = INT_MIN;
    ll mini = INT_MAX;
    for(ll i = 0; i < n; i++)
    {
        mini = min(mini, arr[i][0]);
        maxi = max(maxi, arr[i][n - 1]);
    }
    // cout << "mini: " << mini << " maxi : " << maxi << endl;

    ll ans = binarySearch(arr, mini - 1, maxi, k, n);
    cout << "kth index: " << ans << endl;

    return 0;
}