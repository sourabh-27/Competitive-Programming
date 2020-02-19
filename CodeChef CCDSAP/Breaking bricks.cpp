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
        ll s, a, b, c;
        cin >> s >> a >> b >> c;
        ll sum = a + b + c;
        ll pre = s - a - b; ll post = s - b - c;
        if(s >= sum)
        {
            cout << 1 << endl;
        }
        else if((pre >= 0) || (post >= 0))
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 3 << endl;
        }
    }

    return 0;
}