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
        ll p;
        cin >> p;
        if(p <= 2048)
        {
            ll count = 0;
            while(p)
            {
                count = count + (p & 1);
                p = p >> 1;
            }
            cout << count << endl;
        }
        else
        {
            ll count = 0;
            count = count + (p / 2048);
            p = p % 2048;
            while(p)
            {
                count = count + (p & 1);
                p = p >> 1;
            }
            cout << count << endl;
        }
        
    }

    return 0;
}