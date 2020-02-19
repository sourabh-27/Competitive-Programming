#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    if(n % 2 == 0)
    {
        for(ll i = n / 2 - 1; i >= 0; i--)
        {
            cout << s[i];
        }
        for(ll i = n - 1; i >= n / 2; i--)
        {
            cout << s[i];
        }
    }
    else
    {
        for(ll i = n / 2 - 1; i >= 0; i--)
        {
            cout << s[i];
        }
        cout << s[n / 2];
        for(ll i = n - 1; i > n / 2; i--)
        {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}