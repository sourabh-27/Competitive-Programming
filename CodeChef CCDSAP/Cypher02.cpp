#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool isPrime(ll n)
{
    bool flag = true;
    if(n == 1)
    {
        return false;
    }
    for(int i = 2; i <= n/2; ++i)
    {
        if(n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
 
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
        ll arr[n + 1][m + 1];
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        ll p;
        cin >> p;
        ll count = 0; ll final = 0; ll temp2 = 0;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                if(isPrime(arr[i][j]))
                {
                    count++;
                    // cout << "i: " << i << " j: " << j << endl;
                    if(count == 2)
                    {
                        // cout << "My count is 2 : " << j << endl;
                        temp2 = j;
                    }
                    if(count == p)
                    {
                        final++;
                        count = 0;
                        // cout << "I am final : " << final << endl;
                        j = temp2 - 1;
                    }
                }
                else
                {
                    count = 0;
                }
            }
            count = 0;
            temp2 = 0;
        }
        cout << final << endl;
    }

    return 0;
}