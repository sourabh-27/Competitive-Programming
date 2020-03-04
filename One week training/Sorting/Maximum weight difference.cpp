#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        long long arr[n + 1];
        ll total = 0;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            total = total + arr[i];
        }
        sort(arr, arr + n);
        ll sum1 = 0; ll sum2 = 0; ll temp = 0;
        for(ll i = 0; i < n; i++){
            temp = temp + arr[i];
            if(i == k - 1){
                sum1 = temp; 
            }
            if(i == n - k - 1){
                sum2 = temp;
            }
        }
        cout << max(abs((total - sum1) - (sum1)), abs((total - sum2) - (sum2))) << endl;
    }

    return 0;
}