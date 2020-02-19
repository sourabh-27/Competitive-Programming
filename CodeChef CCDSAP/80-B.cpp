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
        string a, b;
        cin >> a >> b;
        string temp = a + b;
        ll x, y;
        x = stoll(a); y = stoll(b);
        cout << "temp: " << temp << endl;
        for(ll i = 1; i <= x; i++)
        {
            for(ll j = 1; j <= y; j++)
            {
                if(i + j + i * j )
            }
        }
    }

    return 0;
}