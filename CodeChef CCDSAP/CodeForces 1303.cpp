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
        string s;
        cin >> s;
        ll len = s.length();
        vector<ll> vec; ll countZ = 0;
        ll first = 0; ll before = 0; ll after = 0;
        for(ll i = 0; i < len; i++)
        {
            if(s[i] == '1')
            {
                first = i;
                break;
            }
            else 
            {
                before++;
            }
        }
        for(ll i = len - 1; i >= 0; i--)
        {
            if(s[i] == '1')
            {
                break;
            }
            else
            {
                after++;
            } 
        }
        for(ll i = first; i < len; i++)
        {
            if(s[i] == '0')
            {
                countZ++;
            }
            else if(s[i] == '1' && countZ > 0)
            {
                vec.push_back(countZ);
                countZ = 0;
            } 
        }
        // for(ll i = 0; i < vec.size(); i++)
        // {
        //     cout << vec[i] << " ";
        // }
        // cout << endl;
        ll sum = 0;
        for(ll i = 0; i < vec.size(); i++)
        {
            sum += vec[i];
        }

        cout << sum << endl;
    }

    return 0;
}