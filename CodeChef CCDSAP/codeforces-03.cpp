#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    string s, s1;
    cin >> s;
    s1 = s;
    for(ll i = k; i < n; i++)
    {
        s[i] = s[i - k];
    }
    
    if(s >= s1)
    {
        cout << s.length() << endl;
        cout << s << endl;
    }
    else
    {
        for(ll i = k - 1; i >= 0; i--)
        {
            if(s[i] != '9')
            {
                for(ll j = i; j < n; j += k)
                {
                    s[j] += 1;
                }
                break;
            }
            else
            {
                for(ll j = i; j < n; j += k)
                {
                    s[j] = '0';
                }
            }
        }
        cout << s.length() << endl;
        cout << s << endl;
    }
    
    

    return 0;
}