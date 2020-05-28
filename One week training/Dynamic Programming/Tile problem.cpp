#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll setTheTiles(ll n, long long * dp){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    ll ans1 = setTheTiles(n - 1, dp);
    ll ans2 = setTheTiles(n - 2, dp);
    return ans1 + ans2;
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long * dp = new long long[n + 1];
    ll ans = setTheTiles(n, dp);
    cout << "The total no. of choices are: " << ans << endl;
    

    return 0;
}