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
        string str;
        cin >> str;
        ll len = str.length();
        ll maxi = INT_MIN; ll index = -1;
        for(ll i = 0; i < len; i++)
        {
            for(ll j = i + 1; j < len; j++)
            {
                string new;
                new = new + str[]
            }
        }

        for(ll i = 0; i < len; i++)
        {
            if(index == i)
            {
                continue;
            }
            cout << str[i];
        }
        cout << endl;
    }

    return 0;
}