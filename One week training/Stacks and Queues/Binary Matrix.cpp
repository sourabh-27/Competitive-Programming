#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
//binary matrix find max area of rectangle including base
//next level->base not necessary
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

    for(ll i = n - 1; i >= 0; i--){
        for(ll j = 0; j < n; j++){

        }
    }

    return 0;
}