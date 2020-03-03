#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll func(long long * arr, ll x, ll n){
    for(ll i = 0; <)
}

//low inclusive and high exclusive

ll binarySearch(long long * arr, ll low, ll high, ll x, ll n){
    while(high - low > 1){
        ll mid = low + (high - low) / 2;
        if(func(arr, x, n, mid) > )
    }
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i =0 ; i < n; i++)
    {
        cin >> arr[i];
    }
    ll x;
    cin >> x;
    ll ans = binarySearch(arr, 0, n + 1, x, n);

    return 0;
}