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
        for(ll i = 0; i < 2 * n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for(ll i = 0; i < 2 * n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << abs(arr[(2 * n) / 2] - arr[(2 * n) / 2 - 1]) << endl;
    }

    return 0;
}