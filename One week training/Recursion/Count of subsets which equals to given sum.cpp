#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void findAns(long long * arr, ll index, ll n, ll target, ll &ans, ll sum){
    // for(ll i = 0; i < count; i++){
    //     sum += temp[i];
    // }
    if(sum == target){
        ans++;
    }
    if(index == n){
        return;
    }
    for(ll j = index; j < n; j++){
        sum += arr[j];
        // cout << "sum : " << sum << endl;
        findAns(arr, j + 1, n, target, ans, sum);
        sum -= arr[j];
    }
}

ll findAns2(long long *arr, ll index, ll n, ll target){
    if(index > n){
        return 0;
    }
    // cout << "target: " << target << endl;
    if(target == 0){
        return 1;
    }
    if(index == n && target == 0){
        return 1;
    }
    return findAns2(arr, index + 1, n, target - arr[index]) + findAns2(arr, index + 1, n, target);
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
    long long temp[n + 1];
    ll ans = findAns2(arr, 0, n, target);
    cout << "No. of subsets: " << ans << endl;

    return 0;
}