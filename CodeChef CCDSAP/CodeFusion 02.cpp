#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll x;
        cin >> x;
        ll y = 180 - x - x;
        cout << 360 / y << endl;
    }

    return 0;
}