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
        ll previous = -6; ll curr = 0; ll flag = 0;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == 1){
                curr = i + 1;
                if(curr - previous < 6){
                    flag = 1;
                }
                previous = i + 1;
            }
        }
        if(flag == 1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }

    return 0;
}