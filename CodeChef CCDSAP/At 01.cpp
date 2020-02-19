#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    ll diff = abs(b - a);
    ll ans = 0;
    if(diff % 2 == 0)
    {
        ans = diff / 2;
    }
    else
    {
        ll left = a - 1;
        ll right = n - b;
        ans = min(left, right) + (b - a + 1) / 2;
    }
    cout << ans << endl;

    return 0;
}