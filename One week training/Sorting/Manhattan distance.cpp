#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long x[n + 1]; long long y[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    sort(x, x + n);
    sort(y, y + n);

    ll ans = 0;
    long long prefixSum, prefixSum2;
    for(ll i = 0; i < n; i++){
        prefixSum += x[i];
        prefixSum2 += y[i];
    }

    for(ll i = 0; i < n; i++){
        prefixSum -= x[i];
        prefixSum2 -= y[i];
        cout << prefixSum << " ";
        ans += prefixSum - x[i] * (n - i - 1) + prefixSum2 - y[i] * (n - i - 1);
        cout << ans << " ";
    }
    cout << endl;
    cout << "ans: " << ans << endl;

    return 0;
}