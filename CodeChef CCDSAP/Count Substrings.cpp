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
        ll n;
        cin >> n;
        string str;
        cin >> str;
        ll count = 0;
        for(ll i = 0; i < n; i++)
        {
            if(str[i] == '1')
            {
                count++;
            }
        }
        // cout << "count: " << count << endl;
        cout << ((count * (count + 1)) / 2) << endl;
    }

    return 0;
}