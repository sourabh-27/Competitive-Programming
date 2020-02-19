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
        ll n, k;
        cin >> n >> k;
        ll temp;
        ll count = 0;
        for(ll i = 0; i < n; i++)
        {
            cin >> temp;
            temp = temp + k;
            if(temp % 7 == 0)
            {
                count++;
            }
        }
        cout << count << endl;

    }

    return 0;
}