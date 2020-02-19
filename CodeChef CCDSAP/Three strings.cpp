#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        ll n = a.length();
        ll flag = 0; ll count = 0;
        for(ll i = 0; i < n; i++)
        {
            if(a[i] != c[i] && b[i] != c[i])
            {
                flag = 1;
                break;
            }
        }
        // cout << a << " " << b << endl;
        if(flag == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
        
    }

    return 0;
}