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
    ll temp1 = 10, temp2 = 20;
    {

    }
    while(t--)
    {
        ll n;
        cin >> n;
        ll count = 0;
        ll count2 = 0;
        if(n == 1)
        {
            cout << "Yes" << endl;
        }
        else if(n / 20 == 1 || n / 10 == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            while(n % 10 == 0)
            {
                count++;
                n = n / 10;
            }
            while(n % 2 == 0)
            {
                count2++;
                n = n / 2;
            }
            // cout << count << " " << count2 << endl;
            if(n > 1)
            {
                cout << "No" << endl;
            }
            else if(count2 <= count)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}