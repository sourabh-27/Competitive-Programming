#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    list<char> l;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 + n % 2 == 1)
        {
            l.push_back(s[i]);
        }
        else
        {
            l.push_front(s[i]);
        }
    }
    for(auto x : l)
    {
        cout << x;
    }

    return 0;
}