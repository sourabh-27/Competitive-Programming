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
        ll n; cin >> n;
        long long arr[n + 1];
        ll maxi = INT_MIN;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }
        int flag = 0;
        for(ll i = 0; i < n; i++){
            if((maxi - arr[i]) % 2 == 1){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }


    return 0;
}