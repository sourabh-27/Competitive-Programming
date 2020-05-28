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
        ll n;
        cin >> n;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        if(n % 2 != 0){
            cout << arr[n / 2] << " ";
        }
        for(ll i = n / 2 - 1; i >= 0; i--){
            cout << arr[i] << " " << arr[n - i - 1] << " ";
        }
        cout << endl;
        // if(n % 2 == 0){
        //     cout << arr[n / 2] << " " << arr[n / 2 - 1];
        // }
        // else{
        //     cout << arr[n / 2];
        // }
        // cout << endl;
    }

    return 0;
}