#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct two
{
    int value;
    bool var;
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    struct two arr[27];
    for(ll i = 0; i < 26; i++)
    {
        ll k;
        cin >> k;
        arr[i].value = k;
    }

    string str;
    cin >> str;

    int maxi = INT_MIN;
    for(ll i = 0; i < str.length(); i++)
    {
        if(maxi < arr[str[i] - 'a'].value)
        {
            maxi = arr[str[i] - 'a'].value;
        }
    }
    cout << maxi * str.length() << endl;

    return 0;
}