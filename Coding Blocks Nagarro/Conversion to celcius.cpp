#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll mini, maxi, step;
    cin >> mini >> maxi >> step;
    for(ll i = mini; i <= maxi; i = i + step)
    {
        ll c = ((i - 32) * 5) / 9;
        cout << i << " " << c << endl;
    }

    return 0;
}