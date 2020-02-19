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
    // int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    while(t--)
    {
        ll n;
        cin >> n;
        ll one = n / 2; ll seven = n / 3;
        ll sevenOne = (n % 3) / 2;
        cout << "one: " << one << endl;
        string ans = "";
        string ans2 = "";
        for(ll i = 0; i < seven; i++)
        {
            ans += '7';
        }
        for(ll i = 0; i < sevenOne; i++)
        {
            ans += '1';
        }
        for(ll i = 0; i < one; i++)
        {
            ans2 += '1';
        }
        if(ans.length() > ans2.length())
        {
            cout << ans << endl;
        }
        else if(ans2.length() < ans.length())
        {
            cout << ans2 << endl;
        }
        else
        {
            if(ans > ans2)
            {
                cout << ans << endl;
            }
            else
            {
                cout << ans2 << endl;
            }
        }
    }

    return 0;
}