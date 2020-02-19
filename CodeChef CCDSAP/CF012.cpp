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
        string s;
        cin >> s;
        ll len = s.length();
        ll count = 1;
        set<char> myset;
        set<char>::iterator itr;
        for(ll i = 0; i < len - 1; i++)
        {
            for(ll j = i + 1; j < len; j++)
            {
                if(s[i] == s[j])
                {
                    count++;
                    // cout << "I am in : " << i << " " << j << " value is: " << s[j] << " count "  << count << endl;
                }
                else
                {
                    break;
                }
            }
            if(count % 2 != 0)
            {
                // cout << " i is: " << i << endl;
                myset.insert(s[i]);
                i = i + count - 1;
            }
            else
            {
                i = i + count - 1;
            }
            count = 1;
        }
        if(len >= 2)
        {
            if(s[len - 1] != s[len - 2])
            {
                myset.insert(s[len - 1]);
            }
        }
        if(len == 1)
        {
            myset.insert(s[0]);
        }

        for(itr = myset.begin(); itr != myset.end(); itr++)
        {
            cout << *itr;
        }
        cout << endl;
    }

    return 0;
}