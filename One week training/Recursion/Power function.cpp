#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

double myPow(double x, ll n){
    if(n == 0){
        return 1;
    }
    if(n > 0){
        return myPow(x, n - 1) * x;
    }
    else{
        return myPow(x, n + 1) * (1 / x);
    }
}
 
int main()
{
    fast;
    double x;
    cin >> x;
    ll n;
    cin >> n;
    double ans = myPow(x, n);
    cout << fixed;
    cout << setprecision(6);
    cout << ans << endl;

    return 0;
}