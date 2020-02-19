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
        ll n, m;
        cin >> n >> m;
        if(m < n - 1 || m  > ((n * (n - 1)) / 2) + n)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}