#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll func(long long * arr, ll m, ll n)
{
    ll count = 0;
    for(ll i = 0; i < n; i++){
        if(arr[i] <= m){
            count++;
        }
    }
    return count;
}

ll binarySearch(long long * arr, ll low, ll high, ll k, ll n){
    while(high - low > 1){
        ll mid = low + (high - low) / 2;
        if(func(arr, mid, n) < k){
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
    long long arr[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll maxi = INT_MIN;
    ll mini = INT_MAX;
    for(ll i = 0; i < n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
        if(arr[i] < mini){
            mini = arr[i];
        }
    }

    ll k;
    cin >> k;
    
    ll ans = binarySearch(arr, mini - 1, maxi, k, n);
    cout << "kth element will be : " << ans << endl;

    return 0;
}