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
        set<char> myset;
        set<char>::iterator itr;
        string s;
        cin >> s;
        ll len = s.length();
        if(len == 1)
        {
            myset.insert(s[0]);
        }
        else if(len >= 2)
        {
            if(s[0] != s[1])
            {
                myset.insert(s[0]);
            }
            if(s[len - 1] != s[len - 2])
            {
                myset.insert(s[len - 1]);
            }
            for(ll i = 1; i < len - 1; i++)
            {
                if(s[i] != s[i + 1] && s[i] != s[i - 1])
                {
                    myset.insert(s[i]);
                }
                else if(s[i] == s[i + 1] && s[i] == s[i - 1])
                {
                    myset.insert(s[i]);
                }
            }
        }
        for(itr = myset.begin(); itr != myset.end(); itr++)
        {
            cout << *itr;
        }
        cout << endl;
    }

    return 0;
}