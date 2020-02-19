#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        string p;
        cin >> p;
        string s;
        cin >> s;
        int len = s.length();
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(p[i] == s[j])
                {
                    cout << p[i];
                }
            }
        }
        if(t != 0)
        {
            cout << endl;
        }
    }

    return 0;
}