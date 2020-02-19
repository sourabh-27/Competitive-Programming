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
        ll temp = 1;
        ll final = 0;
        while(temp != k)
        {
            ll ans = k / temp;
            cout << "k: " << k << " temp : " << temp << endl;
            if(ans <= n & temp <= n)
            {
                final += ans;
            }
            temp++;
        }
        if(n >= k)
        {
            final += 2;
        }
        else
        {
            final += 1;
        }
        cout << final << endl;
    }

    return 0;
}