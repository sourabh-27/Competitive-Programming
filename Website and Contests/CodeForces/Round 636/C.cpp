#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
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
        ll flag; 
        if(arr[0] > 0){
            flag = 1;
        }
        else{
            flag = 0;
        }
        ll maxi = arr[0]; ll sum = 0;
        for(ll i = 1; i < n; i++){
            if(flag == 0){
                if(arr[i] < 0){
                    maxi = max(arr[i], maxi);
                }
                else{
                    sum = sum + maxi;
                    maxi = arr[i];
                    flag = 1;
                }
            }
            if(flag == 1){
                if(arr[i] > 0){
                    maxi = max(arr[i], maxi);
                }
                else{
                    sum = sum + maxi;
                    maxi = arr[i];
                    flag = 0;
                }
            }
        }
        sum += maxi;
        cout << sum << endl;
        
    }


    return 0;
}