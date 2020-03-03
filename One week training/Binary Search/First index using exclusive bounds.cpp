#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

//low exclusive high inclusive

ll firstOccur(long long * arr, ll low, ll high, ll key){
    ll n = high + 1;
    while(high - low > 1){
        ll mid = low + (high - low) / 2;
        if(arr[mid] < key){
            low = mid;
        }
        else if(arr[mid] >= key){
            high = mid;
        }
    }
    if(arr[high] == key){
        return high;
    }
    return -1;
}

ll lastOccur(long long * arr, ll low, ll high, ll key){
    ll n = high;
    while(high - low > 1){
        ll mid = low + (high - low) / 2;
        if(arr[mid] > key){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    if(arr[low] == key){
        return low;
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
    ll ans = firstOccur(arr, -1, n - 1, key);
    ll ans2 = lastOccur(arr, 0, n, key);
    cout << "First Index: " << ans << endl;
    cout << "Last Index: " << ans2 << endl;

    return 0;
}