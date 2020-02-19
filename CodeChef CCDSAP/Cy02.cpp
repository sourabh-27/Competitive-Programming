#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    char arr[n][m];
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    ll final = 0; ll flag = 0; ll count = 0;
    ll temp;
    vector<ll> v;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            if(arr[i][j] == 'B')
            {
                count++;
                temp = j;
                if(count >= 2)
                break;
            }
        }
        if(count == 1)
        {
            // cout << "temp : " << temp << endl;
            v.push_back(temp);
            count = 0;
        }
        count = 0;
    }

    count = 0;
    // cout << v.size() << endl;
    for(ll i = 0; i < v.size(); i++)
    {
        for(ll j = 0; j < n; j++)
        {
            // cout << "arr[j][v[i]] : " << arr[j][v[i]] << endl; 
            if(arr[j][v[i]] == 'B')
            {
                count++;
                if(count >= 2)
                {
                    break;
                }
            }
        }
        if(count == 1)
        {
            final++;
            count = 0;
        }
        count = 0;
    }
    cout << final << endl;

    return 0;
}