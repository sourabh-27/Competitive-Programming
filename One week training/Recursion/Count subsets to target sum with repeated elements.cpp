#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll findAns(long long * arr, ll index, ll n, ll target){
    if(index > n || target < 0){
        return 0;
    }
    // cout << "target: " << target << endl;
    if(target == 0){
        return 1;
    }
    ll ans1 = findAns(arr, index, n, target - arr[index]);
    ll ans2 = findAns(arr, index + 1, n, target);
    // ll ans3 = findAns(arr, index + 1, n, target - arr[index]);
    return ans1 + ans2;
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
    ll target;
    cin >> target;
    ll ans = findAns(arr, 0, n, target);
    cout << "No. of such subsets: " << ans << endl;
    return 0;
}