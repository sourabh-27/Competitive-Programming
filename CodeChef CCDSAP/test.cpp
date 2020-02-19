#include<bits/stdc++.h>
using namespace std; 
#define mod 107
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll factorial(ll n) 
{ 
    ll f = 1; 
    for (ll i = 1; i <= n; i++) 
    { 
        f *= i; 
    } 
    return f; 
} 

ll sumFactorial(long long *arr, ll n) 
{ 
    int s = 0,i; 
    for (i = 0; i < n; i++) 
    {
        s += factorial(arr[i]); 
    } 
    return s; 
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = sumFactorial(arr, n);
    cout << ans % mod << endl;
    return 0;
}