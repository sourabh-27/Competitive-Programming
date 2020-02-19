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
        ll count[n + 1] = {0};
        ll a, b;
        for(ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            a = x; b = y;
            count[x] += 1;
            count[y] += 1;
        }
        ll oddCount = 0, evenCount = 0;
        ll oddNode;
        for(ll i = 1; i <= n; i++)
        {
            if(count[i] % 2 == 0)
            {
                evenCount++;
            }
            else
            {
                oddCount++;
                oddNode = i;
            }
        }

        // cout << "even degrees: " << evenCount << " odd degrees: " << oddCount << endl;

        if(m % 2 == 0)
        {
            cout << 1 << endl;
            for(ll i = 1; i <= n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
        else if(m % 2 != 0 && oddCount == 0)
        {
            ll temp1, temp2;
            // cout << "temp1 : " << temp1 << " temp2 : " << temp2 << endl;
            // cout << "arr[2] : " << arr[1][2] << endl;
            cout << 3 << endl; ll k = 1;
            for(ll i = 1; i <= n; i++)
            {
                if(i == a || i == b)
                {
                    k = k + 1;
                    cout << k << " ";
                }
                else
                {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }
        else if(m % 2 != 0 && oddCount >= 1)
        {
            cout << 2 << endl;
            for(ll i = 1; i <= n; i++)
            {
                if(i == oddNode)
                {
                    cout << 2 << " ";
                }
                else
                {
                    cout << 1 << " ";
                }      
            }
            cout << endl;
        }
    }

    return 0;
}