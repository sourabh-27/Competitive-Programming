#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll clockwise(long long * arr, ll curr, ll n, ll k){
    ll ans = 0;
    for(ll i = curr; i < n - 1; i++){
        ans = ans + abs(arr[i] - arr[i + 1]);
        cout << "curr: " << i << " ans: " << ans << endl;
    }
    for(ll i = 0; i < curr; i++){
        ans = ans + abs(arr[i] - arr[i + 1]);
    }
    return ans;
}

ll antiClockwise(long long * arr, ll curr, ll n, ll k){
    ll ans = 0;
    for(ll i = curr; i >= 1; i--){
        // cout << "curr: " << curr << endl;
        ans = ans + abs(arr[i] - arr[i - 1]);
    }
    for(ll i = n - 1; i > curr; i--){
        ans = ans + abs(arr[i] - arr[i - 1]);
    }
    return ans;
}
 
int main()
{
    fast;
    ll k, n;
    cin >> k >> n;
    long long arr[n + 1];
    ll mini = INT_MAX;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(ll i = 0; i < n; i++){
        // cin >> arr[i];
        ll ans1 = clockwise(arr, i, n, k);
        cout << "clockwise: " << ans1 << " ";
        ll ans2 = antiClockwise(arr, i, n, k);
        cout << "anticlockwise: " << ans2 << endl;
        mini = min(mini, ans1);
        mini = min(mini, ans2);
    }
    cout << mini << endl;

    return 0;
}