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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll pos = -1;
        for(ll i = n - 1; i >= 0; i--)
        {
            if((s[i] - 48) % 2 != 0)
            {
                pos = i;
                break;
            }
        }
        string str = "";
        if(pos == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            ll sum = 0;
            for(ll i = 0; i <= pos; i++)
            {
                str += s[i];
                sum += (str[i] - 48);
            }
            if(sum % 2 == 0)
            {
                cout << str << endl;
            }
            else
            {
                string final = ""; int flag = 0; int flag2 = 0;
                for(ll i = 0; i <= pos; i++)
                {
                    if((str[i] - 48) % 2 != 0 && flag == 0)
                    {
                        flag = 1;
                        continue;
                    }
                    else
                    {
                        final += str[i];
                        if((str[i] - 48) != 0)
                        {
                            flag2 = 1;
                        }
                    }
                }
                // cout << "flag2: " << flag2 << endl;
                // cout << "final: " << final << endl;
                if(final.length() == 0 || (final[pos - 1] - 48) % 2 == 0 || flag2 == 0)
                {
                    // cout << "yo" << endl;
                    cout << -1 << endl;
                }
                else
                {
                    string final2 = "";
                    int flagf = 0;
                    for(ll i = 0; i < final.length(); i++)
                    {
                        if((final[i] - 48) == 0 && flagf == 0)
                        {
                            continue;
                        }
                        else
                        {
                            final2 += final[i];
                        }
                    }
                    cout << final2 << endl; 
                }
            }
        }
    }

    return 0;
}