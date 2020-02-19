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
        string s;
        cin >> s;
        int len  = s.length();
        ll count = 0;
        for(int i = 0 ; i < len ; i++ )
        {
            if (s[i] == '1')
            {
                count++;
            }
        }
        // if(len == 1)
        // {
        //     if(s[0] == '1')
        //     {
        //         cout << "LOSE";
        //     }
        //     else
        //     {
        //         cout << "WIN";
        //     }
        // }
        if(count % 2 == 0)
        {
            cout << "LOSE" << endl;
        }
        else
        {
            cout << "WIN" << endl;
        }
    }

    return 0;
}