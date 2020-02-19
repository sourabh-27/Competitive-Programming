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
        ll r, g, b;
        cin >> r >> g >> b;
        ll sum1, sum2, sum3;
        sum1 = r + g;
        sum2 = g + b;
        sum3 = b + r;
        if(r >= sum2 + 2 || g >= sum3 + 2 || b >= sum1 + 2)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}