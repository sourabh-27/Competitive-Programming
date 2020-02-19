#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
long long hash2[10000000];
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll d;
        cin >> d;
        long long arr[n + 1];
        memset(hash2, 0, sizeof(hash2));

        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            hash2[arr[i]]++;
        }

        ll count = 0; 
        ll count2= 0;
        // set<pair<ll, ll>> set;
        for(ll i = 0; i < n; i++)
        {
            ll toFind = d - arr[i];
            // cout << "toFind: " << toFind << endl;
            if(toFind > 0)
            {
                if(hash2[toFind] > 0)
                {
                    if(arr[i] == toFind)
                    {
                        count2 = (((hash2[toFind] - 1) * hash2[toFind]) / 2);
                    }
                    else
                    {
                        count = count + (hash2[toFind]);
                    }
                    
                }
            }
            // cout << "count: " << count << endl;
        }
        // cout << "count2: " << count2 / count3 << endl;
        cout << (abs((count)) + abs(count2)) << endl;

        // ll count = 0;
        // for(auto it = set.begin(); it != set.end(); ++it)
        // {
        //     if(it->first != it->second)
        //     {
        //         count = count + 2;
        //     }
        //     else
        //     {
        //         count = count + 1;
        //     }    
        // }

        // cout << set.size() << endl;

    }

    return 0;
}