#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll bS(long long * arr, ll start, ll end){
    ll n = end + 1;
    while(start <= end){
        ll mid = (start + end)  / 2;
        if(mid == 0)
        {
            if(arr[0] > arr[1]){
                return 0;
            }
        }
        if(mid == n - 1){
            if(arr[n - 1] > arr[n - 2]){
                return n - 1;
            }
        }
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        else if(arr[mid] > arr[mid - 1]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
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

    ll ans = bS(arr, 0, n - 1);
    cout << "Maxima: " << ans << endl;

    return 0;
}