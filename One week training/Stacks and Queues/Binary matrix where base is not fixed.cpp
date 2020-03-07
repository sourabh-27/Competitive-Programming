#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll m, n;
    cin >> m >> n;
    long long arr[m + 1][n + 1];
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    // long long height[m + 1][n + 1];
    // for(ll i = 0; i < m; i++){
    //     for(ll j = 0; j < n; j++){
    //         height[i][j] = 0;
    //     }
    // }

    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < n; j++){
            if(arr[i][j] == 1 && i == 0){
                arr[i][j] = 1;
            }
            else if(arr[i][j] == 1){
                arr[i][j] = 1 + arr[i - 1][j];
            }
        }
    }

    for(ll i = 0; i < m; i++){
        for(ll j = 0;j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}