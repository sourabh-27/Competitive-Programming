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
        ll n;
        cin >> n;
        ll height = 0;
        for(ll i = 0; i <= n; i++)
        {
            if(i % 2 == 0)
            {
                height += 1;
            }
            else
            {
                height = height * 2;
            }
        }
        cout << height << endl;
    }

    return 0;
}