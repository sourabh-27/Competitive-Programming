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
        ll a, b, c, r;
        cin >> a >> b >> c >> r;
        if(b < a)
        {
            swap(a, b);
        }
        ll left = c - r;
        ll right = c + r;
        // cout << "left : " << left << " right: " << right << endl;
        ll ans = 0;
        if(a >= left && a < right && b <= right && b > left)
        {
            // cout << "YO " << endl;
            ans = 0;
        }
        else if(a < left && b > right)
        {
            ans = left - a + b - right;
        }
        else if(a <= right && a >= left && b > right)
        {
            ans = b - right;
        }
        else if(b <= right && b >= left && a < left)
        {
            ans = left - a;
        }
        else if(a > right || b < left)
        {
            ans = b - a;
        }
        cout << ans << endl;
    }

    return 0;
}