#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void binarySearch(ll start, ll end, ll k, long long * arr){
    ll n = end + 1;
    while(start <= end){
        ll mid = start + (end - start) / 2;
        if(mid == 0){
            cout << arr[mid] << endl; 
            return;
        }
        else if(mid == n - 1){
            cout << arr[mid] << endl;
            return;
        }
        else if(arr[mid + 1] >= k && arr[mid - 1] <= k){
            cout << arr[mid] << endl;
            return;
        }
        else if(arr[mid] > k){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
}

void binarySearch(ll start, ll end, ll k, long long * arr){
    ll n = end + 1;
    while(end - start > 1){
        ll mid = start + (end - start) / 2;
        if(arr[mid] >= k){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    cout << arr[end] << endl;
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
    ll k;
    cin >> k;
    binarySearch(-1, n - 1, k, arr);

    return 0;
}