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
        vector<ll> vec;
        bool up = false;
        if(s[0] >= 'A' && s[0] <= 'Z')
        {
            up = true;
            for(ll i = 0; i < len; i++)
            {
                vec.push_back(s[i]- 'A');
            }
        }
        else
        {
            for(ll i = 0; i < len; i++)
            {
                vec.push_back(s[i] - 'a');
            }
        }

        for(ll i = 0 ; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;

        vector<ll> vec2[400];
        for(ll i = 0; i < len - 1; i++)
        {
            if(vec2[vec[i]].empty())
            {
                vec2[vec[i]].push_back(vec[i + 1]);
            }
            else
            {
                if(vec2[vec[i]][0] == vec[i + 1] || vec2[vec[i]][1] == vec[i + 1])
                {
                    ll k;
                }
                else
                {
                    vec2[vec[i]].push_back(vec[i + 1]);
                }  
            } 
            if(vec2[vec[i + 1]].empty())
            {
                vec2[vec[i + 1]].push_back(vec[i]);
            }
            else
            {
                if(vec2[vec[i + 1]][0] == vec[i] || vec2[vec[i + 1]][1] == vec[i])
                {
                    ll k;
                }
                else
                {
                    vec2[vec[i + 1]].push_back(vec[i]);
                }  
            } 
        }

        for(ll i = 0; i < 26; i++)
        {
            for(ll j = 0; j < vec2[i].size(); j++)
            {
                cout << vec2[i][j] << " ";
            }
            cout << endl;
        }

        ll flag = 0; ll count = 0;
        for(ll i = 0; i < 26; i++)
        {
            if(vec2[i].size() > 2)
            {
                flag = 1; 
                break;
            }
            else if(vec2[i].size() >= 2)
            {
                count++;
            }
        }
        // cout << "count: " << count << endl;
        if(flag == 1 || count >= 26)
        {
            cout << "NO" << endl;
        }

    }

    return 0;
}