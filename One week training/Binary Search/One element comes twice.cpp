#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll findFirstNotPos(long long * arr, ll first, ll last){
    ll n = last + 1;
    while(first <= last){
        ll mid = first + (last - first) / 2;
        if(mid == 0)
        {
            if(arr[mid] == arr[mid + 1]){
                return mid;
            }
        }
        if(mid == n - 1){
            if(arr[mid] == arr[mid - 1]){
                return mid;
            }
        }
        if(arr[mid] == arr[mid + 1] || arr[mid] == arr[mid - 1]){
            return mid;
        }
        else if(arr[mid] = mid + 1){
            first = mid + 1;
        }
        else{
            last = mid - 1;
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
    ll ans = findFirstNotPos(arr, 0, n - 1);
    cout << "Index where element comes twice: " << ans << endl;

    return 0;
}