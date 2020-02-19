#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll findTrailingZeros(ll n) 
{ 
	ll count = 0; 
	for (ll i = 5; n / i >= 1; i *= 5) 
    {
		count += n / i; 
    }

	return count; 
} 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll ans = findTrailingZeros(n);
    cout << ans / 2 << endl;

    return 0;
}