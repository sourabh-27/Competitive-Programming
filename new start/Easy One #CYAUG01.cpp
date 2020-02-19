#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define modi 1000000007
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    getline(cin, s);
    ll sum = 1;
    int len = s.length(); int value;
    for(int i = 0; i < len; i++)
    {
        ll count = 0;
        int value;
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            value = s[i] - 65;
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
        {
            value = s[i] - 71;
        }
        else if(s[i] >= 48 && s[i] <= 57)
        {
            value = s[i] + 4;
        }
        else if(s[i] == 45)
        {
            value = 62;
        }
        else if(s[i] == 95)
        {
            value = 63;
        }

        for(int k = 0; k < 64; k++)
        {
            for(int j = 0; j < 64; j++)
            {
                if((k | j) == value)
                {
                    count++;
                }
            }
        }

        sum = (count * sum) % modi;
    }

    cout << sum << endl;

    return 0;
}